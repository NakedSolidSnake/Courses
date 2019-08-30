#include <Arduino.h>

#define BOTAO 8
#define LAMPADA 13

void setup() {
	pinMode(BOTAO, INPUT_PULLUP);
	pinMode(LAMPADA, OUTPUT);
}

void loop() {
	if(digitalRead(BOTAO) == 0){
		digitalWrite(LAMPADA, HIGH);
	}
	else{
		digitalWrite(LAMPADA, LOW);
	}
}
