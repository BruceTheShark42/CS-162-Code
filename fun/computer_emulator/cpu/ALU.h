// Made by Bruce Cosgrove

#ifndef CPU_ALU_H
#define CPU_ALU_H

#include <cstdint>

#include "reg/Reg8.h"
#include "reg/Reg16.h"
#include "flags.h"

class ALU {
public:
	void add(const Reg8 &reg1, Reg8 &reg2, const bool &carry = false);
	void sub(const Reg8 &reg1, Reg8 &reg2, const bool &carry = false);
	void shiftRight(const Reg8 &reg, const bool &carry = false);
	void shiftLeft(const Reg8 &reg, const bool &carry = false);
	void rotateRight(const Reg8 &reg, const bool &carry = false);
	void rotateLeft(const Reg8 &reg, const bool &carry = false);
	void bitwiseAND(const Reg8 &reg1, const Reg8 &reg2);
	void bitwiseOR(const Reg8 &reg1, const Reg8 &reg2);
	void bitwiseXOR(const Reg8 &reg1, const Reg8 &reg2);
	void bitwiseNOT(const Reg8 &reg);
	
	Reg16& getStatus() const;
private:
	Reg16 af;
};

#endif
