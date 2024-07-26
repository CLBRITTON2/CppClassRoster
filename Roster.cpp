#include <iostream>
#include <sstream>
#include "Roster.h"
#include "Student.h"
#include "Degree.h"

Roster::Roster()
	:_studentCounter{0}
{
	// initialize class roster pointers to null so we don't get garbage values
	for (int i{ 0 }; i <= 4; i++)
	{
		_classRosterArray[i] = nullptr;
	}

	const std::string studentData[] = 
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	  "A5,Chris,Britton,Test@email.com,27,3, 6, 9,SOFTWARE" };

	ParseStudentData(studentData, 5);
}

void Roster::Add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourseOne, int daysInCourseTwo, int daysInCourseThree, Degree::DegreeProgram degreeProgram)
{
	if (_classRosterArray[_studentCounter] != nullptr)
	{
		std::cout << "Error: Roster is full. Cannot add more students." << std::endl;
		return;
	}

	_classRosterArray[_studentCounter] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourseOne, daysInCourseTwo, daysInCourseThree, degreeProgram);
	_studentCounter++;
}

void Roster::Remove(std::string studentID)
{
	for (int i{ 0 }; i <= 4; i++)
	{
		// If the IDs match, remove the student and set the pointer to null so nothing attempts to access that value again
		if (_classRosterArray[i] != nullptr && _classRosterArray[i]->GetStudentId() == studentID)
		{
			delete _classRosterArray[i];
			_classRosterArray[i] = nullptr;
		}
	}
}

void Roster::PrintAll()
{
	for (int i{ 0 }; i <= 4; i++)
	{
		if (_classRosterArray[i] != nullptr)
		{
			// Use a ref to the student object to avoid unnecessarily copying variables
			Student& student = *_classRosterArray[i];
		
			std::cout << student.GetStudentId() << "    ";
			std::cout << "First Name: " << student.GetStudentFirstName() << "    ";
			std::cout << "Last Name: " << student.GetStudentLastName() << "    ";
			std::cout << "Age: " << student.GetStudentAge() << "    ";

			// Creating the days in course text format ex: daysInCourse: {35, 40, 55}
			std::cout << "daysInCourse: {";
			std::string separator{ "," };
			std::string whiteSpace{ " " };
			for (int j{ 0 }; j <= 2; j++)
			{
				if (student.GetDaysToCompleteCourses()[j] == student.GetDaysToCompleteCourses()[2])
				{
					separator = "";
					whiteSpace = "";
				}
				std::cout << student.GetDaysToCompleteCourses()[j] << separator << whiteSpace;
			}
			std::cout << "}    ";
			std::cout << "Degree Program: " << Degree::DegreeProgramToString(student.GetStudentDegreeProgram()) << "    " << std::endl;
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

void Roster::ParseStudentData(const std::string studentData[], size_t size)
{
	for (const std::string* data = studentData; data < studentData + size; data++)
	{
		// Make sure we don't try to access invalid memory
		if (data == studentData + size - 1 && data->empty())
		{
			break;
		}

		if (data != nullptr)
		{
			std::stringstream stringStream(*data);
			std::string studentID, firstName, lastName, emailAddress, degreeProgramStr;
			int age, daysInCourseOne, daysInCourseTwo, daysInCourseThree;

			// Parse the string - ignore commas
			std::getline(stringStream, studentID, ',');
			std::getline(stringStream, firstName, ',');
			std::getline(stringStream, lastName, ',');
			std::getline(stringStream, emailAddress, ',');
			stringStream >> age;
			stringStream.ignore();
			stringStream >> daysInCourseOne;
			stringStream.ignore();
			stringStream >> daysInCourseTwo;
			stringStream.ignore();
			stringStream >> daysInCourseThree;
			stringStream.ignore(); 
			std::getline(stringStream, degreeProgramStr, ',');

			// Convert the string to an actual enum
			Degree::DegreeProgram degreeProgram = Degree::StringToDegreeProgram(degreeProgramStr);

			Add(studentID, firstName, lastName, emailAddress, age, daysInCourseOne, daysInCourseTwo, daysInCourseThree, degreeProgram);
		}
	}
}
