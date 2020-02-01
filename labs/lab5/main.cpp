// Made by Bruce Cosgrove

#include <iostream>

#define MAX_NAMES 10
#define MAX_CHARS 8

// Error checking not required for the assignment...
// So I'm not implementing it
void setName(char** names, const unsigned int index, const char* name, const unsigned int length)
{
	names[index] = new char[length + 1];
	for (unsigned int i = 0; i < length; ++i)
		names[index][i] = name[i];
	names[index][length] = 0;
}

int main()
{
	char ** names;
	
	//write code here to allocate memory for at most 10 names 
	names = new char*[MAX_NAMES];
	
	//write code here to allocate memory and populate the first name as "charlie"
	//it has to be just big enough for "charlie" which is 8 chars including '\0'
	setName(names, 0, "charlie", 7);
	
	//write code here to allocate memory and populate the second name as "sarah"
	//it has to be just big enough for "sarah"
	setName(names, 1, "sarah", 5);
	
	//write code here to print the names
	for (unsigned int i = 0; i < MAX_NAMES; ++i)
		std::cout << names[i] << '\n';
	
	//write code here to deallocate memory for the names
	for (unsigned int i = 0; i < MAX_NAMES; ++i)
		delete[] names[i];
	delete[] names;
	
	return 0;
}
