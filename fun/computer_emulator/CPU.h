// Made by Bruce Cosgrove

#ifndef CPU_H
#define CPU_H

#include <cstdint>

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
	uint8_t fetch();
	void loadProgram(char *prog, const uint16_t &offset = 0);
	void printStatus();
private:
	Computer *cmp;
	uint8_t cycles;
	
	uint16_t af, bc, de, hl, sp, pc;
	struct Inst {
		const char* name;
		uint8_t cycles;
	};
};

#endif
