#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <task.h>
#include <semphr.h>

typedef struct{
	const char *pcTaskName;
	const char *pcText;
	int SensorID;
	int DelayTicks;
}AnalogReadParam_t;

SemaphoreHandle_t xSerialSemaphore;

void TaskDigitalRead(void *pvParameters);
void TaskAnalogReadParam(void *pvParameters);

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

	TaskHandle_t xLastTask;

	for(pxParam = &xParams[0]; pxParam < &xParams[3]; pxParam++){
		Serial.println("\n------------------------------");
		Serial.print("Creating ");
		Serial.println(pxParam->pcTaskName);

		xTaskCreate(
				TaskAnalogReadParam,
				pxParam->pcTaskName,
				128,
				(void *)pxParam,
				(configMAX_PRIORITIES - 2),
				&xLastTask
				);
	}
	vTaskSuspend(xLastTask);

	xTaskCreate(
			TaskDigitalRead,
			(const portCHAR *)"Digital Read",
			128,
			(void *)xLastTask,
			(configMAX_PRIORITIES - 3),
			NULL
			);

}

void loop() {

}

void SerialDebugWithSemaphore(const char *pszText)
{
	if( xSemaphoreTake( xSerialSemaphore, (TickType_t) 5) == pdTRUE ){
		Serial.println(pszText);
		xSemaphoreGive(xSerialSemaphore);
	}
}

void TaskDigitalRead(void *pvParameters)
{
	uint8_t pushButton = 2;
	TaskHandle_t xTaskParaReiniciar = (TaskHandle_t) pvParameters;

	pinMode(pushButton, INPUT);

	for( ; ; ){
		int buttonState = digitalRead(pushButton);

		if (xSemaphoreTake(xSerialSemaphore, (TickType_t)5) == pdTRUE){
			Serial.print("digital input: ");

			Serial.println(buttonState);

			xSemaphoreGive(xSerialSemaphore);

			if(xTaskParaReiniciar != NULL && (buttonState == 1)){
				vTaskResume(xTaskParaReiniciar);
			}
		}
		vTaskDelay(1);
	}
}

void TaskAnalogReadParam(void *pvParameters)
{
	AnalogReadParam_t *pxParams = (AnalogReadParam_t *)pvParameters;

	for(;;){

		int sensorValue = analogRead(pxParams->SensorID);

		if (xSemaphoreTake(xSerialSemaphore, (TickType_t) 5) == pdTRUE){
			Serial.print(pxParams->pcText);
			Serial.print(": ");
			Serial.println(sensorValue);

			xSemaphoreGive(xSerialSemaphore);
		}

		vTaskDelay(pxParams->DelayTicks);
	}
}
