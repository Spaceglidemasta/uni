
#define PIN_3 3
#define PIN_4 4


void setup() {
  
  Serial.begin(9600);
  Serial.println("Hello this is a reaction Test of Luca De Simone");

  pinMode(PIN_3, INPUT_PULLUP);
  pinMode(PIN_4, INPUT_PULLUP);

}

void loop() {

  int time1;
  int time2;
  int result;


  while(digitalRead(PIN_3));

  time1 = micros();

  Serial.println(F("Time 1: %d microseconds", time1));

  while(digitalRead(PIN_4));

  time2 = micros();

  Serial.println(F("Time 2: %d microseconds", time2));

  Serial.println(F("Result: %.6d microseconds", time2 - time1));


  


}
