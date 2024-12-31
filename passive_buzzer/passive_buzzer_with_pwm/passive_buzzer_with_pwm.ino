
const int buzzerPin = 3;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  analogWrite(buzzerPin, 128);
  delay(1000);
  analogWrite(buzzerPin, 0);
  delay(1000);
}
