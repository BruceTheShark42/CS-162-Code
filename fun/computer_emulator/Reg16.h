// Made by Bruce Cosgrove

#ifndef REG16_H
#define REG16_H

#include <cstdint>

class Reg16 {
public:
	Reg16();
	uint16_t get() const;
	void set(const uint16_t &data);
	void setBits(const uint16_t &bits, const bool set = true);
	void resetBits(const uint16_t &bits);
	void flipBits(const uint16_t &bits);
	void maskBits(const uint16_t &bits);
	uint8_t getLow() const;
	void setLow(const uint8_t &data);
	void setLowBits(const uint8_t &bits, const bool set = true);
	void resetLowBits(const uint8_t &bits);
	void flipLowBits(const uint8_t &bits);
	void maskLowBits(const uint8_t &bits);
	uint8_t getHigh() const;
	void setHigh(const uint8_t &data);
	void setHighBits(const uint8_t &bits, const bool set = true);
	void resetHighBits(const uint8_t &bits);
	void flipHighBits(const uint8_t &bits);
	void maskHighBits(const uint8_t &bits);
private:
	union {
		uint16_t data;
		struct {
			uint8_t low, high;
		};
	};
};

#endif
