#include "tsgb_ctrl.hpp"
#include "scada_layer.hpp"
#include <iostream>
#include <thread>

int main() {
  TsgbController::Params P;
  P.L.nominalVrms = 400.0; // example site
  TsgbController ctl(P);
  ctl.init();

  // Attach SCADA interface
  ScadaInterface scada(ctl);
  scada.registerStandardCommands();

  // Simulate 2 seconds @ 5 kHz
  const double dt = 1.0 / P.sampleRateHz;
  const int steps = int(2.0 / dt);

  Sensors s{};
  s.gridPresent = true;
  s.gridFreqHz = 50.02;
  s.gridRocofHzPerS = 0.0;
  s.gridLineVrms = 400.0;
  s.genRpm = 1500.0;
  s.driveRpm = 3000.0;
  s.driveDcCurrentA = 200.0;
  s.genCurrentA = 300.0;
  s.statorTempC = 70.0;
  s.acProtectionHealthy = true;

  double t = 0.0;
  for (int k = 0; k < steps; ++k) {
    // Script a dip then recovery, plus brief missing-grid event
    if (k == 5000)  { s.gridFreqHz = 49.6; s.gridRocofHzPerS = -0.3; }      // sag → support
    if (k == 15000) { s.gridFreqHz = 50.03; s.gridRocofHzPerS = 0.0; }      // recovery
    if (k == 18000) { s.genRpm = 1510.0; } // Inject overspeed spike 
    if (k == 20000) { s.gridPresent = false; }                              // lose grid
    if (k == 20550) { s.gridPresent = true; s.gridFreqHz = 50.01; }         // back after >500 cycles

    // Overspeed injection test
    if (k == 18000) { s.genRpm = 1510.0; }

    // Crude “load drag”: when supporting, gen rpm tends to fall slightly
    if (ctl.mode() == PlantMode::GridSupport) s.genRpm = 1470.0;
    else if (ctl.mode() == PlantMode::Forming) s.genRpm = 1500.0;
    else s.genRpm = 1500.0;

    // Drive current rises with shorter gears (just for the demo printout)
    s.driveDcCurrentA = 180.0 + ctl.gearIndex() * 30.0;

    Actuators a = ctl.update(s, t);

    // SCADA command simulation
    if (k == 1000) {
      scada.issueCommand("RESET");
    }

    if ((k % 500) == 0) { // print @10 Hz
      auto telemetry = scada.getTelemetry(s);
      std::cout
        << "t=" << t
        << " mode=" << (telemetry.mode == PlantMode::GridFollowing ? "Follow" :
                        telemetry.mode == PlantMode::GridSupport ? "Support" :
                        telemetry.mode == PlantMode::Forming ? "Forming" : "Arrest")
        << " gearIdx=" << telemetry.gearIndex
        << " ratio=" << telemetry.gearRatio
        << " brake=" << telemetry.brakeApplied
        << " ACopen=" << telemetry.acBreakerOpen
        << " forming=" << telemetry.formingEnabled
        << "\n";
    }

    t += dt;
  }

  return 0;
}
