MQ Gas Sensor Calibration (ESP32/Arduino)
Overview

This program performs calibration of MQ gas sensors (MQ2, MQ3, MQ7, MQ135) to determine their baseline resistance (R₀) in clean air. These values are essential for accurate gas concentration calculations later.

Features
Calibrates 4 MQ sensors
Uses multiple samples for accuracy
Computes sensor resistance from ADC values
Outputs R₀ values via Serial Monitor
Hardware Required
ESP32 / Arduino
MQ2, MQ3, MQ7, MQ135 sensors
Load resistor (RL = 10kΩ assumed)
Pin Configuration
Sensor	Pin
MQ2	32
MQ3	33
MQ7	34
MQ135	35
How It Works
1. Warm-Up Phase
delay(15000);
Allows sensors to stabilize (~15 seconds)
2. Resistance Calculation
Rs = (Vcc - Vout) / Vout × RL
Converts ADC reading → voltage → sensor resistance
3. Calibration Process
Takes 50 samples per sensor
Waits 500 ms between readings
Averages all readings to compute R₀
4. Output

Displays calibrated values:

MQ2 R0: XXXX
MQ3 R0: XXXX
MQ7 R0: XXXX
MQ135 R0: XXXX
