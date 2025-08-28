
// tsgb_test.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cassert>

struct TSGBResult {
    float time;
    float freq;
    float rocof;
    int gear;
    float torque;
    float gen_rpm;
};

class TSGB {
public:
    float ratios[12];
    float torques[12];
    float drive_rpm = 3000.0;

    TSGB() {
        for (int i = 0; i < 12; ++i) {
            ratios[i] = 1.8 + i * ((2.20122 - 2.0) / 11.0);
            torques[i] = 420 - i * ((420 - 180) / 11.0);
        }
    }

    int select_gear(float rocof) {
        if (rocof < -1.0) return 0;
        if (rocof < -0.8) return 1;
        if (rocof < -0.6) return 2;
        if (rocof < -0.4) return 3;
        if (rocof < -0.2) return 4;
        if (rocof < -0.05) return 5;
        return 11;
    }

    TSGBResult step(float t, float freq, float last_freq, float dt) {
        float rocof = (freq - last_freq) / dt;
        int gear = select_gear(rocof);
        float torque = torques[gear];
        float gen_rpm = drive_rpm / ratios[gear];
        return {t, freq, rocof, gear + 1, torque, gen_rpm};
    }
};

// Test input: frequency drop from 50Hz to 48Hz over 2s
float freq_profile(float t) {
    if (t < 2.0f) return 50.0f;
    else if (t < 4.0f) return 50.0f - 2.0f * (t - 2.0f);
    return 48.0f;
}

int main() {
    TSGB tsgb;
    std::ofstream csv("tsgb_unit_test_output.csv");
    csv << "Time (s),Frequency (Hz),RoCoF (Hz/s),Gear,Torque (Nm),Gen RPM\n";

    float last_freq = 50.0;
    float dt = 0.01f;
    for (float t = 0; t < 10.0f; t += dt) {
        float freq = freq_profile(t);
        auto result = tsgb.step(t, freq, last_freq, dt);
        last_freq = freq;

        // CSV output
        csv << result.time << "," << result.freq << "," << result.rocof << ","
            << result.gear << "," << result.torque << "," << result.gen_rpm << "\n";

        // Unit test assertion (example)
        assert(result.gear >= 1 && result.gear <= 12);
    }

    csv.close();
    std::cout << "Test complete. Output written to tsgb_unit_test_output.csv\n";
    return 0;
}
