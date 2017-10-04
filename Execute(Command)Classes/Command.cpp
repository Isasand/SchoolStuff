#include "Command.h"

Command::Command(std::string argInfo, std::string argCommand, int argID)
{
	m_Info = argInfo;
	m_Command = argCommand;
	m_Id = argID;

}

Command::~Command()
{
}

std::string Command::get_Command() {
	return m_Command;
}

std::string Command::get_Info() {
	return m_Info;
}

int Command::get_Id() {
	return m_Id;
}