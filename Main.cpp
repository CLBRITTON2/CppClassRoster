#include <iostream>
#include "Student.h"
#include "Roster.h"

int main()
{
    Roster classRoster;
    classRoster.PrintAll();
    std::cout << std::endl;

    classRoster.Remove("A1");
    classRoster.PrintAll();
    std::cout << std::endl;

    classRoster.Remove("A1");
    std::cout << std::endl;
    classRoster.PrintAll();

    classRoster.PrintAverageDaysInCourse("A5");
}