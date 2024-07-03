#pragma once
#include"Student.h"

class BA : public Student {
public:
	int* grades = new int[courses];

	BA();
	void input() override;
	void const print() override;
	bool const milga() override;

	string studType() const override;

	float Average(int* grades, int courses);

	void setGrades(int* grades);
	int* getGrades() const;
};