#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <queue.h>

const byte KeyPin = 2;

QueueHandle_t xQueueEventosChave;

QueueHandle_t xQueue;

void TaskEventosChave( void *pvParameters);
void TaskSend(void *parameters);

void tratarInterrupcaoKeyPin();

void setup() {
	BaseType_t xRet;

	Serial.begin(9600);

	attachInterrupt(digitalPinToInterrupt(KeyPin),
			tratarInterrupcaoKeyPin, RISING);

	pinMode(KeyPin, INPUT_PULLUP);

	xQueueEventosChave = xQueueCreate(
			10,
			sizeof(TickType_t)
			);

	if(xQueueEventosChave)
		Serial.println("Fila xQueueEventosChave criada com sucesso!");

	xQueue = xQueueCreate(
			10,
			21 * sizeof(char)
	);

	xRet = xTaskCreate(TaskEventosChave,
			(const portCHAR *) "TaskEventosCHave",
			128,
			NULL,
			2,
			NULL);

	if(xRet == pdPASS)
		Serial.println("Task TaskEventosChave criada com sucesso:");

	xRet = xTaskCreate(TaskSend,
			(const portCHAR *)"TaskSend",
			128,
			NULL,
			2,
			NULL);

	if(xRet == pdPASS)
			Serial.println("Task TaskSend criada com sucesso:");

}

void loop() {

}

void tratarInterrupcaoKeyPin(){
	BaseType_t xHigherPriorityTaskWoken;
	TickType_t xContadorTicks;

	xContadorTicks = xTaskGetTickCountFromISR();

	xQueueSendToBackFromISR(xQueue, &xContadorTicks, &xHigherPriorityTaskWoken);
	if(xHigherPriorityTaskWoken)
		taskYIELD();
}

void TaskEventosChave( void *pvParameters ){
	TickType_t xTimeofLastInterrupt;
	TickType_t xNow;
	int nTempoEmMs;

	char szText[21];

	Serial.println("Starting loop: TaskEventosChave");

	xTimeofLastInterrupt = xTaskGetTickCount();

	for(;;)
	{
		xQueueReceive(xQueueEventosChave, &xNow, portMAX_DELAY);

		nTempoEmMs = ( xNow - xTimeofLastInterrupt) * portTICK_PERIOD_MS;

		sprintf(szText, "Button: %d ms", nTempoEmMs);
		xQueueSendToBackFromISR(xQueue, szText, portMAX_DELAY);

		xTimeofLastInterrupt = xNow;
	}
}

void TaskSend(void *pvParameters){
	char szText[21];

	Serial.println("Starting loop: TaskSend");

	for(;;)
	{
		xQueueReceive(xQueue, &szText, portMAX_DELAY);
		Serial.print(szText);
	}
}
