// Made by Bruce Cosgrove

#include "Assembler.h"

#include <fstream>
#include <deque>
#include <sstream>
#include <cmath>
#include <unordered_map>
#include <iostream> // DEBUG

bool Assembler::assemble(const std::string &filePath, std::string &program) {
	std::ifstream file(filePath);
	if (!file.is_open())
		return false;
	
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
//				std::cout << "No Comments: \"" << line << "\" "; // DEBUG
				
				// Split line into tokens
				std::vector<std::string> tokens;
				split(line, " ,", tokens);
				
//				// DEBUG
//				std::cout << "Tokens: ";
//				for (auto str : tokens)
//					std::cout << "\"" << str << "\" ";
				
				// If the line is a label
				if (tokens[0][0] != '\t') {
					std::string label = tokens[0];
					// If the label has a colon at the end
					if (label[label.length() - 1] == ':') {
						// Remove the colon
						label = label.substr(0, label.length() - 1);
						// If the label doesn't already exist
						if (labels.find(label) == labels.end()) {
							if (tokens.size() == 1 && labelValid(label)) {
								// Pushes the label name (no colon at end)
								labels.insert({label, programLine});
								std::cout << " Added label: \"" << label << "\" on line " << (fileLine + 1);
							}
						} else {
							std::cout << " ERROR: Duplicate label on line " << (fileLine + 1) << '\n';
							return false;
						}
					} else {
						std::cout << " ERROR: no ':' at the end of the label on line " << (fileLine + 1) << '\n';
						return false;
					}
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
					
					if (tokens[0].length() != 0) {
						// DEBUG
						std::cout << " Parsed: ";
						for (unsigned int i = 0; i < tokens.size(); ++i)
							std::cout << "\"" << tokens[i] << "\" ";
						
						// Try to add instruction to program
						std::string byteCode;
						lookup(tokens, programLine, byteCode);
						if (byteCode.size() != 0) {
							++programLine;
							program += byteCode;
							std::cout << " Instruction: \"" << byteCode << '"';
						} else {
							std::cout << " ERROR: Unknown instruction on line " << (fileLine + 1) << '\n';
							return false;
						}
					}
				}
			}
			std::cout << '\n'; // DEBUG
		}
		++fileLine;
	}
	file.close();
	std::cout << "Lines Processed: " << (fileLine - 1) << '\n'; // DEBUG
	std::cout << "Instructions Processed: " << programLine << '\n'; // DEBUG
	std::cout << "Program Byte Code: " << program << '\n';
	return true;
}

