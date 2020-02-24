// Made by Bruce Cosgrove

#include "Computer.h"

#include <iostream>

#include "Assembler.h"

Computer::Computer() : carryBit(false), memory(new uint8_t[256] {0}) { sp.set(0xff); }
Computer::~Computer() { delete[] memory; }
void Computer::printStatus() { std::cout << "a=" << a << " b=" << b << " sp=" << sp << " pc=" << pc << " carry=" << carryBit << '\n'; }
uint8_t Computer::fetch() { return memory[pc++]; }
void Computer::pushStack(const uint8_t &data) { memory[sp--] = data; }
uint8_t Computer::popStack() { return memory[++sp]; }

void Computer::run() {
	printStatus();
	
	bool running = true;
	while (running) {
		switch (fetch()) {
			case NOP:
				break;
			case ADD: {
				uint16_t sum = (uint16_t)a.get() + (uint16_t)b.get();
				carryBit = sum & 0x0100;
				a.set((uint8_t)(sum & 0x00ff));
				break;
			}
			case MOVA:
				memory[popStack()] = a.get();
				break;
			case MVB:
				b.set(memory[popStack()]);
				break;
			case MVA:
				a.set(memory[popStack()]);
				break;
			case IFA:
				if (a.get() == 0x00)
					break;
			case JMP:
				pc.set(popStack());
				break;
			case PUSH:
				pushStack(fetch());
				break;
			case POPA:
				a.set(popStack());
				break;
			case POPB:
				b.set(popStack());
				break;
			case HLT:
				running = false;
				break;
			case BNOT:
				a.flipBits(0xff);
				break;
			default:
				break;
		}
		printStatus();
	}
}

void Computer::loadProgram(uint8_t *prog, const uint8_t &offset) {
	for (unsigned int i = 0; prog[i] != '\0' && i + offset < 0x00000100; ++i)
		memory[i + offset] = prog[i] - Assembler::OFFSET;
}
