#include <iostream>
#include "networkStudent.h"
using std::cout;

NetworkStudent::NetworkStudent():Student(){
	
	degreetype = NETWORK;
}

NetworkStudent::NetworkStudent(string ID, string firstName, string lastName, string email, int age, int days[], Degree degreetype)
:Student(ID, firstName, lastName, email, age, days){
	
	degreetype = NETWORK;
}

Degree NetworkStudent::getDegreeProgram() {
	
	return NETWORK;
}

//OVERRIDES STUDENT PRINT FUNCTION AND ADDS DEGREE TYPE TO END OF STUDENT POPULATED FIELDS
void NetworkStudent::print(){
	
	cout << getID() << "\t";
	cout << getFName() << "\t";
	cout << getLName() << "\t";
	cout << getEmail() << "\t";
	cout << getAge() << "\t";
	int* days = getDays();
	cout << days[0] << ", " << days[1] << ", " << days[2] << "\t";
	cout << "NETWORK" << "\n";
}

NetworkStudent::~NetworkStudent(){
	
	Student::~Student();
}
