// Made by Bruce Cosgrove

#include "LinkedList.h"

int main() {
	// float, double, int, and long are supported types
	// To add more, add "template class LinkedList<TYPE>;"
	// to the end of LinkedList.cpp
	LinkedList<int> list;
	
	list.insert(0, 3);
	list.insert(0, 10);
	list.insert(0, 1);
	list.insert(0, 7);
	list.insert(0, 9);
	list.insert(0, 12);
	list.printForwards();
	list.printBackwards();
	list.remove(0);
	list.remove(2);
	list.remove(3);
	list.remove(5);
	list.printForwards();
	list.printBackwards();
	return 0;
}
