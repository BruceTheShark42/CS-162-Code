// Made by Bruce Cosgrove

#ifndef REG8_H
#define REG8_H

#include <cstdint>
#include <ostream>

class Reg8 {
public:
	Reg8();
	uint8_t get() const;
	void set(const uint8_t &data);
	void setBits(const uint8_t &bits, const bool set = true);
	void resetBits(const uint8_t &bits);
	void flipBits(const uint8_t &bits);
	void maskBits(const uint8_t &bits);
	uint8_t operator++();
	uint8_t operator++(int);
	uint8_t operator--();
	uint8_t operator--(int);
	friend std::ostream& operator<<(std::ostream& ostr, Reg8 &reg8);
private:
	uint8_t data;
};

std::ostream& operator<<(std::ostream& ostr, Reg8 &reg8);

#endif
