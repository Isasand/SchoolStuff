#pragma once
#include <vector>
#include "Unit.h"
#include "Config.h"

class Cloud
{
	friend class Dashboard;
	friend class Execute;

public:
	Cloud();
	~Cloud();

	void Welcome();
	int get_NumberOfUnits();
	void AddedUnit();
	static void ExitCloud();

protected: 
	std::vector<Unit*> m_CloudUnits;
	int m_NumberOfUnits;
};