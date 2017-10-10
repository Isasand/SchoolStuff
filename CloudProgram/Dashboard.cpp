#include "Dashboard.h"
#include <iomanip>
#include <sstream>

Dashboard::Dashboard()
{
}


Dashboard::~Dashboard()
{
}

void Dashboard::AddUnit(Unit* newUnit, Cloud* cloud) {
	cloud->AddUnitToCloud(newUnit);
	cloud->AddedUnit();
}

void Dashboard::RemoveAllUnits(Cloud* cloud) {
	char sure = 'n';
	std::cout << "**Are you sure you want to remove all units (y/n)?**";
	std::cin.get(sure);
	if ((sure == 'y') || (sure == 'Y')) {
		cloud->ClearListOfUnits();
		std::cout << "All units successfully removed";
	}
}
/*void Dashboard::ListUnits(std::vector<Unit*> units) {
	for (int i = 0; i <units.size(); i++) {
		std::cout << units[i]->get_Name() << " - ";
		std::cout << "ID: " << units[i]->get_Id() << std::endl;
	}
}*/

/*int Dashboard::ChooseUnitById() {
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
}*/

void Dashboard::RemoveUnit(int unitId, Cloud* cloud) {
	int foundAndErased = 0;
	if (unitId != 0) {

		for (int i = 0; i < cloud->get_NumberOfUnits(); i++) {
			if (unitId == cloud->getUnitAt(i)->get_Id()) {
				int temp = cloud->getUnitAt(i)->get_Id();
				cloud->RemoveUnitAt(i);
				std::cout << "Unit with ID " << temp << " has been successfully erased";
				foundAndErased++;
				cloud->RemovedUnit();
			}
		}

	}

	if (foundAndErased == 0) {
		std::cout << "Input valid ID, nothing removed";
	}

	std::cout << "\nOK<ENTER>";
}

Unit* Dashboard::FillNewUnit() {
	Unit *tempUnit = new Unit();
	std::string setName;
	std::string setInfo;
	int setId;

	std::cin.clear();
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
		tempUnit->set_Status(status::ON);
	}

	std::cout << "ID number of new unit?" << std::endl;
	std::cin >> setId;
	tempUnit->set_Id(setId);

	return tempUnit;
}

void Dashboard::ShowUnits(Cloud* cloud) {
	std::cout << "\t***DASHBOARD***\n";
	PrintRow();
	PrintTitleBar();
	PrintRow();
	for (int i = 0; i < cloud->get_NumberOfUnits(); i++) {
		int nameLenght = cloud->getUnitAt(i)->get_Name().size();
		std::cout << "|" << cloud->getUnitAt(i)->get_Name()
			<< std::setw(21 - nameLenght) << std::setfill(' ') << " |";

		int id = cloud->getUnitAt(i)->get_Id();
		std::string str;
		std::stringstream convertToString;
		convertToString << id;
		str = convertToString.str();

		std::cout << cloud->getUnitAt(i)->get_Id()
			<< std::setw(5 - str.size()) << std::setfill(' ') << "|" ;
		std::cout <<PrintUnitStatus(cloud->getUnitAt(i))<< std::setw(4) << std::setfill(' ') << " |" << std::endl;
		PrintRow();
	}
	std::cout << std::endl;

}

void Dashboard::PrintRow() {
	std::cout << "+" << std::setfill('-') << std::setw(33);
	std::cout<< "+----+-----+\n";
	
}
void Dashboard::PrintTitleBar() {
	std::cout << "|UNIT                |ID  |STATE|\n";
}

std::string Dashboard::PrintUnitStatus(Unit* unit) {
	return unit->get_Status() == status::ON ? "ON" : "X ";
}
