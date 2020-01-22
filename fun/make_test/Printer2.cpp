#include "Printer2.h"

#include <iostream>

Printer2::Printer2(const char* text)
	: m_Text(text)
{
	
}

void Printer2::Print() const
{
	std::cerr << m_Text << std::endl;
}
