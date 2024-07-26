#pragma once
#include <string>
#include "Degree.h"
#include "Student.h"

class Roster
{
private:
	int _studentCounter;
	Student* _classRosterArray[5];
	const std::string _studentData[5];
public:
	Roster();
	void Add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourseOne, int daysInCourseTwo, int daysInCourseThree, Degree::DegreeProgram degreeProgram);
	void Remove(std::string studentID);
	void PrintAll();
	void PrintAverageDaysInCourse(std::string studentID);
	void PrintInvalidEmails();
	void PrintByDegreeProgram(Degree::DegreeProgram degreeProgram);
	void ParseStudentData(const std::string studentData[], size_t size);
};