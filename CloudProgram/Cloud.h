#pragma once
#include <vector>
#include "Unit.h"
#include "Config.h"

class Cloud
{

public:
	Cloud();
	~Cloud();

	void Welcome();
	int get_NumberOfUnits();
	void AddedUnit();
	static void ExitCloud();
	Unit* getUnitAt(int index);
	void RemoveUnitAt(int index);
	void RemovedUnit();
	void AddUnitToCloud(Unit* newUnit);
	void ClearListOfUnits();
protected: 
	std::vector<Unit*> m_CloudUnits;
	int m_NumberOfUnits;

};