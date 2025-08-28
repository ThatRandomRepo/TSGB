# TSGB Wind Case — Anchoring, Smoothing, and Curtailment Prevention

Let’s cut through the noise: modern wind farms are inverter farms with a branding problem. Every nacelle is its own little power electronics island, twitching and hunting with the wind. The TSGB doesn’t replace that — it *anchors* it.

---

## 1. The Problem

Wind is chaotic. Turbines see gusts, shear, turbulence — and their inverters react as fast as firmware allows. Multiply that by dozens or hundreds of units, and the substation bus starts looking like a cardiogram. Grid operators hate it, transformers hate it, and tap changers *really* hate it.

Result: you get curtailment orders to protect upstream infrastructure, even when there’s good wind.

---

## 2. The TSGB Solution

Drop a TSGB (or a few) at the point of common coupling (PCC):
- **Inertia:** The TSGB’s rotating mass rides through gust-induced frequency spikes, damping the output profile before it hits the transmission network.
- **Reactive power:** As a synchronous machine, it can hold voltage without a separate STATCOM.
- **Torque offsets:** Multiple TSGBs with staggered lean-in settings avoid hunting and spread response over time.

---

## 3. Benefits

- **Curtailment reduction:** Smooth, compliant output keeps the operator happy.
- **Transformer life:** Lower stress on windings and tap changers from smoothed torque flow.
- **Grid code compliance:** Ride-through, voltage support, frequency stability — baked in by physics.

---

## 4. Deployment Strategy

- 1–3 TSGB units at the PCC sized for a fraction of farm capacity (e.g., 10–20%).
- Offsets assigned at commissioning for anti-hunting.
- Integration via standard generator protection and SCADA.

---

## Bottom Line

The TSGB turns a jittery wind farm into a predictable, stable generator in the eyes of the grid. No turbine modifications, no firmware wars — just a wall of steel at the gate keeping the output clean.
