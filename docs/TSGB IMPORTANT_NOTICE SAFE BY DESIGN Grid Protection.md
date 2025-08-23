
TSGB Output Safety Analysis: Why the 2:1 Ratio and Fixed-Speed DC Drive Ensure Grid Protection

Overview
--------
This document explains why the TwinScroll Grid Balancer (TSGB) system, configured with a maximum 2:1 gear ratio and a fixed-speed DC input drive at 3000 RPM, is inherently safe for grid integration. Specifically, it outlines how these design constraints eliminate the risk of the TSGB pushing grid frequency beyond safe operational limits or causing system instability. The combination of mechanical and electrical limits ensures that even at full output, the TSGB cannot overdrive the grid.

Key Design Parameters
---------------------
1. Fixed-Speed DC Drive @ 3000 RPM:
   - The shaft drive motor is locked to 3000 RPM (50 Hz synchronous speed).
   - It serves to maintain the shaft's rotation and replenish kinetic energy, not to accelerate the system beyond its natural operating point.
   - No overspeeding of the shaft is physically possible via the DC input.

2. Maximum Gear Ratio: 2:1
   - The transmission's top gear multiplies shaft torque by a maximum of 2x.
   - This defines the strongest torque the generator can receive from the flywheel.
   - Even in the lowest gear, the system cannot mechanically exceed safe frequency output.

3. Generator Characteristics:
   - The generator is synchronous, meaning its output frequency is directly tied to the shaft speed.
   - Since the shaft cannot exceed 3000 RPM and the top gear cannot push harder than 2:1, output frequency can’t exceed ~50.10 Hz.

What This Means
---------------
1. No Software Output Limiter Required:
   - The system is physically incapable of pushing grid frequency above operational limits.
   - Unlike inverter-based systems that require digital limits, the TSGB's safety is baked into its mechanics.

2. Inherently Safe Discharge Behavior:
   - The TSGB cannot "run away" or inject power uncontrollably.
   - Even under a fault or control system failure, the flywheel will spin down naturally and the gearbox will prevent torque beyond the 2:1 cap.

3. Grid-Following by Design:
   - The TSGB acts like a synchronous generator in behavior: it follows the grid frequency and supplies torque as needed.
   - It cannot drive frequency up beyond the system average — it can only support ongoing dynamics.

4. Fail-Safe Under Control Loss:
   - If control is lost, the worst-case behavior is a passive discharge at 2:1 ratio.
   - There is no risk of mechanical or electrical runaway conditions.

5. No Overgeneration Risk:
   - Even if the TSGB is discharging at full 10 MW output, it cannot push the grid to a damaging overfrequency condition.
   - This is because the flywheel cannot deliver enough torque at high RPM to raise frequency past the 50.10 Hz ceiling.

Conclusion
----------
The TSGB design, when paired with a 2:1 ultra-close ratio gearbox and a 3000 RPM fixed-speed DC drive, forms a mechanically and electrically self-limiting system. It cannot damage or destabilize the grid, even at full output or under failure modes. This eliminates the need for complex software-based output clamps, aligns perfectly with grid code expectations, and simplifies integration for operators. The system is passively safe — a rare trait in high-power energy systems.
