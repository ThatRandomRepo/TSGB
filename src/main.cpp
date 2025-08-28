#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>

#include "tsgb-controller.h"
#include "scada_layer.hpp"  // from the canvas: header-only façade

using namespace std::chrono_literals;

static const char* modeStr(PlantMode m){
  switch(m){
    case PlantMode::GridFollowing: return "GridFollowing";
    case PlantMode::GridSupport:   return "GridSupport";
    case PlantMode::Forming:       return "Forming";
    case PlantMode::Arrest:        return "Arrest";
  }
  return "?";
}

int main(){
  // ---- Controller parameters ----
  TsgbController::Params P;
  P.sampleRateHz = 5000.0;            // 5 kHz control loop
  P.gridWatchdogCycles = 500;          // ~100 ms grid-missing ⇒ allow forming
  P.L.nominalVrms   = 400.0;
  P.L.targetGenRpm  = 1500.0;          // ~50 Hz target via gearbox
  P.L.freqMapLowHz  = 49.80;           // alarm limits mirrored by SCADA
  P.L.freqMapHighHz = 50.20;
  P.L.vUnderLimit   = 0.90;            // per-unit (relative to nominalVrms)
  P.L.vOverLimit    = 1.10;

  TsgbController ctl(P);
  ctl.init();

  // ---- SCADA façade ----
  scada::Interface scada(ctl);
  scada.setParams(P);
  scada.registerStandardCommands();

  // Subscribe to alarms for demo output
  scada.alarms().onAlarm([](const scada::Alarm& a){
    std::cout << "[ALM] key=" << a.key
              << " active=" << (a.active?"1":"0")
              << " acked=" << (a.acked?"1":"0")
              << " msg=\"" << a.message << "\"\n";
  });

  // ---- Plant sensor initial conditions ----
  Sensors s{};
  s.gridPresent      = true;
  s.gridFreqHz       = 50.00;
  s.gridRocofHzPerS  = 0.0;
  s.gridLineVrms     = 400.0;
  s.genRpm           = 1500.0;
  s.driveRpm         = 3000.0;
  s.driveDcCurrentA  = 180.0;
  s.genCurrentA      = 250.0;
  s.statorTempC      = 70.0;
  s.acProtectionHealthy = true;

  // ---- Simulation timing ----
  const double dt = 1.0 / P.sampleRateHz;
  const double durationS = 2.0; // 2 seconds
  const int steps = static_cast<int>(durationS / dt);

  double t = 0.0;

  for (int k = 0; k < steps; ++k){
    // inject a couple of grid events to exercise alarms & mode logic
    if (k == 5'000)   { s.gridFreqHz = 49.70; s.gridRocofHzPerS = -0.3; }    // under-frequency
    if (k == 10'000)  { s.gridFreqHz = 50.03; s.gridRocofHzPerS =  0.0; }    // back normal

    if (k == 12'000)  { s.gridPresent = false; }                             // brief loss of grid
    if (k == 12'550)  { s.gridPresent = true; s.gridFreqHz = 50.01; }

    // flimsy plant dynamics for the demo: gen rpm drifts a bit with load
    s.genRpm  += 0.02 * std::sin(0.0006 * k);
    s.driveRpm = s.genRpm * 2.0; // pretend a roughly 2:1 box around mid gears

    // drive current rises with shorter gears (just to have something to print)
    s.driveDcCurrentA = 180.0 + ctl.gearIndex() * 30.0;

    // Controller step
    Actuators a = ctl.update(s, t);

    // Feed SCADA
    scada.ingest(s, a);

    // Issue a demo command mid-run
    if (k == 1'000) {
      auto res = scada.issueSBO("RESET", {"operatorA","demo reset"});
      std::cout << "[SBO] RESET result=" << static_cast<int>(res) << "\n";
    }

    // slow status print @10 Hz
    if ((k % 500) == 0) {
      auto last = scada.historian().dump().back();
      std::cout << "t=" << t
                << " mode=" << modeStr(last.mode)
                << " gear=" << last.gearIndex
                << " ratio=" << last.gearRatio
                << " Hz=" << last.gridHz
                << " V=" << last.gridV
                << " genA=" << last.genI
                << " brk=" << (last.brake?1:0)
                << " acOpen=" << (last.acOpen?1:0)
                << " forming=" << (last.forming?1:0)
                << "\n";
    }

    t += dt;
  }

  // End-of-run: show a compact alarm summary
  for (const auto& [key, a] : scada.alarms().snapshot()){
    std::cout << "[ALM-SUMMARY] " << key
              << " active=" << (a.active?"1":"0")
              << " acked=" << (a.acked?"1":"0")
              << "\n";
  }

  return 0;
}
