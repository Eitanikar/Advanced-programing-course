#include "MyDate.h"
#include<iostream>
using namespace std; 

MyDate::MyDate() {//constructor
	this->day = 1;
	this->mon = 1;
	this->year = 1920;
};

MyDate::MyDate(int day, int mon, int year) { //parametric constructor
	
	if ( day < 1 || day >31 || mon < 1 || mon>12 || year < 1920 || year>9999 ||
		(day > 30 && mon < 8 && mon % 2 == 0) ||
		(day > 30 && mon > 7 && mon % 2 == 1) ||
		(day > 29 && mon == 2) ||
		(year % 4 != 0 && year % 100 == 0 && year % 400 != 0 && day > 28 && mon == 2))
	{
		cout << "Error date" << endl;
		this->day = 1;
		this->mon = 1;
		this->year = 1920;
	}
	else {
		this->day = day;
		this->mon = mon;
		this->year = year;
	}
};

MyDate::MyDate(const MyDate& m) {//copy constructor
	this->day = m.day;
	this->mon = m.mon;
	this->year = m.year;
};

void MyDate::setDate(int day, int mon, int year) { // set method
	if (day < 1 || day >31 || mon < 1 || mon>12 || year < 1920 || year>9999 ||
		(day > 30 && mon < 8 && mon % 2 == 0) ||
		(day > 30 && mon > 7 && mon % 2 == 1) ||
		(day > 29 && mon == 2) ||
		(year % 4 != 0 && year % 100 == 0 && year % 400 != 0 && day > 28 && mon == 2))
	{
		cout << "Error date" << endl;
		return;
	}
	else{
		this->day = day;
		this->mon = mon;
		this->year = year;
	}	
}

void MyDate::print() { // print method
	cout << this->day << '/' << this->mon << '/' << this->year; // << endl;
	return;
}

MyDate MyDate::operator=(const MyDate d) { // = operator
	this->day = d.day;
	this->mon = d.mon;
	this->year = d.year;
	return *this;
}

MyDate MyDate::operator++() { //pre operator ++

	this->day++;
	if (this->day > 31) {
		this->day = 1;
		this->mon++;
	}
	else if (this->day > 30 && this->mon == 4 || this->day > 30 && this->mon == 6 || this->day > 30 && this->mon == 9 || this->day > 30 && this->mon == 11) {
		this->day = 1;
		this->mon++;
	}
	else if (this->day > 28 && this->mon == 2 || (this->year % 4 == 0 && this->year % 100 != 0 || this->year % 400 == 0) && this->day > 29 && this->mon == 2) {
		this->day = 1;
		this->mon++;
	}
	if (this->mon >= 12) {
		this->mon = 1;
		this->year++;
	}
	return *this;
}

MyDate MyDate::operator++(int) { //post operator ++
	MyDate temp = *this;
	this->day++;
	if (this->day > 31) {
		this->day = 1;
		this->mon++;
	}
	else if (this->day > 30 && this->mon == 4 || this->day > 30 && this->mon == 6 || this->day > 30 && this->mon == 9 || this->day > 30 && this->mon == 11) {
		this->day = 1;
		this->mon++;
	}
	else if (this->day > 28 && this->mon == 2 || (this->year % 4 == 0 && this->year % 100 != 0 || this->year % 400 == 0) && this->day > 29 && this->mon == 2) {
		this->day = 1;
		this->mon++;
	}
	if (this->mon > 12) {
		this->mon = 1;
		this->year++;
	}
	return temp;
}

bool MyDate::operator>(const MyDate m) {// > operator
	if ((this->year > m.year) || (this->year >= m.year && this->mon > m.mon) || (this->year >= m.year && this->mon >= m.mon && this->day > m.day))
		return true;
	else
		return false;
}

bool MyDate::operator<(const MyDate m) {// < operator
	if ((this->year < m.year) || (this->year <= m.year && this->mon < m.mon) || (this->year <= m.year && this->mon <= m.mon && this->day < m.day))
		return true;
	else
		return false;
}

bool MyDate::operator==(const MyDate m) {// == operator
	if (this->day == m.day && this->mon == m.mon && this->year == m.year)
		return true;
	else
		return false;
}

/*
if (day < 1 || day >31 || mon < 1 || mon>12 || year < 1920 || year>9999 ||
		(day > 30 && mon < 8 && mon % 2 == 0) ||
		(day > 30 && mon > 7 && mon % 2 == 1) ||
		(day > 29 && mon == 2) ||
		(year % 4 == 0 && year % 100 != 0 && year % 400 == 0 && day > 28 && mon == 2))
	{
	}
	*/

/*temp.day = this->day;
	temp.mon = this->mon;
	temp.year = this->year;*/

//MyDate(int day = 1, int month = 1, int year = 1920) //parametric constructor
	//{
	//	if (day < 1 || day>30)
	//	{
	//		cout << "Error Day" << endl;
	//		day = 1;
	//	}
	//	if (month < 1 || month >12)
	//	{
	//		cout << "Error Month" << endl;
	//		month = 1;
	//	}
	//	if (year < 1920)
	//	{
	//		cout << "Error Year" << endl;
	//		year = 1920;
	//	}
	//	this->day = day;
	//	this->mon = month;
	//	this->year = year;
	//}