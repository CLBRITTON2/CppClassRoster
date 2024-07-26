#include <iostream>
#include "Roster.h"
#include "Student.h"
#include "Degree.h"

Roster::Roster()
{
	// initialize class roster pointers to null so we don't get garbage values
	for (int i{ 0 }; i <= 4; i++)
	{
		_classRosterArray[i] = nullptr;
	}
}

void Roster::Add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourseOne, int daysInCourseTwo, int daysInCourseThree, Degree::DegreeProgram degreeProgram)
{
	_classRosterArray[_studentCounter] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourseOne, daysInCourseTwo, daysInCourseThree, degreeProgram);
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
		if (_classRosterArray[i] != nullptr)
		{
			std::string studentID = _classRosterArray[i]->GetStudentId();
			std::string firstName = _classRosterArray[i]->GetStudentFirstName();
			std::string lastName = _classRosterArray[i]->GetStudentLastName();
			std::string emailAddress = _classRosterArray[i]->GetStudentEmailAddress();
			int age = _classRosterArray[i]->GetStudentAge();
			int* daysInCourseOne = _classRosterArray[i]->GetDaysToCompleteCourses();
			Degree::DegreeProgram degreeProgram = _classRosterArray[i]->GetStudentDegreeProgram();

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
