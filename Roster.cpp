#include <iostream>
#include <sstream>
#include "Roster.h"
#include "Student.h"
#include "Degree.h"

Roster::Roster()
	:_studentCounter{0}, 
	 _studentData{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	  "A5,Chris,Britton,test@test.com,27,11,9,11,SOFTWARE" }
{
	// initialize class roster pointers to null so we don't get garbage values
	for (int i{ 0 }; i <= 4; i++)
	{
		_classRosterArray[i] = nullptr;
	}

	ParseStudentData(_studentData, 5);
}

Roster::~Roster()
{
	std::cout << "Roster destructor called - deleting _classRosterArray" << std::endl;
	
	// Delete each student from the roster individually
	for (int i{ 0 }; i < _studentCounter; i++)
	{
		if (_classRosterArray[i] != nullptr)
		{
			delete _classRosterArray[i];
			_classRosterArray[i] = nullptr;
		}
	}
}

void Roster::Add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourseOne, int daysInCourseTwo, int daysInCourseThree, Degree::DegreeProgram degreeProgram)
{
	if (_classRosterArray[_studentCounter] != nullptr)
	{
		std::cout << "Error: Roster is full. Cannot add more students." << std::endl;
		return;
	}

	// Create a new student object with default values
	Student* newStudent = new Student("", "", "", "", 0, 0, 0, 0, Degree::Security);

	// Use mutators to actually set values
	newStudent->SetStudentId(studentID);
	newStudent->SetStudentFirstName(firstName);
	newStudent->SetStudentLastName(lastName);
	newStudent->SetStudentEmailAddress(emailAddress);
	newStudent->SetStudentAge(age);
	newStudent->SetDaysToCompleteCourses(daysInCourseOne, daysInCourseTwo, daysInCourseThree);
	newStudent->SetStudentDegreeProgram(degreeProgram);

	_classRosterArray[_studentCounter] = newStudent;
	_studentCounter++;
}

void Roster::Remove(std::string studentID)
{
	for (int i{ 0 }; i <= 4; i++)
	{
		if (_classRosterArray[i] == nullptr)
		{
			std::cout << "Error: Student with student ID: " << studentID << " was not found." << std::endl;
			return;
		}

		// If the IDs match, remove the student and set the pointer to null so nothing attempts to access that value again
		if (_classRosterArray[i]->GetStudentId() == studentID)
		{
			delete _classRosterArray[i];
			_classRosterArray[i] = nullptr;
			_studentCounter--;
		}
	}
}

void Roster::PrintAll()
{
	for (int i{ 0 }; i < _studentCounter; i++)
	{
		if (_classRosterArray[i] != nullptr)
		{
			// Use a ref to the student object to avoid unnecessarily copying variables
			Student& student = *_classRosterArray[i];
		
			std::cout << student.GetStudentId() << "\t";
			std::cout << "First Name: " << student.GetStudentFirstName() << "\t";
			std::cout << "Last Name: " << student.GetStudentLastName() << "\t";
			std::cout << "Age: " << student.GetStudentAge() << "\t";

			// Creating the days in course text format ex: daysInCourse: {35, 40, 55}
			std::cout << "daysInCourse: {";
			std::string separator{ "," };
			std::string whiteSpace{ " " };
			for (int j{ 0 }; j <= 2; j++)
			{
				if (j == 2)
				{
					separator = "";
					whiteSpace = "";
				}
				std::cout << student.GetDaysToCompleteCourses()[j] << separator << whiteSpace;
			}
			std::cout << "}\t";
			std::cout << "Degree Program: " << Degree::DegreeProgramToString(student.GetStudentDegreeProgram()) << "\t" << std::endl;
		}
	}
}

void Roster::PrintAverageDaysInCourse(std::string studentID)
{
	for (int i{ 0 }; i < _studentCounter; i++)
	{
		if (_classRosterArray[i] != nullptr)
		{
			if (_classRosterArray[i]->GetStudentId() == studentID)
			{
				int* daysToCompleteCourses = _classRosterArray[i]->GetDaysToCompleteCourses();
				int averageDaysInCourse = (daysToCompleteCourses[0] + daysToCompleteCourses[1] + daysToCompleteCourses[2]) / 3;

				std::cout << "Student ID " << studentID << " average number of days in 3 courses is: " << averageDaysInCourse << std::endl;
			}
		}
	}
}

void Roster::PrintInvalidEmails()
{
	for (int i{ 0 }; i < _studentCounter; i++)
	{
		if (_classRosterArray[i] != nullptr)
		{
			std::string emailAddress = _classRosterArray[i]->GetStudentEmailAddress();
			bool emailIsValid = RunEmailValidation(emailAddress);

			if (!emailIsValid)
			{
				std::cout << "Invalid Email Address: " << emailAddress << std::endl;
			}
		}
	}
}

void Roster::PrintByDegreeProgram(Degree::DegreeProgram degreeProgram)
{
	for (int i{ 0 }; i < _studentCounter; i++)
	{
		if (_classRosterArray[i] != nullptr)
		{
			if (_classRosterArray[i]->GetStudentDegreeProgram() == degreeProgram)
			{
				_classRosterArray[i]->PrintStudentDetails();
				std::cout << std::endl;
			}
		}
	}
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

bool Roster::RunEmailValidation(const std::string& studentEmailAddress)
{
	size_t atSymbol = studentEmailAddress.find('@');

	// Check to ensure @ exists, and that it isn't the first or last character
	if (atSymbol == studentEmailAddress[0] || atSymbol == studentEmailAddress.size() - 1 || atSymbol == std::string::npos)
	{
		return false;
	}

	size_t dotSymbol = studentEmailAddress.find('.');

	// Chehck to ensure the . exists, and that it isn't the first or last character in the email
	if (dotSymbol == studentEmailAddress[0] || dotSymbol == studentEmailAddress.size() - 1 || atSymbol == std::string::npos)
	{
		return false;
	}

	size_t space = studentEmailAddress.find(" ");
	// Check to ensure there is no space in the email
	if (space != std::string::npos)
	{
		return false;
	}
}

Student* Roster::GetIndividualStudent(int index)
{
	if (_classRosterArray[index] != nullptr)
	{
		return _classRosterArray[index];
	}
}
