// Made by Bruce Cosgrove

#include "ALU.h"

#include <cstdint>

// ZERO     set if the sum of the registers == 0 else reset
// CARRY    set if the sum of the registers > 255 else reset
// NEGATIVE reset
// SUBTRACT reset
// PARITY   set if the sum's lsb == 1 else reset
// UNUSED_5 unaffected
// UNUSED_6 unaffected
// UNUSED_7 unaffected
void ALU::add(const Reg8 &reg1, const Reg8 &reg2, const bool &carry) {
	uint16_t sum = (uint16_t)reg1.get() + (uint16_t)reg2.get() + carry;
	af.setHigh((uint8_t)(sum & 0xff));
	af.setLowBits(Flags::ZERO, !(sum & 0x00ff));
	af.setLowBits(Flags::CARRY, sum & 0x0100);
	af.resetLowBits(Flags::NEGATIVE | Flags::SUBTRACT);
	af.setLowBits(Flags::PARITY, sum & 0x0001);
}

// ZERO     set if reg1 == reg2 else reset
// CARRY    set if reg1 < reg2 else reset
// NEGATIVE set if the difference's msb == 1 else reset
// SUBTRACT set
// PARITY   set if the difference's lsb == 1 else reset
// UNUSED_5 unaffected
// UNUSED_6 unaffected
// UNUSED_7 unaffected
void ALU::sub(const Reg8 &reg1, const Reg8 &reg2, const bool &carry) {
	int16_t diff = (int16_t)reg1.get() - (int16_t)reg2.get() - carry;
	af.setHigh((uint8_t)(diff & 0xff));
	af.setLowBits(Flags::ZERO, !(diff & 0xff));
	af.setLowBits(Flags::CARRY, diff & 0x8000);
	af.setLowBits(Flags::NEGATIVE, a.get() & 0x80);
	af.setLowBits(Flags::SUBTRACT);
	af.setLowBits(Flags::PARITY, sum & 0x0001);
}

// ZERO     set if the result == 0 else reset
// CARRY    reset
// NEGATIVE reset
// SUBTRACT reset
// PARITY   set if the result's lsb == 1 else reset
// UNUSED_5 unaffected
// UNUSED_6 unaffected
// UNUSED_7 unaffected
void ALU::shiftRight(const Reg8 &reg, const bool &carry) {
	uint8_t shift = (a.get() >> 1) | (carry && (f.get()	& Flags::CARRY) ? 0x80 : 0x00);
	af.setHigh(shift);
	af.setLowBits(Flags::ZERO, !shift);
	af.resetLowBits(Flags::CARRY | Flags::NEGATIVE | Flags::SUBTRACT);
	af.setLowBits(Flags::PARITY, shift & 0x01);
}

// ZERO     set if the result == 0 else reset
// CARRY    reset
// NEGATIVE reset
// SUBTRACT reset
// PARITY   set if the result's lsb == 1 else reset
// UNUSED_5 unaffected
// UNUSED_6 unaffected
// UNUSED_7 unaffected
void ALU::shiftLeft(const Reg8 &reg, const bool &carry) {
	uint8_t shift = a.get() << 1 | (carry && (f.get() & Flags::CARRY));
	af.setHigh(shift);
	af.setLowBits(Flags::ZERO, !shift);
	af.resetLowBits(Flags::CARRY | Flags::NEGATIVE | Flags::SUBTRACT);
	af.setLowBits(Flags::PARITY, shift & 0x01);
}

// ZERO     set if the result == 0 else reset
// CARRY    unaffected if the operation indicates that the carry is not used, else set if the result's lsb == 1 else reset
// NEGATIVE reset
// SUBTRACT reset
// PARITY   set if the result's lsb == 1 else reset
// UNUSED_5 unaffected
// UNUSED_6 unaffected
// UNUSED_7 unaffected
void ALU::rotateRight(const Reg8 &reg, const bool &carry) {
	uint8_t shift = (a.get() >> 1) | (carry && (f.get()	& Flags::CARRY) ? 0x80 : 0x00);
	bool lsb = a.get() & 0x01;
	af.setHigh(shift);
	af.setLowBits(Flags::ZERO, !shift);
	if (carry) af.setLowBits(Flags::CARRY, lsb);
	af.resetLowBits(Flags::NEGATIVE | Flags::SUBTRACT);
	af.setLowBits(Flags::PARITY, shift & 0x01);
}

