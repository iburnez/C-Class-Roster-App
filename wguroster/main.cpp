#include <iostream> 
#include <string>

using namespace std;

#include "roster.h"
#include "student.h"
#include "degree.h"

int main() {
    int numStudents = 5;
    string studentData[5] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,James,Green,jgre466@wgu.edu,32,30,50,33,SOFTWARE",
    };
    //Print out to the screen, via your application, the course title, the programming language used, 
    //your WGU student ID, and your name.
    cout << "Scripting and Programming - Applications - C867" << endl; 
    cout << "Programming language: C++" << endl;
    cout << "Student ID: #001122573" << endl;
    cout << "Student Name: James Green" << endl << endl;

    //Create new Roster Object
    Roster * classRoster = new Roster(numStudents);
    
    //Parse Data
    cout << "Parsing Data...    ";
    for (int i = 0; i < numStudents; i++) {
        classRoster->parseThenAdd(studentData[i]);
    }
    cout << "done." << endl << endl;

    //Print Full Roster
    cout << "Printing Roster" << endl;
    classRoster->printAll();
    cout << "Done printing." << endl << endl;

    //Print Invalid Email Addressess
    cout << "Printing Invalid Emails" << endl;
    classRoster->printInvalidEmails();
    cout << "Done printing emails" << endl;
    cout << endl;
    
    //Print average days to complete course for each student based on studentID
    for (int i = 0; i < numStudents; i++) {
        classRoster->printAverageDaysInCourse(classRoster->GetClassRosterArraySID(i));
    }
    cout << endl;

    //Print Roster based on degree type
    cout << "Printing roster for SOFTWARE Degree: " << endl;
    classRoster->printByDegreeProgram(SOFTWARE);
    cout << "Done printing." << endl << endl;

    //Remove student based on studentID
    cout << "Removing student from roster..." << endl;
    classRoster->remove("A3");
    cout << "Done." << endl << endl;

    //Print Full Roster
    cout << "Printing Roster" << endl;
    classRoster->printAll();
    cout << "Done." << endl << endl;

    //Remove student based on studentID
    cout << "Removing student from roster..." << endl;
    classRoster->remove("A3");
    cout << "Done." << endl;
	return 0;
}