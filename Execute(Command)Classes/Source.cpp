#include "Execute.h"
#include "Command.h"
#include	<windows.h>
int main() {

	std::string command;
	while (true) {
		system("CLS");
		std::cout << "Input command: ";
		std::cin >> command;

		Execute *execute = new Execute(command);
		if (execute->get_ExecutedCommands() == 0) {
			std::cout << "Input a valid command";
		}
		std::cin.get();
		std::cin.get();
	}
}
