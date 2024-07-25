#pragma once
#include <string>

class Degree
{
public:
	enum DegreeProgram {Security, Network, Software};

	// Mapping enums to string values
	static std::string DegreeProgramToString(DegreeProgram degreeProgram);
};