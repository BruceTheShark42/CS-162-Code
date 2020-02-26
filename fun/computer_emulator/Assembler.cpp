// Made by Bruce Cosgrove

#include "Assembler.h"

#include <fstream>
#include <deque>
#include <sstream>
#include <iostream> // DEBUG

void Assembler::assemble(std::string filePath, std::string &program) {
	std::ifstream file(filePath);
	if (!file.is_open())
		return;
	
	program.clear();
	std::vector<std::pair<std::string, uint16_t>> labels;
	uint16_t fileLine = 0, programLine = 0;
	
	while (!file.eof()) {
		std::string line;
		std::getline(file, line);
		if (line.size() != 0) {
			std::cout << "Original: \"" << line << "\" "; // DEBUG
			
			// Remove comments
			line = line.substr(0, line.find(';'));
			if (line.size() != 0) {
				std::cout << "No Comments: \"" << line << "\" "; // DEBUG
				
				// Split line into tokens
				std::vector<std::string> tokens;
				split(line, " ,", tokens);
				
				// DEBUG
				std::cout << "Tokens: ";
				for (auto str : tokens)
					std::cout << "\"" << str << "\" ";
				
				// If the line is a label
				if (tokens[0][0] != '\t') {
					labels.push_back({tokens[0], programLine});
				} else { // The line is an instruction		
					// Remove the tab so it's easier to use
					tokens[0] = tokens[0].substr(1);
					// Make the instruction all lowercase so case doesn't matter
					toLowercase(tokens);
					
					// Try to add instruction to program
					std::string byteCode;
					lookup(tokens, byteCode);
					if (byteCode.size() != 0) {
						++programLine;
					} else {
						//std::cout << "Syntax error on line " << (fileLine + 1) << '\n';
					}
				}
			}
			std::cout << '\n'; // DEBUG
		}
		++fileLine;
	}
	std::cout << "Lines Processed: " << (fileLine - 1) << '\n'; // DEBUG
	std::cout << "Instructions Processed: " << programLine << '\n'; // DEBUG
	file.close();
}

void Assembler::split(std::string &line, std::string delims, std::vector<std::string> &tokens) {
	tokens.clear();
	
	std::string token;
	std::deque<std::string> tempTokens;
	std::istringstream il(line);
	while (std::getline(il, token, delims[0]))
		if (token.size() != 0)
			tempTokens.push_back(token);
	
	if (delims.size() != 1) {
		for (unsigned int d = 1; d < delims.size(); ++d) {
			for (unsigned int i = tempTokens.size(); i > 0; --i) {
				std::istringstream is(tempTokens[0]);
				while (std::getline(is, token, delims[d]))
					if (token.size() != 0)
						tempTokens.push_back(token);
				tempTokens.pop_front();
			}
		}
	}
	
	for (auto token : tempTokens)
		tokens.push_back(token);
}

void Assembler::toLowercase(std::vector<std::string> &tokens) {
	for (auto &token : tokens)
		for (auto &c : token)
			if (c > '@' && c < '[')
				c += 0x20;
}

// Checks if an instruction is valid
// Does not alter byteCode if invalid
// Populates byteCode if valid with hex string equivalent to the assembled instruction
void Assembler::lookup(std::vector<std::string> &tokens, std::string &byteCode) {
	const std::string inst = tokens[0];
	const unsigned int count = tokens.size();
	
	if (!inst.compare("nop"))
		byteCode += "00";
	else if (!inst.compare("ld")) {
		
	}
}
