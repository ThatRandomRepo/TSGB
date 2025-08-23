
# TSGB Control System – C++ Core

This folder contains the **core logic implementation** of the TSGB (Torque Shift Gearbox) system.  
It models the behavior of a mechanically-preloaded grid-stabilizing unit with real-time frequency tracking, gear shifting logic, and SCADA interface capabilities.

---

## 📄 Files Overview

### `main.cpp`
- Simulation loop at 5 kHz
- Drives the TSGB system under artificial frequency inputs
- Handles state transitions and debug outputs
- Useful for testing control logic before hardware implementation

### `tsgb-ctl.cpp`
- **Heart of the TSGB logic**
- Processes:
  - Grid frequency (`Hz`)
  - Rate of change of frequency (`RoCoF`)
  - Torque offset curves
  - Gearbox dwell logic (anti-hunting)
  - State transitions: Cruise, Fight, Forming, Arrest
- Implements **lean-in preload logic** and `always-pushing` concept

### `scada_integration.cpp`
- Stub/adapter for integrating TSGB with SCADA systems
- Handles:
  - Command & telemetry wiring
  - SCADA-friendly hooks for gear index, torque value, and health states

---

## ⚙️ Core Concepts in Code

- **Preload**: Torque is always engaged. The system doesn't wait for a drop — it *fights first*.
- **RoCoF Driven**: RoCoF (Rate of Change of Frequency) determines gear shift timing.
- **Anti-Hunting**: Gearbox changes are delayed by a dwell timer to avoid flapping or over-correction.
- **Closed Loop**: All responses are based on real-time frequency and system resistance — no feed-forward cheating.

---

## 🧪 Testing

Use `main.cpp` to simulate frequency profiles:
```bash
g++ main.cpp tsgb-ctl.cpp scada_integration.cpp -o tsgb_sim
./tsgb_sim
```

Adjust `main.cpp` to:
- Change input waveforms
- Print internal states
- Stress test dwell logic or torque output ramps

---

## ❗ Safety Note

> These files are **not safe for use on live machinery**.  
> They simulate control logic but do not implement hardware safety, overspeed protection, or real-world constraints.

Use for learning, sim development, and software validation only.

---

## 🧠 Author's Intent

This is not about selling hardware.  
This is about showing that **good control logic can be both simple and powerful** when built around first principles and mechanical intuition.

> "I lived this system into existence — now it’s your turn to see what’s possible."

---

— *TSGB Author*
