#include <Arduino.h>

//Da um nome para um numero da porta que vai ser a lampada
#define LAMPADA 13

#define SAIDA	OUTPUT
#define LIGADO	HIGH
#define DESLIGADO LOW

void setup() {

	pinMode(LAMPADA, SAIDA);   //Configura o pino da lampada para saida
}

void loop() {
	digitalWrite(LAMPADA, HIGH); //Liga a lampada
	delay(1000);			     //espera 1s
	digitalWrite(LAMPADA, LOW);	 //Desliga a lampad
	delay(1000);				 //espera 1s
}
