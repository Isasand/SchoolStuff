#include "Cloud.h"
#include <iostream>
#include <vector>
#include <string>
Cloud::Cloud()
{
}

Cloud::~Cloud()
{
}

int Cloud::get_NumberOfUnits() {
	return m_NumberOfUnits;
}


void Cloud::Welcome() {
	int choice;
	std::cout << "Welcome to Tiger and Sands cloud soultion!\n\n";
}

void Cloud::AddedUnit() {
	m_NumberOfUnits += 1;
}

void Cloud::ExitCloud() {
	exit(0);
}