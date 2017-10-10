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
	void ListUnits(Cloud* cloud);
	static Unit *FillNewUnit();
	int ChooseUnitById();
	void ShowUnits(Cloud* cloud);
	void PrintRow();
	void PrintTitleBar();
	std::string PrintUnitStatus(Unit* unit);
	void ShowActiveUnits();
	static void Dashboard::ShowActiveUnits(Cloud* cloud);
	static void Dashboard::ChangeUnitName(Unit* unit);
	static void Dashboard::ChangeUnitInfo(Unit* unit);
	static void GenerateId(Cloud* cloud, Unit* newUnit);

protected:
	Cloud* m_ActiveCloud;
};