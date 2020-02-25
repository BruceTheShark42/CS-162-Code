// Made by Bruce Cosgrove

#include "RAM.h"

RAM::RAM() : memory(new uint8_t[0x10000]) {}
RAM::~RAM() { delete[] memory; }
uint8_t RAM::read(const uint16_t &addr) { return memory[addr]; }
void RAM::write(const uint16_t &addr, const uint8_t &data) { memory[addr] = data; }
