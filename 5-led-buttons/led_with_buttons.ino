const int BTN_ON = 7;
const int BTN_OFF = 8;
const int OUTPUT_SIGNAL = 4;

void setup() {
  pinMode(BTN_ON, INPUT);
  pinMode(BTN_OFF, INPUT);
  pinMode(OUTPUT_SIGNAL, OUTPUT);
  Serial.begin(9600);
}

bool current_state = LOW;

void loop() {
  const bool on_signal = digitalRead(BTN_ON);
  const bool off_signal = digitalRead(BTN_OFF);
  if(on_signal == HIGH && off_signal == HIGH) {
    return;
  } 
  
  if(on_signal == HIGH) {
    current_state = HIGH;
  } else if(off_signal == HIGH) {
    current_state = LOW;
  }
  
  digitalWrite(OUTPUT_SIGNAL, current_state);
}
