#include <Servo.h>

// Define servo motor
Servo myServo;

// Define servo motor pin
int servoPin = 9;

// Define LED pin
int ledPin = 13;

// Variable to store received command
String command;

void setup() {
  // Attach the servo to the specified pin
  myServo.attach(servoPin);

  // Initialize LED pin as an output
  pinMode(ledPin, OUTPUT);

  // Start Serial communication
  Serial.begin(9600);
}

void loop() {
  // Check if there is data available to read
  if (Serial.available() > 0) {
    // Read the incoming command
    command = Serial.readStringUntil('\n');

    // Process the command
    if (command == "WeedDetected") {
      // Your code for servo and LED control when weed is detected
      for (int angle = 0; angle <= 360; angle++) {
        myServo.write(angle);
        delay(10);
      }

      // Pause at the maximum rotation position
      delay(1000);

      // Rotate the servo counterclockwise
      for (int angle = 360; angle >= 0; angle--) {
        myServo.write(angle);
        delay(10);
      }

      // Pause at the minimum rotation position
      delay(1000);

      // Blink the LED to indicate weed detection
      digitalWrite(ledPin, HIGH);
      delay(500);
      digitalWrite(ledPin, LOW);
    }
  }
  
  // Your existing servo and LED control code (without weed detection)
  // Rotate the servo clockwise
  for (int angle = 0; angle <= 360; angle++) {
    myServo.write(angle);
    delay(10);
  }

  // Pause at the maximum rotation position
  delay(1000);

  // Rotate the servo counterclockwise
  for (int angle = 360; angle >= 0; angle--) {
    myServo.write(angle);
    delay(10);
  }

  // Pause at the minimum rotation position
  delay(1000);
}
