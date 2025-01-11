
const int LED_ONE = 11;
const int LED_TWO = 10;

std::function<void()> asynchroneBlinkLED(int led, long interval) {
  unsigned long previousBlinkTime = 0;

  return [led, interval, previousBlinkTime]() mutate {
    unsigned long currentTime = millis();
    if(currentTime - previousBlinkTime >= interval) {
      previousBlinkTime = currentTime;
      int ledState = digitalRead(led);
      if(ledState) {
        turnOffLED(led);
      } else {
        turnOnLED(led);
      }
    }
  }
}

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
