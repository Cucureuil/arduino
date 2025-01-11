const int TILT_BALL_PIN = 2;
const int LED_PIN = 4;

void setup() {
  Serial.begin(9600);
  pinMode(TILT_BALL_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  // important to set, if not the led blinks
  digitalWrite(TILT_BALL_PIN, HIGH);
}

void loop() {
  const int tiltBallState = digitalRead(TILT_BALL_PIN);
  if(tiltBallState) {
    digitalWrite(LED_PIN, LOW);
  } else {
     digitalWrite(LED_PIN, HIGH);
  }
  Serial.println(tiltBallState);
}
