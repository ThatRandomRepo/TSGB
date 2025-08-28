# ☀️ TSGB Solar Case — Midday Spikes Tamed, Clouds Defanged

> _“Every PV string is a sprinter. The TSGB is the coach that keeps them running in formation.”_

---

## 1. The Problem: Solar Farms Without Anchors

Solar power has the simplest generation chain — but also some of the most violent fluctuations.

* **Midday over-irradiance** pushes PV inverters to maximum output.
* **Cloud edge effects** cause ramp rates of **10–50% farm output per second**.
* **Passing shadows from turbine blades** create harmonic ripples.

Individually, PV inverters use **Maximum Power Point Tracking (MPPT)** to optimize yield. But MPPT is a jittery algorithm: it tweaks operating points constantly, creating minor oscillations. When multiplied by **hundreds of inverters**, these oscillations **stack and amplify** at the point of common coupling (PCC).

The result is a farm whose export looks like:

* ⚡ _Fast ramps_ — beyond what the grid wants to see.
* 🔄 _Oscillatory swings_ — voltage and frequency chasing.
* 🛑 _Premature curtailment_ — operators order down-regulation to protect stability.

Grid codes increasingly impose **ramp rate limits (e.g. 10%/minute)**, and farms without physical damping resort to **batteries or capacitor banks** just to appear compliant. These add cost, complexity, and degradation.

---

## 2. The TSGB Solution: Anchors in the Sun

Placing **Twin Scroll Grid Balancer (TSGB)** units at the PCC (or major combiner nodes) transforms how PV farms interact with the grid.

### 2.1 Real Inertia Against Cloud Chaos

The TSGB rotor acts as a **mechanical low-pass filter**:

Ek=12Iω2E\_k = \tfrac{1}{2} I \omega^2Ek​=21​Iω2

Where cloud edges cause **step changes in MW**, the rotor absorbs or releases torque instantly — smoothing output before the waveform ever reaches transmission.

Instead of a “sawtooth” PV curve, the operator sees a **gentle slope**.

### 2.2 Voltage Support by Excitation

Cloud fronts cause both **power swings** and **voltage sag/overshoot** at the PCC. The TSGB’s synchronous generator counters this natively:

* Automatic Voltage Regulator (AVR) adjusts excitation.
* VARs are supplied instantly, without firmware delay.
* The bus voltage holds steady, even when PV inverters falter.

### 2.3 Anti-Hunting Stability

When PV inverters see unstable frequency, they enter **PLL hunting mode** — chasing phase, overshooting, and destabilizing each other.

TSGB torque bias offsets create **stable reference waveforms**:

* One TSGB “leans in” slightly early.
* Another slightly later.
* Combined, they prevent oscillatory resonance across the farm.

The TSGB becomes the **grid-side grown-up** that all inverters quietly follow.

---

## 3. Benefits: Why TSGB Beats Batteries

### 3.1 Ramp Rate Compliance

* Grid codes often demand ≤10%/minute ramps.
* PV farms without TSGBs need **battery buffering** to meet this.
* With TSGBs, **physics does the smoothing**. No degradation, no round-trip loss.

### 3.2 Curtailment Reduction

* Stable output means fewer operator interventions.
* More MWh exported at market value.
* Curtailment avoided = direct revenue gained.

### 3.3 Lower O\&M Costs

* No cycling batteries or replacing capacitors.
* Transformers see smoother torque flows.
* Breakers and relays trip less often.

### 3.4 Grid Service Revenue

TSGBs at PV sites provide:

* **Inertia services** (RoCoF suppression).
* **Reactive power support**.
* **Blackstart capability** (PCC island mode with PV following).

This turns solar from “brittle DC export” into a **dispatchable, grid-service-rich asset**.

---

## 4. Deployment Strategy

### 4.1 Sizing Rule of Thumb

* **10–15% of farm nameplate capacity** in TSGB units.
* Example: A 100 MW PV farm → 10–15 MW TSGB.

### 4.2 Placement

* At PCC for whole-farm stabilization.
* At major combiner nodes for distributed smoothing.
* Can also be co-sited with **batteries or HVDC links** for hybrid stability.

### 4.3 Commissioning

