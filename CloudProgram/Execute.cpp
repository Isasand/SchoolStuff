#include "Execute.h"

//konstruktor som tar en kommandostr�ng och ett cloud
Execute::Execute(std::string argCommand, Cloud* cloud)
{

	bool validId = false;

	m_ActiveCloud = cloud;

	m_ExecutedCommands = 0;
	LoadCommands();
	SplitCommand(argCommand);

	if (m_argUnitId == "not used") {
		for (int i = 0; i < get_NumberOfCommands(); i++) {
			if (getCommandAt(i)->get_Command() == m_argCommand) {
				//n�r ett kommando matchar k�rs Run()-funktionen med IDt 
				Run(getCommandAt(i)->get_Id());
				m_ExecutedCommands++;
			}
		}
	}

	//om mellanslag finns, testa g�r om m_argUnitId till en int att anv�nda f�r ID 
	else {
		try {
			int id = std::stoi(m_argUnitId);
			for (int i = 0; i < m_ActiveCloud->get_NumberOfUnits(); i++) {
				if (m_ActiveCloud->getUnitAt(i)->get_Id() == id) {
					validId = true;
				}
			}
		}
		//�r det annat �n siffror d�r s� hamnar vi h�r och g�r ingenting 
		catch (...) {
		}
	}

	//om mellanslag finns och IDt matchar mot ett ID k�rs r�tt kommando
	if (validId) {
		for (int i = 0; i < get_NumberOfCommands(); i++) {
			if (getCommandAt(i)->get_Command() == m_argCommand) {
				Run(getCommandAt(i)->get_Id());
				m_ExecutedCommands++;
			}
		}
	}

	if (get_ExecutedCommands() == 0) {
		std::cout << "Input a valid command";
	}
}

Execute::~Execute()
{
}

//laddar in alla kommandon i Execute
void Execute::LoadCommands() {
	Command *help = new Command("Lists all command and what they do", "help", 1);
	Command *exit = new Command("Exits program", "exit", 2);
	Command *remove = new Command("Deletes unit with chosen ID, input 'remove <unit ID>'", "remove", 3);
	Command *addunit = new Command("Add a unit to cloud", "addunit", 5);
	Command *changestate = new Command("Change state of unit, input 'changestate <unit ID>'", "changestate", 7);
	Command *showinfo = new Command("Show info about unit, input 'showinfo <unit ID>'", "showinfo", 8);
	Command *showactive = new Command("Prints active units", "showactive", 9);
	Command *changename = new Command("Change name of unit, input 'changename <Unit ID>'", "changename", 10);
	Command *changeinfo = new Command("Changes info of unit, input 'changeinfo <Unit ID>'", "changeinfo", 11);

	AddCommandToExecute(help);
	AddCommandToExecute(exit);
	AddCommandToExecute(remove);
	AddCommandToExecute(addunit);
	AddCommandToExecute(changestate);
	AddCommandToExecute(showinfo);
	AddCommandToExecute(showactive);
	AddCommandToExecute(changename);
	AddCommandToExecute(changeinfo);
}


//Splittar ett kommando om det �r mellanslag 
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

//k�r funktion kopplat till IDt som matchat med kommandot
void Execute::Run(int commandId) {
	switch (commandId) {

	case 1: {//kommando som �r bundet = 'help'
		if (m_argUnitId != "not used") {
			m_ExecutedCommands--;
		}
		else {
			ListAllCommands();
			std::cout << "OK<ENTER>";
		}
		break;
	}
	case 2: { //exit cloud 'exit'
		if (m_argUnitId != "not used") {
			m_ExecutedCommands--;
		}
		else {
			Cloud::ExitCloud();
		}
		break;
	}

	case 3: {
		if (m_ActiveCloud->get_NumberOfUnits() != 0) {
			int id = std::stoi(m_argUnitId);
			Dashboard::RemoveUnit(id, m_ActiveCloud);
		}
		break;
	}

	/*case 4: {// modify unit TODO: l�gg in funktion 

		break;
	}*/

	case 5: { //add unit 
		Unit *newUnit = new Unit();
		newUnit = Dashboard::FillNewUnit();
		Dashboard::GenerateId(m_ActiveCloud, newUnit);
		Dashboard::AddUnit(newUnit, m_ActiveCloud);
		break;
	}

	/*case 6: {
		//search
		break;
	}*/

	case 7: {//change state on unit
		for (int i = 0; i < m_ActiveCloud->get_NumberOfUnits(); i++) {
			try {
				int id = std::stoi(m_argUnitId);
				if (id == m_ActiveCloud->getUnitAt(i)->get_Id()) {
					//Flipstatus �r en funktion som �ndrar ID p� unit till det den inte var innan 
					m_ActiveCloud->getUnitAt(i)->FlipStatus();
					std::cout << "status successfully changed\nOK<ENTER>";
				}
			}
			catch (...) {
			}
		}

		break;

	}
	case 8: { //show info unit
		for (int i = 0; i < m_ActiveCloud->get_NumberOfUnits(); i++) {
			try {
				int id = std::stoi(m_argUnitId);
				if (id == m_ActiveCloud->getUnitAt(i)->get_Id()) {
					std::cout << "showing info about: " << m_ActiveCloud->getUnitAt(i)->get_Name() <<
						std::endl << m_ActiveCloud->getUnitAt(i)->get_Info();
				}
			}
			catch (...) {
			}
		}
		break;
	}

	case 9: {
		Dashboard::ShowActiveUnits(m_ActiveCloud);
		break; 
	}

	case 10: {
		for (int i = 0; i < m_ActiveCloud->get_NumberOfUnits(); i++) {
			try {
				int id = std::stoi(m_argUnitId);
				if (id == m_ActiveCloud->getUnitAt(i)->get_Id()) {
					Dashboard::ChangeUnitName(m_ActiveCloud->getUnitAt(i));
				}
			}
			catch (...) {

			}
		}

		break;
	}
	case 11: {
		for (int i = 0; i < m_ActiveCloud->get_NumberOfUnits(); i++) {
			try {
				int id = std::stoi(m_argUnitId);
				if (id == m_ActiveCloud->getUnitAt(i)->get_Id()) {
					Dashboard::ChangeUnitInfo(m_ActiveCloud->getUnitAt(i));
				}
			}
			catch (...) {

			}
		}

		break;
	}
	}
}

//'help'-kommandot triggar denna
void Execute::ListAllCommands() {
	for (int i = 0; i < m_Commands.size(); i++) {
		std::cout << m_Commands.at(i)->get_Command() << " -- ";
		std::cout << m_Commands.at(i)->get_Info() << "\n";
	}
}

//h�mtar hur m�nga kommandon som k�rts
int Execute::get_ExecutedCommands() {
	return m_ExecutedCommands;
}

int Execute::get_NumberOfCommands() {
	return m_Commands.size();
}

Command* Execute::getCommandAt(int index) {
	return m_Commands.at(index);
}

void Execute::AddCommandToExecute(Command* command) {
	m_Commands.push_back(command);
}