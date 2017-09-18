#include "Pyramid.h"
#include <Iostream> 
#include <windows.h> 

float Pyramid::x() const {
	return m_bredd;
}

float Pyramid::y() const {
	return m_hojd;
}


void Pyramid::setx(float x) { 
	m_bredd = x; 
}; //tilldelar de privata medlemmarna värden


void Pyramid::sety(float y) { 
	m_hojd = y; 
};


float Pyramid::area() { 
	return m_bredd*m_bredd; 
} //uträkning av arean


float Pyramid::Volym() { 
	return (m_bredd*m_bredd*m_hojd) / 3; 
}//uträkning av volym

void Pyramid::change(float x, float y) { //byter plats på bredd och höjd
	float temp;
	temp = m_bredd;
	m_bredd = m_hojd;
	m_hojd = temp;
}
