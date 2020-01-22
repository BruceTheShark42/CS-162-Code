#include "BigInt.h"

#include <iostream>

BigInt::BigInt()
	: m_MaxIndex(0)
{
	
}

BigInt::BigInt(const unsigned long& num)
	: BigInt()
{
	m_Num[0] = (unsigned long)num;
}

void BigInt::Add(const unsigned long& num)
{
	unsigned char i;
	for (i = 0; i < 1 && i < BIG_DIGITS; ++i)
		if (m_Num[i] > (m_Num[i] += num) && i < BIG_DIGITS - 1)
			++m_Num[i + 1];
	
	if (i > m_MaxIndex)
		m_MaxIndex = i;
}


void BigInt::Add(const BigInt& num)
{
	unsigned char i;
	for (i = 0; i < BIG_DIGITS; ++i)
		if (m_Num[i] > (m_Num[i] += num.m_Num[i]) && i < BIG_DIGITS - 1)
			++m_Num[i + 1];
	
	if (i > m_MaxIndex)
		m_MaxIndex = i;
}

void BigInt::Print() const
{
	std::cout << "0x";
	for (char i = BIG_DIGITS - 1; i >= 0; --i)
	{
		// 16 f's in a long; i.e. 0xffffffffffffffff is -1 as a long and has 16 f's
		unsigned long digit = m_Num[i];
		
		int hexIdx = 16;
		char hexStr[17] {0};
		
		while (digit)
		{
			char lsb4 = digit & 0xf;
			hexStr[--hexIdx] = (lsb4 < 10 ? (char)(lsb4 + '0') : lsb4 - 10 + 'a'); // TODO: Optimization - Hard code 'a' - 10 as actual value instead of calculating that every time
			digit >>= 4;
		}
		
		for ( ; hexIdx > 0; )
			hexStr[--hexIdx] = '0';
		
		std::cout << hexStr << ' ';
	}
	std::cout << '\n';
}
