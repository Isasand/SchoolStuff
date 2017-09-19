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
		case 1: { //sensor
			Sensor newSensor;
			FillNewSensor(&newSensor);
			PrintInfoSensor(newSensor);
			break;
		}
		case 2: { //LED

			break;
		}
		case 3: {//LCD

			break;
		}
		case 4: {//use existing
			char c;

			fopen_s(&fptr, "Modules.txt", "r");

			CheckFileStatus(fptr);
			printf("Hello");

			if (fptr) {
				c = fgetc(fptr);

				while (c != EOF) {
					if c
				}
			}
			fclose(fptr);

			for (int i = 0; i < 100; i++) {
				for (int j = 0; j < 100; i++) {
					printf("%s", modulesList[i][j]);
				}
			}

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

