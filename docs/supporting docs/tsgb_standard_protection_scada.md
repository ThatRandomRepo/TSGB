# Using Standard Power Plant Protection and SCADA for TSGB

## Electrical Protections (Generator-Side)

TSGB units behave as **synchronous rotating machines**, so standard generator protections apply directly:

- **Over/Under Frequency**: Relay trips or isolates if grid frequency deviates more than ±2 Hz from nominal. Critical for RoCoF events.  
- **Over/Under Voltage**: Automatic Voltage Regulator (AVR) and relay trips if deviation exceeds ±10%.  
- **Overcurrent & Differential Protection**: Protects against stator winding faults, short circuits, or internal insulation failure.  
- **Reverse Power**: Trips if the generator is dragged into motoring state beyond safe tolerance.  
- **Loss of Excitation**: Standard relay logic detects and isolates to prevent instability.  
- **Out-of-Step / Pole Slip**: Trips the unit during severe grid faults or asynchronous swings.  
- **Islanding Detection**: Where possible, TSGB transitions into islanded operation instead of tripping — unless a local fault is detected.  

---

## Mechanical Protections (Shaft & Rotor)

TSGB relies on stored mechanical energy, so shaft and rotor protections are central:

- **Bearing Temperature Monitoring**: Trips when >75 °C. Multiple redundant sensors per bearing.  
- **Vibration Monitoring**: API 670–compliant vibration probes detect imbalance, misalignment, or shaft crack growth.  
- **Overspeed Protection**:  
  - Primary: DC drive decoupling via sprag clutch.  
  - Secondary: AMT downshift and dynamic braking resistors.  
  - Emergency: Mechanical brakes achieve full stop in <15s.  
- **Shaft Sectional Containment**: Shaft built in segments; containment vessel designed to arrest crack propagation or mass ejection in failure.  

---

## Thermal & Fire Protections

- **Lube Oil Pressure/Temperature**: Trips on low pressure or overheating.  
- **Enclosure Temperature/Humidity**: Prevents condensation, overheating, or arc flash risk.  
- **Fire Detection**: VESDA (Very Early Smoke Detection Apparatus) integrated.  
- **Suppression**: Enclosure sealed for inert gas flooding (CO₂ or N₂).  

---

## DC Input Side Protections

- **DC Overcurrent / Reverse Power**: Relay trips to protect MV drive and cabling.  
- **DC Bus Isolation**: High-speed disconnect on HVDC or DC-side fault.  
- **Converter Protection**: Surge arresters and crowbar circuits for overvoltage.  

---

## SCADA & Monitoring Layers

- **Basic Tier (~15 sensors)**: Shaft RPM, 2x bearing temps, stator current/voltage, rotor excitation current, enclosure temp, lube oil pressure/temp, vibration.  
- **Advanced Tier (30–50 sensors)**: Adds sectional torque sensors, gearbox mesh vibration, redundant temperature probes, enclosure pressure monitoring, partial discharge, and harmonic distortion.  
- **Fleet Management Overlay**: Remote trending, predictive analytics, and alarms. Cyber-isolated (read-only) to TSGB operation.  

---

## Protection Philosophy

- **Fail-Safe by Physics First**: Mechanical protections (sprag clutch, brakes, shaft flex) act first. Electrical trips next. SCADA alarms last.  
- **Standard Interfaces**: SEL, ABB, or Siemens generator protection relays can be used without modification.  
- **No Bespoke Firmware Required**: All trip logic works standalone via analog relays and AVR systems. SCADA is optional overlay, not authority.  

---

## Failure Modes & Effects (FMEA) Summary

| Fault Type                  | Detection Method                          | Trip / Action Taken                                   | Fail-Safe Behavior |
|-----------------------------|-------------------------------------------|------------------------------------------------------|--------------------|
| Bearing Overheat            | Temp sensors (>75 °C)                     | Generator trip, shaft brakes applied                  | Shaft spin-down, safe stop |
| Excessive Vibration / Crack | API 670 vibration probes                  | Alarm → Trip if sustained beyond limits               | Shaft contained, unit isolated |
| Overspeed                   | Shaft RPM sensors, sprag clutch           | DC decouple, AMT downshift, brake if > limit          | Shaft braked, AC isolated |
| Shaft Failure (catastrophic)| Sectional containment + vibration change  | Local trip, SCADA alarm                               | Contained, no mass ejection |
| Over/Under Frequency        | Protection relay                          | Generator trip or islanding sequence                  | Prevents desync, safe reclose |
| Over/Under Voltage          | AVR + relay                               | Generator trip                                        | Prevents insulation damage |
| Loss of Excitation          | Relay                                     | Generator trip                                        | Prevents pole slip |
| Reverse Power               | Relay                                     | Generator trip                                        | Stops drag motoring |
| DC Overcurrent              | DC relay                                  | DC drive isolate                                      | Protects MV drive |
| Lube Oil Failure            | Pressure/temp sensors                     | Generator trip                                        | Shaft coast-down |
| Fire / Smoke                | VESDA + gas detectors                     | CO₂/N₂ flood, trip all electrical                     | Fire suppressed |

---

## Protection Coordination Notes

- **Generator-Side Trips**: Coordinate with upstream grid breakers (e.g., 132 kV, 400 kV) to ensure selectivity — TSGB trips locally first to avoid unnecessary feeder trips.  
- **Mechanical Trips**: Shaft/brake trips are local only; SCADA alarm cascades to operators but upstream breakers remain unaffected unless AC fault is present.  
- **DC-Side Trips**: DC bus isolation devices coordinate with HVDC link protection to avoid backfeeding faults.  
- **SCADA Integration**: Alarms and trip signals are visible to central operators, but **decision logic remains local and analog**, ensuring trip occurs even if SCADA fails.  

---

## Bottom Line

The TSGB uses **proven, off-the-shelf protection systems**, enhanced with mechanical safeguards unique to its shaft-based inertia design.  
This ensures:  
- Grid compliance without reinvention.  
- Predictable and explainable trip logic.  
- Industry-standard maintainability.  
- Protection that defaults to physics, not firmware.  
