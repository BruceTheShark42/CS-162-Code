// Made by Bruce Cosgrove

#include "Assembler.h"

#include <fstream>
#include <deque>
#include <sstream>
#include <cmath>
#include <unordered_map>
#include <iostream> // DEBUG

void Assembler::assemble(std::string filePath, std::string &program) {
	std::ifstream file(filePath);
	if (!file.is_open())
		return;
	
	program.clear();
	std::unordered_map<std::string, uint16_t> labels;
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
					if (labels.find(tokens[0]) == labels.end()) {
						if (tokens.size() == 1 && labelValid(tokens[0])) {
							// Pushes the label name (no colon at end)
							std::string label = tokens[0].substr(0, tokens[0].length() - 1);
							labels.insert({label, programLine});
							std::cout << " Added label: \"" << label << "\" on line " << (fileLine + 1);
						} else {
							std::cout << " NOT SUPPOSED TO HAPPEN YET???";
						}
					} else std::cout << " Duplicate label on line " << (fileLine + 1);
				} else { // The line is an instruction		
					// Make the instruction all lowercase so case doesn't matter
					toLowercase(tokens);
					
					// Make all numbers hexadecimal
					std::string hexNumber;
					if (tokens.size() > 1) {
						makeHex(tokens[1], hexNumber);
						if (hexNumber.length() != 0) {
							tokens[1] = hexNumber;
							hexNumber.clear();
						}
					}
					if (tokens.size() > 2) {
						makeHex(tokens[2], hexNumber);
						if (hexNumber.length() != 0)
							tokens[2] = hexNumber;
					}
					
					// Remove the tab so it's easier to use
					tokens[0] = tokens[0].substr(1);
					
					// DEBUG
					std::cout << " before lookup: ";
					for (unsigned int i = 0; i < tokens.size(); ++i)
						std::cout << "\"" << tokens[i] << "\" ";
					
					// Try to add instruction to program
					std::string byteCode;
					lookup(tokens, programLine, byteCode);
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

void Assembler::makeHex(std::string &number, std::string &hexNumber) {
	auto canBeBin = [](char c) { return c == '0' || c == '1'; };
	auto canBeOct = [](char c) { return c > '/' && c < '8'; };
	auto canBeDec = [](char c) { return c > '/' && c < ':'; };
	auto canBeHex = [&](char c) { return canBeDec(c) || (c > '`' && c < 'g'); };
	auto canBeRad = [&](char c, unsigned char radix) { return (radix == 16 && canBeHex(c)) || (radix == 10 && canBeDec(c)) || (radix == 8 && canBeOct(c)) || (radix == 2 && canBeBin(c)); };
	
	unsigned char radix = 0;
	bool single = false;
	if (canBeHex(number[0])) {
		if (number[0] == '0') {
			if (number.length() > 2) {
				if (number[1] == 'b') radix = 2;
				else if (number[1] == 'o') radix = 8;
				else if (number[1] == 'x') radix = 16;
				else if (canBeDec(number[1])) radix = 10;
			} else if (canBeDec(number[0])) radix = 10;
		} else if (canBeDec(number[0])) radix = 10;
	} else if (number[0] == '$' || number[0] == '#') { radix = 16; single = true; }
	else if (number[0] == '@') { radix = 8; single = true; }
	else if (number[0] == '%') { radix = 2; single = true; }
	
	// If invalid radix
	if (radix == 0) return;
	
	// Validate that the rest of the number is correct
	std::string num;
	for (unsigned int i = (radix != 10 ? 2 - single: 0); i < number.length(); ++i) {
		if (canBeRad(number[i], radix)) num += number[i];
		else return;
	}
	
	// Convert from whatever radix to decimal
	uint32_t n = 0;
	for (unsigned int i = 0; i < num.length(); ++i)
		n += std::pow(radix, num.length() - 1 - i) * (num[i] - (canBeDec(num[i]) ? '0' : 'a'));
	
	// Convert from decimal to hexadecimal
	do {
		uint8_t digit = n % 0x10;
		hexNumber.insert(0, 1, (char)(digit + (digit > 9 ? 'W' : '0')));
		digit = (n >>= 4) % 0x10;
		hexNumber.insert(0, 1, (char)(digit + (digit > 9 ? 'W' : '0')));
		n >>= 4;
	} while (n != 0);
}

bool Assembler::labelValid(std::string &label) {
	std::cout << ' ' << label;
	if (label.length() < 2 || label[label.length() - 1] != ':')
		return false;
	for (unsigned int i = 0; i < label.length() - 1; ++i) {
		char c = label[i];
		if (!((c > '@' && c < '[') || (c > '`' && c < '{') || (c > '/' && c < ':') || c == '_'))
			return false;
	}
	return true;
}

void Assembler::getReg(std::string &reg, Reg8 &reg8) {
	if (!reg.compare("a")) reg8 = A;
	if (!reg.compare("f")) reg8 = F;
	if (!reg.compare("b")) reg8 = B;
	if (!reg.compare("c")) reg8 = C;
	if (!reg.compare("d")) reg8 = D;
	if (!reg.compare("e")) reg8 = E;
	if (!reg.compare("h")) reg8 = H;
	if (!reg.compare("l")) reg8 = L;
	if (!reg.compare("ixh")) reg8 = IXH;
	if (!reg.compare("ixl")) reg8 = IXL;
	if (!reg.compare("iyl")) reg8 = IYH;
	if (!reg.compare("iyl")) reg8 = IYL;
//	if (!reg.compare("n")) reg8 = N; // TODO
	if (!reg.compare("(bc)")) reg8 = pBC;
	if (!reg.compare("(de)")) reg8 = pDE;
	if (!reg.compare("(hl)")) reg8 = pHL;
//	if (!reg.compare("(ix+n)")) reg8 = pIXpN; // TODO
//	if (!reg.compare("(iy+n)")) reg8 = pIYpN; // TODO
	if (!reg.compare("(sp)")) reg8 = pSP;
//	if (!reg.compare("(nn)")) reg8 = pNN; // TODO
	if (!reg.compare("i")) reg8 = I;
	if (!reg.compare("r")) reg8 = R;
}

void Assembler::getReg(std::string &reg, Reg16 &reg16) {
	if (!reg.compare("af")) reg16 = AF;
	if (!reg.compare("bc")) reg16 = BC;
	if (!reg.compare("de")) reg16 = DE;
	if (!reg.compare("hl")) reg16 = HL;
	if (!reg.compare("ix")) reg16 = IX;
	if (!reg.compare("iy")) reg16 = IY;
	if (!reg.compare("sp")) reg16 = SP;
//	if (!reg.compare("nn")) reg16 = NN; // TODO
}

// Checks if an instruction is valid
// Does not alter byteCode if invalid
// Populates byteCode if valid with hex string equivalent to the assembled instruction
void Assembler::lookup(std::vector<std::string> &tokens, const uint16_t &programLine, std::string &byteCode) {
	const std::string inst = tokens[0];
	const unsigned int count = tokens.size();
	
	if (!inst.compare("nop"))
		byteCode += "00";
	else if (!inst.compare("ld")) {
		
	}
}
