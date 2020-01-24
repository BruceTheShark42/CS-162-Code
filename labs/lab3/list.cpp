#include <iostream>

#include "list.h"

bool insert(int position, int val, int* intList, int& size)
{
	//			     |  This is not >= so that if
	//			     |  position == size, it will
	//			     v  act like an append method
	if (position < 0 || position > size)
		return false;
	
	for (int i = size; i > position; --i)
		intList[i] = intList[i - 1];
	
	intList[position] = val;
	++size;
	
	return true;
}

bool remove(int position, int& val, int* intList, int& size)
{
	if (position < 0 || position >= size)
		return false;
	
	val = intList[position];
	
	for (int i = position; i < size - 1; ++i)
		intList[i] = intList[i + 1];
	--size;
	
	return true;
}

void print(const int intList[], int size)
{
	std::cout << "\n[ ";
	for (int i = 0; i < size; ++i)
		std::cout << intList[i] << ' ';
	std::cout << "]\n";
}
