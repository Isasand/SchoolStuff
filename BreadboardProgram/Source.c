#include "Source.h"
typedef int bool;
#define true 1
#define false 0

#define STD_PIN_DISTANCE 2.54

int main() {
	int menuChoice;

	menuChoice = Menu();
	getchar();

	switch (menuChoice) {

	case 1: { // new breadboard
		Breadboard newBreadboard;
		FillNewBreadboard(&newBreadboard);
		newBreadboard.m_Connections = CalculateConnections(&newBreadboard.m_Lenght, &newBreadboard.m_Width, STD_PIN_DISTANCE);
		printf("\nNew breadboard created with the following properties");
		PrintInfoBreadboard(newBreadboard);

		break;//breake case 1 in switch(choice)
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

	int choice = ComponentsMenu();

	switch (choice) {
	case 1: { //new sensor
		Sensor newSensor;
		FillNewSensor(&newSensor);
		PrintInfoSensor(newSensor);
		break;
	}
	case 2: { //new LED

		break;
	}
	case 3: {//new LCD

		break;
	}
	case 4: {//use existing
		/*Sensor hcS1, hcS2, hcS3;
		LED hcLED1, hcLED2, hcLED3;
		int moduleChoice;

		HardCodeModules(hcS1, hcS2, hcS3, hcLED1, hcLED2, hcLED3);

		moduleChoice = ChooseModule();
		switch (moduleChoice) {
		case 1: {

		}

		}*/
		break;
	}

	}
	getchar();

	return 0;
}

