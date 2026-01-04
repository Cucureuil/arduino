int dataPin = 12;
int latchPin = 11;
int clockPin = 10;

byte digits[10] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111  // 9
};

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void displayDigit(byte num) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, digits[num]);
  digitalWrite(latchPin, HIGH);
}

void loop() {
  for(int i = 0; i < 10; i++) {
    displayDigit(i);
    delay(1000);
  }
}
