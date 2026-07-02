
#define POT A0
#define PART2 A1

#define LEDS 3


void setup() {
  Serial.begin(20000000);

}

void loop() {
  Serial.println(analogRead(PART2), DEC);
  analogWrite(LEDS, analogRead(POT) / 4);
}
