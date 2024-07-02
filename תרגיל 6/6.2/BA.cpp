#include"BA.h"

float BA::Average(int* grades, int courses) {
	float avarege = 0;
	for (int i = 0; i < courses; i++) {
		avarege += grades[i];
	}
	avarege = avarege / courses;
	return avarege;
}

bool BA::milga() {
	return (this->courses >= 10 && Average(this->grades, this->courses) > 95 ? true : false);
}

void BA::input() {
	Student::input();
	cout << "and enter a list of student grades\n";
	grades = new int[courses];
	for (int i = 0; i < this->courses; i++)
		cin >> grades[i];
}

void BA::print() {
	Student::print();
	cout << "Grades: ";
	for (int i = 0; i < this->courses; i++) {
		cout << this->grades[i] << " ";
	}
	cout << endl;
}

void BA::setGrades(int* grades) {
	this->grades = grades;
}
int* BA::getGrades() const{
	return this->grades;
}