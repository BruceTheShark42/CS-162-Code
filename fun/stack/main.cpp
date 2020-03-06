// Made by Bruce Cosgrove

#include "Stack.h"
#include <iostream>

int main() {
	Stack<int> s;
	s.print();
	s.push(7);
	s.print();
	s.push(8);
	s.print();
	s.push(3);
	s.print();
	s.pop();
	s.print();
	s.push(1);
	s.print();
	std::cout << s.peek() << '\n';
	s.print();
	s.push(10);
	s.print();
	std::cout << s.pop() << '\n';
	s.print();
	s.pop();
	s.print();
	s.push(3);
	s.print();
	s.pop();
	s.print();
	s.pop();
	s.print();
}
