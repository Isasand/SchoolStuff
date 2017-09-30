#include "Source.h"

int main() {
	bool restart = true;

	//counter for used pins, choosed LEDs, choosed sensors
	int usedPins = 0, LEDCount = 0, sensorCount = 0, pickComponent = 0, check = 0;
	MyTemplate *myBreadboardwComponents = malloc(sizeof(MyTemplate));
	Breadboard hcBreadboard;
	HardCodeBreadboard(&hcBreadboard);
	myBreadboardwComponents->m_Breadboard = hcBreadboard;

	while (restart) { //program is running until you choose Exit in menu 


		system("CLS");
		int menuChoice = Menu();
		/*attach new component,
		attach existing component,
		move/remove,
		preview,
		exit*/
		getchar();

		switch (menuChoice) {

		case 1: { // attach new component
			char chooseAgain = 'y';

			while ((chooseAgain == 'y') || (chooseAgain == 'Y')) {
				system("CLS");
				int choice = ComponentsMenu(); //new sensor, new LED

				switch (choice) {

				case 1: { //new sensor
					system("CLS");
					Sensor newSensor;

					FillNewSensor(&newSensor);
					AttachSensor(&newSensor);
					SetSensorSymbol(&newSensor);
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
					AttachLED(&newLED);
					SetLEDSymbol(&newLED);
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
				}
			}
			break;
		}
		case 2: { //attach existing component
			char chooseAgain = 'y';

			while ((chooseAgain == 'y') || (chooseAgain == 'Y')) {
				system("CLS");
				Sensor hcSensors[3];
				LED hcLEDs[3];
				int moduleChoice;
				//hard code some modules
				HardCodeModules(hcSensors, hcLEDs);

				moduleChoice = ChooseModule();

				//the first three elements are sensors
				if (moduleChoice <= 3) {
					AttachSensor(&hcSensors[moduleChoice - 1]);
					SetSensorSymbol(&hcSensors[moduleChoice - 1]);
					myBreadboardwComponents->m_Sensors[sensorCount] = hcSensors[moduleChoice - 1];
					usedPins = usedPins + myBreadboardwComponents->m_Sensors[sensorCount].m_NumberOfPins;
					myBreadboardwComponents->useOfPotentiometer = CheckMaxVoltage(myBreadboardwComponents, &usedPins);
					sensorCount++;

				}
				//the rest are LEDs
				else {
					AttachLED(&hcLEDs[moduleChoice - 4]);
					SetLEDSymbol(&hcLEDs[moduleChoice - 4]);
					myBreadboardwComponents->m_LEDs[LEDCount] = hcLEDs[moduleChoice - 4];
					usedPins = usedPins + 2;
					LEDCount++;
				}

				getchar();
				printf("Add more components (y/n)?");
				chooseAgain = getchar();
			}
			break;
		}
		case 3: { //move/remove attached component

			if (sensorCount == 0 && LEDCount == 0) {
				printf("Breadboard is empty");
				Sleep(400);
				break;
			}

			system("CLS");
			pickComponent = PickComponent(myBreadboardwComponents, sensorCount, LEDCount);
			MvRm(myBreadboardwComponents, pickComponent, sensorCount, LEDCount);
			break;
		}
		case 4: { //preview breadboard
			PrintVisualBreadboard(myBreadboardwComponents, sensorCount, LEDCount);
			PrintInfoMyTemplate(myBreadboardwComponents, usedPins, LEDCount, sensorCount);
			getchar();
			break;

		}

		case 5: { // exit program
			free(myBreadboardwComponents);
			system("CLS");
			printf("Closing program");
			Sleep(500);
			exit(0);
			break;
		}
		}

		/*system("CLS");
		getchar();
		//print information about struct containing all your components
		
		free(myBreadboardwComponents);*/
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

void SetSensorSymbol(Sensor* sensor) {
	sensor->m_Symbol = 'S';
}

void SetLEDSymbol(LED* led) {
	led->m_Symbol = 'L';
}

void PrintVisualBreadboard(MyTemplate *myTemplate, int cSensors, int cLEDs) {
	char board[10][30];


	printf("\nMy BreadBoard:\n");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 30; j++) {
			board[i][j] = 'X';
		}
	}

	for (int i = 0; i < cSensors; i++) {
		board[myTemplate->m_Sensors[i].m_AnodX - 1][myTemplate->m_Sensors[i].m_AnodY - 1] = myTemplate->m_Sensors[i].m_Symbol;
		board[myTemplate->m_Sensors[i].m_KatodX - 1][myTemplate->m_Sensors[i].m_KatodY - 1] = myTemplate->m_Sensors[i].m_Symbol;
	}

	for (int i = 0; i < cLEDs; i++) {
		board[myTemplate->m_LEDs[i].m_AnodX - 1][myTemplate->m_LEDs[i].m_AnodY - 1] = myTemplate->m_LEDs[i].m_Symbol;
		board[myTemplate->m_LEDs[i].m_KatodX - 1][myTemplate->m_LEDs[i].m_KatodY - 1] = myTemplate->m_LEDs[i].m_Symbol;
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 30; j++) {
			printf("[%c]", board[i][j]);
		}

		printf("\n");
	}
}

int Menu() {
	int choice;
	printf("Welcome to your breadboard!\n\n");
	printf("1. Attach new component\n");
	printf("2. Attach existing component\n");
	printf("3. Move/ remove attached component\n");
	printf("4. Preview breadboard\n");
	printf("5. Exit\n");
	scanf_s("%d", &choice);
	return choice;
}

