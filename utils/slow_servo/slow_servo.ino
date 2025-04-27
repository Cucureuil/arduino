#include <Servo.h>

const Servo servo;

const int SERVO_PIN =7;

const int start_pos = 90;
const int end_pos = 180;
const int delay_to_slow_servo_animation = 5;

void setup() {
  pinMode(SERVO_PIN, OUTPUT);
  servo.attach(SERVO_PIN);
  servo.write(start_pos);
}

void loop() {
  int i = start_pos;
  unsigned long start_time = millis();
  while(i < end_pos) {
    if(millis() - start_time > delay_to_slow_servo_animation) {
      i++;
      servo.write(i);
      start_time = millis();
    }
  }

  delay(3000);
  
  start_time = millis();
  while(i > start_pos) {
    if(millis() > start_time + delay_to_slow_servo_animation) {
      i--;
      servo.write(i);
      start_time = millis();
    }
  }

  delay(3000);
}
