#pragma once
#include<iostream>
using namespace std;

//EITAN IKAR / 213450661 /exc 3 q 2

class MyDate {
private:
	int day, mon, year;
public:
	MyDate();//constructor
	MyDate(int day, int mon, int year);//paranetric constructor
	MyDate(const MyDate& m); //copy constructor

	void setDate(int day, int mon, int year);
	void print();

	MyDate operator=(const MyDate d);
	MyDate operator++();
	MyDate operator++(int);
	bool operator>(const MyDate m);
	bool operator<(const MyDate m);
	bool operator==(const MyDate m);
};