#include <iostream>
#include <iomanip>
#include "student.h"
using std::cout;
using std::left;
using std::setw;

//EMPTY CONSTRUCTOR WILL SET ALL TO DEFAULT VALUES
Student::Student(){
	
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for(int i=0; i<daysArraySize; i++)
		this->daysToComplete[i] = 0;
}

//DEFINED CONSTRUCTOR
Student::Student(string ID, string firstName, string lastName, string email, int age, int days[]){

	this->studentID = ID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = email;
	this->age = age;
	for(int i = 0; i<daysArraySize; i++)
		this->daysToComplete[i] = days[i];
}

//GETTERS
string Student::getID(){
	return studentID;
}

string Student::getFName(){
	return firstName;
}

string Student::getLName(){
	return lastName;
}

string Student::getEmail(){
	return emailAddress;
}

int Student::getAge(){
	return age;
}

int* Student::getDays(){
	return daysToComplete;
}

//SETTERS
void Student::setID(string ID){
	this->studentID = ID;
}

void Student::setFName(string fName){
	this->firstName = fName;
}

void Student::setLName(string lName){
	this->lastName = lName;
}

void Student::setEmail(string email){
	this->emailAddress = email;
}

void Student::setAge(int age){
	this->age = age;
}

void Student::setDays(int days[]){
	
	for (int i = 0; i < daysArraySize; i++) {
		this->daysToComplete[i] = days[i];
	}
}


Student::~Student(){
	//STUDENT OBJECT DOES NOT DECLAIR ANYTHING DYNAMICALLY; SO THIS DESTRUCTOR DOES NOTHING
}
