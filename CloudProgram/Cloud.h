#pragma once
#include <vector>
#include "Unit.h"
class Cloud
{

public:
	Cloud();
	~Cloud();

	void StartMenu();
	void AddUnit(Unit* newUnit);
	void RemoveUnit(int UnitID);
	void RemoveAllUnits();
	void ListUnits();
	
protected: 
	std::vector<Unit*> m_CloudUnits;
};