// Made by Bruce Cosgrove

//#include <iostream>
//#include <cstdint>

//#include "Assembler.h"
#include "Computer.h"

int main() {
	Computer cmp;

//	uint8_t *prog = Assembler::assemble("program.asm");
//	for (unsigned int i = 0; prog[i] != '\0'; ++i)
//		std::cout << +prog[i] << ' ';
//	std::cout << '\n';
//	cmp.loadProgram(prog);
//	delete[] prog;
	cmp.run();
	return 0;
}
