
# TSGB Smooth Lean-In Simulator (Python)

This simulator demonstrates the closed-loop control behavior of a Torque Shift Gearbox (TSGB) responding to a sinusoidal RoCoF event over 6 seconds.  
It visualizes the elegant, smooth transition between gears, showcasing the preloaded "lean-in" principle for real-time power injection.

---

## 📂 Files Included

- `tsgb_live_smooth_sim.csv` — Time series output of:
  - Grid Frequency & RoCoF
  - Gear Index
  - Shaft Input RPM
  - Generator Output RPM
  - Torque and Injected Power
- `tsgb_live_smooth_plot.py` — Python script that generates three visual plots

---

## ▶️ How to Use

1. Ensure Python 3 is installed.
2. Install required libraries:

```bash
pip install pandas matplotlib
```

3. Run the plot script:

```bash
python tsgb_live_smooth_plot.py
```

---

## 📈 What It Shows

- **Grid Frequency and RoCoF** fluctuation over time
- **Dynamic gear shifting** based on live RoCoF (rate of change of frequency)
- **Generator RPM vs Target RPM** at each time step
- **Injected Power** into the grid (calculated from torque × angular velocity)

---

## 🌟 Key Takeaway

This sim illustrates how TSGB isn't simply reactive — it’s preloaded and proactive.

Rather than shocking the system with step responses, it *leans into the signal*, maintains phase, and injects controlled, meaningful inertia.  
The gear shifts serve as **fluid torque modulation**, not brute-force dampers.

---

## 🔧 Expand It

- Replace sine wave input with real-world frequency data
- Adjust control logic thresholds
- Add visual indicators for gear transitions or hunting scenarios

---
