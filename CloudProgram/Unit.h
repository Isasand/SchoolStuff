#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>



class Unit
{
public:
	Unit();
	Unit(std::string, std::string, bool, int);
	~Unit();

	std::string get_Name();
	void set_Name(std::string);
	std::string get_Info();
	void set_Info(std::string);
	int get_Id();
	void set_Id(int);
	bool get_Status();
	void set_Status(bool);
private:

	std::string m_Name;
	std::string m_Info;
	bool m_Status;
	int m_Id;
};

