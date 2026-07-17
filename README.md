# 🌱 IoT-Based Smart Irrigation & Greenhouse Monitoring System

![Status](https://img.shields.io/badge/Status-Completed-brightgreen)
![Platform](https://img.shields.io/badge/Platform-ESP32-blue)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![IDE](https://img.shields.io/badge/IDE-Arduino_IDE-orange)
![IoT](https://img.shields.io/badge/Cloud-Blynk-success)

An IoT-enabled Smart Greenhouse Monitoring and Irrigation System built using **ESP32** to automate irrigation, monitor environmental conditions, detect fire hazards, and provide real-time cloud monitoring through the **Blynk IoT Platform**.

---

# 📑 Table of Contents

- [Overview](#-overview)
- [Features](#-features)
- [Hardware Components](#-hardware-components)
- [Software & Tools](#-software--tools)
- [System Workflow](#-system-workflow)
- [Project Structure](#-project-structure)
- [Documentation](#-documentation)
- [Project Demo](#-project-demo)
- [Future Improvements](#-future-improvements)
- [Author](#-author)

---

# 📌 Overview

Modern agriculture requires intelligent automation to improve efficiency while reducing water consumption and human intervention.

This project presents an **IoT-Based Smart Irrigation & Greenhouse Monitoring System** capable of continuously monitoring environmental conditions and automatically controlling irrigation, greenhouse ventilation, and emergency safety mechanisms.

The ESP32 collects sensor data, processes it locally, and uploads live readings to the **Blynk Cloud**, allowing users to monitor the greenhouse remotely from anywhere.

---

# ✨ Features

- 🌱 Automatic irrigation based on soil moisture
- 🌡️ Temperature & humidity monitoring
- 💡 Ambient light monitoring
- 🌧️ Rain detection
- 🚰 Water tank level monitoring
- 🔥 Fire detection with buzzer alarm
- 🪟 Automatic greenhouse ventilation using Servo Motor
- ☁️ Real-time monitoring using Blynk IoT
- 📟 Live Serial Monitor diagnostics
- ⚡ Autonomous real-time operation

---

# 🛠 Hardware Components

| Component | Function |
|------------|----------|
| ESP32 Dev Board | Main Controller |
| DHT11 | Temperature & Humidity Sensor |
| Soil Moisture Sensor | Irrigation Control |
| LDR | Light Detection |
| Water Sensor | Rain Detection |
| Flame Sensor | Fire Detection |
| HC-SR04 Ultrasonic Sensor | Water Tank Monitoring |
| Servo Motor SG90 | Greenhouse Window Control |
| Relay Module | Pump Switching |
| Water Pump | Irrigation |
| I2C LCD | Local Display |
| Active Buzzer | Alarm System |

---

# 💻 Software & Tools

- Arduino IDE
- ESP32 Arduino Core
- Blynk IoT Platform
- Wokwi Simulator

---

# ⚙️ System Workflow

```text
Read Sensor Data
        │
        ▼
Process Sensor Values
        │
        ▼
Decision Making
        │
 ┌──────┴─────────┐
 │                │
 ▼                ▼
Control Pump   Control Servo
 │                │
 └──────┬─────────┘
        ▼
Update Blynk Dashboard
        ▼
Display Data & Alerts
```

---

# 📂 Project Structure

```
IoT-Smart-Irrigation-System
│
├── Code/
│
├── Documentation/
│   └── Final Report.pdf
│
├── Images/
│
├── Diagrams/
│
└── README.md
```

---

# 📄 Documentation

The complete technical report describing the project architecture, implementation, testing procedures, and evaluation is available inside the **Documentation** folder.

---

# 🎥 Project Demo

Watch the complete project demonstration here:

### ▶️ [Watch Demo Video](https://drive.google.com/file/d/1THavF8XfbiDCVQ4fUKIMlvT7Og5ExhPg/view?usp=drivesdk)

---

# 🚀 Future Improvements

- Weather API Integration
- MQTT Communication
- Mobile Push Notifications
- AI-based Irrigation Prediction
- Solar Power Integration
- Cloud Data Analytics
- Historical Data Logging

---

# 👨‍💻 Author

**Ahmed Samir**

Electronics & Communications Engineering Student

Nile University

📍 Giza, Egypt

---

## ⭐ If you found this project interesting, consider giving it a star.
