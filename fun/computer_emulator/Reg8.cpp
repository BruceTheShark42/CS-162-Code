// Made by Bruce Cosgrove

#include "Reg8.h"

Reg8::Reg8() : data(0) {}
uint8_t Reg8::get() const { return data; }
void Reg8::set(const uint8_t &data) { this->data = data; }
void Reg8::setBits(const uint8_t &bits, const bool set) { data = set ? data | bits : data & ~bits; }
void Reg8::resetBits(const uint8_t &bits) { data &= ~bits; }
void Reg8::flipBits(const uint8_t &bits) { data ^= bits; }
void Reg8::maskBits(const uint8_t &bits) { data &= bits; }
uint8_t Reg8::operator++() { return ++data; }
uint8_t Reg8::operator++(int) { return data++; }
uint8_t Reg8::operator--() { return --data; }
uint8_t Reg8::operator--(int) { return data--; }
std::ostream& operator<<(std::ostream& ostr, Reg8 &reg8) { return ostr << +reg8.data; }
