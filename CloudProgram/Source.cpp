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
		std::cin.get();
	}
	return 0;
}