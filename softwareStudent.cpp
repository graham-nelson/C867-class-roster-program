#include <iostream>
#include "softwareStudent.h"
using std::cout;

SoftwareStudent::SoftwareStudent():Student(){
	
	degreetype = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string ID, string firstName, string lastName, string email, int age, int days[], Degree degreetype)
	:Student(ID, firstName, lastName, email, age, days){
	
	degreetype = SOFTWARE;
}

Degree SoftwareStudent::getDegreeProgram() {
	
	return SOFTWARE;
}

//OVERRIDES STUDENT PRINT FUNCTION AND ADDS DEGREE TYPE TO END OF STUDENT POPULATED FIELDS
void SoftwareStudent::print(){
	
	cout << getID() << "\t";
	cout << getFName() << "\t";
	cout << getLName() << "\t";
	cout << getEmail() << "\t";
	cout << getAge() << "\t";
	int* days = getDays();
	cout << days[0] << ", " << days[1] << ", " << days[2] << "\t";
	cout << "SOFTWARE" << "\n";
}

SoftwareStudent::~SoftwareStudent(){
	
	Student::~Student();
}

