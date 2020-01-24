// Made by Bruce Cosgrove

#include <iostream>

#include "list.h"

const int ARRAY_CAP = 100;

int main()
{
	int* aList = new int[ARRAY_CAP] {0};
	int size = 0;
	int val;
	
	print(aList, size);
	insert(0, 10, aList, size);
	insert(1, 20, aList, size);
	insert(0, 4, aList, size);
	insert(1, 40, aList, size);
	insert(2, 25, aList, size);
	print(aList, size);
	
	if (!remove(5, val, aList, size))
		std::cout << "remove failed\n";
	else
		std::cout << val << " is removed!\n";
	
	if (!remove(1, val, aList, size))
		std::cout << "remove failed\n";
	else
		std::cout << val << " is removed!\n";
	
	print(aList, size);
	
	delete[] aList;
	return 0;
}
