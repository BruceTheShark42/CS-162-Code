// Made by Bruce Cosgrove

#ifndef COMPUTER_H
#define COMPUTER_H

#include <cstdint>

#include "Reg8.h"

class Computer {
public:
	Computer();
	~Computer();
	void run();
	void loadProgram(uint8_t *prog, const uint8_t &offset = 0);
private:
	void printStatus();
	uint8_t fetch();
	void pushStack(const uint8_t &data);
	uint8_t popStack();
	
	Reg8 a, b, sp, pc;
	bool carryBit;
	uint8_t *memory;

	enum OPCODES {
		NOP  = 0x00, ADD  = 0x01, MOVA = 0x02, MVB  = 0x03,
		MVA  = 0x04, JMP  = 0x05, IFA  = 0x06, PUSH = 0x07,
		POPA = 0x08, POPB = 0x09, HLT  = 0x0a, BNOT = 0x0b,
	};
};

#endif
