#include <SoftwareSerial.h>
#include <AFMotor.h>

SoftwareSerial BTSerial(0, 1); // RX | TX
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

void setup() {
  BTSerial.begin(9600);
  Serial.begin(9600);

}


void loop() {
  if (BTSerial.available()) {
    char cmd = BTSerial.read();
    Command(cmd);
  }
}

void Command(char cmd) {
  switch (cmd) {
    case 'L':
      moveForward();
      break;
    case 'R':
      moveBackward();
      break;
    case 'F':
      moveLeft();
      break;
    case 'B':
      moveRight();
      break;
    default:
      stopMotors();
  }
}

void moveForward() {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
    motor1.run(FORWARD);
  motor2.run(FORWARD);
  Serial.println(" Forward");
}

void moveBackward() {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  Serial.println(" Backward");
}

void moveLeft() {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  Serial.println(" Left");
}

void moveRight() {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  Serial.println(" Right");
}

void stopMotors() {
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  Serial.println(" STOP");
}
