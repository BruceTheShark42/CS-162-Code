// Made by Bruce Cosgrove

#include "Deque.h"

int main() {
	Deque<int> deck;
	deck.printFront();

	deck.pushFront(7);
	deck.printFront();
	deck.pushFront(2);
	deck.printFront();
	deck.pushBack(6);
	deck.printFront();
	deck.pushFront(3);
	deck.printFront();
	deck.pushBack(9);
	deck.printFront();
	
	deck.popFront();
	deck.printFront();
	deck.popBack();
	deck.printFront();
	deck.popBack();
	deck.printFront();
	deck.popFront();
	deck.printFront();
	deck.popBack();
	deck.printFront();

	deck.popFront();
	deck.printFront();
	
	return 0;
}
