#include "Student.h"

#include <iostream>
#include <cstring>

Student::Student(const char* id, float gpa)
	: id((char*)id), gpa(gpa)
{
	
}

bool Student::isLessThanById(const Student& student) const
{
	return std::strcmp(id, student.id) < 0;
}

bool Student::qualifiesForHonors(float minGPAForHonors) const
{
	return gpa >= minGPAForHonors;
}

void Student::print() const
{
	std::cout << "Id: " << id << ", GPA: " << gpa << '\n';
}
