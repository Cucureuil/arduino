int pins[] = {13, 12, 11, 10, 9, 8, 7, 6}; // A, B, C, D, E, F, G, DP

byte digits[][8] = {
  {1, 1, 1, 1, 1, 1, 0, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1, 0}, // 2
  {1, 1, 1, 1, 0, 0, 1, 0}, // 3
  {0, 1, 1, 0, 0, 1, 1, 0}, // 4
  {1, 0, 1, 1, 0, 1, 1, 0}, // 5
  {1, 0, 1, 1, 1, 1, 1, 0}, // 6
  {1, 1, 1, 0, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1, 0}, // 8
  {1, 1, 1, 1, 0, 1, 1, 0}  // 9
};

void setup() {
  for(int i = 0; i < 8; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void displayDigit(int num) {
  for(int i = 0; i < 8; i++) {
    digitalWrite(pins[i], digits[num][i]);
  }
}

void loop() {
  for(int i = 0; i < 10; i++) {
    displayDigit(i);
    delay(1000);
  }
}
