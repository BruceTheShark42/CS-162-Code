// Made by Bruce Cosgrove

#ifndef CPU_H
#define CPU_H

#include <cstdint>

#include "Reg16.h"

class Computer;

class CPU {
public:
	CPU();
	~CPU();
	void setup(Computer *cmp);
	void reset();
	void clock();
	uint8_t read(const uint16_t &addr);
	void write(const uint16_t &addr, const uint8_t &data);
	void loadProgram(char *prog, const uint16_t &offset = 0);
private:
	Computer *cmp;
	uint8_t cycles;
	
	void printStatus();
	uint8_t fetch();
	
	Reg16 af, bc, de, hl, sp, pc;
};

#endif
