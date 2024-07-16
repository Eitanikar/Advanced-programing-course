#include"Soldier.h"
#include"PrivateSoldier.h"
#include"Commander.h"

commander::commander() : PrivateSoldier::PrivateSoldier(){
	this->combat = false;
}

string commander::soldierType() const {
	return "commander";
}

bool const commander::medal() const {
	return (this->operations >= 7 && average() > 90 && combat ? true : false);
}
void commander::input() {
	PrivateSoldier::input();
	cout << "enter 1 if the soldier is combat and 0 if not\n";
	cin >> this->combat;
}
void const commander::print() {
	PrivateSoldier::print();
	cout << "combat:" << "	";
	(combat ? cout << "yes\n" : cout << "no\n");
}

void commander::setResearch(bool research) {
	this->combat = research;
}
bool commander::getCombat() {
	return combat;
}

//float const MA::avarage() const {
//	float avarege = 0;
//	for (int i = 0; i < courses; i++) {
//		avarege += grades[i];
//	}
//	avarege = avarege / courses;
//	return avarege;
//}