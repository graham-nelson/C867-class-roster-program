#pragma once
#include <string>
#include "student.h"

//INHERITS FROM STUDENT CLASS
class SoftwareStudent : public Student {
	
private:
	
	Degree degreetype;
	
public:
	
	//CONSTRUCTORS WILL CALL SUPERCONSTRUCTOR FROM STUDENT CLASS
	SoftwareStudent();
	SoftwareStudent(string ID, string firstName, string lastName, string email, int age, int days[], Degree degreetype);
	
	//THE FOLLOWING VIRTUAL METHODS FROM STUDENT CLASS ARE OVERRIDDEN IN THIS CLASS
	Degree getDegreeProgram();
	void print();
	
	~SoftwareStudent();
};
