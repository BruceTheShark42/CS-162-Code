// Made by Bruce Cosgrove

#ifndef CPU_H
#define CPU_H

#include <cstdint>
#include <vector>

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
	void operate(const uint8_t &inst);
	void loadProgram(char *prog, const uint16_t &offset = 0);
	void printStatus();
private:
	uint16_t af, bc, de, hl, ix, iy, sp, pc, afP, bcP, deP, hlP, ir;
	Computer *cmp;
	uint8_t cycles;
	
	enum Flags {
		c = 1 << 0,
		n = 1 << 1,
		pv = 1 << 2,
		/*"unused"*/
		h = 1 << 4,
		/*"unused"*/
		z = 1 << 6,
		s = 1 << 7
	};
};

#endif
