// Made by Bruce Cosgrove

#include "Reg16.h"

Reg16::Reg16() : data(0) {}
uint16_t Reg16::get() const { return data; }
void Reg16::set(const uint16_t &data) { this->data = data; }
void Reg16::setBits(const uint16_t &bits, const bool set) { data = set ? data | bits : data & ~bits; }
void Reg16::resetBits(const uint16_t &bits) { data &= ~bits; }
void Reg16::flipBits(const uint16_t &bits) { data ^= bits; }
void Reg16::maskBits(const uint16_t &bits) { data &= bits; }
uint8_t Reg16::getLow() const { return low; }
void Reg16::setLow(const uint8_t &data) { low = data; }
void Reg16::setLowBits(const uint8_t &bits, const bool set) { low = set ? low | bits : low & ~bits; }
void Reg16::resetLowBits(const uint8_t &bits) { low &= ~bits; }
void Reg16::flipLowBits(const uint8_t &bits) { low ^= bits; }
void Reg16::maskLowBits(const uint8_t &bits) { low &= bits; }
uint8_t Reg16::getHigh() const { return high; }
void Reg16::setHigh(const uint8_t &data) { high = data; }
void Reg16::setHighBits(const uint8_t &bits, const bool set) { high = set ? high | bits : high & ~bits; }
void Reg16::resetHighBits(const uint8_t &bits) { high &= ~bits; }
void Reg16::flipHighBits(const uint8_t &bits) { high ^= bits; }
void Reg16::maskHighBits(const uint8_t &bits) { high &= bits; }
