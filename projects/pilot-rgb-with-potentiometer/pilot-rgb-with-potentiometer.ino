
const int RED = 3;
const int GREEN = 5;
const int BLUE = 6;


void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  Serial.begin(9600); 
}

int redValue = 255;
int greenValue = 0;
int blueValue = 0;
int delayTime = 10;

void loop() {
  int potentiometer = analogRead(A0);
  int convertedValue = map(potentiometer, 0, 1023, 0, 255);

  Serial.println(convertedValue);

  analogWrite(RED, 255 - convertedValue);
  analogWrite(GREEN, convertedValue);

  delay(500);      
}