#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "roster.h"
using std::cout;
using std::cerr;

//THE EMPTY CONSTRUCTOR SETS TO DEFAULT VALUES
Roster::Roster() {
	
	this->capacity = 0;
	this->lastStudent = -1; //MEANS EMPTY SINCE 0 IS A VALID INDEX IN AN ARRAY
	this->classRosterArray = nullptr;
}
//CONSTRUCTOR SETS MAX CAPACITY FOR THE ROSTER
Roster::Roster(int capacity){
	
	this->capacity = capacity;
	this->lastStudent = -1; //MEANS EMPTY
	this->classRosterArray = new Student*[capacity];
}

Student* Roster::getStudentAt(int index){
	return classRosterArray[index];
}

void Roster::parseThenAdd(string row){
	
	if(lastStudent < capacity) {
		lastStudent++;
		
		//THE FOLLOWING CODE WILL PARSE THORUGH EACH STRING
		//GET THE ID AND ASSIGN IT TO A TEMPORARY HOLDING VARIABLE
		unsigned long long rhs = row.find(",");
		string sID = row.substr(0, rhs);
		
		//READ FISRT NAME
		unsigned long long lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string fName = row.substr(lhs, rhs - lhs);
		
		//READ LAST NAME
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string lName = row.substr(lhs, rhs - lhs);
		
		//READ EMAIL ADDRESS
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string email = row.substr(lhs, rhs - lhs);
		
		//READ AGE
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int age = std::stoi(row.substr(lhs, rhs - lhs));
		
		//READ DAYS REMAINING IN EACH COURSE
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int zd1 = std::stoi(row.substr(lhs, rhs - lhs));
		
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int zd2 = std::stoi(row.substr(lhs, rhs - lhs));
		
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int zd3 = std::stoi(row.substr(lhs, rhs - lhs));
		
		//READ DEGREE TYPE. NOTE: THIS ONLY READS DEGREE TYPE AS A STRING AND NOT AN ENUEMERATION TYPE.
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string zD = row.substr(lhs, rhs - lhs);
		
		//DETERMINES ENUEMERATION TYPE.
		Degree dtype;
		if(zD[2] == 'T') dtype = NETWORK;
		else if (zD[2] == 'C') dtype = SECURITY;
		else dtype = SOFTWARE;
		
		//NOW USING ALL OF THE TEMP VARIEABLES, PLACE THE VALUES INTO THIS FUNCTION
		add(sID, fName, lName, email, age, zd1, zd2, zd3, dtype);
	}
	else {
		
		cerr << "ERROR! LIST HAS EXCEEDED MAXIMUM CAPACITY!\n EXITING NOW!";
		exit(-1);
	}
}

void Roster::add(string ID, string firstName, string lastName, string email, int age, int d1, int d2, int d3, Degree degreetype){
	
	int days[Student::daysArraySize];
	days[0] = d1;
	days[1] = d2;
	days[2] = d3;
	if(degreetype == NETWORK) {
		
	classRosterArray[lastStudent] = new NetworkStudent(ID, firstName, lastName, email, age, days, degreetype);
	}
	else if(degreetype == SECURITY) {
		
		classRosterArray[lastStudent] = new SecurityStudent(ID, firstName, lastName, email, age, days, degreetype);
	}
	else {
		
		classRosterArray[lastStudent] = new SoftwareStudent(ID, firstName, lastName, email, age, days, degreetype);
	}
}

void Roster::print_All(){
	
	for(int i = 0; i <= this->lastStudent; i++) (this->classRosterArray)[i]->print();
}

void Roster::remove(string studentID){

	bool studentFound = false;
	cout << "Attempting to find and remove Student " << studentID << " from roster.\n";
	for(int i = 0; i <= lastStudent; i++){
		

		
		if(this->classRosterArray[i]->getID() == studentID) {
			
			studentFound = true;
			cout << "Student " << studentID << " found. Removing.\n";
			
			classRosterArray[i] = nullptr;
			
			//MOVE LAST STUDENT TO THIS POSITION SO THERE ARE NO GAPS LEFT IN THIS ARRAY
			this->classRosterArray[i]= this->classRosterArray[lastStudent];
			lastStudent--;
			
			cout << "Student " << studentID << " successfully removed.\n";
		}
	}
	if(studentFound != true){
		cout << "Student " << studentID << " was not found.\n";
	}
}

void Roster::printAverageDaysInCourse(string studentID){
	
	bool found = false;
	for (int i = 0; i <= lastStudent; i++){
		
		//STUDENT FOUND
		if(this->classRosterArray[i]->getID() == studentID){
		
		found = true;
		int* p = classRosterArray[i]->getDays();
		cout << "Average days remining in three courses for Student " << studentID << " is " << (p[0] + p[1] + p[2]) / 3 << "\n";
		}
	}
	if (!found) cout << "Student not found!\n";
}

void Roster::printInvalidEmails(){
	
	for (int i = 0; i <= lastStudent; i++){
		
		bool validEmail = true;
		if (classRosterArray[i]->getEmail().find(" ") != string::npos ||
			classRosterArray[i]->getEmail().find("@") == string::npos ||
			classRosterArray[i]->getEmail().find(".") == string::npos){
			
			validEmail = false;
			cout << classRosterArray[i]->getEmail() << "\n";
		}
	}
}

void Roster::printByDegreeProgram(Degree d) {
	
	cout << "Printing students in " << degreeType[d] << " degree program:\n";
	for(int i = 0; i <= lastStudent; i++){
		if(this->classRosterArray[i]->getDegreeProgram() == d) this->classRosterArray[i]->print();
	}
}

Roster::~Roster(){
	for(int i = 0; i <= lastStudent; i++){
		
		delete this->classRosterArray[i];
	}
	delete classRosterArray;
}


int main() {
	
	cout << "     - C867 - Scripting and Programming: Applications -\n";
	cout << "                       - C++ -          \n";
	cout << "                   - #000657218 -        \n";
	cout << "                 -  Graham Nelson  -     \n";
	cout << "\n";
	
	int numStudents = 5;
	
	const string studentData[5] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Graham,Nelson,gnels16@wgu.edu,26,20,30,40,SOFTWARE"
	};
	
	Roster* classRoster = new Roster(numStudents);
	cout << "Parsing data and adding students:\n";
	for(int i = 0; i < numStudents; i++) {
		
		classRoster->parseThenAdd(studentData[i]);
	}
	
	
	cout << "Displaying all Students:\n";
	classRoster->print_All();
	cout << "\n";
	
	cout << "Invalid Emails: \n";
	classRoster->printInvalidEmails();
	cout << "\n";
	
	for (int i = 0; i < numStudents; i++) {
		classRoster->printAverageDaysInCourse(classRoster->getStudentAt(i)->getID());
	}
	cout << "\n";
	
	classRoster->printByDegreeProgram(SOFTWARE);
	cout << "\n";
	
	classRoster->remove("A3");
	
	cout << "\n";
		
	classRoster->remove("A3");
	
	//ROSTER DESTRUCTOR IS CALLED EXPLICITLY!
	classRoster->~Roster();
	
	return 0;
};
