#include "Execute.h"
#include <vector>

Execute::Execute(std::string argCommand)
{
	m_ExecutedCommands = 0;
	LoadCommands();

	for (int i = 0; i < m_Commands.size(); i++) {
		if (m_Commands.at(i)->get_Command() == argCommand){
			Run(m_Commands.at(i)->m_Id);
			m_ExecutedCommands++;
		}
	}
}

Execute::~Execute()
{
}

void Execute::LoadCommands() {
	Command *help = new Command("Lists all command and what they do", "help", 1);
	Command *exit = new Command("Exits program", "exit", 2);
	Command *printCow = new Command("Prints a cow", "printCow", 3);
	m_Commands.push_back(help);
	m_Commands.push_back(exit);
	m_Commands.push_back(printCow);
}

void Execute::Run(int commandId) {
	switch (commandId) {

	case 1: {
		ListAllCommands();
		break;
	}
	case 2: {
		ExitProgram();
		break;
	}
	case 3: {
		PrintCow();
		break;
	}
	}
}

void Execute::PrintCow() {
	std::cout << "          (__)\n"
		<< "          (oo)\n"
		<< "   /-------\\/ \n"
		<< "  / |     ||\n"
		<< " *  ||----||  \n"
		<< "    ^^    ^^ \n";
}
void Execute::ListAllCommands(){
	for (int i = 0; i < m_Commands.size(); i++) {
		std::cout << m_Commands.at(i)->get_Command() << " -- ";
		std::cout << m_Commands.at(i)->get_Info() << "\n";
	}
}

void Execute::ExitProgram() {
	exit(0);
}

int Execute::get_ExecutedCommands() {
	return m_ExecutedCommands;
}