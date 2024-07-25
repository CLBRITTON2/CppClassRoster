#pragma once
#include <string>
#include "Degree.h"

class Roster
{
private:
	int _studentCounter{ 0 };
public:
	Roster();
	void Add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourseOne, int daysInCourseTwo, int daysInCourseThree, Degree::DegreeProgram degreeProgram);
	void Remove(std::string studentID);
	void PrintAll();
	void PrintAverageDaysInCourse(std::string studentID);
	void PrintInvalidEmails();
	void PrintByDegreeProgram(Degree::DegreeProgram degreeProgram);
};