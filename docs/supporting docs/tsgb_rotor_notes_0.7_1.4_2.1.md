# TSGB Rotor Feasibility Notes @ 3000 rpm (50 Hz)

**Generated:** 2025-08-15 14:23 UTC

This note compares three solid cylindrical rotors — **0.7 m**, **1.4 m**, and **2.1 m** diameters — at 3000 rpm, each with a mass of **10,000 kg**.

---

## Summary Table

| Parameter | 0.7 m dia | 1.4 m dia | 2.1 m dia |
|---|---:|---:|---:|
| Radius (m) | 0.350 | 0.700 | 1.050 |
| Mass (kg) | 10000 | 10000 | 10000 |
| Tip speed (m/s) | 109.956 | 219.911 | 329.867 |
| Inertia J (kg·m²) | 612.500 | 2450.000 | 5512.500 |
| Stored energy (MJ) | 30.226 | 120.903 | 272.031 |
| 10 MW ride-through (s) | 3.023 | 12.090 | 27.203 |
| Peak hoop stress (MPa) | 38.900 | 155.602 | 350.104 |
| DN (million) | 2.100 | 4.200 | 6.300 |

---

## Interpretation

- **0.7 m:** Very safe stresses, modest inertia (~3 s at 10 MW). Scales easily with length/mass.
- **1.4 m:** Good balance of energy (~12 s at 10 MW) vs. manageable stress (~209 MPa).
- **2.1 m:** High energy (~27 s at 10 MW) but stresses approach low-alloy steel yield (~470 MPa). Needs high-grade materials or design tricks (bored/hooped rotors).

Tip speeds: 110 m/s (0.7 m) → 330 m/s (2.1 m). All are within heavy turbomachinery norms, but the higher end requires tighter rotor dynamics control and containment design.

---

## Bottom Line

- No fundamental hurdle to spinning even a 2.1 m dia rotor at 3000 rpm if designed correctly.
- Energy grows with diameter⁴, so containment, QA, and braking requirements ramp steeply beyond ~1.4 m.
