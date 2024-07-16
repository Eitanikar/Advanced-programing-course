#pragma once
#include"Soldier.h"

class PrivateSoldier : public Soldier {
public:
	int* grades = new int[operations];

	PrivateSoldier();
	PrivateSoldier(const PrivateSoldier&);
	PrivateSoldier(PrivateSoldier&&);
	virtual ~PrivateSoldier();
	PrivateSoldier& operator=(PrivateSoldier&&);
	PrivateSoldier& operator=(const PrivateSoldier&);

	virtual bool operator < (const Soldier& rhs) const override;

	void input() override;
	void const print() override;
	bool const medal() const override;

	string soldierType() const override;

	float const average() const;

	void setGrades(int* grades);
	int* getGrades() const;
};