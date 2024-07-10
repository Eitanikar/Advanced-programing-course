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
	//Student& operator=(const Student&);
	//Student& operator=(Student&&);

	virtual void input() = 0;
	virtual void const print()  = 0;
	virtual bool const milga() const = 0;


	void setFirstName(string);
	void setLastName(string);
	void setId(int);
	void setCourses(int);

	string getFirstName();
	string getLastName();
	int getId();
	int getCourses() const;

	virtual bool operator < (const Student& rhs) const = 0;

	virtual string studType() const = 0;
};