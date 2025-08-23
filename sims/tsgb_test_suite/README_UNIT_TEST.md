
# TSGB Unit Test + CSV Logger (C++)

This is a test harness to validate the TSGB control logic and record simulation results.

---

## 📂 Files

- `tsgb_test.cpp`: Simulation + unit tests + CSV logging
- `tsgb_unit_test_output.csv`: Output log (generated after run)

---

## ▶️ How to Compile and Run

```bash
g++ tsgb_test.cpp -o tsgb_test
./tsgb_test
```

---

## 🧪 What It Does

- Simulates a 10-second frequency profile with a drop from 50 → 48 Hz
- Calculates RoCoF and gear shifts at 100 Hz
- Asserts gear index is within range (1–12)
- Logs:
  - Time
  - Frequency
  - RoCoF
  - Gear index
  - Torque output
  - Generator RPM

---

## 📈 Output

Results are written to `tsgb_unit_test_output.csv` for further analysis in Excel, Python, or MATLAB.

Use this file to validate TSGB responses against spec or expected behavior.

---
