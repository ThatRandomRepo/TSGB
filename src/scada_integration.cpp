// scada_layer.hpp
#pragma once
#include "tsgb-ctl.cpp"
#include <string>
#include <map>
#include <functional>
#include <iostream>

// -------------------- SCADA Interface Layer --------------------
// A simple abstraction allowing external SCADA systems to query state,
// issue high-level commands, and subscribe to data events.

class ScadaInterface {
public:
    using CommandHandler = std::function<void(const std::string&)>;

    struct TelemetrySnapshot {
        double genRpm;
        double driveRpm;
        int gearIndex;
        double gearRatio;
        PlantMode mode;
        bool brakeApplied;
        bool acBreakerOpen;
        bool formingEnabled;
    };

    ScadaInterface(TsgbController& ctlRef)
    : ctl(ctlRef) {}

    // ----------- Telemetry -------------
    TelemetrySnapshot getTelemetry(const Sensors& s) const {
        Actuators last = ctl.update(s, 0.0); // assuming side-effect-free snapshot
        return {
            s.genRpm,
            s.driveRpm,
            ctl.gearIndex(),
            ctl.gearRatio(),
            ctl.mode(),
            last.applyBrake,
            last.openAcBreaker,
            last.enableForming
        };
    }

    // ----------- Command Interface -------------
    void registerCommand(const std::string& cmd, CommandHandler handler) {
        commandMap[cmd] = handler;
    }

    void issueCommand(const std::string& cmd) {
        if (commandMap.count(cmd)) {
            commandMap[cmd](cmd);
        } else {
            std::cerr << "Unknown SCADA command: " << cmd << std::endl;
        }
    }

    // Example: binding high-level reset or trip override
    void registerStandardCommands() {
        registerCommand("RESET", [&](const std::string&) {
            ctl.init();
            std::cout << "[SCADA] Controller reset." << std::endl;
        });

        registerCommand("EMERGENCY_STOP", [&](const std::string&) {
            emergencyStop = true;
            std::cout << "[SCADA] Emergency stop triggered." << std::endl;
        });
    }

    bool isEmergencyStopActive() const {
        return emergencyStop;
    }

private:
    TsgbController& ctl;
    std::map<std::string, CommandHandler> commandMap;
    bool emergencyStop = false;
};
