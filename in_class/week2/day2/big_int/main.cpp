#include <iostream>

#include "BigInt.h"

int main()
{
	BigInt i1(0x0000000000ffffff);
	i1.Print();
	
	BigInt i2(0xfffffffffff00000);
	i2.Print();
	
	for (int i = 0; i < 100; ++i)
		i1.Add(i2);
	i1.Print();
	
	return 0;
}
