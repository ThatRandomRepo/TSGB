#pragma once
#include <array>
#include <cstdint>
#include <cmath>
#include <algorithm>
#include <optional>
#include <chrono>

// -------------------- Platform/plant I/O model --------------------
struct Sensors {
  // Grid-side (filtered or PLL outputs where applicable)
  double gridFreqHz;        // valid when gridPresent == true
  double gridRocofHzPerS;   // negative on falling events
  double gridLineVrms;      // 3-phase line-line or line-neutral per site (configure thresholds)
  bool   gridPresent;       // "valid PLL lock" / signal present flag for this sample

  // Machine-side
  double genRpm;            // synchronous generator shaft rpm (target ~1500 rpm for 50 Hz)
  double driveRpm;          // fixed-RPM drive/mech side (nominally ~3000 rpm mechanically)
  double driveDcCurrentA;   // input drive current (proxy for torque draw)
  double genCurrentA;       // stator current (RMS)
  double statorTempC;       // winding temperature estimate
  bool   acProtectionHealthy; // true if downstream protections ok (OV/OC relays, etc.)
};

struct Actuators {
  int    targetGearIndex;   // 0..11 (12-speed)
  bool   applyBrake;        // mech brake (emergency arrest)
  bool   openAcBreaker;     // trip generator AC breaker
  bool   enableForming;     // form the islanded microgrid (no external grid)
  double excitationSet;     // 0..1 (excitation/AVR demand), optional for forming
};

// -------------------- Operating state --------------------
enum class PlantMode : uint8_t {
  GridFollowing,   // normal; track & support grid
  GridSupport,     // pushing hard into a weak grid (frequency sag / bad ROCOF)
  Forming,         // grid absent; we form voltage/frequency island
  Arrest           // overspeed/critical trip; braking
};

struct Limits {
  // Mechanical
  double targetGenRpm     = 1500.0;
  double maxRatio         = 2.00;   // hard cap (top gear)
  double overspeedRpm     = 3010.0; // emergency arrest

  // Electrical/grid
  double freqMapHighHz    = 50.10;  // top of mapping window
  double freqMapLowHz     = 47.90;  // bottom of mapping window
  double rocofDownshift   = -0.20;  // Hz/s threshold to add shove
  double vOverLimit       = 1.10;   // per-unit Vrms trip (e.g., 10% over)
  double vUnderLimit      = 0.90;   // per-unit under-voltage latch to forming
  double nominalVrms      = 400.0;  // set for your site (LL or LN)

  // Currents/thermal
  double driveOverCurrent = 1200.0; // A
  double genOverCurrent   = 1500.0; // A
  double tempHotC         = 120.0;  // winding temp derate/trip

  // Dynamics & UX
  double minShiftIntervalS = 0.25;  // avoid hunting
  double freqHysteresisHz  = 0.03;  // to keep gear stable near boundaries
  double baselineLearnRate = 0.02;  // moving average for drive idle current
};

// -------------------- 12-speed box w/ geometric spacing 1.00 → 2.00 --------------------
struct Gearbox {
  static constexpr int kGears = 12;
  std::array<double, kGears> ratio; // ratio[i] in ascending torque order

  static Gearbox makeGeometric(double minRatio=1.00, double maxRatio=2.00) {
    Gearbox g{};
    const double step = std::pow(maxRatio/minRatio, 1.0/(kGears-1));
    double r = minRatio;
    for (int i=0;i<kGears;++i) { g.ratio[i] = r; r *= step; }
    return g;
  }

  int clampIndex(int i) const {
    return std::clamp(i, 0, kGears-1);
  }
};

// -------------------- Controller --------------------
class TsgbController {
public:
  struct Params {
    Limits L{};
    Gearbox box = Gearbox::makeGeometric(1.00, 2.00);
    double sampleRateHz = 5000.0; // 5 kHz loop
    int    gridWatchdogCycles = 500; // if no valid grid for 500 cycles → forming
  };

  explicit TsgbController(const Params& p = Params{})
  : P(p) {
    // Build frequency→gear map edges (12 buckets) with hysteresis
    buildFrequencyBands();
  }

  void init() {
    mode_ = PlantMode::GridFollowing;
    gear_ = 4;               // start tall; we’ll step as needed never less than 2
    lastShiftS_ = -1e9;
    baselineDriveA_ = 0.0;
    gridMissingCount_ = 0;
  }

