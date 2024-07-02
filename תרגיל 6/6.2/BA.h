#pragma once
#include"Student.h"

class BA : protected Student {
protected:
	int* grades = new int[courses];

public:
	bool milga();
	void input();
	void print();

	float Average(int* grades, int courses);

	void setGrades(int* grades);
	int* getGrades() const;
};