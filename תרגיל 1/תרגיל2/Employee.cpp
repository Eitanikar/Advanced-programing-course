#include "Employee.h"	
#include<iostream>
#include<cstring>
using namespace std;
#pragma warning (disable:4996)

Employee::Employee() {
	/*this->id = 1;
	this->name[21];
	this->wage = 0;
	this->hours = 0;
	this->amount = 0;*/
	cout << "print: in constructor" << endl;
}

void Employee::setid(int x) {
	//if(x>0&&x<10000)
	this->id = x;
}

int Employee::getid() {
	return id;
}

//Employee::Employee(string name, int id, int wage, int worked, float amount) {
//	cout << " print: in parametric constructor" << endl;
//}

void Employee::setname(char x[]) {
	strcpy(name,x);
}

char* Employee::getname() {
	return name;
}

void Employee::setwage(int x) {
	this->wage = x;
}

int Employee::getwage() {
	return wage;
}

void Employee::sethours(int x) {
	this->hours = x;
}

int Employee::gethours() {
	return hours;
}

void Employee::setamount(int x) {
	this->amount = x;
}

float Employee::getamount() {
	return amount;
}

//float Employee::salary() {
//	float salary = 0.0;
//	int temp = (getwage() * gethours());
//
//	if (getamount() <= 1000)
//		salary = (getamount() * 0.1 + temp);
//
//	if (getamount() > 1000 && getamount() <= 2000)
//		salary = (1000 * 0.1 + -1 * (getamount() - 2000) * 0.15 + temp);
//
//	if (getamount() > 2000 && getamount() <= 4000)
//		salary = (1000 * 0.1 + 1000 * 0.15 + -1 * (getamount() - 4000) * 0.2 + temp);
//
//	if (getamount() > 4000 && getamount() <= 5000)
//		salary = (1000 * 0.1 + 1000 * 0.15 + 2000 * 0.2 + -1 * (getamount() - 5000) * 0.3 + temp);
//
//	if (getamount() > 5000)
//		salary = (1000 * 0.1 + 1000 * 0.15 + 2000 * 0.2 + 1000 * 0.3 + -1*(getamount() - 6000) * 0.4 + temp);
//
//	return salary;
//}

/*if (getamount() <= 1000)
		salary = ((getamount() * 0.1) + (getwage() * gethours()));
	if (getamount() > 1000 && getamount() <= 2000)
		salary = ((1000 * 0.1 + -(getamount() - 2000) * 0.15) + (getwage() * gethours()));
	if (getamount() > 2000 && getamount() <= 4000)
		salary = ((1000 * 0.1 + 1000 * 0.15 + -(getamount() - 4000) * 0.2) + (getwage() * gethours()) );
	if (getamount() > 4000 && getamount() <= 5000)
		salary = ((1000 * 0.1 + 1000 * 0.15 + 2000 * 0.2 + -(getamount() - 5000) * 0.3 ) + (getwage() * gethours()) );
	if (getamount() > 5000)
		salary = ((1000 * 0.1 + 1000 * 0.15 + 2000 * 0.2 + 1000 * 0.3 + -(getamount() - 6000) * 0.4) + (getwage() * gethours()));*/

float Employee::salary() const {
	//float salary = (wage * hours);
	float calc = 0.0;

	if (1000 >= amount && amount >= 0) {
		calc = calc + amount * (float)0.1;
	}
	else {
		calc = calc + 1000 * (float)0.1;
		if (2000 >= amount && amount > 1000)
			calc = calc + (amount - 1000) * (float)0.15;
		else {
			calc = calc + 1000 * (float)0.15;
			if (4000 >= amount && amount > 2000)
				calc = calc + (amount - 2000) * (float)0.2;
			else {
				calc = calc + 2000 * (float)0.2;
				if (5000 >= amount && amount > 4000)
					calc = calc + (amount - 4000) * (float)0.3;
				else 
					calc = calc + 1000 * 0.3 + (amount - 5000) * (float)0.4;
			}
		}
	}
	return (wage * hours) + calc;
}
