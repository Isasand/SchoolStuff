#pragma once
#include "Command.h"
#include <vector>
#include <iostream>
#include <string>

class Execute
{
public:
	Execute(std::string argCommand);
	~Execute();

	void Run(int commandId);
	void ListAllCommands();
	void LoadCommands();
	void ExitProgram();
	int get_ExecutedCommands();
protected: 
	std::vector<Command*> m_Commands;
	int m_ExecutedCommands;
};







