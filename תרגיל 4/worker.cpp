#include"Worker.h"
#include<iostream>
using namespace std;

Worker::Worker(long id, string name, float salary)
{
	this->id = id;
	this->name = name;
	this->salary = salary;
}
Worker& Worker::operator+=(float bonus) {
	this->salary = this->salary + bonus;
	return *this;
}

bool Worker::operator<(const Worker& w) {
	if (this->salary < w.salary)
		return true;
	return false;
}

bool operator==(long id, const Worker& w) {
	if (id == w.id)
		return true;
	return false;
}

bool operator==(string name, const Worker& w) {
	if (name == w.name)
		return true;
	return false;
}

istream& operator>>(istream& is, Worker& w) {
	is >> w.id;
	is >> w.name;
	is >> w.salary;
	return is;
}

ostream& operator<<(ostream& os, const Worker& w) {
	os << w.id << " " << w.name << " " << w.salary << endl;
	return os;
}

//bool operator>(const Worker& a, const Worker& b) {
//	if(a.salary > b.salary)
//		return true;
//	else
//		return false;
//}
//
//bool operator<(const Worker& a, const Worker& b) {
//	if (a.salary < b.salary)
//		return true;
//	else
//		return false;
//}