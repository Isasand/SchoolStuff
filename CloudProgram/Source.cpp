#include <iostream>
#include "Cloud.h"
#include "Unit.h"
#include "Dashboard.h"
#include "Execute.h"
#include "Command.h"

int main() {
	//instansierar ett cloud
	Cloud *cloud = new Cloud();
	//skapar ett dashboard, TODO funktion f�r att l�gga in dashboardet i cloudet vi anv�nder 
	Dashboard *dashboard = new Dashboard();
	//variabel att spara inmatat komando i
	std::string command;
	while (true) {
		//clear screen
		ClearScreenFunction();
		//skriv ut v�lkommen fr�n cloud
		cloud->Welcome();
		//dashboard l�ser in clouds vector av units och baserat p� dessa skrivs en tabell ut 
		dashboard->ShowUnits(cloud);
		//fr�ga anv�ndaren efter kommando
		std::cout << "Input command: ";
		//getline h�mtar inmatad str�ng
		getline(std::cin, command);

		//execute skapas och kommandot skickas in tillsammans med cloudet 
		Execute *execute = new Execute(command, cloud);
		//om executedCommands �r 0 s� har inget kommando matchat och du har skrivit in ett invalid comand
		if (execute->get_ExecutedCommands() == 0) {
			std::cout << "Input a valid command";
		}
		//v�nta p� enter innan loopen forts�tter

		std::cin.get();
	}
	return 0;
}