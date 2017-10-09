#pragma once
#include "Command.h"
#include "Cloud.h"
#include "Unit.h"
#include "Dashboard.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

class Execute
{
public:
	Execute(std::string argCommand, Cloud* cloud);
	~Execute();

	void Run(int commandId);
	void ListAllCommands();
	void LoadCommands();
	//void ExitProgram();
	int get_ExecutedCommands();
	void SplitCommand(std::string argcommand);
	int get_NumberOfCommands();
	Command* getCommandAt(int index);
	void AddCommandToExecute(Command* command);

protected:
	std::vector<Command*> m_Commands;
	std::string m_argCommand; //to store command inputed by user
	std::string m_argUnitId; //to store unit id inputed by user
	int m_ExecutedCommands; //Antal exekverade kommandon
	Cloud* m_ActiveCloud; //aktiva cloudet
};



