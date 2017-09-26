
#include "Source.h"

int main()
{
	int choice = 0;
	int x = 0, y = 0;
	MyTemplate *myBreadboardwComponents = malloc(sizeof(MyTemplate));
	Breadboard *board = malloc(sizeof(Breadboard));

	int sensorCount = 0, LEDCount = 0, usedPins = 0;


	char visualBoard[10][10];

	x = 10, y = 10;
	HardCodeBreadboard(board, x, y);


	system("CLS");
	Sensor hcSensors[3];
	LED hcLEDs[3];
	int moduleChoice;
	//hard code some modules
	HardCodeModules(hcSensors, hcLEDs);
	moduleChoice = ChooseModule();

	//the first three elements are sensors
	if (moduleChoice <= 3) {
		myBreadboardwComponents->m_Sensors[sensorCount] = hcSensors[moduleChoice - 1];
		usedPins = usedPins + myBreadboardwComponents->m_Sensors[sensorCount].m_NumberOfPins;
		//myBreadboardwComponents->useOfPotentiometer = CheckMaxVoltage(myBreadboardwComponents, &usedPins);
		
		int anod = 0, widht = 0;
		printf("Anod Placement: ");
		scanf_s("%d", &anod);
		myBreadboardwComponents->m_Sensors[sensorCount].m_Anod_Placement = anod;
		printf("Width of sensor (in pins): ");
		scanf_s("%d", &widht);
		myBreadboardwComponents->m_Sensors[sensorCount].m_Katod_Placement = (myBreadboardwComponents->m_Sensors[sensorCount].m_Anod_Placement + widht);
		getchar();
		sensorCount++;
	}
	//the rest are LEDs
	else {
		myBreadboardwComponents->m_LEDs[LEDCount] = hcLEDs[moduleChoice - 4];
		usedPins = usedPins + 2;
		LEDCount++;
	}


	printf("\nMy BreadBoard:\n");
	for (int i = 0; i <x; i++) {
		for (int j = 0; j < y; j++) {
			visualBoard[i][j] = 'X';
			printf("[%c]", visualBoard[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < sensorCount; i++) {
		visualBoard[0][myBreadboardwComponents->m_Sensors[i].m_Anod_Placement-1]
		= 'S';
		visualBoard[0]
			[myBreadboardwComponents->m_Sensors[i].m_Katod_Placement-1]
		= 'S';

	}

	printf("\nAdded sensor:\n");
	for (int i = 0; i <x; i++) {
		for (int j = 0; j < y; j++) {
			printf("[%c]", visualBoard[i][j]);
		}
		printf("\n");
	}
	getchar();
	return 0;

}

void AddPlacement(){

}