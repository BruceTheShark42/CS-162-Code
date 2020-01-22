#pragma once

class Printer2
{
public:
	Printer2(const char* text);
public:
	void Print() const;
private:
	const char* m_Text;
};
