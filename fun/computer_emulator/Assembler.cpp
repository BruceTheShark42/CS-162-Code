// Made by Bruce Cosgrove

#include "Assembler.h"

#include <fstream>
#include <cstring>
#include <iostream>

uint8_t* Assembler::assemble(const char *filePath) {
	std::ifstream file(filePath);
	if (!file.is_open())
		return nullptr;
	
	uint8_t *program = new uint8_t[0x101];
	unsigned int byteIndex = 0;
	
	while (!file.eof()) {
		char line[16];
		file.getline(line, 16);
		if (std::strlen(line) != 0) {
			std::cout << line;
			std::strstream s;
			s << line;
			uint16_t decoded = lookup(s) + OFFSET;
			program[byteIndex++] = decoded & 0x00ff;
			if (decoded & 0xff00) {
				program[byteIndex++] = (decoded & 0xff00) >> 8;
			}
		}
	}
	file.close();
	
	program[byteIndex] = '\0';
	return program;
}

uint16_t Assembler::lookup(std::strstream &s) {
	char inst[5];
	s >> inst;
	std::cout << " - " << inst << '\n';
	if (std::strcmp(inst, "nop") == 0) {
		return 0x00;
	} else if (std::strcmp(inst, "add") == 0) {
		return 0x01;
	} else if (std::strcmp(inst, "mova") == 0) {
		return 0x02;
	} else if (std::strcmp(inst, "mvb") == 0) {
		return 0x03;
	} else if (std::strcmp(inst, "mva") == 0) {
		return 0x04;
	} else if (std::strcmp(inst, "jmp") == 0) {
		return 0x05;
	} else if (std::strcmp(inst, "ifa") == 0) {
		return 0x06;
	} else if (std::strcmp(inst, "push") == 0) {
		uint8_t addr;
		s >> addr;
		std::cout << "  --  " << +addr << "  --  ";
		return ((uint16_t)(addr) << 8) | 0x07;
	} else if (std::strcmp(inst, "popa") == 0) {
		return 0x08;
	} else if (std::strcmp(inst, "popb") == 0) {
		return 0x09;
	} else if (std::strcmp(inst, "hlt") == 0) {
		return 0x0a;
	} else if (std::strcmp(inst, "bnot") == 0) {
		return 0x0b;
	} else {
		return 0x00;
	}
}
