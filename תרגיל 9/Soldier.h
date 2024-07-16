#pragma once
#include<cstring>
#include<iostream>
using namespace std;

class Soldier {
public:
	string firstName,
			lastName;
	int id, operations;


	Soldier();
	Soldier(string , string, int, int);
	Soldier(const Soldier&);
	virtual ~Soldier();
	//Student& operator=(const Student&);
	//Student& operator=(Student&&);

	virtual void input() = 0;
	virtual void const print() = 0;
	virtual bool const medal() const = 0;


	void setFirstName(string);
	void setLastName(string);
	void setId(int);
	void setCourses(int);

	string getFirstName();
	string getLastName();
	int getId();
	int getOperations() const;

	virtual bool operator < (const Soldier& rhs) const = 0;

	virtual string soldierType() const = 0;
};