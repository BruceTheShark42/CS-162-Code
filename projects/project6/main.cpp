// Made by Bruce Cosgrove

#include "LinkedList.h"
#include <iostream>

int main() {
	LinkedList l;
	std::cout << "Testing Printing Empty List\nExpecting: [ ]\nResult: ";
	l.print();
	std::cout << "Testing Inserting at Index > List Size\nExpecting: [ 17 ]\nResult: ";
	l.insert(111, 17); l.print();
	std::cout << "Testing Inserting at Index 0\nExpecting: [ 4 17 ]\nResult: ";
	l.insert(0, 4); l.print();
	std::cout << "Testing Inserting at Index 1\nExpecting: [ 4 6 17 ]\nResult: ";
	l.insert(1, 6); l.print();
	std::cout << "Testing Removing at Index > List Size\nExpecting: [ 4 6 ]\nResult: ";
	l.remove(245); l.print();
	std::cout << "Testing Removing at Index 0\nExpecting: [ 6 ]\nResult: ";
	l.remove(0); l.print();
	std::cout << "Testing Inserting at Back\nExpecting: [ 6 1 ]\nResult: ";
	l.pushBack(1); l.print();
	std::cout << "Testing Removing at Front\nExpecting: [ 1 ]\nResult: ";
	l.popFront(); l.print();
	std::cout << "Testing Inserting at Front\nExpecting: [ 5 1 ]\nResult: ";
	l.pushFront(5); l.print();
	std::cout << "Testing Removing at Back\nExpecting: [ 5 ]\nResult: ";
	l.popBack(); l.print();
	return 0;
}
