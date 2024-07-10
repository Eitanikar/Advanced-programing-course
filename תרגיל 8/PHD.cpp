#include"PHD.h"

string PHD::studType() const {
	return "PHD";
}

bool const PHD::milga() const {
	return (this->courses >= 2 && this->weeklyResearch > 25 ? true : false);
}

void PHD::input() {
	cout << "enter id, first name, last name, number of courses\n";
	cin >> this->id;
	cin >> this->firstName;
	cin >> this->lastName;
	cin >> this->courses;
	cout << "enter number of research hours:\n";
	cin >> this->weeklyResearch;
}
void const PHD::print() {
	Student::print();
	cout << "number of research Hours:" << "	" << this->weeklyResearch << endl;
}

void PHD::setWeeklyResearch(int weeklyResearch) {
	this->weeklyResearch = weeklyResearch;
}
int PHD::getweeklyResearch() {
	return weeklyResearch;
}

bool PHD::operator < (const Student& rhs) const {
	if (studType() != rhs.studType())
		throw "cannot compare students of different types";
	if (this->milga() && !rhs.milga())
		return false;
	if (!this->milga() && rhs.milga())
		return true;
	if (this->milga() && rhs.milga() || !(this->milga() && rhs.milga())) {
		if (this->weeklyResearch < ((PHD*)& rhs)->weeklyResearch)
			return true;
	}
	return false;
}

//float const PHD::avarage() const {
	/*float avarege = 0;
	for (int i = 0; i < courses; i++) {
		avarege += grades[i];
	}
	avarege = avarege / courses;
	return avarege;
}*/