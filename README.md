Designed as a portfolio project for embedded systems and IoT development.

# ESP32 Air Quality Monitor

An ESP32-based air quality monitoring system using multiple MQ gas sensors and a DHT11 sensor.  
This project demonstrates raw sensor data acquisition, calibration methodology, and safe analog interfacing with the ESP32.

---

## Hardware Used
- ESP32-WROOM-32
- MQ2 (Smoke / LPG)
- MQ3 (Alcohol)
- MQ7 (Carbon Monoxide)
- MQ135 (Air Quality)
- DHT11 Temperature & Humidity Sensor
- AMS1117-3.3 Voltage Regulator
- Voltage divider circuits for ADC protection

---

## Features
- Reads temperature and humidity using DHT11
- Reads raw analog values from multiple MQ sensors
- Dedicated calibration firmware to calculate baseline resistance (R₀)
- Safe ADC interfacing using voltage dividers
- Modular firmware structure

---

##  Repository Structure
firmware/
├── sensor_reading/
│ └── sensor_reading.ino
├── calibration/
│ └── calibration.ino

hardware/
docs/


---

##  Calibration Process
1. Power MQ sensors for 24–48 hours (burn-in)
2. Place sensors in clean air
3. Upload `calibration.ino`
4. Record printed R₀ values from Serial Monitor
5. Use R₀ in future concentration calculations

---

##  How to Run

### Sensor Reading
- Upload `sensor_reading.ino`
- Open Serial Monitor at **115200 baud**

### Calibration
- Upload `calibration.ino`
- Ensure sensors are warmed up
- Record output values

---

##  Future Improvements
- Convert raw ADC values to PPM
- Add OLED display output
- Log data to cloud (MQTT / HTTP)
- Mobile or web dashboard

---

##  License
MIT License



