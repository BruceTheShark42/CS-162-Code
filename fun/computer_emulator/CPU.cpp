// Made by Bruce Cosgrove

#include "CPU.h"

#include <iostream>
#include <iomanip>

#include "Computer.h"
#include "opcodes.h"

CPU::CPU() { reset(); }
CPU::~CPU() {}
void CPU::setup(Computer *cmp) { this->cmp = cmp; }

void CPU::reset() {
	cycles = 0;
	af = 0x0000;
	bc = 0x0000;
	de = 0x0000;
	hl = 0x0000;
	ix = 0x0000;
	iy = 0x0000;
	sp = 0x0000;
	pc = 0x0000;
	afP = 0x0000;
	bcP = 0x0000;
	deP = 0x0000;
	hlP = 0x0000;
	ir = 0x0000;
}

void CPU::clock() {
	if (cycles == 0) {
		operate(fetch());
//		cycles = instruction.cycles;
//		instruction.operate();
		printStatus();
	}
	--cycles;
}

uint8_t CPU::read(const uint16_t &addr) {
	return cmp->ram.read(addr);
}

void CPU::write(const uint16_t &addr, const uint8_t &data) {
	cmp->ram.write(addr, data);
}

uint8_t CPU::fetch() {
	return read(pc++);
}

// program is in format: "c721001d"
void CPU::loadProgram(char* program, const uint16_t &offset) {
	//											 '0'-1		'9'+1		'a'-10
	auto range = [](uint8_t c) { return c - (c > '/' && c < ':' ? '0' : 'W'); };
	for (unsigned int i = 0; program[i] != '\0'; i += 2) {
		uint8_t c1 = range(program[i + 0]);
		uint8_t c2 = range(program[i + 1]);
		write(i + offset, (c1 << 4) | c2);
	}
}

void CPU::printStatus() {
	std::cout << std::hex << std::setfill('0')
			  << " af=" << std::setw(4) << af
			  << " bc=" << std::setw(4) << bc
			  << " de=" << std::setw(4) << de
			  << " hl=" << std::setw(4) << hl
			  << " sp=" << std::setw(4) << sp
			  << " pc=" << std::setw(4) << pc
			  << " af'=" << std::setw(4) << afP
			  << " bc'=" << std::setw(4) << bcP
			  << " de'=" << std::setw(4) << deP
			  << " hl'=" << std::setw(4) << hlP
			  << " i=" << std::setw(2) << (ir >> 8)
			  << " r=" << std::setw(2) << (ir & 0x00ff)
			  << '\n';
}

void CPU::operate(const uint8_t &inst) {
	switch (inst) {
		case NOP: cycles = 4; break;
	}
}
