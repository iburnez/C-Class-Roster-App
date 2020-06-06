#pragma once
#ifndef ROSTER_H
#define ROSTER_H

using namespace std; 

#include "student.h"
#include "degree.h"

class Roster {

public:
	
	Roster(); //Default constructor
	Roster(int capacity); //Roster Constructor
	string GetClassRosterArraySID(int i); //Get SID to feed the print average days in course function.
	void printByDegreeProgram(DegreeProgram degree); //Loops through classRosterArray based on degree type and prints all student objects with degree type
	void remove(string sID); //Remove student object absed on StudentID - remove and resize array 
	void parseThenAdd(string sData); //Parse each string of StudentData to create temp vairables to be added to student object.
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, double array1, double array2, double array3, DegreeProgram degreeProgram); //Add temp variables parsed from student data to student object
	void printAll(); //Loops through classArrayRoster and calls Student.PrintAll() function to print all student data
	void printInvalidEmails(); //Looks for all invalid email addresses containing " " (spaces) or lacking '@' or '.' symbols
	void printAverageDaysInCourse(string studentID); //Loops through classArrayRoster looking for student object based off studentID - Loops through student object to sum and average numDaysToComplete array

	~Roster(); // Destructor

private:
	int capacity; //Defines the size of the array
	int lastIndex; //Used in loops to mark the end of the array
	Student** classRosterArray; //Array of pointers 

};

#endif