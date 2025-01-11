const int OUTPUT_PIN = 5;
const int ON_PIN = 9;
const int OFF_PIN = 8;

void setup() {
  pinMode(OUTPUT_PIN, OUTPUT);
  pinMode(ON_PIN, INPUT_PULLUP);
  pinMode(OFF_PIN, INPUT_PULLUP);
}

bool current_state = LOW;

void loop() {
  bool on_btn = digitalRead(ON_PIN);
  bool off_btn = digitalRead(OFF_PIN);

  if(on_btn == LOW) {
    current_state = HIGH;
  } else if (off_btn == LOW) {
    current_state = LOW;
  }

  digitalWrite(OUTPUT_PIN, current_state);
}
