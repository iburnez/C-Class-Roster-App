#pragma once
#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

#include <array>
#include <string>
#include "degree.h"

class Student {
public:
	static const int NUM_ELEMENTS = 3;

	Student(); // empty constuctor 
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, double numOfDaysToComplete[], DegreeProgram degreeProgram); // Student Constructor
	void print(); //Prints all variables in an object - called by Roster::printAll()

	//Getters
	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	int GetAge();
	double GetNumOfDaysToComplete(int element);
	DegreeProgram GetDegreeProgram();

	//Setters
	void SetStudentID(string inputStudentID);
	void SetFirstName(string inputFirstName);
	void SetLastName(string inputLastName);
	void SetEmailAddress(string inputEmailAddress);
	void SetAge(int inputAge);
	void SetNumOfDaysToComplete(double inputNumOfDaysToComplete[NUM_ELEMENTS]);
	void SetDegreeProgram(DegreeProgram inputDegreeProgram);

	~Student(); // Destructor


private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	double numOfDaysToComplete[NUM_ELEMENTS];
	DegreeProgram degreeProgram;


};


#endif