// Made by Bruce Cosgrove

#include <iostream>

#include "Vector.h"

int main() {
	vec4f v1(7.9f, 1.3f, 8.7f, 2.6f);
	vec4f v2(3.7f, 3.7f, 6.1f, 8.9f);
	
	std::cout << (v1 + v2) << '\n';
	
	return 0;
}
