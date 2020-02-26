// Made by Bruce Cosgrove

//#include <iostream>
//#include <cstdint>
#include <string>

#include "Assembler.h"
#include "Computer.h"

int main() {
	Computer cmp;
	
//	std::string program;
//	Assembler::assemble("program.asm", program);
//	for (unsigned int i = 0; prog[i] != '\0'; ++i)
//		std::cout << +prog[i] << ' ';
//	std::cout << '\n';
//	cmp.loadProgram(prog);
//	delete[] prog;
	cmp.run();
	return 0;
}
