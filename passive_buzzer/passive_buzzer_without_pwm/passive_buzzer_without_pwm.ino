
const int buzzerPin = 3;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

const int DO = 1910;
const int RE = 1695;
const int MI = 1505;
const int FA = 1430;
const int SOL = 1270;
const int LA = 1130;
const int SI = 1005;

const int SHORT = 250;

void playNote(int noteFrequencyInUs) {
  unsigned long startTime = millis();
  while(millis() - startTime < SHORT) {
    digitalWrite(buzzerPin, HIGH);
    delayMicroseconds(noteFrequencyInUs);
    digitalWrite(buzzerPin, LOW);
    delayMicroseconds(noteFrequencyInUs);
  }
  delay(50);
}

void loop() {
  playNote(DO);
  playNote(RE);
  playNote(MI);
  delay(SHORT);
  playNote(MI);
  playNote(MI);
  playNote(MI);
  delay(SHORT);
  playNote(MI);
  playNote(FA);
  playNote(SOL);
  delay(SHORT);
  playNote(SOL);
  playNote(SOL);
  playNote(SOL);
  delay(SHORT);
  playNote(FA);
  playNote(MI);
  playNote(RE);
  delay(SHORT);
  playNote(RE);
  playNote(RE);
  playNote(RE);
  delay(SHORT);
  playNote(MI);
  playNote(RE);
  playNote(DO);
  delay(SHORT);
  playNote(DO);
  playNote(DO);
  playNote(DO);
  delay(SHORT);
}
