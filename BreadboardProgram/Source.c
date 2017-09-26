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

		CalculateBreadboardWatt(&myBreadboardwComponents->m_Breadboard.m_OperatingVoltage, &myBreadboardwComponents->m_Breadboard.m_Ampere, &myBreadboardwComponents->m_Breadboard.m_Watt);

		//print information about struct containing all your components 
		PrintInfoMyTemplate(myBreadboardwComponents, usedPins, LEDCount, sensorCount);

		getchar();

		free(myBreadboardwComponents);
	}
	return 0;
}

/*
*
*
*
Function definitions
*
*
*/

#if USING_AMPERE_AND_WATT
//here are functions defined if using sensor ampere and watt, its hard to find specs containing
//info about components max watt and ampere, so default is not using it 
void CalculateComponentWatt(float *volt, float *ampere, float *watt) {
	(*watt) = (*volt) * (*ampere);
}

int TotalWattCalculation(MyTemplate *breadboardWComponents, int sensorCount, int LEDCount) {
	int totalWatt = 0;
	for (int i = 0; i < sensorCount; i++) {
		totalWatt = totalWatt + breadboardWComponents->m_Sensors[i].m_Watt;
	}

	for (int j = 0; j < LEDCount; j++) {
		totalWatt = totalWatt + breadboardWComponents->m_LEDs[j].m_Watt;
	}
	return totalWatt;
}

void PowerErrorMessage(int totalWatt, Breadboard b) { 

	if (totalWatt > b.m_Watt) {
		printf("***Total effect of components to high***");
	}
}

#else 

int CalculateComponentWatt() {
	return 0;
}

int TotalWattCalculation() {
	return 0;
}

int PowerErrorMessage() {
	return 0;
}

#endif

void CalculateBreadboardWatt(float *volt, float *ampere, float *watt) {
	(*watt) = (*volt) * (*ampere);
}

int Menu() {
	int choice;
	printf("1. New breadboard\n");
	printf("2. Use existing breadboard\n");
	printf("3. Exit program\n");
	scanf_s("%d", &choice);
	return choice;
}

void FillNewBreadboard(Breadboard *b) {
	float lenght = 0.0, width = 0.0, opVoltage = 0.0, ampere = 0.0;
	int connections = 0;
	printf("Number of pins (vertical): ");
	scanf_s("%f", &lenght);
	b->m_Pins_X = lenght;
	printf("Number of pins (Horizontal): ");
	scanf_s("%f", &width);
	b->m_Pins_Y = width;
	printf("Operating voltage: ");
	scanf_s("%f", &opVoltage);
	b->m_OperatingVoltage = opVoltage;
	printf("Ampere: ");
	scanf_s("%f", &ampere);
	b->m_Ampere = ampere;

	getchar();
}

int CalcConnections(int  *pinsX, int *pinsY) {
	int returnValue = ((*pinsX) * (*pinsY));
	return returnValue;
}

void PrintInfoBreadboard(Breadboard b) {
	printf("Pins (vertical): %d \n", b.m_Pins_X);
	printf("Pins (Horizontal): %d \n", b.m_Pins_Y);
	printf("Available pin connections: %d\n", b.m_Connections);
	printf("Operating voltage: %.1fV\n", b.m_OperatingVoltage);
	printf("Ampere: %.1f\n\n", b.m_Ampere);
}

int ComponentsMenu() {
	int choice;
	printf("Add type of component for attatchment to breadboard\n");
	printf("1. Sensor\n");
	printf("2. LED\n");
	printf("3. Use existing\n");
	scanf_s("%d", &choice);
	return choice;
}

void FillNewSensor(Sensor *s) {
	char *sensorType = malloc(50), *model = malloc(20);
	int numberOfPins = 0;
	float maxOpVolt = 0.0, minOpVolt = 0.0, ampere = 0.0;
	printf("Sensor type: ");
	getchar();
	fgets(sensorType, 50, stdin);
	strcpy(s->m_SensorType, sensorType);
	printf("Model: ");
	fgets(model, 20, stdin);
	strcpy(s->m_Model, model);
	printf("Number of pins: ");
	scanf_s("%d", &numberOfPins);
	s->m_NumberOfPins = numberOfPins;
	printf("Max operating voltage: ");
	scanf_s("%f", &maxOpVolt);
	s->m_MaxOperatingVoltage = maxOpVolt;
	printf("Min operating voltage: ");
	scanf_s("%f", &minOpVolt);
	s->m_MinOperatingVoltage = minOpVolt;
	if (USING_AMPERE_AND_WATT) {
		printf("Ampere: ");
		scanf_s("%f", &ampere);
		s->m_Ampere = ampere;
	}
	getchar();
	free(sensorType);
	free(model);
}

void PrintInfoSensor(Sensor s) {
	printf("Sensor type: %s", s.m_SensorType);
	printf("Model: %s", s.m_Model);
	printf("Number of pins: %d\n", s.m_NumberOfPins);
	printf("Max operating voltage: %.1fV\n", s.m_MaxOperatingVoltage);
	printf("Min operating voltage: %.1fV\n", s.m_MinOperatingVoltage);
	if (USING_AMPERE_AND_WATT)
		printf("Ampere: %.1f\n\n", s.m_Ampere);
}

void FillNewLED(LED *led) {
	char *color = malloc(20);
	float maxOpVolt, minOpVolt;

	printf("Color: ");
	getchar();
	fgets(color, 20, stdin);
	strcpy(led->m_Color, color);
	printf("Max operating voltage: ");
	scanf_s("%f", &maxOpVolt);
	led->m_MaxOperatingVoltage = maxOpVolt;
	printf("Min operating voltage: ");
	scanf_s("%f", &minOpVolt);
	led->m_MinOperatingVoltage = minOpVolt;
	getchar();
	free(color);
}

