// Made by Bruce Cosgrove
// This is not how I would make a string class,
// However, the instructions required that the
// string only hold as many characters as it
// needed. I took that to mean the allocated
// array size.

#include "String.h"

#include <cstring>

String::String() : length(1), maxLength(1), str(new char[1]) { str[0] = '\0'; }
String::String(const String &s) : length(s.length), maxLength(s.maxLength), str(new char[maxLength]) { std::strcpy(str, s.str); }

String::String(char *cstr) {
	length = 1 + std::strlen(cstr);
	str = new char[maxLength = length];
	std::strcpy(str, cstr);
}

String::~String() { delete[] str; }

void String::append(char c) {
	if (length < maxLength) {
		str[length - 1] = c;
		str[length++] = '\0';
	} else {
		char *newStr = new char[++maxLength];
		std::strcpy(newStr, str);
		newStr[length - 1] = c;
		newStr[length++] = '\0';
		delete[] str;
		str = newStr;
	}
}

char& String::operator[](const unsigned int index) { return str[index]; }
unsigned int String::getLength() const { return length - 1; }
char* String::getChars() const { return str; }
std::ostream& operator<<(std::ostream& ostr, String &str) { return ostr << str.str; }
