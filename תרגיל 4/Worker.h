#pragma once
#include <iostream>
#include<string>
#include<fstream>
using namespace std;

class Worker {
private:
	long id;
	string name;
	float salary;

public:
	Worker(long id = 0, string name = "", float salary = 0.0);
	Worker& operator+=(float);
	bool operator<(const Worker&);

	friend bool operator==(long, const Worker&);
	friend bool operator==(string, const Worker&);
	friend istream& operator>>(istream&, Worker&);
	friend ostream& operator<<(ostream&, const Worker&);
};