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
	return m_NumberOFUnits;
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
	m_NumberOFUnits + 1;
}

void Cloud::RemoveAllUnits() {
	char sure = 'n';
	std::cout << "**Are you sure you want to remove all units (y/n)?**";
	std::cin.get(sure);
	if ((sure == 'y') || (sure == 'Y')) {
		m_CloudUnits.clear();
		std::cout << "All units successfully removed";
	}
}
void Cloud::ListUnits() {
	for (int i = 0; i < m_CloudUnits.size(); i++) {
		std::cout << m_CloudUnits[i]->get_Name() << " - ";
		std::cout << "ID: " << m_CloudUnits[i]->get_Id() << std::endl;
	}
}

int Cloud::ChooseUnitById() {
	int unitId = 0;
	std::cout << "Choose unit by ID: ";
	if (!std::cin) {
		std::cout << "invalid input";
		SleepFunction(500);
		std::cin.ignore();
		std::cin.clear();
		std::cin.get();
		return 0;
	}
	return unitId;
}

void Cloud::RemoveUnit(int unitId) {
	int foundAndErased = 0;
	if (unitId != 0) {

		for (int i = 0; i < m_CloudUnits.size(); i++) {
			if (unitId == m_CloudUnits[i]->get_Id()) {
				int temp = m_CloudUnits[i]->get_Id();
				m_CloudUnits.erase(m_CloudUnits.begin() + i);
				std::cout << "Unit with ID " << temp << " has been successfully erased";
				foundAndErased++;
			}
		}

	}

	if (foundAndErased == 0) {
		std::cout << "Input valid ID, nothing removed";
	}

	std::cout << "\nOK<ENTER>";
	std::cin.get();
	std::cin.get();
}

Unit Cloud::FillNewUnit(Unit *emptyUnit) {

	std::string setName;
	std::string setInfo;
	int setId;

	std::cout << "Name of new unit?" << std::endl;
	std::cin.ignore();
	getline(std::cin, setName);
	emptyUnit->set_Name(setName);

	std::cout << "Info of new unit?" << std::endl;
	std::cin.ignore();
	getline(std::cin, setInfo);
	emptyUnit->set_Info(setInfo);

	char activate = 'Y';
	std::cout << "Activate new unit (Y/n)?" << std::endl;
	std::cin.get(activate);
	if ((activate == 'Y') || (activate == 'y') || (activate == '\n')) {
		emptyUnit->set_Status(true);
	}

	std::cout << "ID number of new unit?" << std::endl;
	std::cin >> setId;
	emptyUnit->set_Id(setId);

	return *emptyUnit;
}