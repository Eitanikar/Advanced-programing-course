#include"PrivateSoldier.h"
#include"Soldier.h"

string PrivateSoldier::soldierType() const {
	return "private";
}

PrivateSoldier::PrivateSoldier() : Soldier::Soldier(){
	this->grades = new int[operations];
}

PrivateSoldier::PrivateSoldier(const PrivateSoldier& ba) {//copy constructor
	id = ba.id;
	firstName = ba.firstName;
	lastName = ba.lastName;
	operations = ba.operations;
	grades = new int[operations];
	for (int i = 0; i < operations; i++) {
		grades[i] = ba.grades[i];
	}
}

PrivateSoldier::PrivateSoldier(PrivateSoldier&& ba) {//move constructor
	id = ba.id;
	firstName = ba.firstName;
	lastName = ba.lastName;
	operations = ba.operations;
	grades = ba.grades;
	ba.grades = nullptr;
}

PrivateSoldier::~PrivateSoldier() {
	delete[] grades;
}

PrivateSoldier& PrivateSoldier::operator=(PrivateSoldier&& ps)
{
	id = ps.id;
	firstName = ps.firstName;
	lastName = ps.lastName;
	operations = ps.operations;
	if (grades)
	{
		delete[] grades;
	}
	grades = ps.grades;
	ps.grades = nullptr;
	return *this;
}

PrivateSoldier& PrivateSoldier::operator=(const PrivateSoldier& ps) {
	id = ps.id;
	firstName = ps.firstName;
	lastName = ps.lastName;
	operations = ps.operations;
	if (grades)
	{
		delete[] grades;
	}
	grades = new int[operations];
	for (int i = 0; i < operations; i++) {
		grades[i] = ps.grades[i];
	}
	return *this;
}

float const PrivateSoldier::average() const {
	float ave = 0;
	for (int i = 0; i < operations; i++) {
		ave += grades[i];
	}
	if(operations != 0)
		ave = ave / operations;
	else
		ave = 0;
	return ave;
}

void PrivateSoldier::input() {
	Soldier::input();
	if (operations != 0) {
		cout << "enter " << operations << " grades\n";
		if (operations != 0) {
			grades = new int[operations];
			for (int i = 0; i < this->operations; i++)
				cin >> grades[i];
		}
	}
}

void const PrivateSoldier::print() {
	Soldier::print();
	if(this->operations != 0){
		cout << "grades:	";
		for (int i = 0; i < this->operations; i++) {
			cout << this->grades[i] << " ";
		}
	}
	cout << endl;
}

bool const PrivateSoldier::medal() const {
	return (this->operations >= 10 && average() > 95 ? true : false);
}

void PrivateSoldier::setGrades(int* grades) {
	this->grades = grades;
}
int* PrivateSoldier::getGrades() const{
	return this->grades;
}

bool PrivateSoldier::operator < (const Soldier& rhs) const {
	if (soldierType() != rhs.soldierType())
		throw "cannot compare students of different types";
	if (this->medal() && !rhs.medal())
		return false;
	if (!this->medal() && rhs.medal())
		return true;
	if (this->medal() && rhs.medal() || !(this->medal() && rhs.medal())) {
		if(average() < ((PrivateSoldier*)&rhs)->average())
			return true;
	}
	return false;
}