/*
  ESP32 Air Quality Monitor - Sensor Reading
  Reads raw values from MQ sensors and DHT11

  Author: <Sampurna Raychaudhuri>
*/

#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

// MQ sensor pins (ESP32 ADC)
#define MQ2_PIN   32
#define MQ3_PIN   33
#define MQ7_PIN   34
#define MQ135_PIN 35

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  // DHT11 readings
  float temperature = dht.readTemperature();
  float humidity    = dht.readHumidity();

  // MQ sensor raw ADC values
  int mq2   = analogRead(MQ2_PIN);
  int mq3   = analogRead(MQ3_PIN);
  int mq7   = analogRead(MQ7_PIN);
  int mq135 = analogRead(MQ135_PIN);

  Serial.println("=== Sensor Readings ===");

  if (!isnan(temperature) && !isnan(humidity)) {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  } else {
    Serial.println("DHT11 read failed");
  }

  Serial.print("MQ2   (Raw): "); Serial.println(mq2);
  Serial.print("MQ3   (Raw): "); Serial.println(mq3);
  Serial.print("MQ7   (Raw): "); Serial.println(mq7);
  Serial.print("MQ135 (Raw): "); Serial.println(mq135);

  Serial.println();
  delay(2000);
}
