# Object-ultrasonic-sensor-project
Pin Diagram:
ARDUINO UNO/NANO
-----------------
Pin 7  → Servo Signal (Orange/Yellow wire)
Pin 8  → HC-SR04 Echo
Pin 9  → HC-SR04 Trig
Pin 13 → Built-in LED (L)
5V     → Servo Power (Red wire) + HC-SR04 VCC
GND    → Servo Ground (Brown wire) + HC-SR04 GND
Circuit Diagram (Text Representation):
+-------------------+       +-----------------+
|   ARDUINO UNO     |       |    HC-SR04      |
|                   |       |                 |
| 5V---------------►|-------|VCC              |
|                   |       |                 |
| GND--------------►|-------|GND              |
|                   |       |                 |
| Pin 9------------►|-------|TRIG             |
|                   |       |                 |
| Pin 8◄------------|-------|ECHO             |
|                   |       +-----------------+
| Pin 7------------►|-----+ 
|                   |     |
| Pin 13 (LED)      |     | 
+-------------------+     | 
                          | 
                    +-----v-----+
                    |   SERVO   |
                    |           |
                    | Orange ◄-+ (Signal)
                    |           |
                    | Red---(+)  |
                    |           |
                    | Brown-(-) |
                    +-----------+
Components Needed:
Arduino Uno/Nano

HC-SR04 Ultrasonic Sensor

Servo Motor (SG90 or similar)

Breadboard (optional)

Jumper wires

Connection Details:
Servo Motor:

Red wire → 5V

Brown/Black wire → GND

Orange/Yellow wire → Pin 7

HC-SR04:

VCC → 5V

GND → GND

TRIG → Pin 9

ECHO → Pin 8

Built-in LED:

Already connected to Pin 13 on Arduino

