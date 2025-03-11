#include <Servo.h>
 
/**
 * tp from @RachelDeBarros
 */

int redLED = 11;
int blueLED = 5;
int greenLED = 9;
int buttonPin = 7;
int servoPin = 6;

// red
unsigned long blinkPreviousMillis = 0;
const unsigned long blinkPeriod = 500;

// blue
unsigned long fadePreviousMillis = 0;
const unsigned long fadePeriod = 10;
byte brightness = 0;
byte fadeIncrement = 1;

// green
unsigned long togglePreviousMillis = 0;
const unsigned long togglePeriod = 100;

// servo
int servoIncrement = 1;
int servoPos = 0;
unsigned long servoPreviousMillis = 0;
const unsigned long servoPeriod = 100;

Servo servo;

unsigned long currentMillis = 0;

void blinkLED() {
  if(currentMillis - blinkPreviousMillis >= blinkPeriod) {
    blinkPreviousMillis = currentMillis;
    digitalWrite(redLED, !digitalRead(redLED));  
  }
}

void fadeLED() {
  if(currentMillis - fadePreviousMillis >= fadePeriod) {
    fadePreviousMillis = currentMillis;
    
    analogWrite(blueLED, brightness);
    brightness += fadeIncrement;
  }
}

void toggleLED() {
  if(currentMillis - togglePreviousMillis > togglePeriod) {
    togglePreviousMillis = currentMillis;

    digitalWrite(greenLED, !digitalRead(buttonPin));
  }
}

void servoSweep() {
  if(currentMillis - servoPreviousMillis > servoPeriod) {
    servoPreviousMillis = currentMillis;
    
    if(servoPos >= 180) {
      servoIncrement = -1;
    } else if(servoPos <= 0) {
      servoIncrement = 1;
    }

    servoPos +=servoIncrement;
    
    servo.write(servoPos);
  }
}

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(servoPin, OUTPUT);
  servo.attach(servoPin);
}

void loop() {
  currentMillis = millis();
  blinkLED();
  fadeLED();
  toggleLED();
  servoSweep();
}
