# Temperature as a Proxy for Bearing Health in TSGB Systems

## Why Temperature Works as a Health Indicator

In rotating machinery such as the TSGB, **bearing temperature** is one of the most reliable, load-independent indicators of health. This is because:

1. **Friction → Heat**
   - All bearing losses manifest as heat: rolling element contact, cage friction, lubricant shear, and seal drag.
   - As wear, contamination, or misalignment increases, friction rises — so temperature rises.

2. **Load Independence**
   - A properly lubricated and aligned bearing has a predictable thermal profile at any load.
   - Deviations from this profile (especially sustained increases) are early warnings of degradation, regardless of whether the machine is idling or fully loaded.

3. **Lubricant Health Link**
   - Bearing temperature directly affects lubricant viscosity and film thickness.
   - Overheating reduces film thickness, accelerating wear — a feedback loop that temperature monitoring can catch early.

---

## Defining Safe Operating Ranges

- **Baseline:** Measure normal operating temperature range for each bearing type and installation during commissioning.
- **Alarm Level:** Typically +10–15°C above baseline.
- **Trip Level:** Typically +20–25°C above baseline (adjusted for bearing class and lubricant spec).

Example for an oil-lubricated hydrodynamic journal bearing:
- Baseline: 55–65°C
- Alarm: 75–80°C
- Trip: 85–90°C

---

## Achieving Safe Shutdowns

The TSGB design allows graceful disconnection simply by **disconnecting the DC drive**:

1. **Trip signal** from temperature monitoring system.
2. **DC drive de-energises**, removing torque input.
3. Rotor remains synchronised and coasts down, still pushing gently into the grid.
4. Optional: mechanical brake or sprag engages when rotor falls below a defined speed for stop/lock.

This ensures:
- No abrupt torsional shock to the drivetrain.
- No risk of overspeed.
- Complete shutdown without destabilising the grid.

---

## Bottom Line

- Bearing temperature is a **universal, reliable, and load-independent** proxy for bearing health.
- Safe operating ranges are straightforward to define at commissioning.
- The TSGB’s mechanical simplicity makes **graceful, automatic shutdown** trivial to implement in response to high temperatures.
