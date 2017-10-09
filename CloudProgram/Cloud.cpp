#include "Cloud.h"
#include <iostream>
#include <vector>
#include <string>
Cloud::Cloud()
{
}

Cloud::~Cloud()
{
}

int Cloud::get_NumberOfUnits() {
	return m_NumberOfUnits;
}

void Cloud::Welcome() {
	int choice;
	std::cout << "Welcome to Tiger and Sands cloud soultion!\n\n";
}

void Cloud::AddedUnit() {
	m_NumberOfUnits += 1;
}

void Cloud::RemovedUnit() {
	m_NumberOfUnits -= 1;
}

void Cloud::ExitCloud() {
	exit(0);
}

Unit* Cloud::getUnitAt(int index) {
	return m_CloudUnits.at(index);
}

void Cloud::RemoveUnitAt(int index) {
	m_CloudUnits.erase(m_CloudUnits.begin() + index);
}

void Cloud::AddUnitToCloud(Unit* newUnit) {
	m_CloudUnits.push_back(newUnit);
}

void Cloud::ClearListOfUnits() {
	m_CloudUnits.clear();
}
