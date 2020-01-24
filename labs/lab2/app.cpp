#include <iostream>

#define MAX_CHAR 100
#define MIN_A 90.0
#define MIN_B 80.0
#define MIN_C 70.0
#define MIN_D 60.0

double GetAvg()
{
	double finalAvg;
	
	std::cout << "Please enter your final average: ";
	std::cin >> finalAvg;
	
	while (!std::cin)
	{
		std::cin.clear();
		std::cin.ignore(MAX_CHAR, '\n');
		std::cout << "Input has to be numerical!\n";
		std::cin >> finalAvg;
	}
	
	std::cin.ignore(MAX_CHAR, '\n');
	return finalAvg;
}

char DetermineGrade(double finalAvg)
{
	if (finalAvg >= MIN_A)
		return 'A';	
	else if (finalAvg >= MIN_B)
		return 'B';
	else if (finalAvg >= MIN_C)
		return 'C';
	else if (finalAvg >= MIN_D)
		return 'D';
	else
		return 'F';
}

void PrintMsg(char grade)
{
	switch(grade)
	{
		case 'A':
			std::cout << "Excellent!\n";
			break;
		case 'B':
			std::cout << "Good job!\n";
			break;
		case 'C':
			std::cout << "You've passed!\n";
			break;
		case 'D':
			std::cout << "You need to study more!\n";
			break;
		default:
			std::cout << "You slip on a banana peel...\n";
			break;
	}
}

int main()
{
	PrintMsg(DetermineGrade(GetAvg()));

	return 0;
}