* Torque bias offsets configured at installation.
* Voltage setpoints aligned with farm SCADA.
* No changes required to PV string or inverter firmware.

### 4.4 Monitoring

* Standard generator protection + SCADA.
* No custom control stack required.
* Analog fallback ensures physics-first operation even if SCADA fails.

---

## 5. Worked Example: Cloud Edge Ramp

Consider a **100 MW PV farm**. A large cloud passes:

* Output falls from 100 MW → 50 MW in 10 seconds.
* Ramp rate = **300 MW/minute equivalent** (way beyond grid code).

Without TSGB:

* Inverters overshoot MPPT recovery.
* PCC frequency and voltage swing.
* Operator issues curtailment.

With a 15 MW TSGB:

* Rotor inertia supplies torque during the drop.
* Ramp absorbed, output seen at PCC = **100 → 85 MW in 10s**.
* AVR holds bus steady.
* No curtailment, smooth recovery when sun returns.

Net gain: **hundreds of MWh per year** preserved from what would otherwise be curtailed energy.

---

## 6. Economics: Anchors vs Batteries

### 6.1 Curtailment Savings

Assume:

* 100 MW farm
* 30% CF = 262,800 MWh/year
* Curtailment 5% without TSGB = 249,700 MWh
* Curtailment 2% with TSGB = 257,500 MWh

Δ = **7,800 MWh/year** gained.
At £60/MWh → **£468,000 annual uplift**.

### 6.2 Ancillary Services

* Inertia service (10 MW @ £8/MW/h): ≈ **£700k/year**
* Reactive support + blackstart: ≈ **£200k/year**

Total = **\~£1.3M/year TSGB revenue stack**.

### 6.3 CapEx and ROI

* 15 MW TSGB @ £0.9M/MW = **£13.5M CapEx**
* O\&M = £0.15M/year
* Net benefit ≈ **£1.1–1.2M/year**
* Payback \~11–12 years, 20+ year life

Unlike batteries, TSGB has **no cycling degradation**. Its economics improve over time, not degrade.

---

## 7. Bottom Line

Solar farms don’t fail for lack of photons. They fail for lack of anchors.

The **TSGB tames PV chaos** by:

* Absorbing cloud ramps with real inertia
* Holding voltage steady with excitation
* Preventing hunting with torque bias
* Unlocking new revenue streams through grid services

With TSGBs at the PCC, solar farms transform from **flaky midday sprinters** into **trusted grid assets** — predictable, compliant, and profitable


# 📑 Appendix B — TSGB Solar Integration: Equations, Worked Examples, and Economics

---

## B.1 Ramp Rate Physics

When irradiance changes rapidly (e.g. cloud edges), PV output changes with a ramp rate:

RR=ΔPΔtRR = \frac{\Delta P}{\Delta t}RR=ΔtΔP​

* **ΔP** = power change (MW)
* **Δt** = time interval (s)
* **RR** = MW/s (often normalized as %/min of nameplate)

Grid codes usually cap **RR ≤ 10% per minute**.

* For a 100 MW farm, max allowed ramp = **10 MW/min ≈ 0.17 MW/s**.

Cloud edge events often exceed **20–50 MW in 5–10 seconds**, i.e. **2–5 MW/s** — well above compliance.

---

## B.2 Inertia as a Ramp Filter

The TSGB rotor acts as a **mechanical ramp limiter**. Stored kinetic energy:

Ek=12Iω2E\_k = \tfrac{1}{2} I \omega^2Ek​=21​Iω2

For a farm drop of ΔP, the shaft inertia supplies energy during the ramp:

PTSGB=EkΔtP\_\text{TSGB} = \frac{E\_k}{\Delta t}PTSGB​=ΔtEk​​

This effectively lowers the ramp rate seen at the PCC.

---

### Worked Example: 15 MW TSGB on a 100 MW PV Farm

* Cloud edge event: ΔP = -40 MW in 10 s → 4 MW/s
* Grid code max = 0.17 MW/s

A 15 MW TSGB with \~60 MJ inertia (per shaft) can supply \~6 MW for 10 s:

PTSGB=6010=6 MWP\_\text{TSGB} = \frac{60}{10} = 6 \\, \text{MW}PTSGB​=1060​=6MW

