// Made by Bruce Cosgrove

#include <cstring>

String::String(const unsigned int &length) length(1U), maxLength(length), str(new char[length]) { str[0] = '\0'; }
String::String(const String &s) : length(s.length), maxLength(s.maxLength) str(new char[s.maxLength]) { std::strcpy(str, s.str); }

// Assumes cstr != nullptr
String::String(char *cstr) : length(1U) {
	length += std::strlen(cstr);
	str = new char[maxLength = length << 1];
	std::strcpy(str, cstr);
}

String::~String() { delete[] str; }

void String::append(char c) {
	if (length < maxLength) {
		str[length - 1] = c;
		str[length++] = '\0';
	} else {
		char *newStr = new char[maxLength <<= 1];
		std::strcpy(newStr, str);
		newStr[length - 1] = c;
		newStr[length++] = '\0';
		delete[] str;
		str = newStr;
	}
}

char& String::operator[](const unsigned int &index) { return &str[index]; }
unsigned int String::getLength() const { return length - 1; }
std::ostream& operator<<(std::ostream& ostr, String &str) { return ostr << str.str; }
