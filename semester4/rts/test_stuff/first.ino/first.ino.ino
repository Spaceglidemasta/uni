#define BUTTON 8
#define RED   2

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(RED, OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:

  while (!digitalRead(BUTTON)) {
    digitalWrite(RED, HIGH);
    Serial.print("Pressed\n");
    delay(1);
  }

  digitalWrite(RED, LOW);

  delay(1);

}
