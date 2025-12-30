# 🧹 Smart Vacuum Cleaner Robot

An Arduino-based **Smart Vacuum Cleaner Robot** that autonomously navigates indoor environments, avoids obstacles, and simulates intelligent vacuum-cleaning behavior using ultrasonic sensing and servo-based scanning.

---

## 📌 Project Overview

The robot continuously moves forward while cleaning.  
When an obstacle is detected, it:
1. Stops
2. Moves backward slightly
3. Scans the environment (right & left)
4. Chooses the direction with more free space
5. Performs a pivot turn and continues moving

---

## 🧠 Features

- Autonomous navigation
- Obstacle detection and avoidance
- Servo-based scanning system
- Smooth motor acceleration
- Pivot turning for tight spaces
- Arduino Motor Shield control

---

## 🧩 Hardware Requirements

- Arduino Uno
- Arduino Motor Shield (L293D)
- 4 × DC Motors (TT Motors)
- Ultrasonic Sensor (HC-SR04)
- Servo Motor (SG90)
- Battery Pack
- Robot Chassis
- Jumper Wires
- Vacuum motor (optional)

---

## 🔌 Pin Configuration

### Ultrasonic Sensor
| Pin | Arduino |
|----|---------|
| Trig | A0 |
| Echo | A1 |

### Servo Motor
| Pin | Arduino |
|----|---------|
| Signal | D10 |

### Motor Shield
| Motor | Position |
|------|----------|
| M1 | Front Left |
| M2 | Front Right |
| M3 | Back Left |
| M4 | Back Right |

---

## 📚 Required Libraries

Install the following libraries using Arduino Library Manager:

- AFMotor
- NewPing
- Servo

```cpp
#include <AFMotor.h>
#include <NewPing.h>
#include <Servo.h>
