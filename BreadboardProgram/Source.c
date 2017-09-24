#include "Source.h"

int main() {
	bool restart = true;

	while (restart) { //program is running until you choose Exit in menu 
		
		MyTemplate *myBreadboardwComponents = malloc(sizeof(MyTemplate));

		//counter for used pins
		int usedPins = 0;

		int menuChoice;
		system("CLS");
		menuChoice = Menu();
		getchar();

		switch (menuChoice) { //new breadboard, use existing breadboard, exit program

		case 1: { // new breadboard
			//cls clears screen
			system("CLS");
			Breadboard newBreadboard;
			
			FillNewBreadboard(&newBreadboard);
			//calculate total connections on board
			newBreadboard.m_Connections = CalcConnections(&newBreadboard.m_Pins_X, &newBreadboard.m_Pins_Y);
			system("CLS");
			printf("New breadboard created with the following properties:\n\n");
			PrintInfoBreadboard(newBreadboard);
			printf("\nOK(ENTER)");
			getchar();
			//put breadboard in stuct containing all your components
			myBreadboardwComponents->m_Breadboard = newBreadboard;
			break;
		}
		case 2: { //use existing breadboard
			system("CLS");
			Breadboard hcBreadboard;
			HardCodeBreadboard(&hcBreadboard);
			printf("Using breadboard with the following properties:\n\n");
			PrintInfoBreadboard(hcBreadboard);
			printf("\nOK(ENTER)");
			//put breadboard in struct containing all your components
			myBreadboardwComponents->m_Breadboard = hcBreadboard;
			getchar();
			break;
		}
		case 3: { //exit program
			free(myBreadboardwComponents);
			system("CLS");
			printf("Closing program");
			Sleep(500);
			exit(0);
			break;
		}
		}

		//counters for number of leds and number of sensors chosen
		//used in print functions and for filling the struct containing all components
		int LEDCount = 0, sensorCount = 0;

		char chooseAgain = 'y';
		while ((chooseAgain == 'y') || (chooseAgain == 'Y')) {
			system("CLS");
			int choice = ComponentsMenu(); //new sensor, new LED, use existing

			switch (choice) {

			case 1: { //new sensor

				system("CLS");
				Sensor newSensor;

				FillNewSensor(&newSensor);
				PrintInfoSensor(newSensor);
				//add sensor to struct containing all your components
				myBreadboardwComponents->m_Sensors[sensorCount] = newSensor;
				//add sensor's number of pins to used pins 
				usedPins = usedPins + myBreadboardwComponents->m_Sensors[sensorCount].m_NumberOfPins;
				sensorCount++;
				getchar();
				printf("Choose again (y/n)?");
				chooseAgain = getchar();

				break;
			}
			case 2: {//new LED

				system("CLS");
				//Create new led
				LED newLED;
				FillNewLED(&newLED);
				printf("\nNew LED created with the following properties");
				PrintInfoLED(newLED);
				//add leds to struct containing all your components
				myBreadboardwComponents->m_LEDs[LEDCount] = newLED;
				usedPins = usedPins + 2;
				LEDCount++;
				getchar();
				printf("Add more components (y/n)?");
				chooseAgain = getchar();
				break;
			}
			case 3: {//use existing

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
					myBreadboardwComponents->useOfPotentiometer = CheckMaxVoltage(myBreadboardwComponents, &usedPins);
					sensorCount++;
				}
				//the rest are LEDs
				else {
					myBreadboardwComponents->m_LEDs[LEDCount] = hcLEDs[moduleChoice - 4];
					usedPins = usedPins + 2; 
					LEDCount++;
				}

				getchar();
				printf("Add more components (y/n)?");
				chooseAgain = getchar();
				break;
			}
			}
		}

		system("CLS");
		getchar();
	
		CalculateUniquePins(&myBreadboardwComponents->m_Breadboard);
		//check if used pins are equal to unique pins on board (and print warning if 50 % are used)
		PinError(&myBreadboardwComponents->m_Breadboard, usedPins);

		//calculate breadboard watt if using it (defined in source.h)
		CalculateWatt(&myBreadboardwComponents->m_Breadboard.m_OperatingVoltage, &myBreadboardwComponents->m_Breadboard.m_Ampere, &myBreadboardwComponents->m_Breadboard.m_Watt);
		
		//print information about struct containing all your components 
		PrintInfoMyTemplate(myBreadboardwComponents, usedPins, LEDCount, sensorCount);

		getchar();

		free(myBreadboardwComponents);
	}
	return 0;
}

