int dhtPin = 2;

void setup() {
  Serial.begin(9600);
}

/**
* To start communication with DHT11, we have to send a LOW signal for 20ms and a HIGH signal for 40us
*/
void initCommunication() {
  pinMode(dhtPin, OUTPUT);
  digitalWrite(dhtPin, LOW);
  delay(20); 
  digitalWrite(dhtPin, HIGH);
  delayMicroseconds(40); 
  pinMode(dhtPin, INPUT); 
}

/**
* We're only interested by signal between 18us and 80 us
*/
bool isAValidSignal(unsigned long time, bool state) {
  return state == LOW && (time >= 10 && time < 80);
}

/**
* Register 40 bits - 5 octets
*/
void registerCommunication(int (&durations)[40], int (&index)){
  unsigned long startTime = micros();
  bool lastState = digitalRead(dhtPin);

  while (micros() - startTime < 5000 && index < 40) {
    bool currentState = digitalRead(dhtPin);
    if (currentState != lastState) {
      unsigned long time = micros() - startTime;
      if(isAValidSignal(time, currentState)) {  
        durations[index] = time;
        index++;
      }
      startTime = micros();
      lastState = currentState;
    }
  }
}

/**
* 0 - ~20us
* 1 - ~70us
*/
uint8_t transformSignalToBit(int signal) {
  if(signal <= 35) {
    return 0;
  } else {
    return 1;
  }
}

/**
* Converts durations (signals) to bits (octet) 
* and bit to int / readable values (temperature and humidity)
*/
void transformSignalsToValues(int (&signals)[40], uint8_t (&values)[5]) {
  uint8_t result = 0;
  int curr = 0;
  for (int i = 0; i < 40; i++) {
      result <<= 1;             
      result |= transformSignalToBit(signals[i]);
      if(i != 0 && (i+1) % 8 == 0){
        values[curr] = result;
        curr++;
        result = 0;
      }
  }
}

/**
* Displays temperature and humidity like : 
*  -----
*  Humidity : 43.0%
*  Temperature : 24.4°C
*  -----
*/
void displayTempAndHumidity(uint8_t values[5]) {
  Serial.print("Humidity : ");
  Serial.print(values[0]);
  Serial.print(".");
  Serial.print(values[1]);
  Serial.println("%");

  Serial.print("Temperature : ");
  Serial.print(values[2]);
  Serial.print(".");
  Serial.print(values[3]);
  Serial.println("°C");

  Serial.println("-----");
}

void loop() {
  initCommunication();

  int durations[40];
  int index = 0;
  registerCommunication(durations, index);
  
  uint8_t values[5];
  transformSignalsToValues(durations, values);
  displayTempAndHumidity(values);

  delay(10000);
}