#include <iostream>
#include "Student.h"
#include "Roster.h"

int main()
{
    // Note: studentDataTable is defined in Roster.h and initialized in the Roster constructor
    // Students are added to the classRoster via the ParseStudentData method in Roster.cpp that's called within the Roster constructor

    Roster classRoster;

    classRoster.PrintAll();
    std::cout << std::endl;

    classRoster.PrintInvalidEmails();
    std::cout << std::endl;

    for (int i{ 0 }; i <= 4; i++)
    {
        std::string studentID;

        if (classRoster.GetIndividualStudent(i) != nullptr)
        {
            studentID = classRoster.GetIndividualStudent(i)->GetStudentId();
        }
        classRoster.PrintAverageDaysInCourse(studentID);
    }
    std::cout << std::endl;

    classRoster.PrintByDegreeProgram(Degree::Software);
    std::cout << std::endl;

    classRoster.Remove("A3");
    classRoster.PrintAll();
    std::cout << std::endl;

    classRoster.Remove("A3");
    std::cout << std::endl;
}