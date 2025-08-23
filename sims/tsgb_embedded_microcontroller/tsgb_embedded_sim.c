
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

// Simulated control loop rate
#define CONTROL_HZ 5000
#define DT_SEC (1.0f / CONTROL_HZ)

// Gear ratios and torque offsets
const float gear_ratios[12] = {1.8, 1.8182, 1.8364, 1.8545, 1.8727, 1.8909,
                               1.9091, 1.9273, 1.9455, 1.9636, 1.9818, 2.0};
const float torque_offsets[12] = {420, 401.8, 383.6, 365.4, 347.2, 329.0,
                                  310.9, 292.7, 274.5, 256.3, 238.1, 220};

float last_freq = 50.0f;

// Simulate frequency source (drop from 50Hz to 48Hz over time)
float get_grid_frequency(float t_sec) {
    if (t_sec < 2.0f) return 50.0f;
    else if (t_sec < 4.0f) return 50.0f - (2.0f * (t_sec - 2.0f));
    else return 48.0f;
}

// Simulated drive RPM (fixed)
#define DRIVE_RPM 3000.0f

// TSGB controller
int get_gear_from_rocof(float rocof) {
    if (rocof < -1.0f) return 0;
    else if (rocof < -0.8f) return 1;
    else if (rocof < -0.6f) return 2;
    else if (rocof < -0.4f) return 3;
    else if (rocof < -0.2f) return 4;
    else if (rocof < -0.05f) return 5;
    else return 11;
}

int main(void) {
    float t = 0.0f;
    for (int i = 0; i < (CONTROL_HZ * 10); i++) {
        float freq = get_grid_frequency(t);
        float rocof = (freq - last_freq) / DT_SEC;
        int gear = get_gear_from_rocof(rocof);

        float ratio = gear_ratios[gear];
        float torque = torque_offsets[gear];
        float gen_rpm = DRIVE_RPM / ratio;

        printf("t=%.2fs | F=%.2f Hz | RoCoF=%.2f Hz/s | Gear=%d | Gen RPM=%.1f | Torque=%.1f Nm\n",
               t, freq, rocof, gear + 1, gen_rpm, torque);

        last_freq = freq;
        t += DT_SEC;
    }

    return 0;
}
