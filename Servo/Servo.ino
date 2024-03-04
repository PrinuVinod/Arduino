#include <Servo.h>

Servo servoX;
Servo servoY;

bool servosMoving = false;
bool clockwiseMovement = true;

void setup() {
  Serial.begin(9600);
  servoX.attach(9);
  servoY.attach(10);
  
  servoX.write(180);
  servoY.write(180);
}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    
    Serial.println(data);

    int xCoord = data.substring(0, data.indexOf(',')).toInt();
    int yCoord = data.substring(data.indexOf(',') + 1).toInt();

    if (!servosMoving) {
      moveServo(servoX, clockwiseMovement ? 360 : 0);
      moveServo(servoY, clockwiseMovement ? 360 : 0);
      servosMoving = true;
    }

    if (servosMoving && clockwiseMovement) {
      moveServo(servoX, 0);
      moveServo(servoY, 0);
      delay(1000);
      clockwiseMovement = false;
    } else {
      moveServo(servoX, 180);
      moveServo(servoY, 180);
    }
  }
}

void moveServo(Servo &servo, int angle) {
  angle = constrain(angle, 0, 360);
  servo.write(angle);
  delay(15);
}
