const int xPin = A0;
const int yPin = A1;
const int btnPin = 2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("x:");
  Serial.println(analogRead(xPin));
  Serial.print("y:");
  Serial.println(analogRead(yPin));
  Serial.print("btn:");
  Serial.println(digitalRead(btnPin));
}
