#include <iostream>
#include "Roster.h"
#include "Student.h"
#include "Degree.h"

Student* ClassRosterArray[5];

Roster::Roster()
{
	// initialize class roster pointers to null so we don't get garbage values
	for (int i{ 0 }; i <= 4; i++)
	{
		ClassRosterArray[i] = nullptr;
	}

	std::cout << "Roster constructor called, class roster array pointers initialized to null" << std::endl;;
}

void Roster::Add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree::DegreeProgram degreeProgram)
{
	std::cout << "Student: " << firstName << " added to class roster" << std::endl;
	ClassRosterArray[_studentCounter] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
	_studentCounter++;
}

void Roster::Remove(std::string studentID)
{
}

void Roster::PrintAll()
{
	// Grab a local copy of each student variable to format and print to the console
	for (int i{ 0 }; i <= 4; i++)
	{
		std::string studentID = ClassRosterArray[i]->GetStudentId();
		std::string firstName = ClassRosterArray[i]->GetStudentFirstName();
		std::string lastName = ClassRosterArray[i]->GetStudentLastName();
		std::string emailAddress = ClassRosterArray[i]->GetStudentEmailAddress();
		int age = ClassRosterArray[i]->GetStudentAge();
		int* daysInCourseOne = ClassRosterArray[i]->GetDaysToCompleteCourses();
		Degree::DegreeProgram degreeProgram = ClassRosterArray[i]->GetStudentDegreeProgram();

		std::cout << studentID << "    ";
		std::cout << "First Name: " << firstName << "    ";
		std::cout << "Last Name: " << lastName << "    ";
		std::cout << "Age: " << age << "    ";
		std::cout << "daysInCourse: {";
		std::string separator{ "," };
		std::string whiteSpace{ " " };
		for (int j{ 0 }; j <= 2; j++)
		{
			if (daysInCourseOne[j] == daysInCourseOne[2])
			{
				separator = "";
				whiteSpace = "";
			}
			std::cout << daysInCourseOne[j] << separator << whiteSpace;
		}
		std::cout << "}    ";
		std::cout << "Degree Program: " << Degree::DegreeProgramToString(degreeProgram) << "    " << std::endl;
	}
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
