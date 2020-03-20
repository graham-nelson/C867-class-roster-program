#pragma once
#include <string>
#include "degree.h"
using std::string;

class Student {
	
public:
	
	const static int daysArraySize = 3;
	
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToComplete[daysArraySize];
	
public:
	
	//EMPTY CONSTRUCTOR
	Student();
	Student(string ID, string firstName, string lastName, string email, int age, int days[]);
	
	//GETTERS
	string getID();
	string getFName();
	string getLName();
	string getEmail();
	int getAge();
	int* getDays();
	virtual Degree getDegreeProgram() = 0; //VIRTUAL; CANNOT INSTANTIATE A STUDENT OBJECT

	//SETTERS
	void setID(string ID);
	void setFName(string fName);
	void setLName(string lName);
	void setEmail(string email);
	void setAge(int age);
	void setDays(int days[]);
	
	virtual void print() = 0; //VIRTUAL; WILL BE OVERRIDDEN IN STUDENT SUBCLASSES
	
	//DESTRUCTOR
	~Student();
};
