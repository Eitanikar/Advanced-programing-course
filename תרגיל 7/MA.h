#pragma once
#include"BA.h"
//#include"BA.cpp"

class MA : public BA {
protected:
	bool research;

public:
	MA();
	string studType() const override;

	void input();
	void const print() override;
	bool const milga() override;


	void setResearch(bool research);
	bool getResearch();
};