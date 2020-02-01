// Made by Bruce Cosgrove

#include "Student.h"

#include <iostream>

int main()
{
	Student s1("G10", 3.9);
	Student s2("G20", 3.5);
	
	s1.print();
	std::cout << "-------------\n";
	s2.print();
	
	if (s1.isLessThanById(s2))
		std::cout << "Student 1's id is < student 2's id.\n";
	else
		std::cout << "Student 1's id is >= student 2's id.\n";
	
	float min = 3.75f;
	std::cout << "Min GPA for honors: " << min << '\n';
	
	if (s1.qualifiesForHonors(min))
		std::cout << "Student 1 qualifies.\n";
	else
		std::cout << "Student 1 does not qualify.\n";
	
	if (s2.qualifiesForHonors(min))
		std::cout << "Student 2 qualifies.\n";
	else
		std::cout << "Student 2 does not qualify.\n";
	
	return 0;
}
