#include"Officer.h"

string officer::soldierType() const {
	return "officer";
}

bool const officer::medal() const {
	return (this->operations > 2 && this->sociometric > 92 ? true : false);
}

void officer::input() {
	Soldier::input();
	cout << "enter the sociometric score\n";
	cin >> this->sociometric;
}
void const officer::print() {
	Soldier::print();
	cout << "sociometric score:	" << this->sociometric << endl;
}

void officer::setSocioMetric(int weeklyResearch) {
	this->sociometric = weeklyResearch;
}
int officer::getSocioMetric() {
	return sociometric;
}

bool officer::operator < (const Soldier& rhs) const {
	if (soldierType() != rhs.soldierType())
		throw "cannot compare students of different types";
	if (this->medal() && !rhs.medal())
		return false;
	if (!this->medal() && rhs.medal())
		return true;
	if (this->medal() && rhs.medal() || !(this->medal() && rhs.medal())) {
		if (this->sociometric < ((officer*)& rhs)->sociometric)
			return true;
	}
	return false;
}