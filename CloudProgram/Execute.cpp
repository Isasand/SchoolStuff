#include "Execute.h"

//konstruktor som tar en kommandosträng och ett cloud
Execute::Execute(std::string argCommand, Cloud* cloud)
{


	//validId används ifall du matat in ett kommando där du vill göra något med en särsild unit, är inte IDt rätt är den false
	bool validId = false;
	//lägg in cloud som aktiv medlem i Execute
	m_ActiveCloud = cloud;
	//executed commands nollställs
	m_ExecutedCommands = 0;
	//loadcommands laddar in alla kommandon
	LoadCommands();

	//om det finns ett mellanslag i kommandot kollas det här
	SplitCommand(argCommand);

	//om det inte finns mellanslag är argUnitId == Not used och vi matchar mot kommandot
	if (m_argUnitId == "not used") {
		for (int i = 0; i < get_NumberOfCommands(); i++) {
			if (getCommandAt(i)->get_Command() == m_argCommand) {
				//när ett kommando matchar körs Run()-funktionen med IDt på kommandot som matchat
				Run(getCommandAt(i)->m_Id);
				m_ExecutedCommands++;
			}
		}
	}

	//om mellanslag finns, testa gör om m_argUnitId till en int att använda för ID 
	else {
		try {
			int id = std::stoi(m_argUnitId);
			for (int i = 0; i < m_ActiveCloud->get_NumberOfUnits(); i++) {
				if (m_ActiveCloud->getUnitAt(i)->get_Id() == id) {
					validId = true;
				}
			}
		}
		//är det annat än siffror där så hamnar vi här och gör ingenting 
		catch (...) {
		}
	}

	//om mellanslag finns och IDt matchar mot ett ID körs rätt kommando
	if (validId) {
		for (int i = 0; i < get_NumberOfCommands(); i++) {
			if (getCommandAt(i)->get_Command() == m_argCommand) {
				Run(getCommandAt(i)->get_Id());
				m_ExecutedCommands++;
			}
		}
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
	Command *modify = new Command("For modifying information of unit with chosen ID, input 'modify <unit ID>'", "modify", 4);
	Command *addunit = new Command("Add a unit to cloud", "addunit", 5);
	Command *search = new Command("Search unit by ID, input 'search <unit ID>'", "search", 6);
	Command *changestate = new Command("Change state of unit, input 'changestate <unit ID>'", "changestate", 7);
	Command *showinfo = new Command("Show info about unit, input 'showinfo <unit ID>'", "showinfo", 8);

	AddCommandToExecute(help);
	AddCommandToExecute(exit);
	AddCommandToExecute(remove);
	AddCommandToExecute(modify);
	AddCommandToExecute(addunit);
	AddCommandToExecute(search);
	AddCommandToExecute(changestate);
	AddCommandToExecute(showinfo);
}

//kör funktion kopplat till IDt som matchat med kommandot
void Execute::Run(int commandId) {
	switch (commandId) {

	case 1: {//kommando som är bundet = 'help'
		ListAllCommands();
		break;
	}
	case 2: { //exit cloud 'exitä
		Cloud::ExitCloud();
		break;
	}

	case 3: {//Remove unit TODO: flytta hit funktionen från dashboard
		if (m_ActiveCloud->get_NumberOfUnits() != 0) {
			int id = std::stoi(m_argUnitId);
			Dashboard::RemoveUnit(id, m_ActiveCloud);
		}
		break;
	}

	case 4: {// modify unit TODO: lägg in funktion 

		break;
	}

	case 5: { //add unit 
		Unit *newUnit = new Unit();
		newUnit = Dashboard::FillNewUnit();
		Dashboard::AddUnit(newUnit, m_ActiveCloud);
		break;
	}

	case 6: {
		//search
		break;
	}

	case 7: {//change state on unit
		for (int i = 0; i < m_ActiveCloud->get_NumberOfUnits(); i++) {
			int id = std::stoi(m_argUnitId);
			if (id == m_ActiveCloud->getUnitAt(i)->get_Id()) {
				//Flipstatus är en funktion som ändrar ID på unit till det den inte var innan 
				m_ActiveCloud->getUnitAt(i)->FlipStatus();
				std::cout << "status successfully changed\nOK<ENTER>";
			}
		}
	
		break;

	}
	case 8: { //show info unit
		for (int i = 0; i < m_ActiveCloud->get_NumberOfUnits(); i++) {
			int id = std::stoi(m_argUnitId);
			if (id == m_ActiveCloud->getUnitAt(i)->get_Id()) {
				std::cout << "showing info about: " << m_ActiveCloud->getUnitAt(i)->get_Name() <<
					std::endl << m_ActiveCloud->getUnitAt(i)->get_Info();
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

//en exit-funktion för att stänga av programmet, vi använder den som ligger i cloud istället :) 
void Execute::ExitProgram() {
	exit(0);
}

//hämtar hur många kommandon som körts
int Execute::get_ExecutedCommands() {
	return m_ExecutedCommands;
}

//Splittar ett kommando om det är mellanslag 
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

int Execute::get_NumberOfCommands() {
	return m_Commands.size();
}

Command* Execute::getCommandAt(int index) {
	return m_Commands.at(index);
}

void Execute::AddCommandToExecute(Command* command) {
	m_Commands.push_back(command);
}