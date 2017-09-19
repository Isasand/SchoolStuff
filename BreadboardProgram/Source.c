#include "Source.h"
#define STD_PIN_DISTANCE 2.54 

int main() {
	MyTemplate myBreadboardwComponents = { NULL, NULL, NULL, false };
	int usedPins = 0;

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
		myBreadboardwComponents.m_Breadboard = newBreadboard;
		break;
	}
	case 2: { //use existing breadboard
		Breadboard hcBreadboard;
		HardCodeBreadboard(&hcBreadboard);
		PrintInfoBreadboard(hcBreadboard);
		myBreadboardwComponents.m_Breadboard = hcBreadboard;
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
		myBreadboardwComponents.m_Sensors[0] = newSensor;
		break;
	}
	case 2: {//new LED
		LED newLED;
		FillNewLED(&newLED);
		printf("\nNew LED created with the following properties");
		PrintInfoLED(newLED);
		myBreadboardwComponents.m_LEDs[0] = newLED;
		usedPins=+2;
		break;
	}
	case 3: {//use existing
		Sensor hcS1, hcS2, hcS3;
		LED hcLED1, hcLED2, hcLED3;
		int moduleChoice;

		HardCodeModules(&hcS1, &hcS2, &hcS3, &hcLED1, &hcLED2, &hcLED3);

		moduleChoice = ChooseModule();
		switch (moduleChoice) {
		case 1: {
			myBreadboardwComponents.m_Sensors[0] = hcS1;
			usedPins = +myBreadboardwComponents.m_Sensors[0].m_NumberOfPins;
			myBreadboardwComponents.useOfPotentiometer = CheckMaxVoltage(myBreadboardwComponents, &usedPins);
			break;
		}
		case 2: {
			myBreadboardwComponents.m_Sensors[0] = hcS2;
			usedPins = +myBreadboardwComponents.m_Sensors[0].m_NumberOfPins;
			myBreadboardwComponents.useOfPotentiometer = CheckMaxVoltage(myBreadboardwComponents, &usedPins);
			break;
		}
		case 3: {
			myBreadboardwComponents.m_Sensors[0] = hcS3;
			usedPins = +myBreadboardwComponents.m_Sensors[0].m_NumberOfPins;
			myBreadboardwComponents.useOfPotentiometer = CheckMaxVoltage(myBreadboardwComponents, &usedPins);
			break;
		}
		case 4: {
			myBreadboardwComponents.m_LEDs[0] = hcLED1;
			usedPins = +4; //två för led, två för resistorn 
			break;
		}
		case 5: {
			myBreadboardwComponents.m_LEDs[0] = hcLED2;
			usedPins = +4;
			break;
		}
		case 6: {
			myBreadboardwComponents.m_LEDs[0] = hcLED3;
			usedPins = +4;
			break;
		}
		}
		
		break;
	}
	}

	getchar();
	//int check = PinsError(&myBreadboardwComponents.m_Breadboard, usedPins);
	PrintInfoMyTemplate(myBreadboardwComponents);
	
	getchar();

	return 0;
}

