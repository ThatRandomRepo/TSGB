# Estimating Inertia Requirements for a 100% Renewable Grid
_Generated: 2025-08-15 15:52 UTC_
## Quick Method
1. **Largest Credible Contingency (LCC):** Find the biggest single loss (MW) the grid must ride through.
2. **RoCoF Limit:** Choose the maximum allowable Rate of Change of Frequency (Hz/s).
3. **Compute required inertia energy (MW·s):**
\n\\[ E_k = \\frac{P_{loss} \\cdot f_0}{2 \\cdot \\text{RoCoF}_{max}} \\]\n- Where:  \(E_k\) is total inertia in **MW·s**, \(P_{loss}\) in MW, \(f_0\) in Hz (50), and RoCoF in Hz/s.

---
## Worked Example — Losing a 1.2 GW HVDC Link
- \(P_{loss} = 1200\,\text{MW}\), \(f_0 = 50\,\text{Hz}\)
- Case A: RoCoF limit = **0.25 Hz/s**  
  - Required inertia: **120,000 MW·s** (≈ **120.0 GW·s**)
- Case B: RoCoF limit = **0.125 Hz/s**  
  - Required inertia: **240,000 MW·s** (≈ **240.0 GW·s**)

> Interpretation: Halving the RoCoF limit **doubles** the required inertia. These values set the _floor_ for instantaneous stabilisation, regardless of later primary/secondary response.

---
## Quick-Look Table (Different LCC & RoCoF)
| LCC (MW) | RoCoF (Hz/s) | Required Inertia (GW·s) |
|---:|---:|---:|
| 1200 | 0.250 | 120.0 |
| 1200 | 0.125 | 240.0 |
| 1800 | 0.250 | 180.0 |
| 1800 | 0.125 | 360.0 |

---
## Converting Inertia Target to TSGB Fleet Size
Per-module inertia (examples, 3000 rpm):
| Module | Inertia (MW·s) |
|---|---:|
| 10 t, 0.7 m dia | 30 |
| 10 t, 1.4 m dia | 120 |
| 10 t, 2.1 m dia | 270 |

**Example sizing for the 1.2 GW loss @ 0.25 Hz/s (target ≈ 120 GW·s):**
- 10 t, 0.7 m dia: **4000 units** (each ≈ 30 MW·s)
- 10 t, 1.4 m dia: **1000 units** (each ≈ 120 MW·s)
- 10 t, 2.1 m dia: **445 units** (each ≈ 270 MW·s)

**If targeting 0.125 Hz/s (≈ 240 GW·s):**
- 10 t, 0.7 m dia: **8000 units**
- 10 t, 1.4 m dia: **2000 units**
- 10 t, 2.1 m dia: **889 units**

> Notes:
- You rarely need to meet the entire inertia target with inertia alone; TSGBs also provide **instant active power** from their DC drive, reducing the pure MW·s requirement.
- Allocate inertia **geographically** near risk and load centres to control _local_ RoCoF and avoid protection trips.
- Add margin for high-demand periods and multiple-contingency stress.

---
## Checklist for 100% Renewables Inertia Planning
- [ ] Identify LCCs by region and season.
- [ ] Set RoCoF limits: operational and protection thresholds.
- [ ] Compute MW·s targets per region (formula above).
- [ ] Select TSGB module mix (energy per module vs. footprint).
- [ ] Place modules at PCCs/HVDC ties to anchor inverters and strengthen weak nodes.
- [ ] Validate with dynamic studies (PSS/E, PowerFactory, OpenDSS).
