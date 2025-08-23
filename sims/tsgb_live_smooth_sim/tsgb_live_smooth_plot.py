
import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("tsgb_live_smooth_sim.csv")

plt.figure(figsize=(14, 10))

plt.subplot(3,1,1)
plt.plot(df["Time (s)"], df["Grid Freq (Hz)"], label="Grid Freq")
plt.plot(df["Time (s)"], df["RoCoF (Hz/s)"], label="RoCoF")
plt.legend()
plt.title("Grid Frequency & RoCoF")
plt.grid(True)

plt.subplot(3,1,2)
plt.plot(df["Time (s)"], df["Gear"], drawstyle='steps-post', label="Gear")
plt.plot(df["Time (s)"], df["Gen RPM"], label="Gen RPM")
plt.plot(df["Time (s)"], df["Target RPM"], linestyle="--", label="Target RPM")
plt.legend()
plt.title("Gear & RPM Behavior")
plt.grid(True)

plt.subplot(3,1,3)
plt.plot(df["Time (s)"], df["Injected Power (kW)"], label="Power Injected (kW)", color='green')
plt.legend()
plt.title("Injected Power into Grid")
plt.grid(True)

plt.tight_layout()
plt.show()
