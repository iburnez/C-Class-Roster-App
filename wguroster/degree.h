#pragma once
#ifndef DEGREE_H
#define DEGREE_H

#include <string>

using namespace std;
//Enum values begin at 0
enum DegreeProgram {SECURITY,NETWORK,SOFTWARE};

//Use enum value (0,1,2) to return string value associated with enum value
static const std::string degreeProgramStrings[] = {"SECURITY","NETWORK","SOFTWARE"};


#endif