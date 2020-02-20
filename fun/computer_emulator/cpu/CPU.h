// Made by Bruce Cosgrove

#ifndef CPU_CPU_H
#define CPU_CPU_H

#include "reg/Reg8.h"
#include "reg/Reg16.h"
#include "ALU.h"

class CPU {
public:
	CPU();
	~CPU();
private:
	ALU alu;
	Reg16 bc, de, hl, sp, pc;
};

#endif
