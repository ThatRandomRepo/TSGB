
# TSGB Emergency Operations Manual (Expanded Edition)

## Overview

This manual outlines the use of the TwinScroll Grid Balancer (TSGB) fleet as a dedicated emergency response system for total or partial UK grid collapse scenarios. The TSGB platform enables autonomous spin-up, AC grid island formation, HVDC synchronization, and staged restoration of power using a safe-by-design approach. This operational doctrine is referred to as **Deadlift Mode**.

---

## Operating Philosophy: Deadlift the Grid

### Step 1 – Spin First

- **DC Priming Sources**: Each TSGB unit is energized from distributed renewables, local batteries, or diesel-inverter hybrids.
- **Shaft Synchronization**: The DC motor ramps to 3000 RPM over a controlled time frame (typically <5 seconds).
- **Inertia Charging**: Shaft-mounted flywheel spins up, storing up to 121 MJ of kinetic energy.
- **Load Isolation**: Generator is decoupled during spin-up to avoid transient disturbance.

### Step 2 – Form AC

- **Generator Engagement**: Once RPM is stable, the generator is coupled through a clutch system or permanent connection.
- **Grid-Forming Mode**: TSGB switches to synchronous output mode, targeting 50.00 Hz and nominal voltage (11kV or 33kV based on deployment class).
- **Droop Settings**: 4%–6% droop logic allows frequency control to respond proportionally to downstream load pickup.

### Step 3 – Link

- **Frequency Window for Sync**: Units scan for neighboring TSGB nodes within ±0.05 Hz and ±10° phase window.
- **Handshake Protocol**:
  - Exchanged via low-bandwidth radio or fiber.
  - Each node verifies: voltage, frequency, phase angle, available power reserve.
- **Auto-Synchronization**: If within thresholds, nodes phase-lock and join into a microgrid cluster.

### Step 4 – Bridge

- **HVDC Endpoint Injection**:
  - TSGBs establish stable AC waveforms required to re-energize HVDC terminals.
  - Voltage reference and phase alignment initiated before link reclosing.
- **Stability Watchdog**: Load rejection and arc suppression systems are verified active prior to reclosure.
- **Grid Segment Bridging**: Once HVDC stabilizes, TSGBs assume synchronized generation on both sides.

### Step 5 – Lift

- **Progressive Load Pickup**:
  - Frequency is monitored continuously to detect RoCoF (Rate of Change of Frequency).
  - If RoCoF exceeds 0.25 Hz/s, TSGBs downshift via AMT to increase torque delivery.
- **Inertial Contribution**:
  - Kinetic energy is deployed to buffer against sudden demand.
  - TSGBs can discharge at 10 MW for ~12 seconds or blend DC+inertia for short bursts up to 20 MW.
- **Local Generation Handoff**: Once gas turbines or other generation comes online, TSGBs disengage or switch to absorber mode.

### Step 6 – Repeat

- TSGB fleet moves on to the next blackout zone.
- Process reinitializes at “Spin First.”

---

## Grid Safety and Self-Governance

- **Output Ceiling**: Due to fixed-speed 3000 RPM DC input and 2:1 max gear ratio, TSGBs cannot push grid frequency beyond ~50.10 Hz.
- **No Software Clamp Required**: The system is mechanically limited by design.
- **Fail-Safe Modes**:
  - Loss of DC input → coastdown and passive disconnection
  - Control failure → safe discharge at bounded torque
  - Overspeed impossible due to generator-synchronous behavior

---

## Sequencing Logic Table

| Stage       | Action                           | Time Estimate | Criteria for Progression              |
|-------------|----------------------------------|---------------|----------------------------------------|
| Spin        | Ramp shaft to 3000 RPM           | 3–5 sec       | DC stable, RPM within ±0.5%           |
| Form AC     | Generator engagement             | <1 sec        | Shaft RPM locked, load isolated       |
| Link        | Sync with neighboring nodes      | <10 sec       | Freq ±0.05 Hz, phase <10°             |
| Bridge      | Reactivate HVDC endpoints        | 15–60 sec     | AC waveform stable, sync confirmed    |
| Lift        | Pickup load via droop/inertia    | 10–120 sec    | Load > demand, RoCoF < 0.25 Hz/s      |
| Repeat      | Move to next zone                | n/a           | Segment stabilized and handed off     |

---

## Example Sequencing Event

1. **Zone A** is isolated after transmission collapse.
2. Local wind + battery charges TSGB #1 → spins up and forms 50 Hz island.
3. TSGB #2 and #3 spin up and sync to #1 within 10 seconds.
4. Once 3-unit cluster stabilizes, they re-energize local HVDC terminal.
5. Terminal activates and feeds next grid segment.
6. Fleet moves to **Zone B** and begins sequence again.

---

## Communications and Control Coordination

- **Protocol**: Lightweight TSGB-Link over UDP with fallback to physical signaling.
- **Roles**: Any TSGB can act as a seed or follower; role negotiated at runtime.
- **Telemetry**: RPM, voltage, phase, power reserve, inertia state shared every 500 ms.

---

## Summary

The TSGB system offers a uniquely rugged, self-limiting, and field-adaptable method for blackstart and partial grid reconstitution. Its inertial backbone, safe-by-design output limits, and deterministic sequencing allow it to operate autonomously or under loose supervisory coordination, making it ideal for extreme grid failure scenarios.
