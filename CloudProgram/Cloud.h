#pragma once
#include <vector>

class Cloud
{
public:
	Cloud();
	~Cloud();

	void AddUnit(Unit* newUnit);
	void RemoveUnit(int UnitID);
	void RemoveAllUnits();

protected: 
	vector<Unit> m_CloudUnits;
};

