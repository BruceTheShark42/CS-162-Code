#pragma once

class Printer1
{
public:
	Printer1(const char* text);
public:
	void Print() const;
private:
	const char* m_Text;
};
