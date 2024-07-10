#include"BA.h"
#include"Student.h"

BA::BA() : Student::Student(){
	this->grades = new int[courses];
}

BA::BA(const BA& ba) {//copy constructor
	id = ba.id;
	firstName = ba.firstName;
	lastName = ba.lastName;
	courses = ba.courses;
	grades = new int[courses];
	for (int i = 0; i < courses; i++) {
		grades[i] = ba.grades[i];
	}
}

BA::BA(BA&& ba) {//move constructor
	id = ba.id;
	firstName = ba.firstName;
	lastName = ba.lastName;
	courses = ba.courses;
	grades = ba.grades;
	ba.grades = nullptr;
}

BA::~BA() {
	delete[] grades;
}

BA& BA::operator=(BA&& ba)
{
	id = ba.id;
	firstName = ba.firstName;
	lastName = ba.lastName;
	courses = ba.courses;
	if (grades)
	{
		delete[] grades;
	}
	courses = ba.courses;
	grades = ba.grades;
	ba.grades = nullptr;
	return *this;
}

BA& BA::operator=(const BA& ba) {
	id = ba.id;
	firstName = ba.firstName;
	lastName = ba.lastName;
	courses = ba.courses;
	if (grades)
	{
		delete[] grades;
	}
	courses = ba.courses;
	grades = new int[courses];
	for (int i = 0; i < courses; i++) {
		grades[i] = ba.grades[i];
	}
	return *this;
}

string BA::studType() const {
	return "BA";
}

float const BA::average() const {
	float ave = 0;
	for (int i = 0; i < courses; i++) {
		ave += grades[i];
	}
	if(courses != 0)
		ave = ave / courses;
	else
		ave = 0;
	return ave;
}

void BA::input() {
	Student::input();
	cout << "and enter a list of student grades" << endl;
	grades = new int[courses];
	for (int i = 0; i < this->courses; i++)
		cin >> grades[i];
}

void const BA::print() {
	Student::print();
	cout << "Grades:	";
	for (int i = 0; i < this->courses; i++) {
		cout << this->grades[i] << " ";
	}
	cout << endl;
	cout << "average:	" << this->average() << endl;
	
}

bool const BA::milga() const {
	return (this->courses >= 10 && average() > 95 ? true : false);
}

void BA::setGrades(int* grades) {
	this->grades = grades;
}
int* BA::getGrades() const{
	return this->grades;
}

bool BA::operator < (const Student& rhs) const {
	if (studType() != rhs.studType())
		throw "cannot compare students of different types";
	if (this->milga() && !rhs.milga())
		return false;
	if (!this->milga() && rhs.milga())
		return true;
	if (this->milga() && rhs.milga() || !(this->milga() && rhs.milga())) {
		if(average() < ((BA*)&rhs)->average())
			return true;
	}
	return false;
}