void Assembler::split(const std::string &line, const std::string delims, std::vector<std::string> &tokens) {
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

void Assembler::makeHex(const std::string &number, std::string &hexNumber) {
	uint8_t radix = 0;
	bool single = getRadix(number, radix);
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
	uint8_t byte = 0;
	do {
		uint8_t digit = n % 0x10;
		hexNumber.insert(byte, 1, (char)(digit + (digit > 9 ? 'W' : '0')));
		digit = (n >>= 4) % 0x10;
		hexNumber.insert(byte, 1, (char)(digit + (digit > 9 ? 'W' : '0')));
		n >>= 4;
		byte += 2;
	} while (n != 0);
}

bool Assembler::getRadix(const std::string &number, uint8_t &radix) {
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
	
	return single;
}

bool Assembler::canBeBin(const char c) { return c == '0' || c == '1'; }
bool Assembler::canBeOct(const char c) { return c > '/' && c < '8'; }
bool Assembler::canBeDec(const char c) { return c > '/' && c < ':'; }
bool Assembler::canBeHex(const char c) { return canBeDec(c) || (c > '`' && c < 'g'); }
bool Assembler::canBeRad(const char c, uint8_t radix) {
	return (radix == 16 && canBeHex(c)) || (radix == 10 && canBeDec(c)) ||
		   (radix == 8 && canBeOct(c)) || (radix == 2 && canBeBin(c));
}
bool Assembler::isHex(const std::string &number, const uint8_t numBytes) {
	if (number.length() != numBytes << 1)
		return false;
	for (auto c : number)
		if (!canBeHex(c))
			return false;
	return true;
}

bool Assembler::labelValid(const std::string &label) {
	std::cout << ' ' << label;
	if (label.length() == 0)
		return false;
	for (auto c : label)
		if (!((c > '@' && c < '[') || (c > '`' && c < '{') || (c > '/' && c < ':') || c == '_'))
			return false;
	return true;
}

void Assembler::getReg(const std::string &r, Reg &reg) {
	// 8-bit
	if (!r.compare("a")) reg = A;
	else if (!r.compare("f")) reg = F;
	else if (!r.compare("b")) reg = B;
	else if (!r.compare("c")) reg = C;
	else if (!r.compare("d")) reg = D;
	else if (!r.compare("e")) reg = E;
	else if (!r.compare("h")) reg = H;
	else if (!r.compare("l")) reg = L;
	else if (!r.compare("ixh")) reg = IXH;
	else if (!r.compare("ixl")) reg = IXL;
	else if (!r.compare("iyh")) reg = IYH;
	else if (!r.compare("iyl")) reg = IYL;
	else if (canBeHex(r[0])) reg = N;
	else if (!r.compare("(bc)")) reg = pBC;
	else if (!r.compare("(de)")) reg = pDE;
	else if (!r.compare("(hl)")) reg = pHL;
	else if (!r.compare("(ix)")) reg = pIX;
	else if (!r.compare("(iy)")) reg = pIY;
	else if (r.length() > 5 && !r.substr(0, 4).compare("(ix+") && r[r.length() - 1] == ')' && isHex(r.substr(4, r.length() - 1))) reg = pIXpN;
	else if (r.length() > 5 && !r.substr(0, 4).compare("(iy+") && r[r.length() - 1] == ')' && isHex(r.substr(4, r.length() - 1))) reg = pIYpN;
	else if (!r.compare("(sp)")) reg = pSP;
	else if (r.length() > 2 && !r[0] == '(' && r[r.length() - 1] == ')' && isHex(r.substr(1, r.length() - 1))) reg = pNN;
	else if (!r.compare("i")) reg = I;
	else if (!r.compare("r")) reg = R;
	// 16-bit
	else if (!r.compare("af")) reg = AF;
	else if (!r.compare("bc")) reg = BC;
	else if (!r.compare("de")) reg = DE;
	else if (!r.compare("hl")) reg = HL;
	else if (!r.compare("ix")) reg = IX;
	else if (!r.compare("iy")) reg = IY;
	else if (!r.compare("sp")) reg = SP;
	else if (isHex(r)) reg = NN;
}

// Checks if an instruction is valid
// Does not alter byteCode if invalid
// Populates byteCode if valid with hex string equivalent to the assembled instruction
void Assembler::lookup(const std::vector<std::string> &tokens, const uint16_t &programLine, std::string &byteCode) {
	const std::string inst = tokens[0];
	const unsigned int count = tokens.size();
	
	if (!inst.compare("nop") && count == 1)
		byteCode += "00";
	else if (!inst.compare("ld") && count == 3) {
		std::string dst = tokens[1], src = tokens[2];
		Reg dReg = NONE, sReg = NONE;
		getReg(dst, dReg);
		if (dReg == NONE) return;
		getReg(src, sReg);
		if (sReg == NONE) return;
		std::string hex;
		if (dReg == B) {
			switch(sReg) {
				case N:
					if (isHex(src)) {
						byteCode += "06" + src;
						return;
					}
					break;
				case B: byteCode += "40"; return;
				case C: byteCode += "41"; return;
				case D: byteCode += "42"; return;
				case E: byteCode += "43"; return;
				case H: byteCode += "44"; return;
				case L: byteCode += "45"; return;
				case pHL: byteCode += "46"; return;
				case A: byteCode += "47"; return;
				case IXH: byteCode += "dd44"; return;
				case IXL: byteCode += "dd45"; return;
				case pIXpN:
					hex = src.substr(4, src.length() - 1);
					if (isHex(hex)) {
						byteCode += "dd46" + hex;
						return;
					}
					break;
				case IYH: byteCode += "fd44"; return;
				case IYL: byteCode += "fd45"; return;
				case pIYpN:
					hex = src.substr(4, src.length() - 1);
					if (isHex(hex)) {
						byteCode += "fd46" + hex;
						return;
					}
					break;
			}
		}
		if (dReg == C) {
			switch (sReg) {
				case N:
					if (isHex(src)) {
						byteCode += "0e" + src;
						return;
					}
					break;
				case B: byteCode += "48"; return;
				case C: byteCode += "49"; return;
				case D: byteCode += "4a"; return;
				case E: byteCode += "4b"; return;
				case H: byteCode += "4c"; return;
				case L: byteCode += "4d"; return;
				case pHL: byteCode += "4e"; return;
				case A: byteCode += "4f"; return;
				case IXH: byteCode += "dd4c"; return;
				case IXL: byteCode += "dd4d"; return;
				case pIXpN:
					hex = src.substr(4, src.length() - 1);
					if (isHex(hex)) {
						byteCode += "dd4e" + hex;
						return;
					}
					break;
				case IYH: byteCode += "fd4c"; return;
				case IYL: byteCode += "fd4d"; return;
				case pIYpN:
					hex = src.substr(4, src.length() - 1);
					if (isHex(hex)) {
						byteCode += "fd4e" + hex;
						return;
					}
					break;
			}
		}
		if (dReg == D) {
			switch(sReg) {
				case N:
					if (isHex(src)) {
						byteCode += "16" + src;
						return;
					}
					break;
				case B: byteCode += "50"; return;
				case C: byteCode += "51"; return;
				case D: byteCode += "52"; return;
				case E: byteCode += "53"; return;
				case H: byteCode += "54"; return;
				case L: byteCode += "55"; return;
				case pHL: byteCode += "56"; return;
				case A: byteCode += "47"; return;
				case IXH: byteCode += "dd54"; return;
				case IXL: byteCode += "dd55"; return;
				case pIXpN:
					hex = src.substr(4, src.length() - 1);
					if (isHex(hex)) {
						byteCode += "dd56" + hex;
						return;
					}
					break;
				case IYH: byteCode += "fd54"; return;
				case IYL: byteCode += "fd45"; return;
				case pIYpN:
					hex = src.substr(4, src.length() - 1);
					if (isHex(hex)) {
						byteCode += "fd56" + hex;
						return;
					}
					break;
			}
		}
		if (dReg == E) {
			switch (sReg) {
				case N:
					if (isHex(src)) {
						byteCode += "1e" + src;
						return;
					}
					break;
				case B: byteCode += "58"; return;
				case C: byteCode += "59"; return;
				case D: byteCode += "5a"; return;
				case E: byteCode += "5b"; return;
				case H: byteCode += "5c"; return;
				case L: byteCode += "5d"; return;
				case pHL: byteCode += "5e"; return;
				case A: byteCode += "5f"; return;
				case IXH: byteCode += "dd5c"; return;
				case IXL: byteCode += "dd5d"; return;
				case pIXpN:
					hex = src.substr(4, src.length() - 1);
					if (isHex(hex)) {
						byteCode += "dd5e" + hex;
						return;
					}
					break;
				case IYH: byteCode += "fd5c"; return;
				case IYL: byteCode += "fd5d"; return;
				case pIYpN:
					hex = src.substr(4, src.length() - 1);
					if (isHex(hex)) {
						byteCode += "fd5e" + hex;
						return;
					}
					break;
			}
		}
		if (dReg == H) {
			switch(sReg) {
				case N:
					if (isHex(src)) {
						byteCode += "26" + src;
						return;
					}
					break;
				case B: byteCode += "60"; return;
				case C: byteCode += "61"; return;
				case D: byteCode += "62"; return;
				case E: byteCode += "63"; return;
				case H: byteCode += "64"; return;
				case L: byteCode += "65"; return;
				case pHL: byteCode += "66"; return;
				case A: byteCode += "67"; return;
				case pIXpN:
					hex = src.substr(4, src.length() - 1);
					if (isHex(hex)) {
						byteCode += "dd66" + hex;
						return;
					}
					break;
				case pIYpN:
					hex = src.substr(4, src.length() - 1);
					if (isHex(hex)) {
						byteCode += "fd66" + hex;
						return;
					}
					break;
			}
		}
		if (dReg == L) {
			switch (sReg) {
				case N:
					if (isHex(src)) {
						byteCode += "2e" + src;
						return;
					}
					break;
				case B: byteCode += "68"; return;
				case C: byteCode += "69"; return;
				case D: byteCode += "6a"; return;
				case E: byteCode += "6b"; return;
				case H: byteCode += "6c"; return;
				case L: byteCode += "6d"; return;
				case pHL: byteCode += "6e"; return;
				case A: byteCode += "6f"; return;
				case pIXpN:
					hex = src.substr(4, src.length() - 1);
					if (isHex(hex)) {
						byteCode += "dd6e" + hex;
						return;
					}
					break;
				case pIYpN:
					hex = src.substr(4, src.length() - 1);
					if (isHex(hex)) {
						byteCode += "fd6e" + hex;
						return;
					}
					break;
			}
		}
		if (dReg == pHL) {
			switch(sReg) {
				case N:
					if (isHex(src)) {
						byteCode += "36" + src;
						return;
					}
					break;
				case B: byteCode += "70"; return;
				case C: byteCode += "71"; return;
				case D: byteCode += "72"; return;
				case E: byteCode += "73"; return;
				case H: byteCode += "74"; return;
				case L: byteCode += "75"; return;
				case A: byteCode += "77"; return;
			}
		}
		if (dReg == A) {
			switch (sReg) {
				case pBC: byteCode += "0a"; return;
				case pDE: byteCode += "1a"; return;
				case pNN: byteCode += "3a"; return;
				case N:
					if (isHex(src)) {
						byteCode += "3e" + src;
						return;
					}
					break;
				case B: byteCode += "78"; return;
				case C: byteCode += "79"; return;
				case D: byteCode += "7a"; return;
				case E: byteCode += "7b"; return;
				case H: byteCode += "7c"; return;
				case L: byteCode += "7d"; return;
				case pHL: byteCode += "7e"; return;
				case A: byteCode += "7f"; return;
				case I: byteCode += "3d57"; return;
				case R: byteCode += "3d5f"; return;
				case IXH: byteCode += "dd7c"; return;
				case IXL: byteCode += "dd7d"; return;
				case pIXpN:
					hex = src.substr(4, src.length() - 1);
					if (isHex(hex)) {
						byteCode += "dd7e" + hex;
						return;
					}
					break;
				case IYH: byteCode += "fd7c"; return;
				case IYL: byteCode += "fd7d"; return;
				case pIYpN:
					hex = src.substr(4, src.length() - 1);
					if (isHex(hex)) {
						byteCode += "fd7e" + hex;
						return;
					}
					break;
			}
		}
		if (dReg == IXH) {
			switch (sReg) {
				case N:
					if (isHex(src)) {
						byteCode += "dd26" + src;
						return;
					}
					break;
				case B: byteCode += "dd60"; return;
				case C: byteCode += "dd61"; return;
				case D: byteCode += "dd62"; return;
				case E: byteCode += "dd63"; return;
				case H: byteCode += "dd64"; return;
				case L: byteCode += "dd65"; return;
				case A: byteCode += "dd67"; return;
			}
		}
		if (dReg == IXL) {
			switch (sReg) {
				case N:
					if (isHex(src)) {
						byteCode += "dd2e" + src;
						return;
					}
					break;
				case B: byteCode += "dd68"; return;
				case C: byteCode += "dd69"; return;
				case D: byteCode += "dd6a"; return;
				case E: byteCode += "dd6b"; return;
				case H: byteCode += "dd6c"; return;
				case L: byteCode += "dd6d"; return;
				case A: byteCode += "dd6f"; return;
			}
		}
		if (dReg == IYH) {
			switch (sReg) {
				case N:
					if (isHex(hex)) {
						byteCode += "fd26" + src;
						return;
					}
					break;
				case B: byteCode += "fd60"; return;
				case C: byteCode += "fd61"; return;
				case D: byteCode += "fd62"; return;
				case E: byteCode += "fd63"; return;
				case H: byteCode += "fd64"; return;
				case L: byteCode += "fd65"; return;
				case A: byteCode += "fd67"; return;
			}
		}
		if (dReg == IYL) {
			switch (sReg) {
				case N:
					if (isHex(src)) {
						byteCode += "fd2e" + src;
						return;
					}
					break;
				case B: byteCode += "fd68"; return;
				case C: byteCode += "fd69"; return;
				case D: byteCode += "fd6a"; return;
				case E: byteCode += "fd6b"; return;
				case H: byteCode += "fd6c"; return;
				case L: byteCode += "fd6d"; return;
				case A: byteCode += "fd6f"; return;
			}
		}
		if (dReg == pNN) {
			hex = src.substr(1, src.length() - 1);
			if (isHex(hex, 2)) {
				switch (sReg) {
					case HL: byteCode += "22" + hex; return;
					case A: byteCode += "32" + hex; return;	
					case BC: byteCode += "ed43" + hex; return;	
					case DE: byteCode += "ed53" + hex; return;	
					case SP: byteCode += "ed73" + hex; return;	
					case IX: byteCode += "dd22" + hex; return;	
					case IY: byteCode += "fd22" + hex; return;	
				}
			}
		}
		if (dReg == pBC && sReg == A) {
			byteCode += "02";
			return;
		}
		if (dReg == pDE && sReg == A) {
			byteCode += "12";
			return;
		}
		if (dReg == pIXpN) {
			makeHex(dst.substr(), hex);
			if (hex.length() == 2) {
				switch (sReg) {
					case N: {
						std::string hex2;
						makeHex(src, hex2);
						if (hex2.length() == 2) {
							byteCode += "dd36" + hex + hex2;
							return;
						}
						break;
					}
					case B: byteCode += "dd70" + hex; return;
					case C: byteCode += "dd71" + hex; return;
					case D: byteCode += "dd72" + hex; return;
					case E: byteCode += "dd73" + hex; return;
					case H: byteCode += "dd74" + hex; return;
					case L: byteCode += "dd75" + hex; return;
					case A: byteCode += "dd77" + hex; return;
				}
			}
			hex.clear();
		}
		if (dReg == pIYpN) {
			makeHex(dst.substr(), hex);
			if (hex.length() == 2) {
				switch (sReg) {
					case N: {
						std::string hex2;
						makeHex(src, hex2);
						if (hex2.length() == 2) {
							byteCode += "fd36" + hex + hex2;
							return;
						}
						break;
					}
					case B: byteCode += "fd70" + hex; return;
					case C: byteCode += "fd71" + hex; return;
					case D: byteCode += "fd72" + hex; return;
					case E: byteCode += "fd73" + hex; return;
					case H: byteCode += "fd74" + hex; return;
					case L: byteCode += "fd75" + hex; return;
					case A: byteCode += "fd77" + hex; return;
				}
			}
			hex.clear();
		}
		if (dReg == I && sReg == A) {
			byteCode += "ed47";
			return;
		}
		if (dReg == R && sReg == A) {
			byteCode += "ed4f";
			return;
		}
		if (dReg == BC) {
			makeHex(src, hex);
			if (hex.length() == 4) {
				byteCode += "01" + hex;
				return;
			}
			hex.clear();
		}
		if (dReg == DE) {
			makeHex(src, hex);
			if (hex.length() == 4) {
				byteCode += "11" + hex;
				return;
			}
			hex.clear();
		}
		if (dReg == HL) {
			makeHex(src, hex);
			if (hex.length() == 4) {
				byteCode += "21" + hex;
				return;
			}
			hex.clear();
		}
		if (dReg == IX) {
			const bool opened = src[0] == '(', closed = src[src.length() - 1] == ')';
			if (opened || closed) {
				if (opened && closed) {
					makeHex(src.substr(1, src.length() - 1), hex);
					if (hex.length() == 4) {
						byteCode += "dd2a" + hex;
						return;
					}
				}
			} else {
				makeHex(src, hex);
				if (hex.length() == 4) {
					byteCode += "dd21" + hex;
					return;
				}
			}
			hex.clear();
		}
		if (dReg == IY) {
			const bool opened = src[0] == '(', closed = src[src.length() - 1] == ')';
			if (opened || closed) {
				if (opened && closed) {
					makeHex(src.substr(1, src.length() - 1), hex);
					if (hex.length() == 4) {
						byteCode += "fd2a" + hex;
						return;
					}
				}
			} else {
				makeHex(src, hex);
				if (hex.length() == 4) {
					byteCode += "fd21" + hex;
					return;
				}
			}
			hex.clear();
		}
		if (dReg == SP) {
			switch (sReg) {
				case NN:
					makeHex(src, hex);
					if (hex.length() == 4) {
						byteCode += "31" + hex;
						return;
					}
					break;
				case HL: byteCode += "f9"; return;
				case pNN:
					makeHex(src.substr(1, src.length() - 1), hex);
					if (hex.length() == 4) {
						byteCode += "ed7b" + hex;
						return;
					}
					break;
				case IX: byteCode += "ddf9"; return;
				case IY: byteCode += "fdf9"; return;
			}
		}
	}
}
