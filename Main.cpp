#include <iostream>
#include "Student.h"
#include "Roster.h"

int main()
{
    Roster classRoster;
    classRoster.PrintAll();
    classRoster.Remove("A1");
    classRoster.PrintAll();
}