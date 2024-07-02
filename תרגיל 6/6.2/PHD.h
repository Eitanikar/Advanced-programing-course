#pragma once
#include"Student.h"

class PHD : protected Student {
protected:

	int weeklyResearch;

public:
	bool milga();
	void input();
	void print();

	void setWeeklyResearch(int weeklyResearch);
	int getweeklyResearch();
};