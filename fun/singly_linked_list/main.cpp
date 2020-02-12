// Made by Bruce Cosgrove

#include <iostream>

#include "LinkedList.h"

int main() {
	LinkedList<int> list;
	
	list.insert(0, 7);
	list.insert(1, 6);
	list.insert(1, 3);
	list.insert(2, 1);
	list.insert(4, 9);
	list.print();
	
	list.remove(2);
	list.print();
	list.remove(3);
	list.print();
	list.remove(0);
	list.print();
}
