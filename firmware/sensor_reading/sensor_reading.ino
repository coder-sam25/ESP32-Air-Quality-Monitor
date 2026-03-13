#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#include "RTClib.h"

// --- Define Pins ---
#define OLED_RESET -1 // Reset pin 
#define DHTPIN 4    // DHT data pin
#define DHTTYPE DHT11 // DHT 11

#define MQ7_PIN 34
#define MQ135_PIN 35
#define MQ2_PIN 32
#define MQ3_PIN 33 

// --- Initialize Libraries ---
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);
DHT dht(DHTPIN, DHTTYPE);
RTC_DS1307 rtc; // Replace with your RTC class name

// --- Timing Variables ---
unsigned long previousMillis = 0;
const unsigned long interval = 6000; // 2 seconds interval
int screenState = 0; // 0: RTC/DHT11, 1: MQ7/MQ135, 2: MQ2/Anonymous

// --- Sensor Variables ---
float temperature, humidity;
int mq7_val, mq135_val, mq2_val, mq3_val;
DateTime now;

void setup() {
  Serial.begin(115200);
  dht.begin();

  // Initialize I2C for OLED and RTC
  Wire.begin();
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C or 0x3D
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  display.setTextColor(WHITE);

  // Initialize RTC 
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    
  }
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    // Read all sensors 
    readSensors();
    
    // Cycle through screens
    displayScreen(screenState);
    screenState = (screenState + 1) % 3; // Cycle 0, 1, 2, 0, ...
  }
}

void readSensors() {
  // Read DHT11
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
  }

  // Read MQ sensors (analog values)
  mq7_val = analogRead(MQ7_PIN);
  mq135_val = analogRead(MQ135_PIN);
  mq2_val = analogRead(MQ2_PIN);
  mq3_val = analogRead(MQ3_PIN);

  // Read RTC
  now = rtc.now(); 
}

void displayScreen(int state) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);

  switch (state) {
    case 0:
      display.println("--- RTC & DHT11 ---");
      // Display RTC 
      display.print("Date: ");
      display.print(now.day()); display.print("/");
      display.print(now.month()); display.print("/");
      display.println(now.year());
      display.print("Time: ");
      display.print(now.hour()); display.print(":");
      display.print(now.minute()); display.print(":");
      display.println(now.second());
      
      // Display DHT11
      display.print("Temp: ");
      display.print(temperature);
      display.println(" C");
      display.print("Humi: ");
      display.print(humidity);
      display.println(" %");
      break;

    case 1:
      display.println("--- MQ7 & MQ135 ---");
      // Display MQ7 (analog raw value)
      display.print("MQ7 (CO): ");
      display.println(mq7_val);
      // Display MQ135 (analog raw value)
      display.print("MQ135 (Air Q): ");
      display.println(mq135_val);
      
      break;

    case 2:
      display.println("--- MQ2 & MQ3 ---");
      // Display MQ2 (analog raw value)
      display.print("MQ2 (Smoke/Gas): ");
      display.println(mq2_val);
      // Display Anonymous (analog raw value)
      display.print("MQ3 (Val): ");
      display.println(mq3_val);
      break;
  }
  display.display(); // Update the physical display
}
