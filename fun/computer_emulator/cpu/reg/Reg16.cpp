// Made by Bruce Cosgrove

#include "Reg16.h"

#define SET = set ? data | bits : data & ~bits
#define RESET &= ~bits
#define TOGGLE ^= bits
#define MASK &= mask

Reg16::Reg16() : data((uint16_t)0) {}

uint16_t Reg16::get() const { return data; }
uint8_t Reg16::getLow() const { return low; }
uint8_t Reg16::getHigh() const { return high; }
void Reg16::set(const uint16_t &data) { this->data = data; }
void Reg16::setLow(const uint8_t &low) { this->low = low; }
void Reg16::setHigh(const uint8_t &high) { this->high = high; }
void Reg16::setBits(const uint16_t &bits, const bool &set) { data SET; }
void Reg16::resetBits(const uint16_t &bits) { data RESET; }
void Reg16::toggleBits(const uint16_t &bits) { data TOGGLE; }
void Reg16::maskBits(const uint16_t &mask) { data MASK; }
void Reg16::setLowBits(const uint8_t &bits, const bool &set) { low SET; }
void Reg16::resetLowBits(const uint8_t &bits) { low RESET; }
void Reg16::toggleLowBits(const uint8_t &bits) { low TOGGLE; }
void Reg16::maskLowBits(const uint8_t &mask) { low MASK; }
void Reg16::setHighBits(const uint8_t &bits, const bool &set) { high SET; }
void Reg16::resethighBits(const uint8_t &bits) { high RESET; }
void Reg16::toggleHighBits(const uint8_t &bits) { high TOGGLE; }
void Reg16::maskHighBits(const uint8_t &mask) { high MASK; }

std::ostream& operator<<(std::ostream &ostr, const Reg16 &reg) { return ostr << reg.data; }
