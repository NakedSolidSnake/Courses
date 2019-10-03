#include <Arduino.h>


void blinkLED(void);
void sendKeyState(void);

void setup() {
	pinMode(13, OUTPUT);
	pinMode(1, INPUT);

	Serial.begin(9600);
}

void loop() {
	blinkLED();
	sendKeyState();
}

void blinkLED(void)
{
	digitalWrite(13, HIGH);
	delay(1000);
	digitalWrite(13, LOW);
	delay(1000);
}

void sendKeyState(void)
{
	if(digitalRead(1) == HIGH){
		Serial.println("Key on!");
	}else{
		Serial.println("Key off!");
	}
}
