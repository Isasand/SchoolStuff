#include "Source.h"
typedef int bool;
#define true 1
#define false 0

#define STD_PIN_DISTANCE 2.54

int main() {
	FILE *fptr;
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
			Breadboard hcBreadboard;
			Sensor hcSensor1, hcSensor2, hcSensor3;
			LED hcLED1, hcLED2, hcLED3;

			break;
		}

		}
		break;//breake case 1 in switch(choice)
	}
	case 2: { //use existing breadboard
		break;
	}
	case 3: { //exit program
		break;
	}

	}
	getchar();

	return 0;
}

