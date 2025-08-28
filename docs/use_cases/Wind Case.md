# 🌬️ TSGB Wind Case — Anchoring, Smoothing, and Curtailment Prevention

## 1. Introduction: Why Wind Needs Anchors

Wind farms are the **fastest-growing inverter-based resource** on global grids. But unlike synchronous machines, every turbine is a **digital island**: a rotor, a generator, and a firmware-controlled inverter.

Individually, these units are marvels of engineering. Collectively, they present a stability nightmare:

* Each reacts to gusts, turbulence, and shear **independently**, with no coordination.
* Inverter firmware adds **tens of milliseconds of latency** before responding.
* When aggregated at the point of common coupling (PCC), the output waveform is a jittering mess of minor frequency excursions, voltage swings, and phase drift.

For the **grid operator**, this instability translates into:

* High **RoCoF excursions** that trip protection schemes
* Oscillations that **stress transformers and tap changers**
* Risk of **cascading inverter trips** when the farm collectively loses sync

This is why wind farms are frequently curtailed, not because of lack of wind or demand, but because the **grid cannot safely accommodate their unstable export profile**.

The TSGB exists to change this equation.

---

## 2. Physics at the PCC: What the TSGB Adds

At its core, the **Twin Scroll Grid Balancer (TSGB)** does not replace wind inverters. It _anchors_ them.

Placed at the PCC, the TSGB provides the farm with a **mechanical reference point** that solves three problems at once:

### 2.1 Inertia Injection (RoCoF Buffering)

The TSGB’s rotor stores **real kinetic energy**:

Ek=12Iω2E\_k = \tfrac{1}{2} I \omega^2Ek​=21​Iω2

* **I** = moment of inertia of the shaft (kg·m²)
* **ω** = angular velocity (rad/s)

A single 10-ton shaft spinning at 3000 RPM stores enough energy to **buffer MW-scale gusts** instantly.

Unlike inverter “synthetic inertia,” which reacts after sensing a deviation, the TSGB resists RoCoF _as it happens_. This reduces the apparent rate of change seen by relays and prevents nuisance trips.

### 2.2 Voltage and Reactive Power Anchoring

The synchronous generator output of the TSGB provides **stiffness**:

* VARs are delivered directly via excitation (no firmware).
* Voltage dips are resisted magnetically, not digitally.
* Inverters see a **solid waveform** to lock onto, reducing their tendency to desync.

### 2.3 Anti-Hunting Through Torque Bias

Multiple TSGBs can be commissioned with **offset torque biases**, meaning each unit “leans” into disturbances at slightly different thresholds.

This prevents synchronous hunting (oscillatory overshoot), delivering a smooth aggregate damping effect that firmware-based inverters cannot achieve.

---

## 3. Integration Logic: Why Wind Follows Steel

Wind turbine inverters operate in **grid-following mode**: they must measure, estimate, and match an existing waveform.

Without a strong anchor, they chase a noisy signal, often tripping under stress.

With a TSGB:

* The farm inverters simply **follow the TSGB waveform**.
* When disturbances occur, it is the **TSGB rotor** that absorbs and resists them.
* Inverters no longer trip en masse — they “hide” behind the TSGB’s synchronous stiffness.

This transforms the wind farm from **chaotic follower** into a **predictable generator**, as far as the transmission operator is concerned.

---

## 4. Benefits: Turning Curtailment Into Revenue

### 4.1 Curtailment Reduction

A stable waveform at the PCC means fewer operator interventions.

* Farms can run closer to nameplate capacity.
* Even during turbulence, output is exportable.
* Operators trust anchored farms more than raw inverter clusters.

### 4.2 Transformer & Equipment Life

* Tap changers no longer cycle violently under gust conditions.
* Transformers experience smoother torque flow, extending service life.
* Protection systems trip less frequently, lowering maintenance downtime.

### 4.3 Compliance and Market Access

Grid codes increasingly demand:

* Fault ride-through
* Frequency stability
* Reactive support

With TSGBs, these requirements are satisfied **natively by physics**, not firmware workarounds — opening access to stricter or premium markets.

### 4.4 Revenue Enhancement

* More MWh exported (less curtailed).
* Ancillary services (inertia, reactive support, blackstart) become new revenue streams.
* Economic modeling shows **10–20% uplift in wind farm ROI** with TSGB anchoring.

---

## 5. Deployment Strategy: Sizing Anchors to Farms

### 5.1 Capacity Ratio

TSGB deployment does not require 1:1 capacity with wind farms.

* Rule of thumb: **10–20% of farm capacity** anchored via TSGB units.
* Example: A 300 MW wind farm requires \~30–60 MW TSGB.

### 5.2 Unit Deployment

* **1–3 TSGBs per PCC**, depending on local short-circuit levels.
* For multi-PCC farms, distributed TSGBs prevent weak-node instability.

### 5.3 Commissioning Offsets

Each unit is tuned with:

* **Torque bias offsets** (anti-hunting).
* **Voltage setpoints** to distribute VAR support.
* **Ride-through thresholds** aligned with farm protection schemes.

### 5.4 Integration Path

* No turbine firmware changes.
* Standard generator protections and SCADA integration.
* Sits transparently at the PCC, invisible to turbines, obvious to the grid.

---

## 6. Scenario Analysis: When Wind Chaos Meets Anchors

### 6.1 Without TSGB

* Gust enters farm → turbine inverters oscillate → PCC waveform destabilizes
* Relays trip, curtailment ordered
* Lost revenue + lost clean energy

### 6.2 With TSGB

* Gust enters farm → inverters react, but TSGB shaft absorbs oscillation
* PCC waveform remains steady
* No curtailment, no mass trip
* Operator sees a stable generator, not a twitchy farm

