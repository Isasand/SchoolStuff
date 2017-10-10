#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>
enum class status {
	ON,
	OFF
};

class Unit
{
public:
	Unit();
	Unit(std::string, std::string, status, int);
	~Unit();

	

	std::string get_Name();
	void set_Name(std::string);
	std::string get_Info();
	void set_Info(std::string);
	int get_Id();
	void set_Id(int);
	status get_Status();
	void set_Status(status);
	void FlipStatus();
private:
	std::string m_Name;
	std::string m_Info;
	status m_Status;
	int m_Id;
	
};

