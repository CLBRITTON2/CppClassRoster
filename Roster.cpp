#include "Roster.h"
#include <iostream>
#include "Student.h"

Student* ClassRosterArray[5];

Roster::Roster()
{
	// initialize class roster pointers to null so we don't get garbage values
	for (int i{0}; i <= 4; i++)
	{
		ClassRosterArray[i] = nullptr;
	}

	std::cout << "Roster constructor called, class roster array pointers initialized to null" << std::endl;;
}

void Roster::Add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree::DegreeProgram degreeProgram)
{
	int counter{ 0 };
	std::cout << "Student: " << firstName << " added to class roster" << std::endl;
	if (ClassRosterArray[counter] == NULL)
	{
		ClassRosterArray[counter] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
	}
	counter++;
}

void Roster::Remove(std::string studentID)
{
}

void Roster::PrintAll()
{
	std::cout << "Print all called" << std::endl;

	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int age;
	int* daysInCourseOne;
	Degree::DegreeProgram degreeProgram;

		//Grab all of the values from the student
		for (int i{ 0 }; i <= 4; i++)
		{
			studentID = (*ClassRosterArray)->GetStudentId();
			firstName = (*ClassRosterArray)->GetStudentFirstName();
			lastName = (*ClassRosterArray)->GetStudentLastName();
			emailAddress = (*ClassRosterArray)->GetStudentEmailAddress();
			age = (*ClassRosterArray)->GetStudentAge();
			daysInCourseOne = (*ClassRosterArray)->GetDaysToCompleteCourses();
			degreeProgram = (*ClassRosterArray)->GetStudentDegreeProgram();
		}

	std::cout << studentID << "    ";
	std::cout << "First Name: " << firstName << "    ";
	std::cout << "Last Name: " << lastName << "    ";
	std::cout << "Age: " << age << "    ";
	std::cout << "daysInCourse: {";
	std::string separator{ "," };
	std::string whiteSpace{ " " };
	for (int i{ 0 }; i <= 2; i++)
	{
		if (daysInCourseOne[i] == daysInCourseOne[2])
		{
			separator = "";
			whiteSpace = "";
		}
		std::cout << daysInCourseOne[i] << separator << whiteSpace;
	}
	std::cout << "}    ";
	std::cout << "Degree Program: " << degreeProgram << "    ";
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
