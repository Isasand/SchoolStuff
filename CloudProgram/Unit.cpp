#include "Unit.h"

Unit::Unit(){

};

Unit::Unit(std::string name, std::string info, status status, int id) {

	m_Name = name;
	m_Info = info;
	m_Status = status;
	m_Id = id;

};

Unit::~Unit() {};

std::string Unit::get_Name() {
	return m_Name;
};
void Unit::set_Name(std::string name) {
		m_Name = name;
	
};
std::string Unit::get_Info() {
	return m_Info;
};
void Unit::set_Info(std::string info) {
	m_Info = info;
};
int Unit::get_Id() {
	return m_Id;
};
void Unit::set_Id(int id) {
	m_Id = id;
};

status Unit::get_Status() {
	return m_Status;
};

void Unit::set_Status(status status) {
	m_Status = status;
};

void Unit::FlipStatus() {
	if (m_Status == status::ON) {
		m_Status = status::OFF;
	}
	else {
		m_Status = status::ON;
	}
}