// Made by Bruce Cosgrove

#include "Reg8.h"

Reg8::Reg8() : data((uint8_t)0) {}

uint8_t Reg8::get() const { return data; }
void Reg8::set(const uint8_t &data) { this->data = data; }
void Reg8::setBits(const uint8_t &bits, const bool &set) { data = set ? data | bits : data & ~bits; }
void Reg8::resetBits(const uint8_t &bits) { data &= ~bits; }
void Reg8::toggleBits(const uint8_t &bits) { data ^= bits; }
void Reg8::maskBits(const uint8_t &mask) { data &= mask; }

std::ostream& operator<<(std::ostream& ostr, const Reg8 &reg) { return ostr << +reg.data; }
