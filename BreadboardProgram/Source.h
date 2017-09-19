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

//s�h�r f�r en ett rimligt avst�nd p� connections p� breadboarden 
/*int CalculateConnections(float *lenght, float *width, float pinDistance) {
	int connections;
	float availableSpace;
	//available space for connections use to be like a bit less that 2/3
	availableSpace = (((*lenght) * (*width))* 0.60);
	//pow �r en funktion f�r upph�jt till fr�n math.h
	return connections = (availableSpace / (pinDistance = pow(pinDistance, 2)));
}*/

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

void HardCodeModules(Sensor *b, Sensor *c, Sensor *d, LED *e, LED *f, LED *g ) {
	
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

	return choice;
}

