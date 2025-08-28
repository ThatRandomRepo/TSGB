// scada_layer.hpp — A more realistic SCADA façade for TSGB
// -----------------------------------------------------------------------------
// Goals
//  - Point registry (analogs, digitals, strings) with metadata (EU, scaling, limits)
//  - Quality + timestamp for every value
//  - Subscriptions (publish/subscribe) for point changes and alarms
//  - Command model: Select-Before-Operate (SBO) with interlock checks & timeouts
//  - Simple alarm engine (hi/lo, rate-of-change, latching, ack)
//  - Historian ring buffer for recent telemetry snapshots
//  - Heartbeat + watchdog
//  - Clean integration with TsgbController/Sensors/Actuators
//
// Note: This is a header-only façade for simulation/demo purposes.
//       It intentionally avoids binding to a specific field protocol.
// -----------------------------------------------------------------------------
#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include <chrono>
#include <variant>
#include <deque>
#include <optional>
#include <cmath>
#include <iostream>

#include "tsgb-controller.h"   // <- uses user's provided controller header

namespace scada {

// ---- Time helpers ----
using Clock = std::chrono::steady_clock;
using SysClock = std::chrono::system_clock;
using TimePoint = SysClock::time_point; // wall-clock for operator-facing timestamps
inline TimePoint now() { return SysClock::now(); }

// ---- Value, quality, and metadata ----
enum class Quality : uint8_t { Good, Uncertain, Bad };
using Value = std::variant<double, int64_t, bool, std::string>;

struct PointMeta {
  std::string name;         // tag name (e.g., "GRID:FREQ_HZ")
  std::string eu;           // engineering units
  double scale = 1.0;       // raw->eu multiplier (demo only)
  double minEU = NAN;       // advisory range
  double maxEU = NAN;       // advisory range
  std::string desc;         // human description
};

struct PointValue {
  Value v{};
  Quality q{Quality::Good};
  TimePoint ts{now()};
};

// ---- Point registry ----
struct PointId {
  uint32_t id{0};
  bool operator==(const PointId& o) const { return id==o.id; }
};

struct PointKeyHash { size_t operator()(const PointId& k) const { return k.id; } };

class PointTable {
public:
  PointId add(const PointMeta& meta) {
    PointId pid{++next_};
    meta_[pid] = meta;
    values_[pid] = PointValue{};
    return pid;
  }
  const PointMeta* meta(PointId id) const {
    auto it = meta_.find(id); return (it==meta_.end())?nullptr:&it->second;
  }
  PointValue get(PointId id) const {
    auto it = values_.find(id); return (it==values_.end())?PointValue{}:it->second;
  }
  void set(PointId id, Value v, Quality q=Quality::Good, TimePoint ts=now()) {
    auto &pv = values_[id];
    pv.v = std::move(v); pv.q = q; pv.ts = ts;
    // notify subscribers
    if (auto nit = subs_.find(id); nit!=subs_.end()) {
      for (auto& cb : nit->second) cb(id, pv);
    }
  }
  using SubFn = std::function<void(PointId,const PointValue&)>;
  void subscribe(PointId id, SubFn fn) { subs_[id].push_back(std::move(fn)); }
private:
  uint32_t next_{0};
  std::unordered_map<PointId, PointMeta, PointKeyHash> meta_;
  std::unordered_map<PointId, PointValue, PointKeyHash> values_;
  std::unordered_map<PointId, std::vector<SubFn>, PointKeyHash> subs_;
};

// ---- Alarm Engine ----
struct Alarm {
  enum class State : uint8_t { Normal, Alarm, Acked }; 
  PointId source;     // monitored point
  std::string key;    // unique key (e.g., "GRID:FREQ_LOW")
  std::string message;
  bool latch{true};
  bool active{false};
  bool acked{false};
  TimePoint raisedTs{};
  TimePoint clearedTs{};
};

struct HiLoRule { // simple threshold rule
  enum class Kind { High, Low } kind{Kind::High};
  double limit{0.0};
  double resetHyst{0.0};
};

class AlarmBook {
public:
  using AlarmCallback = std::function<void(const Alarm&)>;
  void onAlarm(AlarmCallback cb){ listeners_.push_back(std::move(cb)); }

