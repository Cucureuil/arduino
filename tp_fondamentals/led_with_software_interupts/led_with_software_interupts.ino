#include <TimerOne.h>

int blueLED = 10;
int redLED = 12;

void blinkBlue() {
  digitalWrite(blueLED, !digitalRead(blueLED));  
}

void setup() {
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(blinkBlue);
}

void loop() {
  digitalWrite(redLED, HIGH);
  delay(500);
  digitalWrite(redLED, LOW);
  delay(500);
}
