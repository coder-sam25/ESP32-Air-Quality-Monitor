# ESP32 Multi-Gas Air Quality Monitoring System

## Overview

This project implements a **real-time air quality monitoring system using ESP32** with multiple environmental sensors and an OLED display.

The system measures:

* Temperature
* Humidity
* Carbon Monoxide (CO)
* Smoke / Gas
* Alcohol vapors
* General air pollution

Sensor data is displayed on an **OLED screen**, with multiple information pages that automatically rotate.

The system also includes a **Real Time Clock (RTC)** to show the current **date and time**.

---

# Features

* ESP32-based environmental monitoring
* Multi-gas detection
* Temperature and humidity sensing
* Real-time clock display
* OLED display interface
* Automatic screen rotation
* Serial debugging output

---

# Hardware Components

| Component    | Purpose                   |
| ------------ | ------------------------- |
| ESP32        | Main microcontroller      |
| MQ2          | Smoke / gas detection     |
| MQ3          | Alcohol detection         |
| MQ7          | Carbon monoxide detection |
| MQ135        | Air quality detection     |
| DHT11        | Temperature & humidity    |
| DS1307 RTC   | Real-time clock           |
| SSD1306 OLED | Display interface         |

---

# Pin Configuration

| Sensor | ESP32 Pin |
| ------ | --------- |
| DHT11  | GPIO 4    |
| MQ2    | GPIO 32   |
| MQ3    | GPIO 33   |
| MQ7    | GPIO 34   |
| MQ135  | GPIO 35   |

### I2C Devices

| Device       | Address |
| ------------ | ------- |
| OLED Display | 0x3C    |
| RTC Module   | 0x68    |

---

# Display Screens

The OLED rotates between **three information screens** every few seconds.

## Screen 1 — RTC + Environment

Displays:

* Date
* Time
* Temperature
* Humidity

Example:

Date: 10/03/2026
Time: 14:25:30
Temp: 27°C
Humidity: 65%

---

## Screen 2 — Air Quality Sensors

Displays:

* MQ7 (Carbon Monoxide)
* MQ135 (Air Quality)

These are shown as **raw ADC values**.

---

## Screen 3 — Gas Detection

Displays:

* MQ2 (Smoke / LPG)
* MQ3 (Alcohol vapors)

---

# How the System Works

1. ESP32 reads environmental data from the **DHT11 sensor**
2. Gas concentrations are read as **analog signals** from MQ sensors
3. Time and date are obtained from the **RTC module**
4. Data is displayed on the **SSD1306 OLED display**
5. The display automatically cycles between information pages

---

# MQ Sensor Calibration

MQ sensors require calibration before use.

Calibration determines the **baseline resistance (R₀)** in clean air.

## Calibration Steps

1. Upload the **calibration code**
2. Place sensors in **clean air**
3. Wait for sensors to warm up
4. Record the printed **R0 values**
5. Insert these values into your main program

Calibration significantly improves measurement accuracy.

---


# Required Libraries
* Adafruit GFX
* Adafruit SSD1306
* DHT Sensor Library
* RTClib

---

---

# Applications

* Indoor air quality monitoring
* Smart home environmental monitoring
* Industrial gas detection
* Environmental research
* IoT pollution monitoring

---

# Author

Sampurna Raychaudhuri

ESP32-based multi-sensor air quality monitoring system with OLED display.
