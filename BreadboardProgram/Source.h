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
	printf("\nLenght: ");
	scanf_s("%f", &lenght);
	b->m_Lenght = lenght;
	printf("Width: ");
	scanf_s("%f", &width);
	b->m_Width = width;
	printf("Operating voltage: ");
	scanf_s("%f", &opVoltage);
	b->m_OperatingVoltage = opVoltage;
	getchar();
}

void PrintInfoBreadboard(Breadboard b) {
	printf("\nLenght: %.1f mm\n", b.m_Lenght);
	printf("Width: %.1f mm\n", b.m_Width);
	printf("Available pin connections: %d\n", b.m_Connections);
	printf("Operating voltage: %.1fV\n", b.m_OperatingVoltage);
}

//såhär får en ett rimligt avstånd på connections på breadboarden
int CalculateConnections(float *lenght, float *width, float pinDistance) {
	int connections;
	float availableSpace;
	//available space for connections use to be like a bit less that 2/3
	availableSpace = (((*lenght) * (*width))* 0.60);
	//pow är en funktion för upphöjt till från math.h
	return connections = (availableSpace / (pinDistance = pow(pinDistance, 2)));
}

int ComponentsMenu() {
	int choice;
	printf("\nAdd type of component for attatchment to breadboard\n");
	printf("Sensor (1)\n");
	printf("LED (2)\n");
	printf("LCD (3)\n");
	printf("Use existing (4)\n");
	scanf_s("%d", &choice);
	return choice;
}

void FillNewSensor(Sensor *s) {
	char *sensorType = malloc(20), *model = malloc(20);
	int numberOfPins = 0;
	float maxOpVolt = 0.0, minOpVolt = 0.0;
	printf("Sensor type: ");
	getchar();
	fgets(sensorType, 20, stdin);
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
}

void PrintInfoSensor(Sensor s) {
	printf("\nSensor type: %s", s.m_SensorType);
	printf("Model: %s", s.m_Model);
	printf("Number of pins: %d\n", s.m_NumberOfPins);
	printf("Max operating voltage: %.1fV\n", s.m_MaxOperatingVoltage);
	printf("Min operating voltage: %.1fV\n", s.m_MinOperatingVoltage);
}

void AddNewLed() {
	printf("Color: ");
	printf("Max operating voltage: ");
	printf("Min operating voltage: ");
}

void HardCodeModules(Breadboard *a, Sensor *b, Sensor *c, Sensor *d, LED *e, LED *f, LED *g ) {
	a->m_Lenght = 165; a->m_Width = 55; a->m_Connections = 830; a->m_OperatingVoltage = 5;
	
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

/*int Calc_RowOfAvailableConnections(Breadboard *b, float pinDistance) {
	//hittar hur lång rad av unika spår som finns på breadboarden för att kolla hur många sensorer som får plats
	
	int row;

	row = ((b->m_Lenght) / pinDistance);

	return row;
}*/
