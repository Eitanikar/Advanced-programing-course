#pragma once
#include<iostream>
using namespace std;

class Employee {
private:
	int id;
	char name[21];
	int wage;
	int hours;
	float amount;
	//float salary;

public:
	Employee(); //default constructor
	Employee(string name, int id, int salary, int worked, float amount); // parametric constructor
	
	
	void setid(int x);
	int getid();
	void setname(char x[]); //setname(char* x);
	char* getname();
	void setwage(int x);
	int getwage();
	void sethours(int x);
	int gethours();
	void setamount(int x);
	float getamount();

	float salary()const; //calculate the salary)
};