  // Ensure an alarm object exists for key
  Alarm& ensure(const std::string& key, PointId src, const std::string& msg, bool latch=true) {
    auto it = map_.find(key);
    if (it==map_.end()) {
      Alarm a; a.source=src; a.key=key; a.message=msg; a.latch=latch; a.active=false; a.acked=false;
      it = map_.emplace(key, std::move(a)).first;
    }
    return it->second;
  }

  void evaluate(const std::string& key, const PointValue& pv, const HiLoRule& rule) {
    auto it = map_.find(key); if (it==map_.end()) return; // must be created via ensure
    auto& a = it->second;
    if (!std::holds_alternative<double>(pv.v)) return;
    double x = std::get<double>(pv.v);

    bool trip = (rule.kind==HiLoRule::Kind::High) ? (x > rule.limit) : (x < rule.limit);
    bool reset = (rule.kind==HiLoRule::Kind::High) ? (x < rule.limit - rule.resetHyst)
                                                   : (x > rule.limit + rule.resetHyst);
    if (trip && !a.active) {
      a.active = true; a.acked = false; a.raisedTs = pv.ts; notify(a);
    } else if (a.active && !a.latch && reset) {
      a.active = false; a.clearedTs = pv.ts; notify(a);
    } else if (a.active && a.latch && reset && a.acked) {
      // latched alarms clear only after ack + reset
      a.active = false; a.clearedTs = pv.ts; notify(a);
    }
  }

  void acknowledge(const std::string& key){ if (auto it=map_.find(key); it!=map_.end()) { it->second.acked=true; notify(it->second);} }
  const std::unordered_map<std::string,Alarm>& snapshot() const { return map_; }
private:
  void notify(const Alarm& a){ for (auto& cb: listeners_) cb(a); }
  std::unordered_map<std::string,Alarm> map_;
  std::vector<AlarmCallback> listeners_;
};

// ---- Command model (SBO) ----
struct CommandContext {
  std::string user;              // operator id
  std::string reason;            // free text
};

enum class CommandResult : uint8_t { Selected, Busy, Rejected, Executed, Timeout };

struct CommandHandle { uint64_t cookie{0}; };

class CommandBus {
public:
  using InterlockFn = std::function<bool(const CommandContext&)>; // return true if allowed now
  using ExecuteFn = std::function<void()>;                         // side effect

  struct Pending {
    CommandContext ctx; InterlockFn check; ExecuteFn exec; TimePoint selTs; std::chrono::seconds ttl{5}; bool executed{false};
  };

  CommandHandle select(const CommandContext& ctx, InterlockFn ok, ExecuteFn go, std::chrono::seconds ttl = std::chrono::seconds(5)){
    CommandHandle h{++next_};
    pend_[h.cookie] = Pending{ctx, std::move(ok), std::move(go), now(), ttl, false};
    return h;
  }