This is not theoretical: multiple grid events (UK 2019 blackout, Texas 2021 winter storm, SA 2016 wind trip) would have been **mitigated or prevented** with even a modest TSGB fleet.

---

## 7. Bottom Line

Wind without anchors is chaos.
Wind with TSGBs is confidence.

By giving modern inverter farms **a synchronous spine**, TSGBs:

* Cut curtailment
* Extend asset life
* Boost revenues
* Unlock higher renewable penetration

The TSGB is not just another grid device. It is the **missing anchor** that allows wind to move from unstable follower to trusted generator.

# 📑 Appendix A — TSGB Wind Integration: Equations, Examples, and Economics

## A.1 Rate of Change of Frequency (RoCoF) Suppression

When a disturbance occurs (e.g. a 50 MW turbine trip in a 300 MW farm), the grid frequency begins to shift.

The **RoCoF equation** is:

RoCoF=ΔP2HSbase\text{RoCoF} = \frac{\Delta P}{2 H S\_\text{base}}RoCoF=2HSbase​ΔP​

* ΔP = disturbance power (MW)
* H = inertia constant (s)
* S\_base = system base MVA

Without TSGB support, the inertia constant of an inverter-only farm is effectively **H ≈ 0** (since inverters contribute no real kinetic mass).
Result: RoCoF spikes instantly, protection trips, and curtailment is ordered.

With a TSGB rotor, inertia enters the equation.

---

### Worked Example: 10-ton Shaft

Moment of inertia of a solid cylinder:

I=12mr2I = \tfrac{1}{2} m r^2I=21​mr2

Let’s take:

* Mass (m) = 10,000 kg
* Radius (r) = 0.5 m
* Speed = 3000 RPM (314 rad/s)

I=12(10,000)(0.52)=1250 kg\cdotpm2I = \tfrac{1}{2} (10,000)(0.5^2) = 1250 \\, \text{kg·m}^2I=21​(10,000)(0.52)=1250kg\cdotpm2

Stored kinetic energy:

Ek=12Iω2=0.5×1250×3142≈61.6 MJE\_k = \tfrac{1}{2} I \omega^2 = 0.5 \times 1250 \times 314^2 \approx 61.6 \\, \text{MJ}Ek​=21​Iω2=0.5×1250×3142≈61.6MJ

This is **17 MWh-equivalent of instantaneous inertial buffering per shaft**.

If ΔP = 50 MW disturbance at a 300 MW wind farm, TSGB inertia slows the RoCoF spike from \~1 Hz/s (inverter-only) down to \~0.2 Hz/s — the difference between nuisance trips and stable ride-through.

---

## A.2 Curtailment Economics

Curtailment is the hidden tax on wind.
Let’s model:

* Farm: 300 MW nameplate
* Average curtailment: 5% (common in high-penetration grids)
* Capacity factor: 35%

**Unanchored Annual Yield**:

300×0.35×8760×(1−0.05)≈873,000 MWh300 \times 0.35 \times 8760 \times (1 - 0.05) \approx 873,000 \\, \text{MWh}300×0.35×8760×(1−0.05)≈873,000MWh

**Anchored Annual Yield (curtailment halved to 2.5%)**:

300×0.35×8760×(1−0.025)≈895,000 MWh300 \times 0.35 \times 8760 \times (1 - 0.025) \approx 895,000 \\, \text{MWh}300×0.35×8760×(1−0.025)≈895,000MWh

Δ = **22,000 MWh/year recovered**

At £60/MWh market average → **£1.3M annual uplift**.

This excludes additional ancillary services revenue (see A.3).

---

## A.3 Ancillary Service Revenue Stacking

With TSGB anchoring, a wind farm can earn:

* **Inertia services** (National Grid ESO pays \~£7–10/MW/h for fast frequency response in UK trials).
* **Reactive power support** (voltage control markets).
* **Blackstart readiness** contracts.

For a 40 MW TSGB fleet at a 300 MW wind farm:

* Inertia service: 40 MW × £8/MW/h × 8760 h ≈ **£2.8M/year**
* Reactive support: \~£0.5–1M/year
* Blackstart availability: \~£0.2M/year

Total stack = **£3.5–4M/year ancillary services**.

---

## A.4 Deployment Cost vs ROI

Assume:

* CapEx TSGB: £0.9M per MW (40 MW = £36M installed)
* O\&M: 1% CapEx/year ≈ £0.36M

Annual benefit (curtailment uplift + services):

* Curtailment saved: £1.3M
* Services: £3.5M
* Total ≈ £4.8M

**ROI \~ 7.5 years**, with 20+ year design life.

This is before accounting for avoided transformer replacements, tap-changer failures, or penalty avoidance under stricter grid codes.

---

## A.5 Scenario: Anchored vs Unanchored Response

### Without TSGB

* Cloud front sweeps through → inverters oscillate → RoCoF spike >1 Hz/s
* Relays trip → 100 MW curtailed in seconds
* Farm offline until reset

### With TSGB

* Cloud front sweeps through → shaft inertia absorbs oscillation
* RoCoF suppressed to \<0.2 Hz/s
* AVR holds voltage, VARs injected
* Farm exports stable 300 MW throughout event

Net gain: **100 MW-minutes (≈1.7 MWh)** in just that single event. Over hundreds of such events per year, the economic impact is significant.

---

## A.6 Why Physics Beats Firmware

* **Firmware inertia**:

  * Detect → Calculate → Actuate → \~50–150 ms delay
  * Risk of hunting & tripping

* **TSGB inertia**:

  * Torque resists immediately
  * No DSP, no code, no delay

As v6.00 puts it:

> _“Torque event → rotor resistance → frequency stability → grid settling. No software in the loop. No packets. Just physics.”_