
# TSGB Grid Integration Block Diagram and Technical Overview

## Overview

This document outlines the electrical integration of the **TwinScroll Grid Balancer (TSGB)** with a renewable power source and the AC grid. The TSGB unit serves as a self-regulating mechanical grid support device that delivers real inertia, black start capability, and synchronous power output, using a fixed-RPM DC drive and synchronous generator.

---

## Block-Level Schematic

```
+--------------------------+           +---------------------------+           +--------------------------+
|                          |           |                           |           |                          |
|   DC Power Source        |   DC In   |   TSGB Core System        |   3-Phase |   AC Grid / Substation   |
|   (Battery / Wind / PV)  +---------->+   (Motor, Shaft, AMT,     +---------->+   Busbars / HVDC / Load  |
|                          |           |    Generator)             |           |                          |
+--------------------------+           |                           |           +--------------------------+
                                        |                           |
                                        |  Internal Protections:    |
                                        |  - Overcurrent Relays     |
                                        |  - Shaft Overspeed Brake  |
                                        |  - Sprag Clutch (1-way)   |
                                        |  - Gearbox Shift Logic    |
                                        |                           |
                                        +-------------+-------------+
                                                      |
                                                      v
                                       +-------------------------------+
                                       |   Local Monitoring & Control  |
                                       |   - RPM / Torque / Current    |
                                       |   - Grid Sync Detection       |
                                       |   - Protection Feedback       |
                                       |   - Manual/Auto Control Mode  |
                                       +-------------------------------+
                                                      |
                                                      v
                                       +-------------------------------+
                                       |       SCADA / DNO Interface   |
                                       |       (Telemetry + Commands)  |
                                       +-------------------------------+
```

---

## Electrical Interfaces

### DC Input
- **Terminals**: 2-wire HVDC connection
- **Source Types**:
  - Battery Energy Storage Systems (BESS)
  - Rectified output from wind turbines
  - HVDC bus connections
  - Photovoltaic solar (via DC/DC control)
- **Nominal Voltage Range**: 400 V to 1500 V (configurable)
- **Protections**:
  - DC fuse or breaker
  - Reverse polarity blocking
  - Overcurrent protection
- **Monitoring**:
  - Real-time current feedback (used to trigger AMT downshifts)
  - Input voltage for diagnostics and ramp-up control

---

### TSGB Core System
- **Components**:
  - Fixed-RPM DC Motor (3000 RPM)
  - Flywheel Shaft (up to 10–40 tons, typically 0.7–1.2 m radius)
  - Automated Manual Transmission (AMT) — e.g. Volvo I-Shift
  - Synchronous AC Generator (1500 RPM output for 50 Hz grid)

- **Key Behaviors**:
  - Shaft inertia provides ~121 MJ (12.1 seconds at 10 MW)
  - Downshifts enabled by DC input current change
  - Sprag clutch disengages motor under overspeed or regen events
  - Braking engages above 3010 RPM to protect generator
  - Dual-clutch AMT allows seamless power flow during shifts

---

### AC Output
- **Terminals**: 3-wire 3-phase AC
- **Nominal Output**:
  - Voltage: Configurable (11kV, 33kV, or direct generator voltage)
  - Frequency: 50.00 Hz (synchronous)
  - Power: 1 MW to 100 MW depending on unit class
- **Protections**:
  - Sync check relay (phase, frequency, voltage match)
  - Over/undervoltage detection
  - Phase loss and imbalance protection
- **Connection Options**:
  - Direct substation busbar injection
  - Transformer coupling (if voltage mismatch exists)
  - HVDC converter AC sync anchor

---

## Control & Monitoring

### Embedded Monitoring
- Shaft RPM (optical encoder or Hall sensor)
- Generator current and voltage (true RMS)
- DC motor current draw
- Transmission gear state
- Overspeed flag and brake status

### Control Logic
- Gear shifting triggered by:
  - Rate of Change of Frequency (RoCoF)
  - Current draw thresholds
  - RPM deviation
- Emergency shutdown conditions:
  - Overspeed > 3010 RPM
  - Brake engagement failure
  - Voltage or frequency anomaly

### SCADA / DNO Interface
- Protocol: Modbus TCP / DNP3 / IEC 61850
- Reporting:
  - Real-time power (P, Q)
  - Unit availability and health
  - Frequency support status
- Remote Commands:
  - Online/offline control
  - Black start trigger
  - Gear hold/manual override

---

## Summary

The TSGB is a drop-in, self-contained, grid-support module with simple DC in and 3-phase AC out. Its fixed-speed shaft and mechanical transmission allow instant frequency response, torque delivery, and inertia injection. Minimal external infrastructure is required, with off-the-shelf protections and remote telemetry easily integrated via standard grid protocols.

This document serves as a baseline technical integration guide. Site-specific adaptations (e.g., voltage level, relay models, SCADA interface type) may be required based on DNO preferences.
