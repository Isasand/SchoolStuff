#include "Cloud.h"

Cloud::Cloud()
{
}

Cloud::~Cloud()
{
}

void Cloud::Cloud AddUnit(Unit* newUnit) {
	m_CloudUnits.push_back(newUnit);
}

void Cloud::Cloud RemoveUnit(int unitID) {
	m_CloudUnits.at(m_CLoudUnits.begin() +(unitID -1))
}

void RemoveAllUnits() {
	m_CloudUnits.clear();
}