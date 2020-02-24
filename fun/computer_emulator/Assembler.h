// Made by Bruce Cosgrove

#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <cstdint>
#include <strstream>

class Assembler {
public:
	static uint8_t* assemble(const char *filePath);
private:
	static uint16_t lookup(std::strstream &s);
public:
	static const unsigned int OFFSET = 0x01;
};

#endif