void PrintInfoLED(LED led) {
	printf("Color: %s", led.m_Color);
	printf("Max operating voltage: %.1f", led.m_MaxOperatingVoltage);
	printf("\nMin operating voltage: %.1f\n", led.m_MinOperatingVoltage);
}

void HardCodeBreadboard(Breadboard *a) {
	//hard codes a breadboard
	a->m_Pins_X = 20; a->m_Pins_Y = 10;
	a->m_Connections = 200;
	a->m_OperatingVoltage = 5;
	a->m_Ampere = 0.5;
}

void HardCodeModules(Sensor *hcSensors, LED *leds) {
	//hard codes three sensors and three leds to choose in program 
	strcpy(hcSensors[0].m_SensorType, "Soil Moisture Sensor");
	strcpy(hcSensors[0].m_Model, "LM393");
	hcSensors[0].m_NumberOfPins = 4; hcSensors[0].m_MaxOperatingVoltage = 5; hcSensors[0].m_MinOperatingVoltage = 3.3; if (USING_AMPERE_AND_WATT) hcSensors[0].m_Ampere = 0.1;

	strcpy(hcSensors[1].m_SensorType, "Ultrasonic Sensor");
	strcpy(hcSensors[1].m_Model, "HC-SR04");
	hcSensors[1].m_NumberOfPins = 4; hcSensors[1].m_MaxOperatingVoltage = 5; hcSensors[1].m_MinOperatingVoltage = 5; if (USING_AMPERE_AND_WATT) hcSensors[1].m_Ampere = 0.1;

	strcpy(hcSensors[2].m_SensorType, "Temperature/ Humidity Sensor");
	strcpy(hcSensors[2].m_Model, "DHT11");
	hcSensors[2].m_NumberOfPins = 3; hcSensors[2].m_MaxOperatingVoltage = 5; hcSensors[2].m_MinOperatingVoltage = 5; if (USING_AMPERE_AND_WATT) hcSensors[2].m_Ampere = 0.1;

	strcpy(leds[0].m_Color, "Red"); leds[0].m_MaxOperatingVoltage = 2.2; leds[0].m_MinOperatingVoltage = 1.8;
	strcpy(leds[1].m_Color, "Green"); leds[1].m_MaxOperatingVoltage = 2.2; leds[1].m_MinOperatingVoltage = 1.8;
	strcpy(leds[2].m_Color, "Green"); leds[2].m_MaxOperatingVoltage = 2.2; leds[2].m_MinOperatingVoltage = 1.8;
}

int ChooseModule() {
	int choice = 0;
	printf("Choose which module to use\n");
	printf("Sensors:\n");
	printf("\n1. Soil Moisture Sensor");
	printf("\n2. Ultrasonic Sensor");
	printf("\n3. Temperature/ Humidity Sensor");
	printf("\n\nLEDs:\n\n4. Red\n5. Green\n6. Blue\n");
	scanf_s("%d", &choice);
	return choice;
}

void PrintInfoMyTemplate(MyTemplate *myTemplate, int usedPins, int LEDCount, int sensorCount) {

	//use led and sensor count to print all the components you have chosen 

	printf("Breadboard (%d connections, %.1fV)\n", myTemplate->m_Breadboard.m_Connections, myTemplate->m_Breadboard.m_OperatingVoltage);
	printf("Watt: %.1f\n", myTemplate->m_Breadboard.m_Watt);
	if (sensorCount != 0) {
		printf("Sensors:\n");
		for (int i = 0; i < sensorCount; i++) {
			//print sensor type 
			printf("%s\n", myTemplate->m_Sensors[i].m_SensorType);
		}
	}

	if (LEDCount != 0) {
		printf("\nLEDS:\n");
		for (int j = 0; j < LEDCount; j++) {
			//print colot and max operating voltage
			printf("%s", myTemplate->m_LEDs[j].m_Color);
			if ((myTemplate->m_LEDs[j].m_MaxOperatingVoltage) != 0.0) {
				printf("(%.1fV max)\n", myTemplate->m_LEDs[j].m_MaxOperatingVoltage);
			}
		}
	}

	printf("Used pins: %d", usedPins);

}

int CheckMaxVoltage(MyTemplate *myTemplate, int *usedPins) {
	//if breadboards operating voltage is higher than sensors max voltage, we need to add a potentiometer
	if (myTemplate->m_Breadboard.m_OperatingVoltage > myTemplate->m_Sensors[0].m_MaxOperatingVoltage) {
		printf("\n**Since this module needs voltage regulation we added a potentiometer (uses 3 connection pins)**\n");
		*usedPins = *usedPins + 3;
		return 1;
	}
	else {
		return 0;
	}
}

void CalculateUniquePins(Breadboard* b) {
	//get unique pins by taking pins_x * 2, breadboards are often designed with two sides being independent from each other
	b->m_UniquePins = b->m_Pins_X * 2;
}

int PinError(Breadboard* b, int usedPins) {
	//if used pins are bigger than the unique pins on the board
	if (b->m_UniquePins < usedPins) {
		printf("\n***No more unique pins available, pick a bigger board***\n");
		return 1;
	}
	//if you used half of the unique pins, print warning. 
	//because the pins are rarely placed right next to each other
	if (b->m_UniquePins * 0.5 < usedPins) {
		printf("\n***You're running out of unique pins, pick a bigger board***\n");
		return 1;
	}

	else {
		return 0;
	}

}