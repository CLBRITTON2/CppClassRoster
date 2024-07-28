#include "Student.h"
#include <iostream>

Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int* daysToCompleteCourses, Degree::DegreeProgram degreeProgram)
	: _studentID{ studentID }, _firstName{ firstName }, _lastName{ lastName }, _emailAddress{ emailAddress }, _age{ age }, _degreeProgram{
	degreeProgram
}
{
	_daysToCompleteCourses = new int[3];
	_daysToCompleteCourses[0] = daysToCompleteCourses[0];
	_daysToCompleteCourses[1] = daysToCompleteCourses[1];
	_daysToCompleteCourses[2] = daysToCompleteCourses[2];
}

Student::~Student()
{
	// Delete the entire array of days
	delete[] _daysToCompleteCourses;
}

std::string Student::GetStudentId()
{
	return _studentID;
}

std::string Student::GetStudentFirstName()
{
	return _firstName;
}

std::string Student::GetStudentLastName()
{
	return _lastName;
}

std::string Student::GetStudentEmailAddress()
{
	return _emailAddress;
}

int Student::GetStudentAge()
{
	return _age;
}

 int* Student::GetDaysToCompleteCourses()
{
	 return _daysToCompleteCourses;
}

Degree::DegreeProgram Student::GetStudentDegreeProgram()
{
	return _degreeProgram;
}

void Student::SetStudentId(std::string studentID)
{
	_studentID = studentID;
}

void Student::SetStudentFirstName(std::string firstName)
{
	_firstName = firstName;
}

void Student::SetStudentLastName(std::string lastName)
{
	_lastName = lastName;
}

void Student::SetStudentEmailAddress(std::string emailAddress)
{
	_emailAddress = emailAddress;
}

void Student::SetStudentAge(int age)
{
	_age = age;
}

void Student::SetDaysToCompleteCourses(int daysInCourseOne, int daysInCourseTwo, int daysInCourseThree)
{
	_daysToCompleteCourses[0] = daysInCourseOne;
	_daysToCompleteCourses[1] = daysInCourseTwo;
	_daysToCompleteCourses[2] = daysInCourseThree;
}

void Student::SetStudentDegreeProgram(Degree::DegreeProgram degreeProgram)
{
	_degreeProgram = degreeProgram;
}

void Student::PrintStudentDetails()
{
	std::cout << _studentID << "\t";
	std::cout << "First Name: " << _firstName << "\t";
	std::cout << "Last Name: " << _lastName << "\t";
	std::cout << "Age: " << _age << "\t";

	// Creating the days in course text format ex: daysInCourse: {35, 40, 55}
	std::cout << "daysInCourse: {";
	std::string separator{ "," };
	std::string whiteSpace{ " " };
	for (int j{ 0 }; j < 3; j++)
	{
		if (j == 2)
		{
			separator = "";
			whiteSpace = "";
		}
		std::cout << _daysToCompleteCourses[j] << separator << whiteSpace;
	}
	std::cout << "}\t";
	std::cout << "Degree Program: " << Degree::DegreeProgramToString(_degreeProgram) << "\t" << std::endl;
}
