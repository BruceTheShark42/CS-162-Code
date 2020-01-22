#include <iostream>

const unsigned int MAX_CHARS = 100U;

char* GetString(const char* message)
{	
	std::cout << message;
	char* in = new char[MAX_CHARS + 1];
	std::cin.get(in, MAX_CHARS, '\n');
	std::cin.get();
	return in;
}

void Echo(const char* message)
{	
	char* str = GetString(message);
	std::cout << "Echo: \"" << str << "\"\n";
	delete[] str;
}

int main()
{
	Echo("Enter a message: ");
	Echo("Enter a reminder: ");
	
	return 0;
}
