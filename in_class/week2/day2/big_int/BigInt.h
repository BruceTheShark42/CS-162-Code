class BigInt
{
public:
	BigInt();
	BigInt(const unsigned long& num);
public:
	void Add(const unsigned long& num);
	void Add(const BigInt& num);
	
	void Print() const;
private:
	static const unsigned char BIG_DIGITS = 8;
	unsigned long m_Num[BIG_DIGITS] {0};
	unsigned char m_MaxIndex;	
};
