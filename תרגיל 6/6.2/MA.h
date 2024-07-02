#pragma once
#include"BA.h"
//#include"BA.cpp"

class MA : protected BA {
protected:
	bool research;

public:
	bool milga();
	void input();
	void print();

	void setResearch(bool research);
	bool getResearch();
};