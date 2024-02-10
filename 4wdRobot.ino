#include <SoftwareSerial.h>
#include <AFMotor.h>

SoftwareSerial BTSerial(0, 1); // RX | TX
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

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
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  Serial.println(" Forward");
}

void moveBackward() {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  Serial.println(" Backward");
}

void moveLeft() {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  Serial.println(" Left");
}

void moveRight() {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  Serial.println(" Right");
}

void stopMotors() {
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  Serial.println(" STOP");
}
