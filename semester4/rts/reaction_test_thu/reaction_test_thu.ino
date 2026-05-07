// Luca De Simone 1592157
// 07.05.2026
// Reaction Test THU
// MIT License

#define PIN_3 3
#define PIN_4 4


void setup() {
  
  Serial.begin(9600);
  Serial.println("Hello this is a reaction Test of Luca De Simone");

  pinMode(PIN_3, INPUT_PULLUP);
  pinMode(PIN_4, INPUT_PULLUP);

}

void loop() {

  unsigned long time1;
  unsigned long time2;
  double        result;

  while (digitalRead(PIN_3));

  time1 = micros();

  Serial.print("Time 1: ");
  Serial.print(time1);
  Serial.println(" microseconds");

  while (digitalRead(PIN_4));

  time2 = micros();

  Serial.print("Time 2: ");
  Serial.print(time2);
  Serial.println(" microseconds");

  result = (time2 - time1) / 1000000.0;

  Serial.print("Result: ");
  Serial.print(result, 6);
  Serial.println(" microseconds");
}