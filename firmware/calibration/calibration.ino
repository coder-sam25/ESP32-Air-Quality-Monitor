
#define MQ7_PIN   34
#define MQ135_PIN 35
#define MQ2_PIN   32
#define MQ3_PIN   33

#define RL_VALUE 10.0
#define ADC_MAX 4095.0

#define CALIBRATION_SAMPLES 50
#define SAMPLE_INTERVAL 500

float R0_MQ2;
float R0_MQ3;
float R0_MQ7;
float R0_MQ135;

float calculateResistance(int adcValue)
{
  float voltage = adcValue * (3.3 / ADC_MAX);
  float rs = (3.3 - voltage) / voltage * RL_VALUE;
  return rs;
}

float calibrateSensor(int pin)
{
  float rs = 0;

  for (int i = 0; i < CALIBRATION_SAMPLES; i++)
  {
    int adc = analogRead(pin);
    rs += calculateResistance(adc);
    delay(SAMPLE_INTERVAL);
  }

  rs = rs / CALIBRATION_SAMPLES;
  return rs;
}

void setup()
{
  Serial.begin(115200);

  Serial.println("MQ Sensor Calibration Starting...");
  Serial.println("Place sensors in CLEAN AIR");

  delay(15000); // sensor warmup

  R0_MQ2 = calibrateSensor(MQ2_PIN);
  R0_MQ3 = calibrateSensor(MQ3_PIN);
  R0_MQ7 = calibrateSensor(MQ7_PIN);
  R0_MQ135 = calibrateSensor(MQ135_PIN);

  Serial.println("\nCalibration Complete\n");

  Serial.print("MQ2 R0: ");
  Serial.println(R0_MQ2);

  Serial.print("MQ3 R0: ");
  Serial.println(R0_MQ3);

  Serial.print("MQ7 R0: ");
  Serial.println(R0_MQ7);

  Serial.print("MQ135 R0: ");
  Serial.println(R0_MQ135);

  
}

void loop() {}
