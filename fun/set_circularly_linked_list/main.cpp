// Made by Bruce Cosgrove

#include "CircularlyLinkedSet.h"

#include <iostream>

int main() {
	CircularlyLinkedSet<int> cls;
	
	cls.print(true);
	cls.add(7);
	cls.print(true);
	cls.add(7);
	cls.print(true);
	cls.add(1);
	cls.print(true);
	cls.add(3);
	cls.print(true);
	cls.add(4);
	cls.print(true);
	cls.add(8);
	cls.print(true);
	cls.add(3);
	cls.print(true);
	cls.remove(0);
	cls.print(true);
	cls.remove(4);
	cls.print(true);
	cls.add(2);
	cls.print(true);
	cls.remove(7);
	cls.print(true);
	cls.remove(1);
	cls.print(true);
	cls.remove(3);
	cls.print(true);
	cls.remove(8);
	cls.print(true);
	cls.remove(2);
	cls.print(true);
	cls.remove(3);
	cls.print(true);
	cls.add(4);
	cls.print(true);
	cls.add(1);
	cls.print(true);
	cls.add(5);
	cls.print(true);
	
	return 0;
}
