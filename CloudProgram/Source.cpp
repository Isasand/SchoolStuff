#include <iostream>
#include "Cloud.h"
#include "Unit.h"


int main() {

	Cloud *cloud = new Cloud();
	int menuChoice = 0;
	while (true) {
		ClearScreenFunction();
		menuChoice = cloud->StartMenu();

		switch (menuChoice) {

		case 1: { //show connected units
			cloud->ListUnits();
			std::cin.get();
			std::cout << "OK<ENTER>";
			std::cin.get();
			break;
		}

		case 2: {// add unit
			Unit *unit = new Unit();
			cloud->FillNewUnit(unit);
			cloud->AddUnit(unit);
			std::cout << "OK<ENTER>";
			std::cin.get();
			std::cin.get();
			break;
		}
		case 3: {//remove unit
			if (cloud->get_NumberOfUnits() == 0) {
				std::cout << "No units to remove";
				SleepFunction(1000);
				break;
			}
			cloud->ListUnits();
			int unitId = cloud->ChooseUnitById();
			cloud->RemoveUnit(unitId);
			break;
		}
		case 4: { //show dashboard
			break;
		}

		case 5: { //exit
			std::cout << "Closing program";
			SleepFunction(300);
			ClearScreenFunction();
			exit(0);
			break;
		}

		default: {
			std::cout << "Wrong input, try again!";
			SleepFunction(400);
			ClearScreenFunction();
			break;
		}
		}
	}
	return 0;
}