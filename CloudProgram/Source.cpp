#include <iostream>
#include "Cloud.h"
#include "Unit.h"
#include "Dashboard.h"
#include "Execute.h"
#include "Command.h"

int main() {
	//instansierar ett cloud
	Cloud *cloud = new Cloud();
	//skapar ett dashboard, TODO funktion för att lägga in dashboardet i cloudet vi använder 
	Dashboard *dashboard = new Dashboard();
	//variabel att spara inmatat komando i
	std::string command;
	while (true) {
		//clear screen
		ClearScreenFunction();
		//skriv ut välkommen från cloud
		cloud->Welcome();
		//dashboard läser in clouds vector av units och baserat på dessa skrivs en tabell ut 
		dashboard->ShowUnits(cloud);
		//fråga användaren efter kommando
		std::cout << "Input command: ";
		//getline hämtar inmatad sträng
		getline(std::cin, command);

		//execute skapas och kommandot skickas in tillsammans med cloudet 
		Execute *execute = new Execute(command, cloud);
		//om executedCommands är 0 så har inget kommando matchat och du har skrivit in ett invalid comand
		if (execute->get_ExecutedCommands() == 0) {
			std::cout << "Input a valid command";
		}
		//vänta på enter innan loopen fortsätter

		std::cin.get();
	}
	return 0;
}