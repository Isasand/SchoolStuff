#include <iostream>
#include "Cloud.h"
#include "Unit.h"
#include "Dashboard.h"
#include "Execute.h"
#include "Command.h"

int main() {
	
	Cloud *cloud = new Cloud();
	Dashboard *dashboard = new Dashboard();
	
	std::string command;
	while (true) {
		
		ClearScreenFunction();
		cloud->Welcome();
		dashboard->ShowUnits(cloud);

		std::cout << "Input command: ";
		getline(std::cin, command);
		Execute *execute = new Execute(command, cloud);
		
		if (execute->get_ExecutedCommands() == 0) {
			std::cout << "Input a valid command";
		}

		std::cin.get();
	}
	return 0;
}