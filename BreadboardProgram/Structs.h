#pragma once

typedef int bool;
#define true 1
#define false 0

//breadboard struct
typedef struct {
	int m_Pins_X; 
	int m_Pins_Y;
	int m_Connections;
	float m_OperatingVoltage;
	float m_Ampere; //dessa kan användas för att räkna ut watt, men i mitt program så väljer jag att ta bort det 
	float m_Watt;
	float m_UniquePins;
} Breadboard;

//Sensor struct
typedef struct {
	char m_SensorType[50];
	char m_Model[20];
	int m_NumberOfPins;
	float m_MaxOperatingVoltage;
	float m_MinOperatingVoltage;
	float m_Ampere;
	float m_Watt;
} Sensor;

//LED struct
typedef struct {
	char m_Color[20];
	float m_MaxOperatingVoltage;
	float m_MinOperatingVoltage;
} LED;

//struct containing all your chosen components 
typedef struct {
	Breadboard m_Breadboard;
	Sensor m_Sensors[20];
	LED m_LEDs[20];
	bool useOfPotentiometer;
} MyTemplate;