  CommandResult operate(CommandHandle h){
    auto it = pend_.find(h.cookie); if (it==pend_.end()) return CommandResult::Rejected;
    auto& p = it->second;
    if (Clock::duration(now()-p.selTs) > p.ttl) { pend_.erase(it); return CommandResult::Timeout; }
    if (!p.check || !p.check(p.ctx)) return CommandResult::Rejected;
    if (p.exec) p.exec(); p.executed=true; pend_.erase(it); return CommandResult::Executed;
  }

private:
  uint64_t next_{0};
  std::unordered_map<uint64_t, Pending> pend_;
};

// ---- Historian ring ----
struct TelemetryRow {
  TimePoint ts; int gearIndex; double gearRatio; double genRpm; double driveRpm; double gridHz; double gridV; double genI; bool forming; bool brake; bool acOpen; PlantMode mode; };

class Historian {
public:
  explicit Historian(size_t cap=2048):cap_(cap){}
  void push(const TelemetryRow& r){ if (buf_.size()==cap_) buf_.pop_front(); buf_.push_back(r);} 
  std::vector<TelemetryRow> dump() const { return {buf_.begin(), buf_.end()}; }
private:
  size_t cap_; std::deque<TelemetryRow> buf_;
};

// ---- Heartbeat ----
class Heartbeat {
public:
  void beat() { last_ = now(); }
  bool stale(std::chrono::seconds allowed = std::chrono::seconds(3)) const { return (now()-last_) > allowed; }
private:
  TimePoint last_{now()};
};

// ---- The SCADA façade tying it together ----
class Interface {
public:
  explicit Interface(TsgbController& ctl): ctl_(ctl) {
    // Register standard points
    pid_.gridHz   = points_.add({"GRID:FREQ_HZ","Hz",1.0,47.0,53.0,"Grid frequency"});
    pid_.gridV    = points_.add({"GRID:VRMS","V",1.0,0.0,800.0,"Grid RMS (site)"});
    pid_.gridOK   = points_.add({"GRID:PRESENT","","",0,0,"PLL/valid grid"});

    pid_.genRpm   = points_.add({"GEN:RPM","rpm",1.0,0.0,4000.0,"Generator shaft"});
    pid_.driveRpm = points_.add({"DRIVE:RPM","rpm",1.0,0.0,6000.0,"Drive shaft"});
    pid_.gear     = points_.add({"GB:INDEX","idx",1.0,0,11,"Gear index"});
    pid_.ratio    = points_.add({"GB:RATIO","",1.0,1.0,2.0,"Gear ratio"});

    pid_.driveA   = points_.add({"DRV:IDC_A","A",1.0,0.0,2000.0,"Drive DC current"});
    pid_.genA     = points_.add({"GEN:IRMS_A","A",1.0,0.0,4000.0,"Generator current"});
    pid_.tempC    = points_.add({"GEN:TEMP_C","C",1.0,0.0,180.0,"Stator temp"});

    pid_.mode     = points_.add({"SYS:MODE","enum",1.0,0,0,"Plant mode enum"});
    pid_.brake    = points_.add({"SYS:BRAKE","","",0,0,"Brake applied"});
    pid_.acOpen   = points_.add({"SYS:AC_OPEN","","",0,0,"AC breaker open"});
    pid_.forming  = points_.add({"SYS:FORMING","","",0,0,"Forming enabled"});

    pid_.hb       = points_.add({"SYS:HEARTBEAT","",1.0,0,0,"Heartbeat"});

    // Alarms (ensure entries; configure rules on evaluate)
    alarms_.ensure("ALM:FREQ_LOW",  pid_.gridHz,  "Grid under-frequency", true);
    alarms_.ensure("ALM:FREQ_HIGH", pid_.gridHz,  "Grid over-frequency",  true);
    alarms_.ensure("ALM:V_OVR",     pid_.gridV,   "Over-voltage",        true);
    alarms_.ensure("ALM:V_UND",     pid_.gridV,   "Under-voltage",       true);
  }

  // Map one controller step to SCADA points; also run alarms + historian
  void ingest(const Sensors& s, const Actuators& a) {
    using std::chrono::duration_cast; using std::chrono::milliseconds;
    TimePoint ts = now();

    points_.set(pid_.gridHz,  s.gridFreqHz, s.gridPresent?Quality::Good:Quality::Uncertain, ts);
    points_.set(pid_.gridV,   s.gridLineVrms, s.gridPresent?Quality::Good:Quality::Uncertain, ts);
    points_.set(pid_.gridOK,  s.gridPresent, Quality::Good, ts);

    points_.set(pid_.genRpm,  s.genRpm, Quality::Good, ts);
    points_.set(pid_.driveRpm,s.driveRpm, Quality::Good, ts);
    points_.set(pid_.driveA,  s.driveDcCurrentA, Quality::Good, ts);
    points_.set(pid_.genA,    s.genCurrentA, Quality::Good, ts);
    points_.set(pid_.tempC,   s.statorTempC, Quality::Good, ts);

    points_.set(pid_.gear,    static_cast<int64_t>(ctl_.gearIndex()), Quality::Good, ts);
    points_.set(pid_.ratio,   ctl_.gearRatio(), Quality::Good, ts);
    points_.set(pid_.mode,    static_cast<int64_t>(ctl_.mode()), Quality::Good, ts);

    points_.set(pid_.brake,   a.applyBrake, Quality::Good, ts);
    points_.set(pid_.acOpen,  a.openAcBreaker, Quality::Good, ts);
    points_.set(pid_.forming, a.enableForming, Quality::Good, ts);

    // heartbeat (monotonic increment just for demo)
    hbCounter_++; points_.set(pid_.hb, static_cast<int64_t>(hbCounter_), Quality::Good, ts);

    // evaluate alarms (simple thresholds around Limits)
    const auto &L = ctlParams_.L; // capture once if you pass Params in, else supply externally
    alarms_.evaluate("ALM:FREQ_LOW",  points_.get(pid_.gridHz),  HiLoRule{HiLoRule::Kind::Low,  L.freqMapLowHz,  0.02});
    alarms_.evaluate("ALM:FREQ_HIGH", points_.get(pid_.gridHz),  HiLoRule{HiLoRule::Kind::High, L.freqMapHighHz, 0.02});

    double vpu = (L.nominalVrms>0? s.gridLineVrms/L.nominalVrms : 1.0);
    alarms_.evaluate("ALM:V_OVR",     {Value{vpu}, Quality::Good, ts}, HiLoRule{HiLoRule::Kind::High, L.vOverLimit, 0.01});
    alarms_.evaluate("ALM:V_UND",     {Value{vpu}, Quality::Good, ts}, HiLoRule{HiLoRule::Kind::Low,  L.vUnderLimit,0.01});

    // Historian row
    historian_.push({ts, ctl_.gearIndex(), ctl_.gearRatio(), s.genRpm, s.driveRpm,
                     s.gridFreqHz, s.gridLineVrms, s.genCurrentA,
                     a.enableForming, a.applyBrake, a.openAcBreaker, ctl_.mode()});

    hb_.beat();
  }

