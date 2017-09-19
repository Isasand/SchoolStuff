#pragma once

typedef struct {
	float m_Lenght; //enhet: mm
	float m_Width;
	int m_Connections;
	float m_OperatingVoltage;
} Breadboard;

typedef struct {
	char m_SensorType[20];
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
