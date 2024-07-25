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
	std::vector<int> _daysToCompleteCourses;
	Degree::DegreeProgram _degreeProgram;

public:
	// Accessors
	std::string GetStudentId();
	std::string GetStudentFirstName();
	std::string GetStudentLastName();
	std::string GetStudentEmailAddress();
	int GetStudentAge();
	std::vector<int> GetDaysToCompleteCourses();
	Degree::DegreeProgram GetStudentDegreeProgram();

	// Mutators
	void SetStudentId(std::string studentID);
	void SetStudentFirstName(std::string firstName);
	void SetStudentLastName(std::string lastName);
	void SetStudentEmailAddress(std::string emailAddress);
	void SetStudentAge(int age);
	void SetDaysToCompleteCourses(std::vector<int> daysToCompleteCourses);
	void SetStudentDegreeProgram(Degree::DegreeProgram degreeProgram);

	// Printer
	void PrintStudentDetails();

	// Constructor
	Student(std::string studentID,
			std::string firstName,
			std::string emailAddress,
			int age,
			std::vector<int> daysToCompleteCourses,
			Degree::DegreeProgram degreeProgram);
};