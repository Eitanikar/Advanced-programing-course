#include"Student.h"
#include"MA.h"
#include"BA.h"

MA::MA() : BA::BA(){
	this->research = false;
}

string MA::studType() const {
	return "MA";
}

bool const MA::milga() const {
	return (this->courses >= 7 && average() > 90 && research ? true : false);
}
void MA::input() {
	cout << "enter id, first name, last name, number of courses\n";
	cin >> this->id;
	cin >> this->firstName;
	cin >> this->lastName;
	cin >> this->courses;
	cout << "and enter a list of student grades\n";
	for (int i = 0; i < this->courses; i++) {
		cin >> grades[i];
	}
	cout << "enter 1 if the student does research and 0 if not\n";
	cin >> this->research;
}
void const MA::print() {
	BA::print();
	cout << endl;
	cout << "research:" << "	";
	(research ? cout << "YES\n" : cout << "NO\n");
}

void MA::setResearch(bool research) {
	this->research = research;
}
bool MA::getResearch() {
	return research;
}

//float const MA::avarage() const {
//	float avarege = 0;
//	for (int i = 0; i < courses; i++) {
//		avarege += grades[i];
//	}
//	avarege = avarege / courses;
//	return avarege;
//}