  Actuators update(const Sensors& s, double nowS) {
    // ---------- Update grid presence watchdog ----------
    if (s.gridPresent) gridMissingCount_ = 0;
    else               gridMissingCount_ = std::min(gridMissingCount_+1, 100000000);

    // ---------- Safety layer (dominates) ----------
    Actuators a{};
    a.targetGearIndex = gear_;
    a.applyBrake = false;
    a.openAcBreaker = false;
    a.enableForming = false;
    a.excitationSet = 0.0;

    // Mechanical overspeed → Arrest
    if (s.genRpm > P.L.overspeedRpm) {
      mode_ = PlantMode::Arrest;
    }

    // Electrical hard trips (breaker open)
    const double vpu = (P.L.nominalVrms > 0.0) ? (s.gridLineVrms / P.L.nominalVrms) : 1.0;
    const bool overV = vpu > P.L.vOverLimit;
    const bool underV= vpu < P.L.vUnderLimit;
    const bool driveOC = s.driveDcCurrentA > P.L.driveOverCurrent;
    const bool genOC   = s.genCurrentA   > P.L.genOverCurrent;
    const bool tooHot  = s.statorTempC   > P.L.tempHotC;

    if (overV || driveOC || genOC || tooHot) {
      a.openAcBreaker = true;
      if (overV || s.genRpm > P.L.overspeedRpm) {
        mode_ = PlantMode::Arrest;
      }
    }

    // ---------- Mode arbitration ----------
    if (mode_ == PlantMode::Arrest) {
      // Let sprag freewheel mechanically; actively brake to arrest rpm.
      a.applyBrake = true;
      a.openAcBreaker = true;
      a.enableForming = false;
      // Remain in Arrest until rpm well below target, then return to Forming or GridFollowing depending on grid presence
      if (s.genRpm < (P.L.targetGenRpm * 0.7)) {
        mode_ = (gridMissingCount_ >= P.gridWatchdogCycles) ? PlantMode::Forming
                                                            : PlantMode::GridFollowing;
      }
      a.targetGearIndex = gear_; // freeze gear while arresting
      return a;
    }

    // If grid is missing long enough → Forming mode
    if (gridMissingCount_ >= P.gridWatchdogCycles) {
      mode_ = PlantMode::Forming;
    } else {
      // Grid present—choose following/support based on quality
      const bool weak = (s.gridFreqHz < 50.0 - 0.10) || (s.gridRocofHzPerS <= P.L.rocofDownshift);
      mode_ = weak ? PlantMode::GridSupport : PlantMode::GridFollowing;
    }

    // ---------- Gearing logic ----------
    // Map frequency to a *commanded* gear bucket. We’ll still enforce one-step-at-a-time & min dwell.
    int commanded = gearFromFrequency((mode_==PlantMode::Forming) ? 50.00 : s.gridFreqHz);

    // In support mode, bias one extra "downshift" (toward more torque) if not already at max
    if (mode_ == PlantMode::GridSupport && commanded < Gearbox::kGears-1) {
      commanded += 1;
    }

    // One-step policy with dwell
    if (canShift(nowS)) {
      if (commanded > gear_) gear_ += 1;         // “downshift”: toward more torque (bigger ratio)
      else if (commanded < gear_) gear_ -= 1;    // “upshift”: toward less torque
      gear_ = P.box.clampIndex(gear_);
      lastShiftS_ = nowS;
    }

    // Enforce mechanical cap even if table mis-set
    if (P.box.ratio[gear_] > P.L.maxRatio) {
      gear_ = P.box.clampIndex(gear_ - 1);
    }

    
    // ---------- Overspeed protection: fast gen RPM rise check ----------
    static double lastGenRpm = s.genRpm;
    static double lastTimeS = nowS;

    double rpmRate = (nowS > lastTimeS) ? (s.genRpm - lastGenRpm) / (nowS - lastTimeS) : 0.0;

    bool genRpmSpike = s.genRpm > 1501.0 || rpmRate > 100.0; // Threshold can be tuned
    if (genRpmSpike) {
      mode_ = PlantMode::Arrest;
      a.applyBrake = true;
      a.openAcBreaker = true;
      a.targetGearIndex = gear_; // Freeze gear
      return a;
    }

    lastGenRpm = s.genRpm;
    lastTimeS = nowS;

// ---------- AVR/excitation hint ----------
    if (mode_ == PlantMode::Forming) {
      a.enableForming = true;
      // Simple droop-ish excitation hint: nudge voltage target based on load (gen current)
      a.excitationSet = std::clamp(0.5 + 0.0001 * (s.genCurrentA - 500.0), 0.0, 1.0);
      // In forming, synthesize a frequency reference near nominal and keep gear near unity
      // but allow one “support” downshift if load drags rpm
      if (std::fabs(s.genRpm - P.L.targetGenRpm) > 40.0 && canShift(nowS)) {
        if (s.genRpm < P.L.targetGenRpm && gear_ < Gearbox::kGears-1) { gear_ += 1; lastShiftS_ = nowS; }
        if (s.genRpm > P.L.targetGenRpm && gear_ > 0)                  { gear_ -= 1; lastShiftS_ = nowS; }
      }
    } else {
      // Grid-following/support: tiny corrective step if gen RPM drifts far (close-ratio box)
      if (std::fabs(s.genRpm - P.L.targetGenRpm) > 60.0 && canShift(nowS)) {
        if (s.genRpm < P.L.targetGenRpm && gear_ < Gearbox::kGears-1) { gear_ += 1; lastShiftS_ = nowS; }
        if (s.genRpm > P.L.targetGenRpm && gear_ > 0)                  { gear_ -= 1; lastShiftS_ = nowS; }
      }
    }

    // ---------- Baseline learning (drive idle current when grid calm) ----------
    if (s.gridPresent && std::fabs(s.gridFreqHz-50.0) < 0.02 && std::fabs(s.gridRocofHzPerS) < 0.02) {
      baselineDriveA_ = (1.0 - P.L.baselineLearnRate) * baselineDriveA_ + P.L.baselineLearnRate * s.driveDcCurrentA;
    }

    // ---------- Final actuator pack ----------
    a.targetGearIndex = gear_;
    // Interlock: if AC protections unhealthy, open breaker
    if (!s.acProtectionHealthy) a.openAcBreaker = true;
    return a;
  }

