#include <iostream>
#include "securityStudent.h"
using std::cout;

SecurityStudent::SecurityStudent():Student(){
	
	degreetype = SECURITY;
}

SecurityStudent::SecurityStudent(string ID, string firstName, string lastName, string email, int age, int days[], Degree degreetype)
:Student(ID, firstName, lastName, email, age, days){
	
	degreetype = SECURITY;
}

Degree SecurityStudent::getDegreeProgram() {
	
	return SECURITY;
}

//OVERRIDES STUDENT PRINT FUNCTION AND ADDS DEGREE TYPE TO END OF STUDENT POPULATED FIELDS
void SecurityStudent::print(){
	
	cout << getID() << "\t";
	cout << getFName() << "\t";
	cout << getLName() << "\t";
	cout << getEmail() << "\t";
	cout << getAge() << "\t";
	int* days = getDays();
	cout << days[0] << ", " << days[1] << ", " << days[2] << "\t";
	cout << "SECURITY" << "\n";
}

SecurityStudent::~SecurityStudent(){
	
	Student::~Student();
}

