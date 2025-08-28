
# TSGB Interactive Python Simulator

This Python script simulates the behavior of a Torque Shift Gearbox (TSGB) under changing grid conditions. It tracks how the TSGB logic reacts to frequency drops using RoCoF to control gear selection and torque delivery.

---

## 📂 Files

- `tsgb_rocof_sim.csv` — Simulated data for frequency, RoCoF, gear, torque, and generator RPM
- `tsgb_rocof_sim.py` — Python script to visualize the simulation results

---

## ▶️ How to Run

1. Make sure you have Python 3 installed.
2. Install required packages:
```bash
pip install matplotlib pandas numpy
```
3. Run the script:
```bash
python tsgb_rocof_sim.py
```

---

## 🧪 Simulation Overview

- Starts at 50Hz, drops to 48Hz over 2 seconds
- TSGB responds to RoCoF (Rate of Change of Frequency)
- Outputs include:
  - Frequency and RoCoF
  - Gear shifts (1–12)
  - Torque delivery
  - Generator RPM

---

## 📈 Visual Output

The script displays four plots:
1. Grid Frequency
2. RoCoF
3. Gear Index (step function)
4. Torque Output (Nm)

This gives a full-picture view of how the TSGB logic operates in real time.

---
