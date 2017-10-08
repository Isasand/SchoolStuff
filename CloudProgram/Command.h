#pragma once
#include <string>
#include <iostream>

class Command {

	friend class Execute;

public:

	Command(std::string argInfo, std::string argCommand, int argID);
	~Command();

	std::string get_Command();
	std::string get_Info();
	int get_Id();

protected:
	std::string m_Info;
	std::string m_Command;
	int m_Id;
};

