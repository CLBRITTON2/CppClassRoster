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
