#include "Unit.h"

Unit::Unit() {
	m_Status = false;
};

Unit::Unit(std::string name, std::string info, bool status, int id) {

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
bool Unit::get_Status() {
	return m_Status;
};
void Unit::set_Status(bool status) {
	m_Status = status;
};

void Unit::FlipStatus() {
	m_Status = !m_Status;
}