#include "Degree.h"
#include <string>

std::string Degree::DegreeProgramToString(DegreeProgram degreeProgram)
{
    switch (degreeProgram)
    {
    case Security:
        return "Security";

    case Network:
        return "Network";

    case Software:
        return "Software";

    default:
        return "Unknown";
    }
}

Degree::DegreeProgram Degree::StringToDegreeProgram(std::string degreeProgramString)
{
    if (degreeProgramString == "SECURITY")
    {
        return Security;
    }
    else if (degreeProgramString == "NETWORK")
    {
        return Network;
    }
    else if (degreeProgramString == "SOFTWARE")
    {
        return Software;
    }
}
