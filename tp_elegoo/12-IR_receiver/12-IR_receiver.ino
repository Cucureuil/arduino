int pin = 11;

void setup() {
  Serial.begin(9600);
  pinMode(pin, INPUT);
}

bool isDurationValid(unsigned long duration) {
  return duration < 2500;
}

/**
 * Protocol :
 * 0 : < 1000us
 * 1 : > 1000us
 */
int getBitFromDuration(unsigned long duration) {
  return duration > 1000 ? 1 : 0;
}

/**
 * IR Receiver protocol send 64 bits of data :
 * 32bits for address
 * 32bits for command
 * + 8 bits of checksum
 */
void receiveData(unsigned long long &data, int &index) {
  bool previousState = digitalRead(pin);
  unsigned long startTime = micros();
  unsigned long duration = 0;
  
  while (index < 64 || micros() - startTime < 3000) {
    bool currentState = digitalRead(pin);
    if (currentState != previousState) {
      duration = micros() - startTime;

      previousState = currentState;
      if (isDurationValid(duration)) {
        data = (data << 1) | getBitFromDuration(duration);
        index++;
      }
      startTime = micros();
    }
  }
}

void loop() {
  // store 64 bits - easy to convert to HEX
  unsigned long long data = 0;
  int index = 0;
  
  receiveData(data, index);

  if (index >= 64) {
    unsigned long address = (data >> 32) & 0xFFFFFFFF;
    unsigned long command = data & 0xFFFFFFFF;

    Serial.print("Adresse extraite : 0x");
    Serial.println(address, HEX);

    Serial.print("Commande extraite : 0x");
    Serial.println(command, HEX);

    // TODO - next step : map HEX code and buttons. - Control LEDS with controller :D 
  }
}
