// Made by Bruce Cosgrove

#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <cstdint>
#include <vector>
#include <string>

#include "registers.h"

class Assembler {
public:
	static void assemble(std::string filePath, std::string &program);
private:
	static void split(std::string &line, std::string delims, std::vector<std::string> &tokens);
	static void toLowercase(std::vector<std::string> &tokens);
	static void makeHex(std::string &number, std::string &hexNumber);
	static void lookup(std::vector<std::string> &tokens, std::string &byteCode);
	static void getReg(std::string &reg, Reg8 &reg8);
	static void getReg(std::string &reg, Reg16 &reg16);
};

#endif