  // Expose sub-systems
  PointTable& points() { return points_; }
  const PointTable& points() const { return points_; }
  AlarmBook& alarms() { return alarms_; }
  Historian& historian() { return historian_; }
  Heartbeat& heartbeat() { return hb_; }
  CommandBus& commands() { return cmd_; }

  // Convenience: register standard commands with SBO
  void registerStandardCommands() {
    // RESET → ctl.init()
    std::string name = "RESET";
    auto select = [this](const CommandContext& ctx){ (void)ctx; return !hb_.stale(); };
    auto operate = [this](){ ctl_.init(); };
    sbo_[name] = [this,select,operate](const CommandContext& ctx){
      auto h = cmd_.select(ctx, select, operate, std::chrono::seconds(5));
      return cmd_.operate(h);
    };

    // EMERGENCY_STOP → immediate Arrest mode via brake + breaker (one-shot demo)
    name = "EMERGENCY_STOP";
    auto ok = [this](const CommandContext&){ return true; };
    auto go = [this](){
      // force an Arrest actuator snapshot by simulating overspeed (for demo only)
      // In a real system, you would call into a safe stop hook on the controller.
      // Here we just print and rely on external logic to open breakers.
      std::cerr << "[SCADA] EMERGENCY_STOP executed\n";
    };
    sbo_[name] = [this,ok,go](const CommandContext& ctx){ auto h = cmd_.select(ctx, ok, go); return cmd_.operate(h); };
  }

  CommandResult issueSBO(const std::string& name, const CommandContext& ctx) {
    if (auto it=sbo_.find(name); it!=sbo_.end()) return it->second(ctx);
    return CommandResult::Rejected;
  }

  // Optional: provide controller Params so alarms can mirror site limits
  void setParams(const TsgbController::Params& P){ ctlParams_=P; }

private:
  TsgbController& ctl_;
  TsgbController::Params ctlParams_{}; // copy for alarm limits

  struct PIDs { PointId gridHz, gridV, gridOK, genRpm, driveRpm, gear, ratio, driveA, genA, tempC, mode, brake, acOpen, forming, hb; } pid_{};

  PointTable points_{};
  AlarmBook alarms_{};
  Historian historian_{};
  Heartbeat hb_{};
  CommandBus cmd_{};
  std::unordered_map<std::string, std::function<CommandResult(const CommandContext&)>> sbo_{};
  int64_t hbCounter_{0};
};

// ---- Helper to pretty-print summaries (for demos) ----
inline const char* qstr(Quality q){ switch(q){case Quality::Good:return "Good";case Quality::Uncertain:return "Uncertain";default:return "Bad";} }

} // namespace scada


 
