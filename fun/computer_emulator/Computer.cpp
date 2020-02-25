// Made by Bruce Cosgrove

#include "Computer.h"

Computer::Computer() { cpu.setup(this); }
Computer::~Computer() {}

void Computer::run() {
	bool running = true;
	while (running) {
		cpu.clock();
	}
}
