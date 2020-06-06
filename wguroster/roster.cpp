#include <iostream>
#include <ios>
#include <iomanip>
#include <string> 
#include <array>

using namespace std;

#include "roster.h"
#include "student.h"
#include "degree.h"

//Default constructor
Roster::Roster() {
	this->capacity = 0;
	this->lastIndex = -1;
	Student** classRosterArray = nullptr;

}

//Roster Constructor
Roster::Roster(int capacity) {
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student*[capacity];
}

//Get SID to feed the print average days in course function.
string Roster::GetClassRosterArraySID(int i){
	return classRosterArray[i]->GetStudentID();
}

//Loops through classRosterArray based on degree type and prints all student objects with degree type
void Roster::printByDegreeProgram(DegreeProgram degree){
	for (int i = 0; i <= lastIndex; i++) {
		if (classRosterArray[i]->GetDegreeProgram() == degree) {
			classRosterArray[i]->print();
		}
	}
	
	return;
}

//Remove student object absed on StudentID - remove and resize array 
void Roster::remove(string sID){
	bool found = false; 
	for (int i = 0; i <= lastIndex; i++) {
		// If the object to delete is <  last index. Delete the object and shift each item -1 
		//(I know in larger programs this would be memory intensive but wit such a small array i decided to get some extra practice in and design the function this way)
		if (classRosterArray[i]->GetStudentID() == sID) {
			if (i < lastIndex) {
				delete classRosterArray[i];
				for (int j = i; j < lastIndex; j++) {
					classRosterArray[j] = classRosterArray[j + 1];
				}
			}
			//if object to delete is the last object just delete
			else if (i == lastIndex) {
				delete classRosterArray[i];
			}
			lastIndex--;
			found = true;
		}
	}
	if (found == false) {
		cout << "Student ID NOT FOUND." << endl;
	}
}

//Parse each string of StudentData to create temp vairables to be added to student abject.
void Roster::parseThenAdd(string sData){
	if (lastIndex < capacity) {
		lastIndex++;
		//Parse Student ID
		int endPosition = sData.find(",", 0);
		string sID = sData.substr(0, endPosition);

		//Parse First Name
		int startPosition = endPosition + 1;
		endPosition = sData.find(",", startPosition);
		int searchRange = endPosition - startPosition;
		string fName = sData.substr(startPosition, searchRange);

		//Parse Last Name
		startPosition = endPosition + 1;
		endPosition = sData.find(",", startPosition);
		searchRange = endPosition - startPosition;
		string lName = sData.substr(startPosition, searchRange);

		//Parse Email Address
		startPosition = endPosition + 1;
		endPosition = sData.find(",", startPosition);
		searchRange = endPosition - startPosition;
		string eName = sData.substr(startPosition, searchRange);

		//Parse Age
		startPosition = endPosition + 1;
		endPosition = sData.find(",", startPosition);
		searchRange = endPosition - startPosition;
		int aName = stoi(sData.substr(startPosition, searchRange));

		//Parse Array Value 1
		startPosition = endPosition + 1;
		endPosition = sData.find(",", startPosition);
		searchRange = endPosition - startPosition;
		double array1 = stod(sData.substr(startPosition, searchRange));

		//Parse Array Value 2
		startPosition = endPosition + 1;
		endPosition = sData.find(",", startPosition);
		searchRange = endPosition - startPosition;
		double array2 = stod(sData.substr(startPosition, searchRange));

		//Parse Array Value 3
		startPosition = endPosition + 1;
		endPosition = sData.find(",", startPosition);
		searchRange = endPosition - startPosition;
		double array3 = stod(sData.substr(startPosition, searchRange));

		//Parse Degree Program 
		startPosition = endPosition + 1;
		endPosition = sData.find(",", startPosition);
		searchRange = endPosition - startPosition;
		string dName = sData.substr(startPosition, searchRange);

		//Determine eNum Degree Program
		DegreeProgram degreeProgram;
		if (dName == "SECURITY") {
			degreeProgram = SECURITY;
		}
		else if (dName == "NETWORK") {
			degreeProgram = NETWORK;
		}
		else if (dName == "SOFTWARE") {
			degreeProgram = SOFTWARE;
		}
		else {
			cout << "Invalid Degree Program." << endl;
			exit(-1);
		}

		add(sID, fName, lName, eName, aName, array1, array2, array3, degreeProgram);
	}
}

//Add temp variables parsed from student data to student object
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, double array1, double array2, double array3, DegreeProgram degreeProgram) {
	double tempArray[Student::NUM_ELEMENTS];
	tempArray[0] = array1;
	tempArray[1] = array2;
	tempArray[2] = array3;
	classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, tempArray, degreeProgram);
}

//Loops through classArrayRoster and calls Student.PrintAll() function to print all student data
void Roster::printAll() {
	for (int i = 0; i <= lastIndex; i++) {
		this->classRosterArray[i]->print();
	}
}

//Looks for all invalid email addresses containing " " (spaces) or lacking '@' or '.' symbols
void Roster::printInvalidEmails() {
	for (int i = 0; i <= lastIndex; i++) {
		string tempEmail = classRosterArray[i]->GetEmailAddress();
		if (tempEmail.find('@', 0) == string::npos) {
			cout << "Invalid Email address (no @): " << tempEmail << endl; 
		}
		else if (tempEmail.find('.', 0) == string::npos) {
			cout << "Invalid Email address (no'.'): " << tempEmail << endl;
		}
		else if (tempEmail.find(" ", 0) != string::npos) {
			cout << "Invalid Email address (contains space): " << tempEmail << endl;
		}
	}
}

//Loops through classArrayRoster looking for student object based off studentID
//Loops through student object to sum and average numDaysToComplete array
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i <= lastIndex; i++) {
		string tempID = classRosterArray[i]->GetStudentID();
		if (tempID == studentID) {
			double sumDays = 0;
			for (int j = 0; j < Student::NUM_ELEMENTS; j++) {
				sumDays = sumDays + classRosterArray[i]->GetNumOfDaysToComplete(j);
			}
			cout << "Average days to complete course for " << classRosterArray[i]->GetFirstName();
			cout << " " << classRosterArray[i]->GetFirstName() << ": " << setprecision(4) << (sumDays / Student::NUM_ELEMENTS) << endl;
		}
	}
}

//Destructor
Roster::~Roster() {
	for (int i = 0; i < Student::NUM_ELEMENTS; i++) {
		delete classRosterArray[i];
	}
	delete classRosterArray;
}
