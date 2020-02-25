// Made by Bruce Cosgrove

#ifndef RAM_H
#define RAM_H

#include <cstdint>

class RAM {
public:
	RAM();
	~RAM();
	uint8_t read(const uint16_t &addr);
	void write(const uint16_t &addr, const uint8_t &data);
private:
	uint8_t *memory;
};

#endif
