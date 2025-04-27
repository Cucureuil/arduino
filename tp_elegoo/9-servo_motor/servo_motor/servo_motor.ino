#include <Servo.h>

const Servo myServo;

const int SERVO_PIN = 9;

void setup() {
  pinMode(SERVO_PIN, OUTPUT);
  myServo.attach(SERVO_PIN);
  myServo.write(0);
}

void loop() {
  for (int i=0;i<=180;i++) {
    myServo.write(i);f:\projet-arduino\arduino\tp_elegoo\12-IR_receiver\12-IR_receiver.ino
    delay(5);
  }
   for (int i=180;i>=0;i--) {
    myServo.write(i);
    delay(5);
  }
  delay(1000);
  myServo.write(50);
  delay(100);
  myServo.write(100);
  delay(100);
  myServo.write(150);
  delay(100);
  myServo.write(0);
  delay(1000);
}
