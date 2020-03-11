// Made by Bruce Cosgrove

#include "Mat.h"

int main() {
	Matf a(3, 3, false);
	a(0, 0) = 3;
	a(0, 2) = 2;
	a(1, 0) = 2;
	a(1, 2) = -2;
	a(2, 1) = 1;
	a(2, 2) = 1;
	Matf::print(Matf::inverse(a));
	return 0;
}
