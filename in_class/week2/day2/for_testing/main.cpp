#include <iostream>

int main()
{
	std::cout << "Starting for\n";
	for (short i = 0; i > 0; --i)
		std::cout << "for: i = " << i << '\n';
	
	std::cout << "Ending for\n";
	std::cin.get();
	
	std::cout << "Starting while\n";
	short i = 0;
	while (i > 0)
	{
		std::cout << "while: i = " << i << '\n';
		++i;
	}
	
	std::cout << "Ending while\n";
	std::cin.get();
	
	std::cout << "Starting do while\n";
	i = 0;
	do
	{
		std::cout << "do while: i = " << i << '\n';
		++i;
	}
	while (i > 0);
	
	std::cout << "Ending do while\n";
	std::cin.get();
	return 0; 
}
