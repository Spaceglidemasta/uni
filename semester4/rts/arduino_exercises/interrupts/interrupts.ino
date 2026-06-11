// Luca De Simone 1592157
// 11.06.2026
// Interrupt Lights program. Switches between modes by pressing button



volatile bool g_blinkstate = false;
volatile unsigned long last_interrupt_time = 0;
volatile bool printedstatic = false;


#define BUTTON 2

void changeMode() {
  unsigned long currentTime = millis();
  
  if (currentTime - last_interrupt_time > 100) {
    g_blinkstate = !g_blinkstate;
    last_interrupt_time = currentTime;
  }
}

void blinkingLights() {

  printedstatic = false;
  Serial.println("Blinking...");

  for (size_t i = 5; i <= 12; i++) {
    digitalWrite(i, HIGH);
  }

  while (g_blinkstate) {

    for (size_t i = 5; i <= 12 && g_blinkstate; i++) {
      digitalWrite(i, LOW);
      delayMicroseconds(2500);
      digitalWrite(i, HIGH);
      delay(60);
    }
  }
}

void staticLights() {

  if(!printedstatic) {
    Serial.println("Static...");
    printedstatic = true;
  }


  for (size_t i = 6; i <= 11; i++) {
    digitalWrite(i, HIGH);
  }

  digitalWrite(5, LOW);
  digitalWrite(12, LOW);
}

void setup() {

  Serial.begin(9600);

  for (size_t i = 5; i <= 12; i++) {
    pinMode(i, OUTPUT);
  }

  pinMode(BUTTON, INPUT_PULLUP);

  attachInterrupt(
    digitalPinToInterrupt(BUTTON),
    changeMode,
    FALLING
  );

  changeMode();
}

void loop() {

  if (g_blinkstate) {
    blinkingLights();
  } else {
    staticLights();
  }
}