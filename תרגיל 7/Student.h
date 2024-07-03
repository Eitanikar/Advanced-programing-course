#pragma once
#include<cstring>
#include<iostream>
using namespace std;

class Student {
public:
	string firstName,
			lastName;
	int id, courses;


	Student();

	Student(string , string, int, int);
	Student(const Student&);
	virtual ~Student();

	virtual void input() = 0;
	virtual void const print()  = 0;
	virtual bool const milga() = 0;

	Student* addStudent();

	void setFirstName(string);
	void setLastName(string);
	void setId(int);
	void setCourses(int);

	string getFirstName();
	string getLastName();
	int getId();
	int getCourses();

protected:
	virtual string studType() const = 0;
};