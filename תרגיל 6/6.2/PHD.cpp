#include"PHD.h"

bool PHD::milga() {
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
void PHD::print() {
	cout << "ID:" << "	" << this->id << endl;
	cout << "Name:" << "	" << this->firstName << " " << this->lastName << endl;
	cout << "number of research Hours:" << "	" << this->weeklyResearch << endl;
}

void PHD::setWeeklyResearch(int weeklyResearch) {
	this->weeklyResearch = weeklyResearch;
}
int PHD::getweeklyResearch() {
	return weeklyResearch;
}