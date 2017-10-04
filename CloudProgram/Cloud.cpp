#include "Cloud.h"
#include <iostream>
#include <vector>
Cloud::Cloud()
{
}

Cloud::~Cloud()
{
}

void Cloud::StartMenu() {
	std::cout << "Welcome to Tiger and Sands cloud soultion!\n\n"
		<< "1. Show connected units\n"
		<< "2. Add units\n"
		<< "3. Remove units\n"
		<< "4. Show Dashboard\n"
		<< "5. Exit\n";
}

void Cloud::AddUnit(Unit* newUnit) {
	m_CloudUnits.push_back(newUnit);
}

/*void Cloud::RemoveUnit(int unitID) {
	m_CloudUnits.at(m_CloudUnits.begin() + (unitID - 1));
}
*/
void Cloud::RemoveAllUnits() {
	m_CloudUnits.clear();
}

void Cloud::ListUnits() {
	std::string tempname;
	for (int i = 0; i < (sizeof(m_CloudUnits)); i++) {
	}
}