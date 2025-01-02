
const int buzzerPin = 3;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

const int DO = 261;
const int RE = 294;
const int MI = 331;
const int FA = 348;
const int SOL = 392;
const int LA = 441;
const int SI = 496;

const int SHORT = 250;

void playNote(int noteFrequency) {
  tone(buzzerPin, noteFrequency, SHORT);
  delay(SHORT);
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
