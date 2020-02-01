#ifndef STUDENT_H
#define STUDENT_H

class Student
{
public:
	Student(const char* id, float gpa);
	bool isLessThanById(const Student& student) const;
	bool qualifiesForHonors(float minGPAForHonors) const;
	void print() const;
private:
	char* id;
	float gpa;
};

#endif
