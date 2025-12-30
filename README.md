# 🧹 Smart Vacuum Cleaner Robot  
### Autonomous Mobile Robot for Indoor Cleaning  
**Academic / Graduation Project**

---

## 📌 Abstract

This project presents the design and implementation of a **Smart Vacuum Cleaner Robot** based on **Arduino Uno**.  
The robot autonomously navigates indoor environments, detects obstacles using an ultrasonic sensor, and makes real-time decisions to avoid collisions while simulating vacuum-cleaning behavior.

The system uses a **servo-mounted ultrasonic sensor** to scan left and right directions and applies a simple yet effective decision-making algorithm to select the safest path.

---

## 🎯 Objectives

- Design an autonomous mobile robot for indoor environments  
- Implement obstacle detection and avoidance  
- Apply intelligent navigation logic  
- Use low-cost and easily available hardware components  
- Simulate real-world robotic vacuum cleaner behavior  

---

## 🧠 System Features

- Autonomous navigation without human intervention  
- Obstacle detection using HC-SR04 ultrasonic sensor  
- Servo-based scanning (Left / Center / Right)  
- Pivot turning for efficient movement in narrow spaces  
- Smooth motor acceleration  
- Modular and scalable design  

---

## 🧩 Hardware Components

| Component | Description |
|---------|-------------|
| Arduino Uno | Main microcontroller |
| Arduino Motor Shield (L293D) | Motor driver |
| DC Motors (4× TT motors) | Robot movement |
| Ultrasonic Sensor (HC-SR04) | Obstacle detection |
| Servo Motor (SG90) | Sensor rotation |
| Battery Pack | Power supply |
| Robot Chassis | Mechanical structure |
| Vacuum Motor (Optional) | Cleaning simulation |

---

## 🔌 Pin Configuration

### Ultrasonic Sensor
| Signal | Arduino Pin |
|------|-------------|
| Trig | A0 |
| Echo | A1 |

### Servo Motor
| Signal | Arduino Pin |
|------|-------------|
| PWM | D10 |

### DC Motors (Motor Shield)
| Motor | Position |
|------|----------|
| M1 | Front Left |
| M2 | Front Right |
| M3 | Back Left |
| M4 | Back Right |

---

## 📷 System Images

### 🔧 Hardware Setup
![WhatsApp Image 2025-12-29 at 1 23 46 AM](https://github.com/user-attachments/assets/eff1d0d2-d468-4b42-8a0d-d260b1f2654d)



## 📚 Software Requirements

### Libraries Used
- AFMotor  
- NewPing  
- Servo  

```cpp
#include <AFMotor.h>
#include <NewPing.h>
#include <Servo.h>



