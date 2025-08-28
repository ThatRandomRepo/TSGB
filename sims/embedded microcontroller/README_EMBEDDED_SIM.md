
# TSGB Embedded Simulator (C)

This C code simulates the TSGB control logic running on a microcontroller at 5 kHz.  
It models RoCoF-driven gear shifting and torque output based on a synthetic grid frequency drop event.

---

## 📂 File

- `tsgb_embedded_sim.c` — Control loop for embedded-style simulation

---

## ▶️ How to Compile and Run (PC)

```bash
gcc tsgb_embedded_sim.c -o tsgb_sim
./tsgb_sim
```

This will print time-stamped lines with:

- Time step
- Grid frequency (Hz)
- RoCoF (Hz/s)
- Selected Gear Index
- Generator RPM
- Torque Output (Nm)

---

## ⚙️ Porting to Microcontrollers

- Place loop logic inside:
  - `void loop()` (Arduino)
  - `HAL_TIM_PeriodElapsedCallback()` (STM32Cube)
- Replace `printf` with:
  - `Serial.print()` or `UART_Transmit()`
- Simulate or inject grid frequency values via analog read or I2C/SPI sensors

---

## 🔧 Notes

- Drive RPM is fixed at 3000
- Gear range is 1.8:1 to 2.0:1 (12 steps)
- Anti-hunting logic can be added as a timer/delay per shift

---