void AttachSensor(Sensor *sensor) {
	char str[4];
	int x = 0, y = 0;
	printf("Input coordinates for sensor anod like x,y: ");
	scanf("%s", str);
	char s;
	sscanf(str, "%d %c %d", &x, &s, &y);
	sensor->m_AnodX = x;
	sensor->m_AnodY = y;


	printf("\nInput coordinates for sensor katod like x,y: ");
	scanf("%s", str);
	sscanf(str, "%d %c %d", &x, &s, &y);
	sensor->m_KatodX = x;
	sensor->m_KatodY = y;
}

void AttachLED(LED *led) {
	char str[4];
	printf("Input coordinates for LED anod like x,y: ");
	scanf("%s", str);
	char s;
	int x = 0, y = 0;
	sscanf(str, "%d %c %d", &x, &s, &y);
	led->m_AnodX = x;
	led->m_AnodY = y;


	printf("\nInput coordinates for sensor katod like x,y: ");
	scanf("%s", str);
	sscanf(str, "%d %c %d", &x, &s, &y);
	led->m_KatodX = x;
	led->m_KatodY = y;
}

int PickComponent(MyTemplate *breadboardWComponents, int cSensors, int cLEDs) {
	int pickedComponent = 0;
	int i = 0;

	printf("Pick component:\n");

	if (cSensors != 0) {
		for (i; i < cSensors; i++) {
			//print sensor type 
			if (breadboardWComponents->m_Sensors[i].m_Symbol != 'X') {
				printf("%d. %s\n", i + 1, breadboardWComponents->m_Sensors[i].m_SensorType);
			}
		}

	}

	if (cLEDs != 0) {
		for (i = cSensors-1; i < cLEDs; i++) {
			//print led
			if (breadboardWComponents->m_LEDs[i].m_Symbol != 'X') {
				printf("%d. LED (Color: %s)\n", i + 1, breadboardWComponents->m_LEDs[i].m_Color);
			}
		}
	}
	scanf("%d", &pickedComponent);

	return pickedComponent;
}

void MvRm(MyTemplate *breadboardWComponents, int pickedComponent, int cSensors, int cLEDs) {
	int mvOrRm = 0;

	printf("1. Move Component\n");
	printf("2. Remove Component\n");
	printf("3. Clear breadboard\n");
	scanf("%d", &mvOrRm);

	if (mvOrRm == 3) {
		printf("I will clear the breadboard here");
	}

	//if pickedComponent is smaller than cSensors, the picked component is a sensor
	else if (pickedComponent <= cSensors) {
		if (mvOrRm == 1) {
			AttachSensor(&breadboardWComponents->m_Sensors[pickedComponent - 1]);
		}

		else if (mvOrRm == 2) {
			RmSensor(&breadboardWComponents->m_Sensors[pickedComponent - 1]);
		}
	}

	else {
		if (mvOrRm == 1) {
			AttachLED(&breadboardWComponents->m_LEDs[cSensors + cLEDs - pickedComponent - 1]);
		}

		else if (mvOrRm == 2) {
			RmLED(&breadboardWComponents->m_LEDs[cSensors + cLEDs - pickedComponent - 1]);
		}//;

	}
}

//TODO 


void RmSensor(Sensor *sensor) {
	sensor->m_Symbol = 'X';
}


void RmLED(LED *led) {
	led->m_Symbol = 'X';
}

void ClearBoard(MyTemplate *breadboard) {

}


void PrintInfoBreadboard(Breadboard b) {
	printf("Pins (vertical): %d \n", b.m_Pins_X);
	printf("Pins (Horizontal): %d \n", b.m_Pins_Y);
	printf("Available pin connections: %d\n", b.m_Connections);
	printf("Operating voltage: %.1fV\n", b.m_OperatingVoltage);
}

int ComponentsMenu() {
	int choice;
	printf("Add type of component for attatchment to breadboard\n");
	printf("1. Sensor\n");
	printf("2. LED\n");
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
	a->m_Pins_X = 10; a->m_Pins_Y = 30;
	a->m_Connections = 300;
	a->m_OperatingVoltage = 5;
}

void HardCodeModules(Sensor *hcSensors, LED *leds) {
	//hard codes three sensors and three leds to choose in program 
	strcpy(hcSensors[0].m_SensorType, "Soil Moisture Sensor");
	strcpy(hcSensors[0].m_Model, "LM393");
	hcSensors[0].m_NumberOfPins = 4; hcSensors[0].m_MaxOperatingVoltage = 5; hcSensors[0].m_MinOperatingVoltage = 3.3;

	strcpy(hcSensors[1].m_SensorType, "Ultrasonic Sensor");
	strcpy(hcSensors[1].m_Model, "HC-SR04");
	hcSensors[1].m_NumberOfPins = 4; hcSensors[1].m_MaxOperatingVoltage = 5; hcSensors[1].m_MinOperatingVoltage = 5;

	strcpy(hcSensors[2].m_SensorType, "Temperature/ Humidity Sensor");
	strcpy(hcSensors[2].m_Model, "DHT11");
	hcSensors[2].m_NumberOfPins = 3; hcSensors[2].m_MaxOperatingVoltage = 5; hcSensors[2].m_MinOperatingVoltage = 5;

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
/*
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

}*/