// ZERO     set if the result == 0 else reset
// CARRY    unaffected if the operation indicates that the carry is not used, else set if the result's msb == 1 else reset
// NEGATIVE reset
// SUBTRACT reset
// PARITY   set if the result's lsb == 1 else reset
// UNUSED_5 unaffected
// UNUSED_6 unaffected
// UNUSED_7 unaffected
void ALU::rotateLeft(const Reg8 &reg, const bool &carry) {
	uint8_t shift = a.get() << 1 | (carry && (f.get() & Flags::CARRY));
	bool msb = a.get() & 0x80;
	af.setHigh(shift);
	af.setLowBits(Flags::ZERO, !shift);
	af.setLowBits(Flags::CARRY, carry && msb);
	af.resetLowBits(Flags::NEGATIVE | Flags::SUBTRACT);
	af.setLowBits(Flags::PARITY, shift & 0x01);
}

// ZERO     set if the result == 0 else reset
// CARRY    reset
// NEGATIVE reset
// SUBTRACT reset
// PARITY   set if the result's lsb == 1 else reset
// UNUSED_5 unaffected
// UNUSED_6 unaffected
// UNUSED_7 unaffected
void ALU::bitwiseAND(const Reg8 &reg1, const Reg8 &reg2) {
	uint8_t bits = reg1.get() & reg2.get();
	af.setHigh(bits);
	af.setLowBits(Flags::ZERO, !bits);
	af.resetLowBits(Flags::CARRY | Flags::NEGATIVE | Flags::SUBTRACT);
	af.setLowBits(Flags::PARITY, bits & 0x01);
}

// ZERO     set if the result == 0 else reset
// CARRY    reset
// NEGATIVE reset
// SUBTRACT reset
// PARITY   set if the result's lsb == 1 else reset
// UNUSED_5 unaffected
// UNUSED_6 unaffected
// UNUSED_7 unaffected
void ALU::bitwiseOR(const Reg8 &reg1, const Reg8 &reg2) {
	uint8_t bits = reg1.get() | reg2.get();
	af.setHigh(bits);
	af.setLowBits(Flags::ZERO, !bits);
	af.resetLowBits(Flags::CARRY | Flags::NEGATIVE | Flags::SUBTRACT);
	af.setLowBits(Flags::PARITY, bits & 0x01);
}

// ZERO     set if the result == 0 else reset
// CARRY    reset
// NEGATIVE reset
// SUBTRACT reset
// PARITY   set if the result's lsb == 1 else reset
// UNUSED_5 unaffected
// UNUSED_6 unaffected
// UNUSED_7 unaffected
void ALU::bitwiseXOR(const Reg8 &reg1, const Reg8 &reg2) {
	uint8_t bits = reg1.get() ^ reg2.get();
	af.setHigh(bits);
	af.setLowBits(Flags::ZERO, !bits);
	af.resetLowBits(Flags::CARRY | Flags::NEGATIVE | Flags::SUBTRACT);
	af.setLowBits(Flags::PARITY, bits & 0x01);
}

// ZERO     set if the result == 0 else reset
// CARRY    reset
// NEGATIVE reset
// SUBTRACT reset
// PARITY   set if the result's lsb == 1 else reset
// UNUSED_5 unaffected
// UNUSED_6 unaffected
// UNUSED_7 unaffected
void ALU::bitwiseNOT(const Reg8 &reg) {
	uint8_t bits = ~reg.get();
	af.setHigh(bits);
	af.setLowBits(Flags::ZERO, !bits);
	af.resetLowBits(Flags::CARRY | Flags::NEGATIVE | Flags::SUBTRACT);
	af.setLowBits(Flags::PARITY, bits & 0x01);
}

Reg16& ALU::getStatus() const { return &af; }
