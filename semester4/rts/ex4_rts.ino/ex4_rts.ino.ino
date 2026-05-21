// Luca De Simone 1592157
// 21.05.2026
// Reaction Test THU
// MIT License
#define LED1  5
#define LED2  6
#define LED3  7
#define LED4  8
#define LED5  9
#define LED6  10
#define LED7  11
#define LED8  12
#define BUTTON 2
#define LED_NUM 8

#define LIGHT_ON_TIME_MS 2
#define STEP_DURATION_uS 60500

void setup() {

  Serial.begin(9600);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);

  pinMode(BUTTON, INPUT_PULLUP);

}

void loop() {

  size_t i = 0;
  for(; i < LED_NUM; i++){
    

    digitalWrite(5 + i, LOW);
    delay(LIGHT_ON_TIME_MS);

    digitalWrite(5 + i , HIGH);
    delayMicroseconds(STEP_DURATION_uS);


  }
  

  while(!digitalRead(BUTTON));



}
