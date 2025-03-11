int blueLED = 11;
int redLED = 12;
int buttonPin = 2;

volatile int buttonState;

void setup() {
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin),ISR_button, CHANGE);
}

void ISR_button() {
  buttonState = digitalRead(buttonPin);
  digitalWrite(blueLED, !buttonState);
}

void loop() {
  digitalWrite(redLED, HIGH);
  delay(500);
  digitalWrite(redLED, LOW);
  delay(500);
}
