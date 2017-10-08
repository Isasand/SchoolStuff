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

	Execute *p = this;

	void Run(int commandId, Cloud* cloud);
	void ListAllCommands();
	void LoadCommands();
	void ExitProgram();
	int get_ExecutedCommands();
	void PrintCow();
	void SplitCommand(std::string argcommand);

protected:
	std::vector<Command*> m_Commands;
	std::string m_argCommand; //to store command inputed by user
	std::string m_argUnitId; //to store unit id inputed by user
	int m_ExecutedCommands;
	Cloud* m_Cloud;
};



