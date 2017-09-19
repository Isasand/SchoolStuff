#pragma once

typedef int bool;
#define true 1
#define false 0


typedef struct {
	int m_Pins_X; 
	int m_Pins_Y;
	int m_Connections;
	float m_OperatingVoltage;
} Breadboard;

typedef struct {
	char m_SensorType[50];
	char m_Model[20];
	int m_NumberOfPins;
	float m_MaxOperatingVoltage;
	float m_MinOperatingVoltage;
} Sensor;

typedef struct {
	char m_Color[20];
	float m_MaxOperatingVoltage;
	float m_MinOperatingVoltage;
} LED;

//average LED 1.8v min 2.2v max 

typedef struct {
	Breadboard m_Breadboard;
	Sensor m_Sensors[20];
	LED m_LEDs[20];
	bool useOfPotentiometer;
} Template;
