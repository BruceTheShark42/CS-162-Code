// Made by Bruce Cosgrove

#include "LinkedList.h"

int main() {
	LinkedList<int> l; l.print();
	l.insert(111, 17); l.print();
	l.insert(0, 4); l.print();
	l.insert(1, 6); l.print();
	l.remove(245); l.print();
	l.remove(0); l.print();
	l.pushBack(1); l.print();
	l.popFront(); l.print();
	l.pushFront(5); l.print();
	l.popBack(); l.print();
	l.popBack(); l.print();
	return 0;
}
