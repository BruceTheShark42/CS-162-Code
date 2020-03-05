// Made by Bruce Cosgrove

// BRUCE is included in case there is already a definition of STRING_H, which there probably is
#ifndef BRUCE_STRING_H
#define BRUCE_STRING_H

#include <ostream>

class String {
public:
	String();
	String(const String &s);
	String(char *cstr);
	~String();
public:
	void append(char c);
	char& operator[](const unsigned int index);
	unsigned int getLength() const;
	char* getChars() const;
	friend std::ostream& operator<<(std::ostream& ostr, String &str);
private:
	unsigned int length, maxLength;
	char *str;
};

std::ostream& operator<<(std::ostream& ostr, String &str);

#endif
