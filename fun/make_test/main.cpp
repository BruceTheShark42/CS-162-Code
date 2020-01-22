#include <iostream>

#include "Printer1.h"
#include "Printer2.h"

int main()
{
	Printer1 p1("Hello from output!");
	Printer2 p2("Hello from error!");
	
	p1.Print();
	p2.Print();
	
	std::cin.get();
	return 0;
}
