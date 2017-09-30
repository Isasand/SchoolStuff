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
	float m_UniquePins;
} Breadboard;

//Sensor struct
typedef struct {
	char m_SensorType[50];
	char m_Model[20];
	int m_NumberOfPins;
	float m_MaxOperatingVoltage;
	float m_MinOperatingVoltage;
	int m_AnodX;
	int m_AnodY;
	int m_KatodX;
	int m_KatodY;
	char m_Symbol;
} Sensor;

//LED struct
typedef struct {
	char m_Color[20];
	float m_MaxOperatingVoltage;
	float m_MinOperatingVoltage;
	int m_AnodX;
	int m_AnodY;
	int m_KatodX;
	int m_KatodY;
	char m_Symbol; 
} LED;

//struct containing all your chosen components 
typedef struct {
	Breadboard m_Breadboard;
	Sensor m_Sensors[20];
	LED m_LEDs[20];
	bool useOfPotentiometer;
} MyTemplate;