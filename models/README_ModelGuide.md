
# TSGB PowerFactory Model Guide

This model package includes the core files required to simulate the TSGB system as a torque-preloaded mechanical stabilizer in DIgSILENT PowerFactory. It models control behavior based on real-world torque dynamics using gearbox shifts and RoCoF detection.

---

## 📂 Files Included

- `gearbox_curve.csv` — Gear index, ratio, and torque offset table (1.8:1 to 2.0:1)
- `tsgb_control.dsl` — PowerFactory DSL control block handling RoCoF detection, gear shift logic, and torque output
- `tsgb_component_model.dsl` — Composite block to represent torque-controlled mechanical inertia delivery
- `README_ModelGuide.md` — This file

---

## ⚙️ Inputs and Parameters

| Input             | Description                                      |
|------------------|--------------------------------------------------|
| `gridFreqHz`     | Measured grid frequency                          |
| `gridRoCoFHzps`  | Measured Rate of Change of Frequency             |
| `driveRpm`       | Fixed input shaft RPM (typically 3000 rpm)       |

---

## 🔁 Control Logic Summary

- **Always preloaded** — torque is applied even at idle state
- **RoCoF triggers gear shift** — more RoCoF → more torque → lower gear
- **Hysteresis prevents hunting**
- **Max generator RPM is capped by gear ratio**

---

## 📤 Outputs

| Output              | Description                           |
|---------------------|---------------------------------------|
| `torqueCommandNm`   | Calculated torque value to generator  |
| `gearIndex`         | Active gear index (1-12)              |
| `genRpm`            | Resulting generator RPM               |

---

## 🧠 Notes for Engineers

- Gear 1 = max torque (1.8:1), Gear 12 = cruise (2.0:1)
- The generator cannot exceed safe RPM due to physical constraints
- You **must** use a user-defined generator model with correct excitation setup
- RoCoF detection threshold and dwell time are hardcoded for clarity — adapt as needed

---

## ✅ Integration Steps

1. Import `tsgb_component_model.dsl` into your project
2. Load `gearbox_curve.csv` as a lookup table
3. Attach `tsgb_control.dsl` to drive torque setpoint
4. Connect outputs to generator mechanical input
5. Use standard PowerFactory tools to run frequency event simulations

---

## ⚠️ Warning

This model simulates torque, not full electromechanical feedback. It's suitable for system-level stability simulations and concept validation.

---

Author: ScholarGPT x [Your Handle]
