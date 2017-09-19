#pragma once
#include "Structs.h"
#include <stdio.h>
#include <math.h> 
#include <conio.h>
#include <stdlib.h>

void CheckFileStatus(FILE *fptr) {
	if (fptr == NULL) {
		printf("Could not open file");
	}
}

int Menu() {
	int choice;
	printf("New breadboard (1)\n");
	printf("Use existing breadboard (2)\n");
	printf("Exit program (3) \n");
	scanf_s("%d", &choice);
	return choice;
}

void FillNewBreadboard(Breadboard *b) {
	float lenght = 0, width = 0, opVoltage = 0;
	int connections = 0;
	printf("\nNumber of pins (vertical): ");
	scanf_s("%f", &lenght);
	b->m_Pins_X = lenght;
	printf("Number of pins (Horizontal): ");
	scanf_s("%f", &width);
	b->m_Pins_Y = width;
	printf("Operating voltage: ");
	scanf_s("%f", &opVoltage);
	b->m_OperatingVoltage = opVoltage;
	getchar();
}


int CalcConnections(int  *pinsX, int *pinsY, float pinDistance) {
	int returnValue = ((*pinsX) * (*pinsY)) / (pinDistance = pow(pinDistance, 2));
	return returnValue;
}

void PrintInfoBreadboard(Breadboard b) {
	printf("\nPins (vertical): %d \n", b.m_Pins_X);
	printf("Pins (Horizontal): %d \n", b.m_Pins_Y);
	printf("Available pin connections: %d\n", b.m_Connections);
	printf("Operating voltage: %.1fV\n", b.m_OperatingVoltage);
}

int ComponentsMenu() {
	int choice;
	printf("\nAdd type of component for attatchment to breadboard\n");
	printf("Sensor (1)\n");
	printf("LED (2)\n");
	printf("Use existing (3)\n");
	scanf_s("%d", &choice);
	return choice;
}

void FillNewSensor(Sensor *s) {
	char *sensorType = malloc(20), *model = malloc(20);
	int numberOfPins = 0;
	float maxOpVolt = 0.0, minOpVolt = 0.0;
	printf("Sensor type: ");
	getchar();
	fgets(sensorType, 50, stdin);
	strcpy(s->m_SensorType, sensorType);
	printf("Model: ");
	fgets(model, 20, stdin);
	strcpy(s->m_Model, model);
	printf("Number of pins: ");
	scanf_s("%d", &numberOfPins);
	s->m_NumberOfPins = numberOfPins;
	printf("Max operating voltage: ");
	scanf_s("%f", &maxOpVolt);
	s->m_MaxOperatingVoltage = maxOpVolt;
	printf("Min operating voltage: ");
	scanf_s("%f", &minOpVolt);
	s->m_MinOperatingVoltage = minOpVolt;
	getchar();
	free(sensorType);
	free(model);
}

void PrintInfoSensor(Sensor s) {
	printf("\nSensor type: %s", s.m_SensorType);
	printf("Model: %s", s.m_Model);
	printf("Number of pins: %d\n", s.m_NumberOfPins);
	printf("Max operating voltage: %.1fV\n", s.m_MaxOperatingVoltage);
	printf("Min operating voltage: %.1fV\n", s.m_MinOperatingVoltage);
}

void FillNewLED(LED *led) {
	char *color = malloc(20);
	float maxOpVolt, minOpVolt;

	printf("Color: ");
	getchar();
	fgets(color, 20, stdin);
	strcpy(led->m_Color, color);
	printf("Max operating voltage: ");
	scanf_s("%f", &maxOpVolt);
	led->m_MaxOperatingVoltage = maxOpVolt;
	printf("Min operating voltage: ");
	scanf_s("%f", &minOpVolt);
	led->m_MinOperatingVoltage = minOpVolt;
	getchar();
	free(color);
}

