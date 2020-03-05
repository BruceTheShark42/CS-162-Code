// Made by Bruce Cosgrove

#include "util.h"

#include <iostream>
#include <cstring>

String getString(const char *message) {
	// Print the message
	std::cout << message;
	String in;
	
	// Get user input
	for (char c = std::cin.get(); c != '\n'; c = std::cin.get())
		in.append(c);
	
	// Help clean up io stuff
	if (!std::cin) {
		std::cin.clear();
		std::cin.get();
	}
	return in;
}

int getInt(const char *message, const int &returnError) {
	String numberInput = getString(message);
	
	// Validate input
	bool valid = true;
	unsigned int len = numberInput.getLength();
	if (len == 0) {
		valid = false;
		std::cout << "No number present.\n";
	}
	
	for (unsigned int i = 0; valid && i < len; ++i)
		if (numberInput[i] < '0' || numberInput[i] > '9') {
			valid = false;
			std::cout << "Invalid number.\n";
		}
	
	if (valid) {
		return std::stoi(numberInput.getChars());
	} else {
		std::cout << "Defaulting to " << returnError << ".\n";
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
