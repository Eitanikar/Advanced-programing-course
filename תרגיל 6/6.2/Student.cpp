#include"Student.h"

Student::Student() {
	this->firstName = "";
	this->lastName = "";
	this->id = 0;
	this->courses = 0;
}

void Student::input() {
	cout << "enter id, first name, last name, number of courses\n" << endl;
	cin >> this->id;
	cin >> this->firstName;
	cin >> this->lastName;
	cin >> this->courses;
}

void Student::print() {
	cout << "ID: " << this->id << endl;
	cout << "Name: " << this->firstName << " " << this->lastName << endl;
	//cout << "Courses: " << this->courses << endl;
}

void Student::setFirstName(string) {
this->firstName = firstName;
}
void Student::setLastName(string) {
this->lastName = lastName;
}
void Student::setId(int) {
this->id = id;
}
void Student::setCourses(int) {
this->courses = courses;
}

string Student::getFirstName() {
	return this->firstName;
}
string Student::getLastName() {
	return this->lastName;
}
int Student::getId() {
	return this->id;
}
int Student::getCourses() {
	return this->courses;
}