#pragma once
#include "Structs.h"
#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
#include <Windows.h>

//change to true if using watt and ampere 
#define USING_AMPERE_AND_WATT false

#if USING_AMPERE_AND_WATT
void CalculateComponentWatt(float *volt, float *ampere, float *watt);
int TotalWattCalculation(MyTemplate *breadboardWComponents, int sensorCount, int LEDCount);
void PowerErrorMessage(int totalWatt, Breadboard b);

#else 
int CalculateComponentWatt();
int TotalWattCalculation();
int PowerErrorMessage();

#endif

void CalculateWatt(float *volt, float *ampere, float *watt);

int Menu();

void FillNewBreadboard(Breadboard *b);

int CalcConnections(int  *pinsX, int *pinsY);

void PrintInfoBreadboard(Breadboard b);

int ComponentsMenu();

void FillNewSensor(Sensor *s);

void PrintInfoSensor(Sensor s);

void FillNewLED(LED *led);

void PrintInfoLED(LED led);

void HardCodeBreadboard(Breadboard *a);

void HardCodeModules(Sensor *hcSensors, LED *leds);

int ChooseModule();

void PrintInfoMyTemplate(MyTemplate *myTemplate, int usedPins, int LEDCount, int sensorCount);

int CheckMaxVoltage(MyTemplate *myTemplate, int *usedPins);

void CalculateUniquePins(Breadboard* b);

int PinError(Breadboard* b, int usedPins);