#include "Printer1.h"

#include <iostream>

Printer1::Printer1(const char* text)
	: m_Text(text)
{
	
}

void Printer1::Print() const
{
	std::cout << m_Text << std::endl;
}
