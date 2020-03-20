#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

//ROSTER STORES A COLLECTION OF STUDENTS
class Roster {
private:
	int lastStudent; //INDEX OF LAST STUDENT IN REPOSITORY
	int capacity; //THE MAXIMUM SIZE OF THE ROSTER
	Student** classRosterArray; //ARRAY OF POINTERS TO STUDENTS
	
public:
	Roster(); //EMPTY CONSTRUCTOR CREATES ROSTER AND INITIALIZES ALL FIELD TO DEFAULT VALUES
	Roster(int capacity); //CONSTRUCTOR SETS MAX SIZE
	
	Student* getStudentAt(int index);
	void parseThenAdd(string row);
	void add(string ID, string firstName, string lastName, string email, int age, int d1, int d2, int d3, Degree degreetype);
	void print_All();
	void remove(string studentID);
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(Degree d);
	
	~Roster(); //DESTRUCTOR DESTROYS THE ROSTER, RELEASING ANY RESOURCES IT REQUESTED DYNAMICALLY
};
