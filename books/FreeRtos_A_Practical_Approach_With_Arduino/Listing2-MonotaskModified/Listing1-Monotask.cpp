#include <Arduino.h>

void setup() {
	pinMode(13, OUTPUT);
	pinMode(1, INPUT);

	Serial.begin(9600);
}

void loop() {
	digitalWrite(13, HIGH);
	delay(1000);
	digitalWrite(13, LOW);
	delay(1000);

	if(digitalRead(1) == HIGH){
		Serial.println("Key on!");
	}else{
		Serial.println("Key off!");
	}
}
