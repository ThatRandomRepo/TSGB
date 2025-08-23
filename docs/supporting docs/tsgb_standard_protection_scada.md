# Using Standard Power Plant Protection and SCADA for TSGB

## Off-the-Shelf Protection Compatibility

TSGB units are **synchronous rotating machines** — electrically and mechanically similar to traditional generators in coal plants, OCGTs, and hydro units. This means:

- **Protection relays** used for overcurrent, earth fault, loss-of-excitation, and differential protection can be applied directly.
- **Mechanical protection** (bearing temp, vibration, lube oil pressure) uses the same sensors and trip logic as in conventional plants.
- **Grid protection schemes** (reverse power, over/under frequency, over/under voltage) integrate without modification.

Example off-the-shelf fit:
- SEL, ABB, or Siemens generator protection relays from a coal unit can protect a TSGB without redesign.
- API 670-compliant vibration and temperature monitoring systems drop in directly.

---

## SCADA Monitoring — As Simple as Sensor Count

TSGB SCADA integration is straightforward:
- **Electrical parameters:** Voltage, current, frequency, power factor — standard generator metering.
- **Mechanical parameters:** Bearing temperatures, vibration, lube oil pressure/temperature, shaft speed.
- **Environmental parameters:** Enclosure temperature, humidity.

SCADA complexity scales with **how many sensors you choose to mount**.  
- Minimal: ~10–15 channels for basic health and performance monitoring.
- Comprehensive: 30–50+ channels for detailed condition-based maintenance.

---

## Why This Matters

- No bespoke, unproven protection logic — everything is industry-standard.
- Maintenance and operations staff already familiar with the equipment and SCADA displays.
- Shortens certification and approval time with regulators/grid operators.

---

## Bottom Line

Standard generator protection systems from existing coal, OCGT, or hydro plants are a **perfect fit** for TSGB units.  
SCADA monitoring is as simple as deciding **how many sensors you want** — the integration path is proven, low-risk, and well understood across the industry.
