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
	  "A5,[firstname],[lastname],[emailaddress],[age], [numberofdaystocomplete3courses],SOFTWARE" };

	ParseStudentData(studentData, 5);
}

void Roster::Add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourseOne, int daysInCourseTwo, int daysInCourseThree, Degree::DegreeProgram degreeProgram)
{
	if (_classRosterArray[_studentCounter] != nullptr) // assuming _classRosterArray has 5 elements
	{
		std::cout << "Error: Roster is full. Cannot add more students." << std::endl;
		return;
	}

	_classRosterArray[_studentCounter] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourseOne, daysInCourseTwo, daysInCourseThree, degreeProgram);

	std::cout << "Added student: " << firstName << " to _classRosterArray" << std::endl;

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
			std::stringstream ss(*data);
			std::string studentID, firstName, lastName, emailAddress, degreeProgramStr;
			int age, daysInCourseOne, daysInCourseTwo, daysInCourseThree;

			// Parse the string
			std::getline(ss, studentID, ',');
			std::getline(ss, firstName, ',');
			std::getline(ss, lastName, ',');
			std::getline(ss, emailAddress, ',');
			ss >> age;
			ss.ignore(); // Ignore the comma
			ss >> daysInCourseOne;
			ss.ignore(); // Ignore the comma
			ss >> daysInCourseTwo;
			ss.ignore(); // Ignore the comma
			ss >> daysInCourseThree;
			ss.ignore(); // Ignore the comma
			std::getline(ss, degreeProgramStr, ','); // Read the rest of the string

			// Convert the string to an actual enum
			Degree::DegreeProgram degreeProgram = Degree::StringToDegreeProgram(degreeProgramStr);

			Add(studentID, firstName, lastName, emailAddress, age, daysInCourseOne, daysInCourseTwo, daysInCourseThree, degreeProgram);
		}
	}
}
