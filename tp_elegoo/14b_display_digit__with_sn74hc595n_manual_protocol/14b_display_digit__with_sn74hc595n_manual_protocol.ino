int dataPin = 12; // envoie des bits
int latchPin = 11; // à trigger (LOW-> HIGH) quand toutes les données ont été envoyées, pour finaliser la séquence et afficher les données sur le digit
int clockPin = 10; // à trigger (LOW-> HIGH) pour push le bit écrit sur dataPin

// dp g f e d c b a
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

void sendDigits(uint8_t val) {
  uint8_t i;

	digitalWrite(latchPin, LOW);

	for (i = 0; i < 8; i++)  {
    // écriture du bit sur le segment a,b,c,d....
		digitalWrite(dataPin, (val & 128) != 0);
		val <<= 1;
		
    // push du bit
		digitalWrite(clockPin, HIGH);
		digitalWrite(clockPin, LOW);		
	}

  // push des données
	digitalWrite(latchPin, HIGH);
}

void loop() {
  for(int i = 0; i < 10; i++) {
    sendDigits(digits[i]);
    delay(1000);
  }
}
