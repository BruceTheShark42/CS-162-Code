// Made by Bruce Cosgrove

#include <iostream>

#include "DynamicArray.h"

int main() {
	DynamicArray<float> array(4);
	
	array.insert(0, 3.7f);
	array.insert(0, 2.2f);
	array.insert(0, 7.4f);
	array.insert(0, 9.0f);
	array.insert(0, 8.2f);
	
	std::cout << array << '\n';
	
	array.remove(2);
	array.remove(0);
	array.remove(1);
	
	std::cout << array << '\n';
	
	return 0;
}
