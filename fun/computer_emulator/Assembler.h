// Made by Bruce Cosgrove

#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <cstdint>
#include <vector>
#include <string>

class Assembler {
public:
	static void assemble(std::string filePath, std::string &program);
private:
	static void split(std::string &line, std::string delims, std::vector<std::string> &tokens);
	static void toLowercase(std::vector<std::string> &tokens);
	static void lookup(std::vector<std::string> &tokens, std::string &byteCode);
};

#endif
