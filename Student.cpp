#include "Student.h"

Student::Student(std::string studentID, std::string firstName, std::string emailAddress, int age, std::vector<int> daysToCompleteCourses, Degree::DegreeProgram degreeProgram)
	: _studentID{studentID}, _firstName{firstName}, _emailAddress{emailAddress}, _age{age}, _daysToCompleteCourses{daysToCompleteCourses}, _degreeProgram{degreeProgram}
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

std::vector<int> Student::GetDaysToCompleteCourses()
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

void Student::SetDaysToCompleteCourses(std::vector<int> daysToCompleteCourses)
{
	_daysToCompleteCourses = daysToCompleteCourses;
}

void Student::SetStudentDegreeProgram(Degree::DegreeProgram degreeProgram)
{
	_degreeProgram = degreeProgram;
}

void Student::PrintStudentDetails()
{
	// For printing specific student data 
}
