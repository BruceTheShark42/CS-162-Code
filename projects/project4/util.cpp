// Made by Bruce Cosgrove

#include "util.h"

#include <iostream>
#include <cstring>

// Returns a char[] entered by the user
char* getString(const char *message) {
	std::cout << message;
	
	unsigned int length = 0;
	unsigned int maxLength = 16;
	char *in = new char[maxLength];
	char c;
	do {
		std::cin.get(c);
		if (length < maxLength) {
			in[length++] = c;
		} else {
			char *newIn = new char[maxLength <<= 1];
			memcpy(newIn, in, length);
			newIn[length++] = c;
			delete[] in;
			in = newIn;
		}
	} while (c != '\n');
	
	std::cin.get();
	if (!std::cin) {
		std::cin.clear();
		std::cin.get();
	}
	
	return in;
}

int getInt(const char *message, const int &returnError) {
	char *numberInput = getString(message);
	
	// Validate input
	bool valid = true;
	if (!std::strlen(numberInput)) {
		valid = false;
		std::cout << "No number present.\n";
	}
	
	for (unsigned int i = 0; valid && numberInput[i]; ++i)
		if (numberInput[i] < '0' || numberInput[i] > '9') {
			valid = false;
			std::cout << "Invalid number.\n";
		}
	
	if (valid) {
		int number = std::stoi(numberInput);
		delete[] numberInput;
		return number;
	} else {
		std::cout << "Defaulting to " << returnError << ".\n";
		delete[] numberInput;
		return returnError;
	}
}

bool contains(char *str1, const char *str2) {
	unsigned int str1len = std::strlen(str1);
	unsigned int str2len = std::strlen(str2);
	
	if (str1len < str2len)
		return false;
	
	for (unsigned int i = 0; i < str1len - str2len + 1; ++i) {
		bool has = true;
		for (unsigned int j = 0; j < str2len; ++j)
			if (str1[i + j] != str2[j])
				has = false;
		if (has)
			return true;
	}
	return false;
}

bool contains(char *str, char c) {
	unsigned int len = std::strlen(str);
	for (unsigned int i = 0; i < len; ++i)
		if (str[i] == c)
			return true;
	return false;
}
