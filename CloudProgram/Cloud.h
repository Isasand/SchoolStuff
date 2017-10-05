#pragma once
#include <vector>
#include "Unit.h"

#include "Config.h"
class Cloud
{

public:
	Cloud();
	~Cloud();

	int StartMenu();
	void AddUnit(Unit* newUnit);
	void RemoveUnit(int UnitID);
	void RemoveAllUnits();
	void ListUnits();
	Unit FillNewUnit(Unit *emptyUnit);
	int ChooseUnitById();
	int get_NumberOfUnits();
	
protected: 
	std::vector<Unit*> m_CloudUnits;
	int m_NumberOFUnits;
};