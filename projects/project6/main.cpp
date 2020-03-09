// Made by Bruce Cosgrove

#include "LinkedList.h"

int main() {
	LinkedList<int> l;
	l.print();
	l.insert(0, 17);
	l.print();
	l.insert(0, 4);
	l.print();
	l.insert(1, 6);
	l.print();
	l.remove(2);
	l.print();
	l.remove(0);
	l.print();
	l.remove(0);
	l.print();
	return 0;
}
