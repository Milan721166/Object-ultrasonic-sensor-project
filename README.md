# Arduino Object Detection System with Ultrasonic Sensor

![Project Banner](https://github.com/user-attachments/assets/f3bf87c7-a2a9-4dfc-bbbd-3ec22787f845)

A smart object detection system using Arduino Uno, HC-SR04 ultrasonic sensor, servo motor, and alarm speaker. Detects objects within adjustable range and triggers visual/audio alerts.

## Features
- 180° servo scanning motion
- Adjustable detection range (up to 4m)
- Dynamic alarm tone (pitch changes with distance)
- Serial monitor feedback
- Emergency stop when objects detected

## Components
| Component | Quantity |
|-----------|----------|
| Arduino Uno | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| SG90 Servo Motor | 1 |
| 8Ω Speaker/Piezo Buzzer | 1 |
| Jumper Wires | 10+ |
| Breadboard | 1 |

## Pin Connections
![Pin Diagram](https://github.com/user-attachments/assets/34195ef4-2bbe-401b-b672-922530011633)

| Arduino Pin | Connected To |
|-------------|--------------|
| 5V          | HC-SR04 VCC, Servo VCC |
| GND         | HC-SR04 GND, Servo GND, Speaker- |
| D7          | Servo Signal (Orange) |
| D8          | HC-SR04 Echo |
| D9          | HC-SR04 Trig |
| D5          | Speaker+ |
| D13         | Built-in LED |

## Circuit Diagram
![Wiring Schematic](https://github.com/user-attachments/assets/1ddcadfc-929d-4d6c-bb65-dede5c31f07b)

## Installation
1. Clone this repository
2. Upload `ObjectDetection.ino` to Arduino
3. Connect components as per pin diagram
4. Open Serial Monitor (9600 baud)

## Configuration
```cpp
// Adjust these values in code:
const int maxDistance = 200; // Max detection range (cm)
const int alertDistance = 50; // Trigger distance (cm)
const int alarmTone = 1000; // Base alarm frequency (Hz)
