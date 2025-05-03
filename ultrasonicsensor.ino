#include <Servo.h>

// Pins configuration
const int trigPin = 9;
const int echoPin = 8;
const int ledPin = 13;  // Built-in LED (L)

// Servo configuration
Servo myServo;
const int servoPin = 7;
const int servoSpeed = 5;  // Speed control (lower is faster)

// Variables
long duration;
int distance;
int currentAngle = 0;  // Start at 0 degrees
int sweepDirection = 1;  // 1 for increasing, -1 for decreasing

void setup() {
  // Sensor setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Servo setup
  myServo.attach(servoPin);
  myServo.write(currentAngle);
  
  // LED setup
  pinMode(ledPin, OUTPUT);
  
  // Serial monitor
  Serial.begin(9600);
}

void loop() {
  // Get distance measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Object detection logic
  if (distance < 10 && distance > 0) {
    // Emergency stop with LED blinking
    while (distance < 10 && distance > 0) {
      // Blink LED
      digitalWrite(ledPin, HIGH);
      delay(200);
      digitalWrite(ledPin, LOW);
      delay(200);
      
      // Keep checking distance
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance = duration * 0.034 / 2;
      
      Serial.print("ALERT! Object at: ");
      Serial.print(distance);
      Serial.println(" cm");
    }
  } 
  else {
    // Continuous 180 degree sweeping
    digitalWrite(ledPin, LOW);  // Ensure LED is off
    
    // Move servo
    currentAngle += sweepDirection * servoSpeed;
    myServo.write(currentAngle);
    
    // Change direction at limits
    if (currentAngle >= 180) {
      sweepDirection = -1;
      currentAngle = 180;
    } 
    else if (currentAngle <= 0) {
      sweepDirection = 1;
      currentAngle = 0;
    }
    
    delay(50);  // Control sweep speed
  }
}
