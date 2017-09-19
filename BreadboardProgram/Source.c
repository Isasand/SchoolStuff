#include "Source.h"
#define STD_PIN_DISTANCE 2.54 
/*
typedef struct {
	Breadboard m_Breadboard;
	Sensor m_Sensors[20];
	LED m_LEDs[20];
	bool useOfPotentiometer;
} Template;*/

int main() {
	Template myBreadboardwComponents;

	int menuChoice;
	menuChoice = Menu();
	getchar();

	switch (menuChoice) { //new breadboard, use existing breadboard, exit program

	case 1: { // new breadboard
		Breadboard newBreadboard;
		FillNewBreadboard(&newBreadboard);
		newBreadboard.m_Connections = CalcConnections(&newBreadboard.m_Pins_X, &newBreadboard.m_Pins_Y, STD_PIN_DISTANCE);
		printf("\nNew breadboard created with the following properties");
		PrintInfoBreadboard(newBreadboard);

		break;
	}
	case 2: { //use existing breadboard
		Breadboard hcBreadboard;
		HardCodeBreadboard(&hcBreadboard);
		PrintInfoBreadboard(hcBreadboard);

		break;
	}
	case 3: { //exit program
		break;
	}
	}

	int choice = ComponentsMenu(); //new sensor, new LED, use existing
	switch (choice) {

	case 1: { //new sensor
		Sensor newSensor;
		FillNewSensor(&newSensor);
		PrintInfoSensor(newSensor);

		break;
	}
	case 2: {//new LED
		LED newLED;
		FillNewLED(&newLED);
		printf("\nNew LED created with the following properties");
		PrintInfoLED(newLED);
		break;
	}
	case 3: {//use existing
		Sensor hcS1, hcS2, hcS3;
		LED hcLED1, hcLED2, hcLED3;
		int moduleChoice;

		HardCodeModules(&hcS1, &hcS2, &hcS3, &hcLED1, &hcLED2, &hcLED3);

		break;
	}

	}
	getchar();

	return 0;
}

