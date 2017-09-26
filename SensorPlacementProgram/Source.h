#pragma once
#include <stdio.h>

#include "Structs.h"
int ChooseBreadboard() {
	int choice;

	printf("Choose what size of breadboard you want to use: \n");
	printf("1. 10 x 10 pins\n2. 20 x 10 pins\n3. 30 x 10 pins\n4. 30 x 20 pins\n");
	scanf("%d", &choice);
	return choice;
}


void HardCodeBreadboard(Breadboard *a,int x, int y) {
	//hard codes a breadboard
	a->m_Pins_X = x; a->m_Pins_Y = y;
	a->m_Connections = 200;
	a->m_OperatingVoltage = 5;
	a->m_Ampere = 0.5;
}

void PrintBoard(MyTemplate *breadboardWComponents, int sensorCount, char** board) {

	int i, j, row = 10, col = 10;

	printf("My BreadBoard:\n");
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			board[i][j] = 'X';
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < sensorCount; i++) {
		board[breadboardWComponents->m_Sensors[i].m_Anod_Placement]
			[breadboardWComponents->m_Sensors[i].m_Katod_Placement]
			= 'S';
	}
}

int ComponentsMenu() {
	int choice;
	printf("Add type of component for attatchment to breadboard\n");
	printf("1. Sensor\n");
	printf("2. LED\n");
	printf("3. Use existing\n");
	scanf_s("%d", &choice);
	return choice;
}

void FillNewSensor(Sensor *s) {
	char *sensorType = malloc(50), *model = malloc(20);
	int numberOfPins = 0, anod = 0, widht = 0;
	float maxOpVolt = 0.0, minOpVolt = 0.0, ampere = 0.0;

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
	if (USING_AMPERE_AND_WATT) {
		printf("Ampere: ");
		scanf_s("%f", &ampere);
		s->m_Ampere = ampere;
	}
	printf("Anod Placement: ");
	scanf_s("%d", &anod);
	s->m_Anod_Placement = anod;
	printf("Width of sensor (in pins): ");
	scanf_s("%d", &widht);
	s->m_Katod_Placement = (s->m_Anod_Placement + widht);
	getchar();
	free(sensorType);
	free(model);
}

void HardCodeModules(Sensor *hcSensors, LED *leds) {
	//hard codes three sensors and three leds to choose in program 
	strcpy(hcSensors[0].m_SensorType, "Soil Moisture Sensor");
	strcpy(hcSensors[0].m_Model, "LM393");
	hcSensors[0].m_NumberOfPins = 4; hcSensors[0].m_MaxOperatingVoltage = 5; hcSensors[0].m_MinOperatingVoltage = 3.3; if (USING_AMPERE_AND_WATT) hcSensors[0].m_Ampere = 0.1;

	strcpy(hcSensors[1].m_SensorType, "Ultrasonic Sensor");
	strcpy(hcSensors[1].m_Model, "HC-SR04");
	hcSensors[1].m_NumberOfPins = 4; hcSensors[1].m_MaxOperatingVoltage = 5; hcSensors[1].m_MinOperatingVoltage = 5; if (USING_AMPERE_AND_WATT) hcSensors[1].m_Ampere = 0.1;

	strcpy(hcSensors[2].m_SensorType, "Temperature/ Humidity Sensor");
	strcpy(hcSensors[2].m_Model, "DHT11");
	hcSensors[2].m_NumberOfPins = 3; hcSensors[2].m_MaxOperatingVoltage = 5; hcSensors[2].m_MinOperatingVoltage = 5; if (USING_AMPERE_AND_WATT) hcSensors[2].m_Ampere = 0.1;

	strcpy(leds[0].m_Color, "Red"); leds[0].m_MaxOperatingVoltage = 2.2; leds[0].m_MinOperatingVoltage = 1.8;
	strcpy(leds[1].m_Color, "Green"); leds[1].m_MaxOperatingVoltage = 2.2; leds[1].m_MinOperatingVoltage = 1.8;
	strcpy(leds[2].m_Color, "Green"); leds[2].m_MaxOperatingVoltage = 2.2; leds[2].m_MinOperatingVoltage = 1.8;
}


int ChooseModule() {
	int choice = 0;
	printf("Choose which module to use\n");
	printf("Sensors:\n");
	printf("\n1. Soil Moisture Sensor");
	printf("\n2. Ultrasonic Sensor");
	printf("\n3. Temperature/ Humidity Sensor");
	printf("\n\nLEDs:\n\n4. Red\n5. Green\n6. Blue\n");
	scanf_s("%d", &choice);
	return choice;
}

#if USING_AMPERE_AND_WATT
//here are functions defined if using sensor ampere and watt, its hard to find specs containing
//info about components max watt and ampere, so default is not using it 
void CalculateComponentWatt(float *volt, float *ampere, float *watt) {
	(*watt) = (*volt) * (*ampere);
}

int TotalWattCalculation(MyTemplate *breadboardWComponents, int sensorCount, int LEDCount) {
	int totalWatt = 0;
	for (int i = 0; i < sensorCount; i++) {
		totalWatt = totalWatt + breadboardWComponents->m_Sensors[i].m_Watt;
	}

	for (int j = 0; j < LEDCount; j++) {
		totalWatt = totalWatt + breadboardWComponents->m_LEDs[j].m_Watt;
	}
	return totalWatt;
}

void PowerErrorMessage(int totalWatt, Breadboard b) {

	if (totalWatt > b.m_Watt) {
		printf("***Total effect of components to high***");
	}
}

#else 

int CalculateComponentWatt() {
	return 0;
}

int TotalWattCalculation() {
	return 0;
}

int PowerErrorMessage() {
	return 0;
}

#endif