  PlantMode mode() const { return mode_; }
  int gearIndex() const { return gear_; }
  double gearRatio() const { return P.box.ratio[gear_]; }

private:
  bool canShift(double nowS) const {
    return (nowS - lastShiftS_) >= P.L.minShiftIntervalS;
  }

  // Build 12 bands across [50.10 .. 47.90] with hysteresis
  void buildFrequencyBands() {
    const double hi = P.L.freqMapHighHz;
    const double lo = P.L.freqMapLowHz;
    const double span = hi - lo; // positive (2.20 Hz)
    const double step = span / Gearbox::kGears;
    bandHi_.fill(0.0);
    bandLo_.fill(0.0);
    for (int i=0;i<Gearbox::kGears;i++) {
      const double center = hi - (i + 0.5) * step;
      bandHi_[i] = center + 0.5*step + 0.5*P.L.freqHysteresisHz;
      bandLo_[i] = center - 0.5*step - 0.5*P.L.freqHysteresisHz;
    }
    // Band 0 ~ highest freq (tallest gear), Band 11 ~ lowest freq (shortest gear)
  }

  int gearFromFrequency(double freqHz) const {
    // If above top band → tallest gear (0). If below bottom band → shortest (11).
    if (freqHz >= bandHi_[0]) return 0;
    if (freqHz <= bandLo_[Gearbox::kGears-1]) return Gearbox::kGears-1;

    // Find band whose [Lo, Hi] contains freq
    for (int i=0;i<Gearbox::kGears;i++) {
      if (freqHz <= bandHi_[i] && freqHz >= bandLo_[i]) return i;
    }
    // Between bands due to hysteresis: pick nearest by center distance
    double bestDist = 1e9; int best = 0;
    for (int i=0;i<Gearbox::kGears;i++) {
      const double center = 0.5*(bandHi_[i] + bandLo_[i]);
      const double d = std::fabs(freqHz - center);
      if (d < bestDist) { bestDist = d; best = i; }
    }
    return best;
  }

  Params P;
  PlantMode mode_{PlantMode::GridFollowing};
  int    gear_{0};
  double lastShiftS_{-1e9};
  double baselineDriveA_{0.0};
  int    gridMissingCount_{0};
  std::array<double, Gearbox::kGears> bandHi_{};
  std::array<double, Gearbox::kGears> bandLo_{};
};
