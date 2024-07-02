#pragma once
#include<iostream>
using namespace std;

class Student {
protected:
	string firstName,
			lastName;
	int id, courses;

public:
	Student();

	void input();
	void print();

	void setFirstName(string);
	void setLastName(string);
	void setId(int);
	void setCourses(int);

	string getFirstName();
	string getLastName();
	int getId();
	int getCourses();
};