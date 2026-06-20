// Luca De Simone 1592157
// 18.06.2026
// ApproachLights2

// debug print loop times
#define TIMECHECK false

#define AREAD A0
#define BUTTON1 2
#define BUTTON2 3
#define LED1 5
#define LED2 6
#define LED3 7
#define LED4 8
#define LED5 9
#define LED6 10
#define LED7 11
#define LED8 12

#define ON_TIME_MS 2

#define ON LOW
#define OFF HIGH

int Leds[] = {LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8};

typedef enum { RUN, CONFIG } Mode;

const unsigned long DebounceTime{500};
volatile bool Button1Pressed{false};
volatile bool Button2Pressed{false};
unsigned long LastButton1PressedTime{0};
unsigned long LastButton2PressedTime{0};

int LedSequenceState[] = {0, 0};
int LedCount;
Mode mode{RUN};

unsigned long OffTime_MS = 0;
unsigned int OffTime_MICROSECONDS = 0;

int GetLedCount() { return (analogRead(AREAD)) / 128 + 1; }

void SetLedCount(int count) {
	LedCount = count;
	double FOffTime = 500.0 / LedCount - ON_TIME_MS;
	OffTime_MS = (unsigned long)FOffTime;
	OffTime_MICROSECONDS = round((FOffTime - OffTime_MS) * 1000);
}

void OnButton1Pressed() { Button1Pressed = true; }
void OnButton2Pressed() { Button2Pressed = true; }

void setup() {
	Serial.begin(9600);
	for (int Led : Leds) {
		pinMode(Led, OUTPUT);
		digitalWrite(Led, OFF);
	}
	pinMode(BUTTON1, INPUT_PULLUP);
	pinMode(BUTTON2, INPUT_PULLUP);

	attachInterrupt(digitalPinToInterrupt(BUTTON1), OnButton1Pressed, FALLING);
	attachInterrupt(digitalPinToInterrupt(BUTTON2), OnButton2Pressed, FALLING);

	SetLedCount(8);
}

unsigned long LastTimeCheckTime = 0;
void LedSequence(int Led, int SequenceState) {
	switch (SequenceState) {
	case 0:
		break;

	case 1:
		digitalWrite(Led, ON);
		break;

	case 2:
		delay(ON_TIME_MS);
		break;

	case 3:
		digitalWrite(Led, OFF);
		break;

	case 4:
		delay(OffTime_MS);
		delayMicroseconds(OffTime_MICROSECONDS);

		// TimeCheck -> 500ms +-1
		if (Led == Leds[LedCount - 1] && TIMECHECK) {
			const unsigned long TimeCheckTime = millis();
			Serial.print(TimeCheckTime - LastTimeCheckTime);
			Serial.println("ms");
			LastTimeCheckTime = TimeCheckTime;
		}
		if (Led == Leds[LedCount - 1]) {
			Serial.print(analogRead(AREAD));
			Serial.print(" - LedCount: ");
			Serial.println(LedCount);
		}
		break;
	}
}

void loop() {
	
	if (Button1Pressed) {
		Button1Pressed = false;
		const unsigned long Button1PressedTime = millis();

		if ((Button1PressedTime - LastButton1PressedTime) > DebounceTime) {
			mode = RUN;
			Serial.println("MODE: RUN");
			LastButton1PressedTime = Button1PressedTime;
		}
	}

	if (Button2Pressed) {
		Button2Pressed = false;
		const unsigned long Button2PressedTime = millis();

		if ((Button2PressedTime - LastButton2PressedTime) > DebounceTime) {
			mode = CONFIG;
			Serial.println("MODE: CONFIG");
			LastButton2PressedTime = Button2PressedTime;
		}
	}

	switch (mode) {
	case CONFIG:
		SetLedCount(GetLedCount());
		Serial.print(analogRead(AREAD));
		Serial.print(" - LedCount: ");
		Serial.println(LedCount);
		for (int i = 0; i < 8; i++) {
			digitalWrite(Leds[i], i < LedCount ? ON : OFF);
		}
		break;

	case RUN:
		// Led Sequence
		for (int i = 0; i < LedCount; i++) {
			if (i != LedSequenceState[0]) {
				digitalWrite(Leds[i], OFF);
			}
			LedSequence(Leds[LedSequenceState[0]], LedSequenceState[1]);
			LedSequenceState[1]++;
			if (LedSequenceState[1] > 4) {
				LedSequenceState[1] = 0;

				LedSequenceState[0]++;
				if (LedSequenceState[0] >= LedCount) {
					LedSequenceState[0] = 0;
				}
			}
		}
		break;
	}
}
