#include "Student.h"
#include <iostream>

Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourseOne, int daysInCourseTwo, int daysInCourseThree, Degree::DegreeProgram degreeProgram)
	: _studentID{ studentID }, _firstName{ firstName }, _lastName{ lastName }, _emailAddress{ emailAddress }, _age{ age }, _daysInCourseOne{ daysInCourseOne }, _daysInCourseTwo{ daysInCourseTwo }, _daysInCourseThree{daysInCourseThree}, _degreeProgram{
	degreeProgram
}
{

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
	 return new int[3] { _daysInCourseOne, _daysInCourseTwo, _daysInCourseThree };
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
	_daysInCourseOne = daysInCourseOne;
	_daysInCourseTwo = daysInCourseTwo;
	_daysInCourseThree = daysInCourseThree;
}

void Student::SetStudentDegreeProgram(Degree::DegreeProgram degreeProgram)
{
	_degreeProgram = degreeProgram;
}

void Student::PrintStudentDetails()
{
	std::cout << "Student ID: " << _studentID << std::endl;
	std::cout << "First Name: " << _firstName << std::endl;
	std::cout << "Last Name: " << _lastName << std::endl;
	std::cout << "Email Address: " << _emailAddress << std::endl;
	std::cout << "Age: " << _age << std::endl;
	std::cout << "Days in Course One: " << _daysInCourseOne << std::endl;
	std::cout << "Days in Course Two: " << _daysInCourseTwo << std::endl;
	std::cout << "Days in Course Three: " << _daysInCourseThree << std::endl;
	std::cout << "Degree Program: " << _degreeProgram << std::endl;
}
