import numpy as np
import matplotlib.pyplot as plt

# Define gearbox parameters
gear_indices = list(range(1, 13))  # Gears 1 to 12
ratios = np.linspace(2.20122, 2.0, 12)  # From 1.8:1 (Gear 1) to 2.0:1 (Gear 12)
torque_offsets = np.linspace(420, 180, 12)  # Torque curve: higher torque in lower gears

# Assume fixed drive RPM (shaft input)
drive_rpm = 3000
gen_rpm = drive_rpm / ratios  # Generator RPM = input RPM ÷ gear ratio

# Plot 1: Generator RPM vs Gear Index
plt.figure(figsize=(10, 6))
plt.plot(gear_indices, gen_rpm, marker='o')
plt.title("Generator RPM vs Gear Index (Drive RPM = 3000)")
plt.xlabel("Gear Index (1 = Max Torque, 12 = Cruise)")
plt.ylabel("Generator RPM")
plt.grid(True)
plt.xticks(gear_indices)
plt.tight_layout()
plt.show()

# Plot 2: Torque Offset vs Gear Index
plt.figure(figsize=(10, 6))
plt.plot(gear_indices, torque_offsets, marker='s', linestyle='--')
plt.title("Torque Offset vs Gear Index")
plt.xlabel("Gear Index (1 = Max Torque, 12 = Cruise)")
plt.ylabel("Torque Offset (Nm)")
plt.grid(True)
plt.xticks(gear_indices)
plt.tight_layout()
plt.show()

# Plot 3: Combined Plot
fig, ax1 = plt.subplots(figsize=(10, 6))

color = 'tab:blue'
ax1.set_xlabel('Gear Index')
ax1.set_ylabel('Generator RPM', color=color)
ax1.plot(gear_indices, gen_rpm, marker='o', color=color)
ax1.tick_params(axis='y', labelcolor=color)
ax1.set_xticks(gear_indices)

ax2 = ax1.twinx()
color = 'tab:red'
ax2.set_ylabel('Torque Offset (Nm)', color=color)
ax2.plot(gear_indices, torque_offsets, marker='s', linestyle='--', color=color)
ax2.tick_params(axis='y', labelcolor=color)

plt.title("TSGB Gearbox: Gen RPM and Torque vs Gear Index")
fig.tight_layout()
plt.grid(True)
plt.show()
