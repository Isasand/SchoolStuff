#include "Execute.h"


Execute::Execute(std::string argCommand, Cloud* cloud)
{
	bool validId = false;
	m_Cloud = cloud;
	m_ExecutedCommands = 0;
	LoadCommands();

	SplitCommand(argCommand);

	if (m_argUnitId == "not used") {
		for (int i = 0; i < m_Commands.size(); i++) {
			if (m_Commands.at(i)->get_Command() == m_argCommand) {
				Run(m_Commands.at(i)->m_Id, cloud);
				m_ExecutedCommands++;
			}
		}
	}

	else {
		try {
			int id = std::stoi(m_argUnitId);
			for (int i = 0; i < cloud->m_CloudUnits.size(); i++) {
				if (cloud->m_CloudUnits.at(i)->get_Id() == id) {
					validId = true;
				}
			}
		}
		catch (...) {
		}
	}

	if (validId) {
		for (int i = 0; i < m_Commands.size(); i++) {
			if (m_Commands.at(i)->get_Command() == m_argCommand) {
				Run(m_Commands.at(i)->m_Id, cloud);
				m_ExecutedCommands++;
			}
		}
	}

}

Execute::~Execute()
{
}

void Execute::LoadCommands() {
	Command *help = new Command("Lists all command and what they do", "help", 1);
	Command *exit = new Command("Exits program", "exit", 2);
	Command *remove = new Command("Deletes unit with chosen ID, input 'remove <unit ID>'", "remove", 3);
	Command *modify = new Command("For modifying information of unit with chosen ID, input 'modify <unit ID>'", "modify", 4);
	Command *addunit = new Command("Add a unit to cloud", "addunit", 5);
	Command *search = new Command("Search unit by ID, input 'search <unit ID>'", "search", 6);
	Command *changestate = new Command("Change state of unit, input 'changestate <unit ID>'", "changestate", 7);
	Command *showinfo = new Command("Show info about unit, input 'showinfo <unit ID>'", "showinfo", 8);

	this->m_Commands.push_back(help);
	this->m_Commands.push_back(exit);
	this->m_Commands.push_back(remove);
	this->m_Commands.push_back(modify);
	/*this->*/m_Commands.push_back(addunit);
	this->m_Commands.push_back(search);
	this->m_Commands.push_back(changestate);
	this->m_Commands.push_back(showinfo);
}

void Execute::Run(int commandId, Cloud* cloud) {
	switch (commandId) {

	case 1: {
		ListAllCommands();
		break;
	}
	case 2: {
		Cloud::ExitCloud();
		break;
	}
	case 3: {//Remove

		break;
	}
	case 4: {
		break;
	}
	case 5: { //add unit 
		Unit *newUnit = new Unit();
		newUnit = Dashboard::FillNewUnit();
		Dashboard::AddUnit(newUnit, m_Cloud);
		break;
	}
	case 6: {
		//search
		break;
	}
	case 7: {//change state
		for (int i = 0; i < cloud->m_CloudUnits.size(); i++) {
			int id = std::stoi(m_argUnitId);
			if (id == cloud->m_CloudUnits.at(i)->get_Id()) {
				cloud->m_CloudUnits.at(i)->FlipStatus();
				std::cout << "status successfully changed\nOK<ENTER>";
			}
		}

		break;

	}
	case 8: { //show info
		for (int i = 0; i < cloud->m_CloudUnits.size(); i++) {
			int id = std::stoi(m_argUnitId);
			if (id == cloud->m_CloudUnits.at(i)->get_Id()) {
				std::cout << "showing info about: " << cloud->m_CloudUnits.at(i)->get_Name() <<
					std::endl << cloud->m_CloudUnits.at(i)->get_Info();
			}
		}
		break;
	}
	}
}

void Execute::ListAllCommands() {
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

void Execute::SplitCommand(std::string argCommand) {
	std::string command;
	std::string unitId;
	bool containingSpace = false;
	for (int i = 0; i < argCommand.size(); i++) {
		if (argCommand.at(i) == ' ') {
			containingSpace = true;
		}

	}
	if (containingSpace) {
		std::stringstream split(argCommand);
		getline(split, command, ' ');
		getline(split, unitId, ' ');

		m_argCommand = command;
		m_argUnitId = unitId;
	}
	else {
		m_argCommand = argCommand;
		m_argUnitId = "not used";
	}
}