// Made by Bruce Cosgrove

#ifndef CPU_REG_REG16_H
#define CPU_REG_REG16_H

#include <cstdint>
#include <ostream>

class Reg16 {
public:
	Reg16();
public:
	uint16_t get() const;
	uint8_t getLow() const;
	uint8_t getHigh() const;
	void set(const uint16_t &data);
	void setLow(const uint8_t &low);
	void setHigh(const uint8_t &high);
	void setBits(const uint16_t &bits, const bool &set = true);
	void resetBits(const uint16_t &bits);
	void toggleBits(const uint16_t &bits);
	void maskBits(const uint16_t &mask);
	void setLowBits(const uint8_t &bits, const bool &set = true);
	void resetLowBits(const uint8_t &bits);
	void toggleLowBits(const uint8_t &bits);
	void maskLowBits(const uint8_t &mask);
	void setHighBits(const uint8_t &bits, const bool &set = true);
	void resethighBits(const uint8_t &bits);
	void toggleHighBits(const uint8_t &bits);
	void maskHighBits(const uint8_t &mask);
	
	friend std::ostream& operator<<(std::ostream &ostr, const Reg16 &reg);
	friend class ALU;
private:
	union {
		uint16_t data;
		struct { uint8_t low, high; };
	};
};

std::ostream& operator<<(std::ostream &ostr, const Reg16 &reg);

#endif
