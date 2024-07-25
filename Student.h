#pragma once
#include <string>
#include <vector>
#include "Degree.h"

class Student
{
private:
	std::string _studentID;
	std::string _firstName;
	std::string _lastName;
	std::string _emailAddress;
	int _age;
	int _daysInCourseOne;
	int _daysInCourseTwo;
	int _daysInCourseThree;
	Degree::DegreeProgram _degreeProgram;

public:
	// Accessors
	std::string GetStudentId();
	std::string GetStudentFirstName();
	std::string GetStudentLastName();
	std::string GetStudentEmailAddress();
	int GetStudentAge();
	int* GetDaysToCompleteCourses();
	Degree::DegreeProgram GetStudentDegreeProgram();

	// Mutators
	void SetStudentId(std::string studentID);
	void SetStudentFirstName(std::string firstName);
	void SetStudentLastName(std::string lastName);
	void SetStudentEmailAddress(std::string emailAddress);
	void SetStudentAge(int age);
	void SetDaysToCompleteCourses(int daysInCourseOne, int daysInCourseTwo, int daysInCourseThree);
	void SetStudentDegreeProgram(Degree::DegreeProgram degreeProgram);

	// Printer
	void PrintStudentDetails();

	// Constructor
	Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourseOne, int daysInCourseTwo, int daysInCourseThree, Degree::DegreeProgram degreeProgram);
};