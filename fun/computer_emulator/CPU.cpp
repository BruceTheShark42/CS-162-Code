// Made by Bruce Cosgrove

#include "CPU.h"

#include <iostream>

#include "Computer.h"

CPU::CPU() { reset(); }
CPU::~CPU() { }

void CPU::setup(Computer *cmp) {
	this->cmp = cmp;
}

void CPU::reset() {
	cycles = 0;
	af.set(0x0000);
	bc.set(0x0000);
	de.set(0x0000);
	hl.set(0x0000);
	sp.set(0xffff);
	pc.set(0x0000);
}

void CPU::clock() {
	if (cycles == 0) {
		uint8_t instruction = fetch();
		printStatus();
	} else --cycles;
}

uint8_t CPU::read(const uint16_t &addr) {
	return cmp->ram.read(addr);
}

void CPU::write(const uint16_t &addr, const uint8_t &data) {
	cmp->ram.write(addr, data);
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
	std::cout << std::hex << "af=" << af.get() << " bc=" << bc.get()
			  << " de=" << de.get() << " hl=" << hl.get()
			  << " sp=" << sp.get() << " pc=" << pc.get() << std::dec << '\n';
}

uint8_t CPU::fetch() {
	uint8_t byte = read(pc.get());
	pc.set(pc.get() + 1);
	return byte;
}
