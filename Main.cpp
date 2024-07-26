#include <iostream>
#include "Student.h"
#include "Roster.h"

int main()
{
    Roster classRoster;
    //classRoster.Add("A1", "John", "Smith", "John1989@gm", 20, 30, 35, 40, Degree::Security);
    //classRoster.Add("A2", "Suzan", "Erickson", "Erickson_1990@gmailcom", 19, 50, 30, 40, Degree::Network);
    //classRoster.Add("A3", "Jack", "Napoli", "The_lawyer99yahoo.com", 19, 20, 40, 33, Degree::Software);
    //classRoster.Add("A4", "Erin", "Black", "Erin.black@comcast.net", 22, 50, 58, 40, Degree::Security);
    //classRoster.Add("A5", "Chris", "Britton", "test@email.com", 27, 3, 6, 9, Degree::Software);
    classRoster.PrintAll();
}