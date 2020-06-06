#include <iostream>
#include <string>
#include <ios>
#include <iomanip>

using namespace std;

#include "student.h"
#include "degree.h"

//Default Constuctor 
Student::Student() { 
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < NUM_ELEMENTS; i++) {
		this->numOfDaysToComplete[i] = 0;
	}


}
//Student Constucotr
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, double numOfDaysToComplete[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < NUM_ELEMENTS; i++) {
		this->numOfDaysToComplete[i] = numOfDaysToComplete[i];
	}
	this->degreeProgram = degreeProgram;
}

//Prints all variables in an object - called by Roster::printAll()
void Student::print() {
	cout << left << setw(5) << studentID;
	cout << left << setw(10) << firstName;
	cout << left << setw(10) << lastName;
	cout << left << setw(25) << emailAddress;
	cout << left << setw(5) << age;
	cout << left << setw(5) << numOfDaysToComplete[0];
	cout << left << setw(5) << numOfDaysToComplete[1];
	cout << left << setw(5) << numOfDaysToComplete[2];
	cout << left << setw(15) << degreeProgramStrings[degreeProgram] << endl;
}

//Getters
string Student::GetStudentID() {
	return studentID;
}
string Student::GetFirstName() {
	return firstName;
}
string Student::GetLastName() {
	return lastName;
}
string Student::GetEmailAddress() {
	return emailAddress;
}
int Student::GetAge() {
	return age;
}
double Student::GetNumOfDaysToComplete(int element) {
	return numOfDaysToComplete[element];
}
DegreeProgram Student::GetDegreeProgram() {
	return degreeProgram;
}

//Setters
void Student::SetStudentID(string inputStudentID) {
	this->studentID = inputStudentID;
}
void Student::SetFirstName(string inputFirstName) {
	this->firstName = inputFirstName;
}
void Student::SetLastName(string inputLastName) {
	this->lastName = inputLastName;
}
void Student::SetEmailAddress(string inputEmailAddress) {
	this->emailAddress = inputEmailAddress;
}
void Student::SetAge(int inputAge) {
	this->age = inputAge;
}
void Student::SetNumOfDaysToComplete(double inputNumOfDaysToComplete[NUM_ELEMENTS]) {
	for (int i = 0; i < NUM_ELEMENTS; i++) {
		this->numOfDaysToComplete[i] = inputNumOfDaysToComplete[i];
	}
	
}
void Student::SetDegreeProgram(DegreeProgram inputDegreeProgram) {
	this->degreeProgram = inputDegreeProgram;
}

Student::~Student() {

}