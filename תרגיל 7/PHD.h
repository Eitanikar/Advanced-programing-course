#pragma once
#include"Student.h"

class PHD : public Student {
protected:

	int weeklyResearch;

public:
	string studType() const override;

	void input();
	void const print() override;
	bool const milga() override;


	void setWeeklyResearch(int weeklyResearch);
	int getweeklyResearch();
};