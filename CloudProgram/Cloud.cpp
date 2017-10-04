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

int Cloud::StartMenu() {
	int choice;
	std::cout << "Welcome to Tiger and Sands cloud soultion!\n\n"
		<< "1. Show connected units\n"
		<< "2. Add units\n"
		<< "3. Remove units\n"
		<< "4. Show Dashboard\n"
		<< "5. Exit\n";
	std::cin >> choice;
	return choice;
}

void Cloud::AddUnit(Unit* newUnit) {
	m_CloudUnits.push_back(newUnit);
}

void Cloud::RemoveAllUnits() {
	m_CloudUnits.clear();
}

void Cloud::ListUnits() {
	std::string tempname;
	for (int i = 0; i < m_CloudUnits.size(); i++) {
		std::cout << m_CloudUnits[i]->get_Name() << std::endl;

	}
}