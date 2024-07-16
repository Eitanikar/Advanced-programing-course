#include "Soldier.h"

#include <algorithm>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <stack>

Soldier::Soldier() {
	this->firstName = "";
	this->lastName = "";
	this->id = 0;
	this->operations = 80;
}

Soldier::Soldier(string firstName, string lastName, int id, int courses) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->id = id;
	this->operations = courses;
}
Soldier::Soldier(const Soldier& Student) {
	this->firstName = Student.firstName;
	this->lastName = Student.lastName;
	this->id = Student.id;
	this->operations = Student.operations;
}

Soldier::~Soldier() {}

void Soldier::input() {
	cout << "enter id, first name, last name and number of operations" << endl;
	cin >> this->id;
	cin >> this->firstName;
	cin >> this->lastName;
	cin >> this->operations;
}

void const Soldier::print() {
	cout << soldierType() << endl;
	cout << "ID:	" << this->id << endl;
	cout << "first name:	" << this->firstName << endl;
	cout<< "last name:	" << this->lastName << endl;
	cout << "num operations:	" << this->operations << endl;
}

void Soldier::setFirstName(string) {
this->firstName = firstName;
}
void Soldier::setLastName(string) {
this->lastName = lastName;
}
void Soldier::setId(int) {
this->id = id;
}
void Soldier::setCourses(int) {
this->operations = operations;
}

string Soldier::getFirstName() {
	return this->firstName;
}
string Soldier::getLastName() {
	return this->lastName;
}
int Soldier::getId() {
	return this->id;
}
int Soldier::getOperations() const {
	return this->operations;
}