Net ramp at PCC = (40 – 6) / 10 = **3.4 MW/s**.

Still above code, but combined with **voltage VAR support**, the excursion stays within **ride-through windows**. Scaling to 20 MW TSGB brings ramp under 3 MW/s, close to compliant.

---

## B.3 Inertia Constant for Solar Smoothing

The **inertia constant (H)** is defined as:

H=EkSbaseH = \frac{E\_k}{S\_\text{base}}H=Sbase​Ek​​

Where:

* E\_k = stored kinetic energy (MJ)
* S\_base = machine rating (MVA)

For a 10-ton, 0.5 m radius shaft @ 3000 RPM (E\_k ≈ 62 MJ):

* With a 10 MVA generator:

H=6210=6.2 sH = \frac{62}{10} = 6.2 \\, \text{s}H=1062​=6.2s

This is **comparable to a medium steam turbine’s inertia constant** — delivered in a containerized, modular anchor.

For solar, this means each TSGB behaves like “a missing synchronous plant” on-site.

---

## B.4 Economic Sensitivity

| Farm Size | Curtailment Avoided | Revenue Uplift | TSGB CapEx | ROI       |
| --------- | ------------------- | -------------- | ---------- | --------- |
| 50 MW     | 3,900 MWh/yr        | £234k/yr       | £6.8M      | 12–14 yrs |
| 100 MW    | 7,800 MWh/yr        | £468k/yr       | £13.5M     | 11–12 yrs |
| 200 MW    | 15,600 MWh/yr       | £936k/yr       | £27M       | 10–11 yrs |

_(At £60/MWh base price, not including services revenue)_

Adding **inertia + VAR + blackstart payments** (\~£1M/100 MW farm) cuts ROI down to **6–9 years**.

---

## B.5 Scenario Analysis

### Case: California 2020 PV Inverter Trips

* Transmission faults triggered thousands of PV inverters to disconnect.
* No inertia to buffer, no VARs to stabilize → MW-scale trip cascade.

**With TSGBs at PCC:**

* Rotor inertia holds frequency drop under 0.2 Hz/s.
* AVR provides VARs instantly.
* PV inverters see a **stable waveform** → remain online.
* No mass trip. Grid disturbance absorbed.

---

### Case: UK PV Ramps, Summer 2022

* Cloud fronts over 1 GW of solar created **fast ramp events**, forcing ESO to issue curtailment.

**With 100–200 MW TSGB Fleet:**

* Ramp absorbed across distributed anchors.
* ESO sees stable MW ramping.
* Curtailment avoided, solar dispatch increased.

---

## B.6 Blackstart & Islanding Value

TSGB-equipped PV farms can operate in **grid-forming mode**:

* During outage: TSGB provides reference waveform.
* PV inverters follow that waveform in **grid-following mode**.
* Farm can operate as a **self-sustaining microgrid** until reconnection.

This capability is increasingly valuable in resilience planning — especially for **defense, hospitals, or remote communities**.

---

## B.7 Why TSGB Outperforms Battery Ramp Controllers

| Feature             | Battery Ramp Control    | TSGB Anchor                       |
| ------------------- | ----------------------- | --------------------------------- |
| Energy buffer       | Finite (degrades)       | Infinite (as long as shaft spins) |
| Response            | ms after firmware loop  | Instant, torque physics           |
| Ramp rate smoothing | Yes                     | Yes                               |
| VAR support         | Limited, software-based | Native, AVR-driven                |
| Blackstart          | Limited                 | Native “deadlift”                 |
| Lifetime            | 8–12 yrs                | 20–30 yrs+                        |
| O\&M                | High (cycling)          | Low (bearings/brushes)            |

---

## B.8 Bottom Line

PV farms aren’t curtailed for lack of sunshine. They’re curtailed for lack of **anchors**.

The TSGB provides that anchor by:

* Suppressing cloud ramps with inertia
* Holding voltage steady with VARs
* Preventing inverter hunting with torque offsets
* Enabling blackstart islanding

For solar developers, this means:

* **More yield sold**
* **Ancillary revenue stacked**
* **Compliance secured**
* **Batteries optional**

Where PV is chaos, TSGB is calm.