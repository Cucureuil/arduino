void setup() {
  Serial.begin(9600);
}

const float U_REF = 5;
const float MAX_ANALOG = 1024;
const float R1 = 220;

void loop() {
  // lire a0
  const float a0 = analogRead(A0);
  // Serial.println(a0);
  // convertir l'input analogique en volt
  const float u2 = a0 * (U_REF / MAX_ANALOG);
  // calcul de la valeur de la résistance
  const float r2 = ( R1 * u2 ) / ( U_REF - u2 );
  Serial.print(r2);
  Serial.println(" ohm");
}
