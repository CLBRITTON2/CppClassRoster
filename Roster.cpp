#include "Roster.h"
#include <iostream>
#include "Student.h"

Roster::Roster()
{

}

void Roster::Add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree::DegreeProgram degreeProgram)
{
}

void Roster::Remove(std::string studentID)
{
}

void Roster::PrintAll()
{
	//std::cout << _studentID << "    ";
	//std::cout << "First Name: " << _firstName << "    ";
	//std::cout << "Last Name: " << _lastName << "    ";
	//std::cout << "Age: " << _age << "    ";
	//std::cout << "daysInCourse: {";
	//std::string separator{ "," };
	//std::string whiteSpace{ " " };
	//for (int i{ 0 }; i < _daysToCompleteCourses.size(); i++)
	//{
	//	if (_daysToCompleteCourses[i] == _daysToCompleteCourses.back())
	//	{
	//		separator = "";
	//		whiteSpace = "";
	//	}
	//	std::cout << _daysToCompleteCourses[i] << separator << whiteSpace;
	//}
	//std::cout << "}    ";
	//std::cout << "Degree Program: " << _degreeProgram << "    ";
}

void Roster::PrintAverageDaysInCourse(std::string studentID)
{
}

void Roster::PrintInvalidEmails()
{
}

void Roster::PrintByDegreeProgram(Degree::DegreeProgram degreeProgram)
{
}
