// Made by Bruce Cosgrove

#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <sstream>

class Assembler {
public:
	static char* assemble(const char *filePath);
private:
	static uint16_t lookup(std::sstream &s);
};

#endif
