#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <queue.h>

typedef enum
{
	itTemperaturaReading,
	itHourry,
	itReceivedText
}ItemType_t;

typedef struct
{
	ItemType_t Type;
	union
	{
		float Temperatura;
		struct
		{
			uint8_t Hour;
			uint8_t Minutes;
			uint8_t Seconds;
		}Horary;
		char Text[13];
	}Data;
}QueueItem_t;



QueueHandle_t xQueue;

void TaskReadTemp(void *pvParameters);
void TaskCurrentTime(void *pvParameters);
void TaskSerialReception(void *pvParameters);
void TaskSend(void *pvParameters);

int createTasks(void)
{
	BaseType_t taskRet;
	taskRet = xTaskCreate(TaskReadTemp, (const portCHAR *)"TaskReadTemp", 128, NULL, 2, NULL);
	if(taskRet == pdPASS)
		Serial.println("Task TaskReadTemp created successully!");
	else
		return 0;

	taskRet = xTaskCreate(TaskCurrentTime, (const portCHAR *)"TaskCurrentTime", 128, NULL, 2, NULL);
	if(taskRet == pdPASS)
		Serial.println("Task TaskCurrentTime created successully!");
	else
		return 0;

	taskRet = xTaskCreate(TaskSerialReception, (const portCHAR *)"TaskSerialReception", 128, NULL, 2, NULL);
	if(taskRet == pdPASS)
		Serial.println("Task TaskSerialReception created successully!");
	else
		return 0;

	taskRet = xTaskCreate(TaskSend, (const portCHAR *)"TaskSend", 128, NULL, 2, NULL);
	if(taskRet == pdPASS)
		Serial.println("Task TaskSend created successully!");
	else
		return 0;

	return 1;
}


void setup() {
	Serial.begin(9600);

	xQueue = xQueueCreate(10, sizeof(QueueItem_t));
	if(xQueue)
	{
		Serial.println("Queue created successully!");
		if(!createTasks())
			Serial.println("Error creating tasks");
	}
	else
		Serial.println("Error creating the queue occurred!");
}

void loop() {
}

void TaskReadTemp(void *pvParameters)
{
	QueueItem_t Item;
	Item.Type = itTemperaturaReading;

	Serial.println("Starting loop: TaskReadTemp");
	for(;;)
	{
		int sensorValue = analogRead(A0);
		Item.Data.Temperatura = ((float(sensorValue) * 5 / 1023)) / 0.01;
		xQueueSendToBack(xQueue, &Item, portMAX_DELAY);
		vTaskDelay(500 / portTICK_PERIOD_MS);
	}
}

void treatClock(QueueItem_t *pItem)
{
	pItem->Data.Horary.Seconds++;
	if(pItem->Data.Horary.Seconds == 60)
	{
		pItem->Data.Horary.Seconds = 0;
		pItem->Data.Horary.Minutes++;
		if(pItem->Data.Horary.Minutes == 60)
		{
			pItem->Data.Horary.Minutes = 0;
			pItem->Data.Horary.Hour++;

			if(pItem->Data.Horary.Hour == 24)
				pItem->Data.Horary.Hour = 0;
		}
	}
}

void TaskCurrentTime(void *pvParameters)
{
	QueueItem_t Item;

	Item.Type = itHourry;
	Item.Data.Horary.Seconds = 0;
	Item.Data.Horary.Minutes = 0;
	Item.Data.Horary.Hour = 0;

	Serial.println("Starting loop: TaskSerialReception");
	for(;;)
	{
		treatClock(&Item);
		xQueueSendToBack(xQueue, &Item, portMAX_DELAY);
		vTaskDelay(1000 / portTICK_PERIOD_MS);

	}
}

void TaskSerialReception(void *pvParameters)
{
	QueueItem_t Item;
	char readedChar;
	int size = 0;

	Item.Type = itReceivedText;
	Item.Data.Text[size] = '\0';

	Serial.println("Starting loop: TaskSerialReception");

	for(;;)

	{
		if(Serial.available())
		{
			readedChar = (char) Serial.read();
			if(readedChar != '\n')
			{
				Item.Data.Text[size++] = readedChar;
				Item.Data.Text[size] = '\0';
			}

			if(readedChar == '\n' || size == (sizeof(Item.Data.Text - 1)))
			{
				xQueueSendToBack(xQueue, &Item, portMAX_DELAY);
				size = 0;
				Item.Data.Text[size] = '\0';
			}
		}
	}
}

void TaskSend(void *pvParameters)
{
	char DisplayMirror[2][17] = {"00:00:00 |      ",
								 "T: 000.0 |      "
	};

	QueueItem_t Item;
	int l, i;
	char *p;

	Serial.println("Starting loop: TaskSend");

	for(;;)
	{
		xQueueReceive(xQueue, &Item, portMAX_DELAY);
		switch(Item.Type)
		{
		case itTemperaturaReading:
			sprintf(&DisplayMirror[1][3], "%3.1f", Item.Data.Temperatura);
			break;

		case itHourry:
			sprintf(&DisplayMirror[0][0], "%0.2d", Item.Data.Horary.Hour);
			sprintf(&DisplayMirror[0][3], "%0.2d", Item.Data.Horary.Minutes);
			sprintf(&DisplayMirror[0][6], "%0.2d", Item.Data.Horary.Seconds);
			break;

		case itReceivedText:
			for(l = 0; l < 2; l++)
			{
				for(i = 0, p = &DisplayMirror[l][10]; i < 6; i++, p++)
				{
					*p = ' ';
				}
				*p = '\0';
			}

			for(l = 0; l < 2; l++)
			{
				p = &DisplayMirror[l][10];
				for(i = 0; i < 6 && Item.Data.Text[i]; i++)
				{
					*p = Item.Data.Text[i];
					p++;
				}

				*p = '\0';
			}
			break;
		}

		Serial.println("----------------");
		Serial.println(DisplayMirror[0]);
		Serial.println(DisplayMirror[1]);
	}
}
