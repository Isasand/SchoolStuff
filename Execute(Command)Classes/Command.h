#pragma once
#include <string>
#include <iostream>

class Command{
public:
	Command(std::string argInfo, std::string argCommand, int argID);
	~Command();

	std::string get_Command();
	std::string get_Info();
	int get_Id();

//proteced:
	std::string m_Info;
	std::string m_Command;
	int m_Id;
};

