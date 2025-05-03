#include <Servo.h>

// Pins configuration
const int trigPin = 9;
const int echoPin = 8;
const int ledPin = 13;  // Built-in LED (L)
const int speakerPin = 5; // Speaker connected to pin 5 (PWM capable)

// Servo configuration
Servo myServo;
const int servoPin = 7;
const int servoSpeed = 5;  // Speed control (lower is faster)

// Detection parameters
const int maxDistance = 200; // Maximum reliable distance in cm (up to 400cm theoretically)
const int alertDistance = 20; // Distance threshold for alert (adjust as needed)

// Alarm tones
const int alarmTone = 1000; // Frequency in Hz
const int alarmDuration = 200; // Duration in ms

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
  
  // Speaker setup
  pinMode(speakerPin, OUTPUT);
  
  // Serial monitor
  Serial.begin(9600);
  Serial.println("Object Detection System Initialized");
}

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void loop() {
  // Get distance measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH, 30000); // Timeout after 30ms (≈500cm)
  distance = duration * 0.034 / 2;
  
  // Handle out-of-range readings
  if (duration == 0) {
    distance = maxDistance + 1; // No object detected
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Object detection logic
  if (distance <= alertDistance && distance > 0) {
    // Emergency stop with LED blinking and alarm
    while (distance <= alertDistance && distance > 0) {
      // Blink LED and play alarm (frequency increases as object gets closer)
      int dynamicTone = map(distance, 0, alertDistance, 2000, 800);
      digitalWrite(ledPin, HIGH);
      playTone(dynamicTone, alarmDuration);
      digitalWrite(ledPin, LOW);
      playTone(dynamicTone, alarmDuration);
      
      // Keep checking distance
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH, 30000);
      distance = duration * 0.034 / 2;
      if (duration == 0) distance = maxDistance + 1;
      
      Serial.print("ALERT! Object at: ");
      Serial.print(distance);
      Serial.println(" cm");
    }
  } 
  else {
    // Continuous 180 degree sweeping
    digitalWrite(ledPin, LOW);
    noTone(speakerPin);
    
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
    
    delay(50);
  }
}
