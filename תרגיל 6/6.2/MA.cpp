#include"MA.h"
#include"BA.h"

bool MA::milga() {
	return (this->courses >= 7 && Average(this->grades, this->courses) > 90 && research ? true : false);
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
void MA::print() {
	cout << "ID:" << "	" << this->id << endl;
	cout << "Name:" << "	" << this->firstName << " " << this->lastName << endl;
	cout << "Grades: ";
	for (int i = 0; i < this->courses; i++) {
		cout << this->grades[i] << " ";
	}
	cout << endl;
	cout << "research:" << "	";
	(research ? cout << "1\n" : cout << "0\n");
}

void MA::setResearch(bool research) {
	this->research = research;
}
bool MA::getResearch() {
	return research;
}