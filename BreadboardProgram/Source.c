#include "Source.h"
#define STD_PIN_DISTANCE 2.54 


int main() {
	MyTemplate *myBreadboardwComponents = malloc(sizeof(MyTemplate));
	
	int usedPins = 0;

	int menuChoice;
	menuChoice = Menu();
	getchar();

	switch (menuChoice) { //new breadboard, use existing breadboard, exit program

	case 1: { // new breadboard
		Breadboard newBreadboard;
		FillNewBreadboard(&newBreadboard);
		newBreadboard.m_Connections = CalcConnections(&newBreadboard.m_Pins_X, &newBreadboard.m_Pins_Y);
		printf("\nNew breadboard created with the following properties");
		PrintInfoBreadboard(newBreadboard);
		myBreadboardwComponents->m_Breadboard = newBreadboard;
		break;
	}
	case 2: { //use existing breadboard
		Breadboard hcBreadboard;
		HardCodeBreadboard(&hcBreadboard);
		PrintInfoBreadboard(hcBreadboard);
		myBreadboardwComponents->m_Breadboard = hcBreadboard;
		break;
	}
	case 3: { //exit program
		break;
	}
	}

	int LEDCount = 0, sensorCount = 0;
	char chooseAgain = 'y';
	while (chooseAgain == 'y') {
		int choice = ComponentsMenu(); //new sensor, new LED, use existing

		switch (choice) {

		case 1: { //new sensor
			Sensor newSensor;

			FillNewSensor(&newSensor);
			PrintInfoSensor(newSensor);
			myBreadboardwComponents->m_Sensors[sensorCount] = newSensor;
			usedPins = usedPins + myBreadboardwComponents->m_Sensors[sensorCount].m_NumberOfPins;
			sensorCount++;
			getchar();
			printf("Choose again (y/n)?");
			chooseAgain = getchar();

			break;
		}
		case 2: {//new LED
			LED newLED;
			FillNewLED(&newLED);
			printf("\nNew LED created with the following properties");
			PrintInfoLED(newLED);
			myBreadboardwComponents->m_LEDs[LEDCount] = newLED;
			usedPins = usedPins + 4;
			LEDCount++;

			getchar();
			printf("Choose again (y/n)?");
			chooseAgain = getchar();
			break;
		}
		case 3: {//use existing
			Sensor hcSensors[3];
			LED hcLEDs[3];
			int moduleChoice;

			HardCodeModules(hcSensors, hcLEDs);

			moduleChoice = ChooseModule();

			if (moduleChoice < 3) {
				myBreadboardwComponents->m_Sensors[sensorCount] = hcSensors[moduleChoice - 1];
				usedPins = usedPins + myBreadboardwComponents->m_Sensors[sensorCount].m_NumberOfPins;
				myBreadboardwComponents->useOfPotentiometer = CheckMaxVoltage(myBreadboardwComponents, &usedPins);
				sensorCount++;
			}

			else {
				myBreadboardwComponents->m_LEDs[LEDCount] = hcLEDs[moduleChoice - 4];
				usedPins = usedPins + 2; //två för led, två för resistorn 
				LEDCount++;
			}

			getchar();
			printf("Choose again (y/n)?");
			chooseAgain = getchar();
			break;
		}
		}
	}

	getchar();
	//int check = PinsError(&myBreadboardwComponents.m_Breadboard, usedPins);
	CalculateUniquePins(&myBreadboardwComponents->m_Breadboard);
	PinError(&myBreadboardwComponents->m_Breadboard, usedPins);
	CalculateWatt(&myBreadboardwComponents->m_Breadboard.m_OperatingVoltage, &myBreadboardwComponents->m_Breadboard.m_Ampere, &myBreadboardwComponents->m_Breadboard.m_Watt);
	PrintInfoMyTemplate(myBreadboardwComponents, usedPins, LEDCount, sensorCount);

	getchar();

	return 0;
}