void PrintInfoLED(LED led) {
	printf("\nColor: %s", led.m_Color);
	printf("Max operating voltage: %.1f", led.m_MaxOperatingVoltage);
	printf("\nMin operating voltage: %.1f\n", led.m_MinOperatingVoltage);
}

void HardCodeBreadboard(Breadboard *a) {
	a->m_Pins_X = 120; a->m_Pins_Y = 42; a->m_Connections = 781; a->m_OperatingVoltage = 5;
}

void HardCodeModules(Sensor *b, Sensor *c, Sensor *d, LED *e, LED *f, LED *g) {

	strcpy(b->m_SensorType, "Soil Moisture Sensor");
	strcpy(b->m_Model, "LM393");
	b->m_NumberOfPins = 4; b->m_MaxOperatingVoltage = 5; b->m_MinOperatingVoltage = 3.3;

	strcpy(c->m_SensorType, "Ultrasonic Sensor");
	strcpy(c->m_Model, "HC-SR04");
	c->m_NumberOfPins = 4; c->m_MaxOperatingVoltage = 5; c->m_MinOperatingVoltage = 5;

	strcpy(d->m_SensorType, "Temperature/ Humidity Sensor");
	strcpy(d->m_Model, "DHT11");
	d->m_NumberOfPins = 3; d->m_MaxOperatingVoltage = 5; d->m_MinOperatingVoltage = 5;

	strcpy(e->m_Color, "Red"); e->m_MaxOperatingVoltage = 2.2; e->m_MinOperatingVoltage = 1.8;
	strcpy(f->m_Color, "Green"); f->m_MaxOperatingVoltage = 2.2; f->m_MinOperatingVoltage = 1.8;
	strcpy(g->m_Color, "Green"); g->m_MaxOperatingVoltage = 2.2; g->m_MinOperatingVoltage = 1.8;
}

int ChooseModule() {
	int choice = 0;
	printf("Choose which module to use");
	printf("\nSoil Moisture Sensor (1)");
	printf("\nUltrasonic Sensor (2)");
	printf("\nTemperature/ Humidity Sensor (3)");
	printf("LED Red (4), Green (5), Blue (6)");
	scanf_s("%d", &choice);
	return choice;
}

void PrintInfoMyTemplate(MyTemplate myTemplate) {
	int i, j;
	

	printf("\nBreadboard (%d connections, %.1fV)\n", myTemplate.m_Breadboard.m_Connections, myTemplate.m_Breadboard.m_OperatingVoltage);
	printf("Sensors:\n");
	for (i = 0; i < 20; i++) {
		if ((myTemplate.m_Sensors[i].m_SensorType) != NULL) {
			printf("%s", myTemplate.m_Sensors[i].m_SensorType);
		}
		else {
			i = 20;
		}
	}

	printf("\nLEDS:\n");
	for (j = 0; j < 20; j++) {
		printf("%s", myTemplate.m_LEDs[j].m_Color);
		if ((myTemplate.m_LEDs[j].m_MaxOperatingVoltage) != 0.0) {
			printf("(%.1fV max)", myTemplate.m_LEDs[j].m_MaxOperatingVoltage);
		}
	}

}

int CheckMaxVoltage(MyTemplate myTemplate, int *usedPins) {
	//om volten till breadboaren är större är maxvoltage hos sensorn så lägger vi till en potentiometer
	if (myTemplate.m_Breadboard.m_OperatingVoltage > myTemplate.m_Sensors[0].m_MaxOperatingVoltage) {
		printf("\n**Since this module needs voltage regulation we added a potentiometer (uses 3 connection pins)**\n");
		*usedPins = +3;
		return 1;
	}
	else {
		return 0;
	}
}

/*int PinsError(Breadboard *b, int usedPins) {
	float approxUniquePins = ((b->m_Pins_X) * 2);
	approxUniquePins = approxUniquePins * 0.6; //vi måste räkna marginal för att en placerar ut grejerna + pinsen ligger inte bredvid varandra
	if (usedPins > approxUniquePins) {
		return 1;
	}
	else {
		return 0;
	}
}*/