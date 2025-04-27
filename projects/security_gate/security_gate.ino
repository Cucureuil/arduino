#include <Servo.h>

const Servo myServo;

const int SERVO_PIN = 9;
const int LASER_PIN = 7;
const int LASER_DETECTOR_PIN = A0;

const int GREEN_LED_PIN = 2;


void setup() {
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(SERVO_PIN, OUTPUT);

  myServo.attach(SERVO_PIN);
  myServo.write(90);

  pinMode(LASER_PIN, OUTPUT);
  digitalWrite(LASER_PIN, HIGH);

  Serial.begin(9600);
}

bool isSignalInterrupted(int laserSignal) {
  // at the initialization of the program, set the real value of the photosensor as the default value (replace 100)
  // to avoid bug if we change the context
  return laserSignal > 100;
}

bool isGateOpen = true;
int openPos = 180;
int closePos = 85;
void closeGate() {
  if(isGateOpen) {
    digitalWrite(GREEN_LED_PIN, LOW);
    Serial.println("Closing gate...");
    // get current servo pos to check state before doing anything
    for(int i = openPos; i > closePos; i--){
      myServo.write(i);
    }
    Serial.println("Gate is closed now.");
    isGateOpen = false;
  }
}
void openGate() {
  Serial.println("Opening gate...");
  for(int i = closePos; i < openPos; i++){
      myServo.write(i);
  }
  digitalWrite(GREEN_LED_PIN, HIGH);
  Serial.println("Gate is opened now.");
  isGateOpen = true;
}

void loop() {
  const int laserSignal = analogRead(LASER_DETECTOR_PIN);
  Serial.println(laserSignal);

  if(isSignalInterrupted(laserSignal)) {
    openGate();
  } else {
    closeGate();
  }

  delay(500);
}
