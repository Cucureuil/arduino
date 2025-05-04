int LED = 9;

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  Serial.begin(9600); 
}

int intensity = 0;

void loop() {
  int potentiometer = analogRead(A0);
  int convertedValue = map(potentiometer, 0, 1023, 0, 255);

  Serial.println(potentiometer);

  if(potentiometer == 90) {
    analogWrite(LED, 0);
  } else {
    analogWrite(LED, convertedValue);
  }
  

  delay(500);      
}