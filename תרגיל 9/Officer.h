#pragma once
#include"Soldier.h"

class officer : public Soldier {
protected:

	int sociometric;

public:

	void input();
	void const print() override;
	bool const medal() const override;

	string soldierType() const override;

	void setSocioMetric(int weeklyResearch);
	int getSocioMetric();

	bool operator<(const Soldier& rhs) const;

	//float const avarage() const;
};