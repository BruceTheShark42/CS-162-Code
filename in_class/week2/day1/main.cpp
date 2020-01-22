#include <iostream>

// Note: Max numbers this will print is 92
int main()
{
	int num;
	std::cin >> num;
	
	long n0 = 0, n1 = 1, n2 = 1;
	while (num && n2 > 0)
	{
		std::cout << n0 << ' ';
		n2 = n0 + n1;
		n0 = n1;
		n1 = n2;
		--num;
	}
	std::cout << '\n';
	
	return 0;
}
