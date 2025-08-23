# TSGB QuickFacts — Q&A Summary

A consolidated quick-reference answering common technical, operational, and integration questions about the TwinScroll Grid Balancer (TSGB).

---

## 1. **What is the TSGB?**
A mechanically self-limiting, synchronous generator with a fixed-speed DC input and integrated flywheel mass, designed to provide real inertia and grid stability without inverters.

---

## 2. **Why doesn’t it need complex software for frequency control?**
- The grid and rotor are mechanically locked; physics ensures proportional, instantaneous response.
- Fixed gear ratio + fixed-speed DC drive prevents over-frequency push.
- Inertia output is self-metering — proportional to the rate of change in frequency (RoCoF).

---

## 3. **How is hunting avoided in a distributed fleet?**
- Use **torque bias offsets** — e.g., ±4%, ±2%, 0% — to stagger lean-in levels across the fleet.
- The AC frequency remains the anchor for all units, so they self-balance without synchronous oscillation.

---

## 4. **How is overspeed prevented?**
- Mechanical limits: shaft speed capped at synchronous speed (3000 rpm for 50 Hz grid).
- Maximum gear ratio (2:1) limits torque transfer; can’t exceed safe electrical output frequency.
- In a fault, simply disconnect the DC drive — rotor coasts down gracefully.

---

## 5. **Why is bearing temperature the key health indicator?**
- Friction and wear directly increase bearing temperature at any load.
- Safe ranges are easy to define at commissioning.
- Over-temperature triggers a simple, graceful shutdown via DC drive disconnect.

---

## 6. **What are the safe operating temperature ranges?**
Example (oil-lubricated journal bearing):
- Baseline: 55–65°C
- Alarm: 75–80°C
- Trip: 85–90°C

---

## 7. **What protection systems are used?**
- Standard generator protection relays (overcurrent, earth fault, differential, loss-of-excitation).
- Mechanical protection (bearing temp, vibration, oil pressure) — same as coal/OCGT/hydro plants.
- No bespoke, unproven logic required.

---

## 8. **How is SCADA monitoring handled?**
- As simple as **how many sensors you mount** — electrical, mechanical, and environmental channels.
- Minimal: ~10–15 signals. Comprehensive: 30–50+ signals.
- Industry-standard integration; no novel protocols.

---

## 9. **Is the rotor design feasible at 3000 rpm?**
Yes. Examples for a 10 t solid rotor:
- **0.7 m dia:** ~30 MW·s (~3 s @ 10 MW), hoop stress ~52 MPa.
- **1.4 m dia:** ~120 MW·s (~12 s @ 10 MW), hoop stress ~209 MPa.
- **2.1 m dia:** ~270 MW·s (~27 s @ 10 MW), hoop stress ~470 MPa (requires high-grade material or structural optimisation).

---

## 10. **Can it integrate directly with DC renewables or HVDC?**
Yes. The TSGB can be driven directly from wind/solar/HVDC DC buses:
- DC drive motor spins the shaft at synchronous speed.
- Synchronous generator outputs AC directly to the grid.
- Eliminates inverter latency and complexity.

---

## 11. **Why is it safe by design?**
- Physical constraints (speed, gear ratio) prevent over-frequency events.
- No runaway possible — worst case is passive spin-down.
- Inertia and torque contribution are determined by physics, not software assumptions.

---

## 12. **Bottom line?**
The TSGB uses **established rotating machinery technology** in a novel configuration to provide inertia and stability without the risks of power electronics.  
Mechanical simplicity, off-the-shelf protection, and proven monitoring make it low-risk to deploy at scale.
