#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>

typedef struct{
	const char *pcTaskName;
	const char *pcText;
	int SensorID;
	int DelayTicks;
}AnalogReadParam_t;

SemaphoreHandle_t xSerialSemaphore;

void TaskDigitalRead(void *pvParameters);
void TaskAnalogReadParam(void pvParameters);

AnalogReadParam_t xParams[3], *pxParam = xParams;

void setup() {
	Serial.begin(9600);

	while(!Serial){
		;
	}

	if(xSerialSemaphore == NULL){
		xSerialSemaphore = xSemaphoreCreateMutex();
		if( xSerialSemaphore != NULL){
			xSemaphoreGive(xSerialSemaphore);
		}
	}

	pxParam->pcTaskName = "TaskInputA1";
	pxParam->pcText = "Input A1";
	pxParam->SensorID = A1;
	pxParam->DelayTicks = pdMS_TO_TICKS( 250UL );
	pxParam++;

	pxParam->pcTaskName = "TaskInputA2";
	pxParam->pcText = "Input A2";
	pxParam->SensorID = A2;
	pxParam->DelayTicks = 1; //pdMS_TO_TICKS( 250UL );
	pxParam++;

	pxParam->pcTaskName = "TaskInputA3";
	pxParam->pcText = "Input A3";
	pxParam->SensorID = A3;
	pxParam->DelayTicks = 1; //pdMS_TO_TICKS( 250UL );
}

void loop() {

}
