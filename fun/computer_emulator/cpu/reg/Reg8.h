// Made by Bruce Cosgrove

#ifndef CPU_REG_REG8_H
#define CPU_REG_REG8_H

#include <cstdint>
#include <ostream>

class Reg8 {
public:
	Reg8();
public:
	uint8_t get() const;
	void set(const uint8_t &data);
	void setBits(const uint8_t &bits, const bool &set = true);
	void resetBits(const uint8_t &bits);
	void toggleBits(const uint8_t &bits);
	void maskBits(const uint8_t &mask);
	
	friend std::ostream& operator<<(std::ostream &ostr, const Reg8 &reg);
	friend class ALU;
private:
	uint8_t data;
};

std::ostream& operator<<(std::ostream &ostr, const Reg8 &reg);

#endif
