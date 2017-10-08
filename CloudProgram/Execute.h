#pragma once
#include "Command.h"
#include "Cloud.h"
#include "Unit.h"
#include "Dashboard.h"
#include <vector>
#include <iostream>
#include <string>

class Execute
{
public:
	Execute(std::string argCommand, Cloud* cloud);
	~Execute();

	Execute *p = this;

	void Run(int commandId);
	void ListAllCommands();
	void LoadCommands();
	void ExitProgram();
	int get_ExecutedCommands();
	void PrintCow();

protected:
	std::vector<Command*> m_Commands;
	int m_ExecutedCommands;
	Cloud* m_Cloud;
};



