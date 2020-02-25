// Made by Bruce Cosgrove

#ifndef COMPUTER_H
#define COMPUTER_H

#include <cstdint>

#include "CPU.h"
#include "RAM.h"

class Computer {
public:
	Computer();
	~Computer();
	void run();
	
	CPU cpu;
	RAM ram;
};

#endif
