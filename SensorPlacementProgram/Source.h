#pragma once

#include "Structs.h"
#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
#include <Windows.h>


void SetSensorSymbol(Sensor* sensor);

void SetLEDSymbol(LED* led);

void PrintVisualBreadboard(MyTemplate *breadboard, int cSensors, int cLEDs);

void MvRm(MyTemplate *breadboardWComponents, int pickedComponent, int cSensors, int cLEDs);


void RmSensor(Sensor *sensor);


void RmLED(LED *led);

void AttachSensor(Sensor *sensor);

void AttachLED(LED *led);

int PickComponent(MyTemplate *breadboardWComponents, int cSensors, int cLED);

int Menu();

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