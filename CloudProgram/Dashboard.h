#pragma once
#include "Unit.h"
#include "Cloud.h"
#include <iostream>
#include <vector>
#include <string>

class Dashboard
{

public:
	Dashboard();
	~Dashboard();

	static void AddUnit(Unit* newUnit, Cloud* cloud);
	static void RemoveUnit(int UnitID, Cloud* cloud);
	void RemoveAllUnits(Cloud* cloud);
	void ListUnits(std::vector<Unit*> units);
	static Unit *FillNewUnit();
	int ChooseUnitById();
	void ShowUnits(Cloud* cloud);
	void PrintRow();
	void PrintTitleBar();
	std::string PrintUnitStatus(Unit* unit);

};

