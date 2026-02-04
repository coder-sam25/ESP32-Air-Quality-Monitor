/*
  ESP32 Air Quality Monitor - MQ Sensor Calibration

  This sketch calculates the baseline resistance (R0)
  for MQ-series gas sensors in clean air.

  Author: <Sampurna Raychaudhuri>
*/

#define ADC_MAX 4095
#define VREF    3.3
#define RL      10.0   // Load resistor in kOhms

// MQ sensor pins
#define MQ2_PIN   32
#define MQ3_PIN   33
#define MQ7_PIN   34
#define MQ135_PIN 35

float calculateR0(int pin) {
  long adcSum = 0;

  for (int i = 0; i < 100; i++) {
    adcSum += analogRead(pin);
    delay(50);
  }

  float adcAvg = adcSum / 100.0;
  float voltage = (adcAvg / ADC_MAX) * VREF;
  float rs = ((VREF - voltage) / voltage) * RL;

  return rs;
}

void setup() {
  Serial.begin(115200);
  delay(2000);

  Serial.println("MQ Sensor Calibration");
  Serial.println("Ensure sensors are in clean air");
  Serial.println();

  Serial.print("MQ2 R0: ");
  Serial.println(calculateR0(MQ2_PIN));

  Serial.print("MQ3 R0: ");
  Serial.println(calculateR0(MQ3_PIN));

  Serial.print("MQ7 R0: ");
  Serial.println(calculateR0(MQ7_PIN));

  Serial.print("MQ135 R0: ");
  Serial.println(calculateR0(MQ135_PIN));
}

void loop() {
  // Calibration runs once
}
