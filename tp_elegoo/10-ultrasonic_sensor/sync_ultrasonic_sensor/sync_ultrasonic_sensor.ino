const int TRIGGER_PIN = 12;
const int ECHO_PIN = 11;
const float SPEED_OF_SOUND = 0.0343;

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // emits a trigger signal to the module, to start the "detection"
  Serial.println("TRIGGER");
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  // then the module send around 8 cycles of 40khz - echos / like a ping
  // and pulseIn listens and measures the time for echos to come back (/!\ it's a sync function)
  // if an object is in the area, the ECHO_PIN will be in HIGH position
  const long duration = pulseIn(ECHO_PIN, HIGH);
  if(duration > 0 && duration < 40000) {
    const float distance = (duration / 2.0) * SPEED_OF_SOUND;
    Serial.print(distance);
    Serial.println("cm");
  } else {
    Serial.println("Nothing in the area");
  }

  delay(1000);
}
