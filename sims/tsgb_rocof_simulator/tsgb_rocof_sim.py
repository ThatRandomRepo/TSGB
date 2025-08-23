
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# Load simulation data
df = pd.read_csv("tsgb_rocof_sim.csv")

# Plot results
plt.figure(figsize=(12, 10))

plt.subplot(4, 1, 1)
plt.plot(df["Time (s)"], df["Frequency (Hz)"])
plt.title("Grid Frequency Over Time")
plt.ylabel("Hz")
plt.grid(True)

plt.subplot(4, 1, 2)
plt.plot(df["Time (s)"], df["RoCoF (Hz/s)"])
plt.ylabel("RoCoF (Hz/s)")
plt.grid(True)

plt.subplot(4, 1, 3)
plt.step(df["Time (s)"], df["Gear"], where='post')
plt.ylabel("Gear Index")
plt.grid(True)

plt.subplot(4, 1, 4)
plt.plot(df["Time (s)"], df["Torque (Nm)"])
plt.xlabel("Time (s)")
plt.ylabel("Torque (Nm)")
plt.grid(True)

plt.tight_layout()
plt.show()
