# TSGB Continuous Lean-In Operation — Why No Software Is Needed for Core Function

## Principle of Operation
In this mode, the TSGB:
- Is always “leaning into” the grid from the **input side** (DC motor fed by wind, solar, HVDC, etc.).
- Has its synchronous generator rotor locked in step with the grid.
- Feeds torque continuously into the rotor from the DC side.
- Relies on the grid’s instantaneous resistance changes to modulate torque naturally.

This is **mechanical grid-following**: there is no “store then dump” behaviour. Instead, the flywheel’s inertia resists changes in speed, and any inertial contribution is *proportional to the rate of change* in grid conditions.

---

## Why Software Isn’t Required for Core Safety or Frequency Control

1. **Instantaneous Physical Response**  
   Any change in grid frequency (Δf) directly causes a torque imbalance.  
   - If the grid slows → the rotor resists deceleration and supplies extra torque.  
   - If the grid speeds up → the rotor resists acceleration, absorbing energy.  
   This is all **purely mechanical**, with no sensing or control loop delay.

2. **No Overpush Possible**  
   - Fixed gear ratio and fixed-speed DC motor mean shaft speed cannot exceed synchronous speed.  
   - You physically cannot drive the generator faster than the grid will accept, so frequency cannot be overdriven.

3. **Self-Metering Inertia**  
   - Inertial output is proportional to grid load changes — no controller needed to “decide” how much to inject.  
   - Stable grid → steady torque from the DC drive only.  
   - Grid dip → proportional inertial boost from rotor physics.

4. **Naturally Safe Fault Behaviour**  
   - Lose DC input → rotor coasts, continues supplying torque until it slows into balance with the grid.  
   - Lose control electronics → still mechanically tied to the grid, no runaway.

---

## When Software *Is* Useful

While it’s not essential for core operation, software can add value for:
- **Logging & Optimisation** – Monitor real-time power flow, efficiency, and wear.  
- **Fleet Coordination** – Align torque bias across multiple TSGB units for grid operator instructions.  
- **Health Monitoring** – Track bearing temps, vibration, and maintenance needs.  
- **Dispatch Control** – Adjust lean-in torque for market or ancillary service participation.

---

## Bottom Line

With a fixed mechanical link and constant lean-in operation, the TSGB’s **core safety and proportional inertial response come from physics alone**.  
Software is an optional overlay for monitoring, optimisation, and coordination — **not** a requirement for safe, stable, or effective operation.

