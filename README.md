Arduino Uno R3 Motion Detection System

A simple **motion detection circuit** built using an **Arduino Uno R3 and PIR (Passive Infrared) sensor**. The system detects movement from nearby objects or people and activates a **buzzer and LED** as an alert.
This project was first simulated in tinkercad, an open source circuit simulator. 
Here's my Tinkercad link for this project: https://www.tinkercad.com/things/9v8QUbc2ab3-motion-detection-circuit-

## 📌 Project Overview

This project demonstrates how an Arduino Uno can interface with a PIR sensor to detect motion.

The PIR sensor detects changes in infrared radiation caused by moving objects, particularly humans. When motion is detected, the Arduino activates an alarm system consisting of:

- 🔊 **Buzzer** — provides an audible alert
- 💡 **LED** — provides a visual indication
- 📡 **PIR Sensor** — detects motion
- 🧠 **Arduino Uno R3** — processes the sensor signal

### Working Principle

```text
        Human / Object
              │
              ▼
       ┌─────────────┐
       │  PIR Sensor │
       └──────┬──────┘
              │
         Motion Signal
              │
              ▼
       ┌─────────────┐
       │ Arduino Uno │
       │     R3      │
       └──────┬──────┘
              │
        ┌─────┴─────┐
        ▼           ▼
    ┌───────┐   ┌────────┐
    │  LED  │   │ Buzzer │
    └───────┘   └────────┘
      ON           ON
```

---

## 🧰 Components Required

| Component | Quantity | Purpose |
|---|---:|---|
| Arduino Uno R3 | 1 | Main controller |
| PIR Motion Sensor | 1 | Motion detection |
| LED | 1 | Visual indication |
| Buzzer | 1 | Audible alarm |
| Resistor | 1 | LED current limiting |
| Breadboard | 1 | Circuit prototyping |
| Jumper Wires | Several | Connections |
| USB Cable | 1 | Programming and power |

---

## 🔌 Circuit Connections

### PIR Sensor → Arduino Uno

| PIR Pin | Arduino Uno |
|---|---|
| VCC | 5V |
| GND | GND |
| OUT | Digital Pin 2 |

### LED → Arduino Uno

| LED Connection | Arduino |
|---|---|
| Anode (+) | Digital Pin 13 |
| Cathode (-) | GND through resistor |

### Buzzer → Arduino Uno

| Buzzer Pin | Arduino |
|---|---|
| Positive (+) | Digital Pin 8 |
| Negative (-) | GND |

> **Note:** The exact PIR module pin arrangement can vary. Check the markings on the sensor before connecting it.

---

## ⚙️ How It Works

1. The PIR sensor continuously monitors the surrounding infrared radiation.
2. When no movement is detected, the sensor output remains LOW.
3. When motion is detected, the PIR output becomes HIGH.
4. The Arduino reads this signal through **Digital Pin 2**.
5. If motion is detected:
   - LED turns ON.
   - Buzzer turns ON.
6. When motion stops, the LED and buzzer are turned OFF.

---

## 💻 Arduino Code

```cpp
// ========================================
// Arduino Uno R3 Motion Detection System
// PIR Sensor + LED + Buzzer
// ========================================

// Pin Definitions
const int PIR_PIN = 2;
const int LED_PIN = 13;
const int BUZZER_PIN = 8;

void setup() {
  // Configure pins
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Start Serial Monitor
  Serial.begin(9600);

  Serial.println("Motion Detection System Started");
}

void loop() {

  // Read PIR sensor
  int motion = digitalRead(PIR_PIN);

  if (motion == HIGH) {

    // Motion detected
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);

    Serial.println("Motion Detected!");

  } else {

    // No motion
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);

    Serial.println("No Motion");
  }

  delay(200);
}
```

---

## 🖥️ Serial Monitor

Open the Arduino IDE Serial Monitor and set the baud rate to:

```text
9600 baud
```

When motion is detected:

```text
Motion Detected!
```

When there is no motion:

```text
No Motion
```

---

## 🧪 Testing

### Test 1 — No Motion

Keep the area in front of the PIR sensor clear.

**Expected result:**

```text
PIR → LOW
LED → OFF
Buzzer → OFF
```

### Test 2 — Motion Detected

Walk in front of the PIR sensor.

**Expected result:**

```text
PIR → HIGH
LED → ON
Buzzer → ON
```

The Serial Monitor should also display:

```text
Motion Detected!
```

---

## 🏠 Applications

This basic circuit can be extended into several practical systems:

- 🏠 Home security systems
- 🚪 Automatic door systems
- 🚨 Intruder alarms
- 💡 Automatic lighting
- 🏢 Office security
- 🅿️ Motion-based lighting
- 🔔 Visitor detection systems
- 📦 Restricted-area monitoring

---

## 🚀 Future Improvements

The project can be upgraded by adding:

- 📱 **ESP32/ESP8266** for Wi-Fi notifications
- 📲 Mobile app notifications
- 📷 ESP32-CAM for capturing images
- 🔐 Password/keypad-based security
- 💡 Automatic room lighting
- 📡 GSM module for SMS alerts
- 💾 SD card for event logging
- 🌐 Web-based monitoring dashboard

---

## 📸 Circuit Diagram

The prototype uses an **Arduino Uno R3, PIR sensor, LED, resistor, and buzzer** mounted on a breadboard.

> Add your circuit photograph or diagram to the repository, for example:

```text
images/
└── motion-detection-circuit.png
```

Then display it in the README using:

```markdown
![Motion Detection Circuit](images/motion-detection-circuit.png)
```

---

## 📂 Repository Structure

```text
arduino-motion-detection/
│
├── motion_detection.ino
├── images/
│   └── motion-detection-circuit.png
├── README.md
└── LICENSE
```

---

## 🛠️ Technologies Used

- **Arduino Uno R3**
- **Arduino IDE**
- **C/C++**
- **PIR Motion Sensor**
- **Digital GPIO**
- **Embedded Systems**

---

## 👨‍💻 Author

**Sohan Ghosh**  
Electronics & Communication Engineering

---

## ⭐ Project Summary

This project is a beginner-friendly implementation of a **PIR-based motion detection and alarm system**. It demonstrates the fundamentals of **sensor interfacing, digital input processing, GPIO control, and embedded-system programming using Arduino Uno R3**.
