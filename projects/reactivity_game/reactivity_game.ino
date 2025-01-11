const int RED_PIN = 5;
const int YELLOW_PIN = 4;
const int GREEN_PIN = 3;
const int BUZZER_PIN = 6;
const int START_BTN_PIN = 7;

const int PLAYER_ONE_BTN = 8;
const int PLAYER_ONE_LED = 11;

const int PLAYER_TWO_BTN = 9;
const int PLAYER_TWO_LED = 10;

const int BEEP_START_FREQUENCY = 496; 
const int BEEP_WAITING_FREQUENCY = 261;

void setup() {
  Serial.begin(9600);
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(START_BTN_PIN, INPUT_PULLUP);

  pinMode(PLAYER_ONE_BTN, INPUT_PULLUP);
  pinMode(PLAYER_TWO_BTN, INPUT_PULLUP);

  pinMode(PLAYER_ONE_LED, OUTPUT);
  pinMode(PLAYER_TWO_LED, OUTPUT);
}

/**
* Utils
*/
bool hasBtnBeenPressed(int btnPin) {
  return digitalRead(btnPin) == LOW;
}

void beep(unsigned int frequency, unsigned long duration) {
  tone(BUZZER_PIN, frequency, duration);
}

void turnOnLED(int pin) {
  digitalWrite(pin, HIGH);
  beep(BEEP_WAITING_FREQUENCY, 500);
}

void turnOffLED(int pin) {
  digitalWrite(pin, LOW);
}

/**
* Methods
*/
void turnOffAllCountdownLED() {
  turnOffLED(RED_PIN);
  turnOffLED(YELLOW_PIN);
  turnOffLED(GREEN_PIN);
  beep(BEEP_START_FREQUENCY, 1000);
}

void countdown() {
  turnOffLED(PLAYER_ONE_LED);
  turnOffLED(PLAYER_TWO_LED);

  turnOnLED(RED_PIN);
  delay(1000);
  turnOnLED(YELLOW_PIN);
  delay(1000);
  turnOnLED(GREEN_PIN);
  delay(1000);
  turnOffAllCountdownLED();

  turnOnLED(PLAYER_ONE_LED);
  turnOnLED(PLAYER_TWO_LED);
}

void resetGame() {
  beep(BEEP_START_FREQUENCY, 150);
  delay(150);
  beep(BEEP_START_FREQUENCY, 150);
}

void playerLost(int loserLed) {
  turnOffLED(loserLed);
  beep(BEEP_START_FREQUENCY, 500);
}

void equality() {
  turnOnLED(PLAYER_ONE_LED);
  turnOnLED(PLAYER_TWO_LED);
  delay(150);
  turnOffLED(PLAYER_ONE_LED);
  turnOffLED(PLAYER_TWO_LED);
  delay(150);
  turnOnLED(PLAYER_ONE_LED);
  turnOnLED(PLAYER_TWO_LED);
}

bool updateGameState(bool playerOneBtn, bool playerTwoBtn) {
  if(!playerOneBtn && !playerTwoBtn) {
    return false;
  }

  if(playerOneBtn && playerTwoBtn) {
    equality();
  } else if(playerOneBtn) {
    playerLost(PLAYER_TWO_LED);
  } else if(playerTwoBtn) {
    playerLost(PLAYER_ONE_LED);
  }

  return true;
}

void loop() {
  bool btnStartHasBeenPressed = hasBtnBeenPressed(START_BTN_PIN);
  if(btnStartHasBeenPressed) {
    countdown();

    bool gameIsOver = false;
    while(!gameIsOver) {
      bool btnPlayerOneBeenPressed = hasBtnBeenPressed(PLAYER_ONE_BTN);
      bool btnPlayerTwoBeenPressed = hasBtnBeenPressed(PLAYER_TWO_BTN);

      gameIsOver = updateGameState(btnPlayerOneBeenPressed, btnPlayerTwoBeenPressed);
    }

    resetGame();
  }
}
