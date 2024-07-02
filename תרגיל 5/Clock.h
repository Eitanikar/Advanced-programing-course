#pragma once
#include <iostream>
using namespace std;

class Clock
{
	int hour = 0, 
		minute = 0, 
		second = 0;

public:

	Clock(int h, int m, int s);

	void setHour(int h);
	void setMinute(int m);
	void setSecond(int s);

	int gethour();
	int getminute();
	int getsecond();

	bool equals(Clock c);
	bool before(Clock c);
	bool after(Clock c);

	Clock operator+=(int sec);
	friend istream& operator>>(istream& is, const Clock& c);
	friend ostream& operator<<(ostream& os, const Clock& c);
};