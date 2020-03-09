// Made by Bruce Cosgrove

#include "Vec2.h"
#include <iostream>

int main() {
	Vec2f a(1.0f, 0.0f), b(0.0f, 1.0f);
	std::cout << "a.dot(b) / (a.mag() * b.mag())=" << (a.dot(b) / (a.mag() * b.mag())) << '\n';
	std::cout << "a=";
	a.print();
	std::cout << "b=";
	b.print();
	std::cout << "a += b=";
	(a += b).print();
	std::cout << "a=";
	a.print();
	std::cout << "b=";
	b.print();
	std::cout << "b + a=";
	(b + a).print();
	std::cout << "a=";
	a.print();
	std::cout << "b=";
	b.print();
	std::cout << "a.mag()=" << a.mag() << "\na.nml()\n";
	a.nml();
	std::cout << "a.mag()=" << a.mag() << "\na=";
	a.print();
	return 0;
}
