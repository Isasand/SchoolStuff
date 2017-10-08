#include "Dashboard.h"
#include <iomanip>


Dashboard::Dashboard()
{
}


Dashboard::~Dashboard()
{
}

void Dashboard::AddUnit(Unit* newUnit, Cloud* cloud) {
	cloud->m_CloudUnits.push_back(newUnit);
	cloud->AddedUnit();
}

void Dashboard::RemoveAllUnits(Cloud* cloud) {
	char sure = 'n';
	std::cout << "**Are you sure you want to remove all units (y/n)?**";
	std::cin.get(sure);
	if ((sure == 'y') || (sure == 'Y')) {
		cloud->m_CloudUnits.clear();
		std::cout << "All units successfully removed";
	}
}
void Dashboard::ListUnits(std::vector<Unit*> units) {
	for (int i = 0; i <units.size(); i++) {
		std::cout << units[i]->get_Name() << " - ";
		std::cout << "ID: " << units[i]->get_Id() << std::endl;
	}
}

int Dashboard::ChooseUnitById() {
	int unitId = 0;
	std::cout << "Choose unit by ID : ";
	std::cin >> unitId;
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

void Dashboard::RemoveUnit(int unitId, Cloud* cloud) {
	int foundAndErased = 0;
	if (unitId != 0) {

		for (int i = 0; i < cloud->m_CloudUnits.size(); i++) {
			if (unitId == cloud->m_CloudUnits[i]->get_Id()) {
				int temp = cloud->m_CloudUnits[i]->get_Id();
				cloud->m_CloudUnits.erase(cloud->m_CloudUnits.begin() + i);
				std::cout << "Unit with ID " << temp << " has been successfully erased";
				foundAndErased++;
				cloud->m_NumberOfUnits--;
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

Unit* Dashboard::FillNewUnit() {
	Unit *tempUnit = new Unit();
	std::string setName;
	std::string setInfo;
	int setId;

	std::cout << "Name of new unit?" << std::endl;
	getline(std::cin, setName);
	tempUnit->set_Name(setName);
	std::cin.clear();
	std::cout << "Info of new unit?" << std::endl;
	getline(std::cin, setInfo);
	tempUnit->set_Info(setInfo);
	std::cin.clear();
	char activate = 'Y';
	std::cout << "Activate new unit (Y/n)?" << std::endl;
	std::cin.get(activate);
	if ((activate == 'Y') || (activate == 'y') || (activate == '\n')) {
		tempUnit->set_Status(true);
	}

	std::cout << "ID number of new unit?" << std::endl;
	std::cin >> setId;
	tempUnit->set_Id(setId);

	return tempUnit;
}

void Dashboard::ShowUnits(Cloud* cloud) {
	PrintRow();
	PrintTitleBar();
	PrintRow();
	for (int i = 0; i < cloud->m_CloudUnits.size(); i++) {
		std::string name = cloud->m_CloudUnits.at(i)->get_Name();
		std::cout << "|" << name << std::setw(20 - name.size())   << std::setfill(' ')  << "|" << std::endl;
	}

}

void Dashboard::PrintRow() {
	std::cout << "+" << std::setfill('-') << std::setw(33);
	std::cout<< "+----+-----+\n";
	
}
void Dashboard::PrintTitleBar() {
	std::cout << "|UNIT                |ID  |STATE|\n";
}