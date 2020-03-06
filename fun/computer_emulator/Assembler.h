// Made by Bruce Cosgrove

#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <cstdint>
#include <vector>
#include <string>

#include "registers.h"

class Assembler {
public:
	static bool assemble(const std::string &filePath, std::string &program);
private:
	static void split(const std::string &line, const std::string delims, std::vector<std::string> &tokens);
	static void toLowercase(std::vector<std::string> &tokens);
	static void makeHex(const std::string &number, std::string &hexNumber);
	static bool getRadix(const std::string &number, uint8_t &radix);
	static bool canBeBin(const char c);
	static bool canBeOct(const char c);
	static bool canBeDec(const char c);
	static bool canBeHex(const char c);
	static bool canBeRad(const char c, uint8_t radix);
	static bool isHex(const std::string &number, const uint8_t numBytes = 1);
	static bool labelValid(const std::string &label);
	static void getReg(const std::string &r, Reg &reg);
	static void lookup(const std::vector<std::string> &tokens, const uint16_t &programLine, std::string &byteCode);
};

#endif
