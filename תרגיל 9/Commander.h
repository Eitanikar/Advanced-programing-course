#pragma once
#include"PrivateSoldier.h"
//#include"BA.cpp"

class commander : public PrivateSoldier {
protected:
	bool combat;

public:
	commander();

	void input();
	void const print() override;
	bool const medal() const override;

	string soldierType() const override;

	void setResearch(bool research);
	bool getCombat();

	//float const avarage() const override;
};