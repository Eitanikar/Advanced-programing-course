#pragma once
#include"Student.h"

class BA : public Student {
public:
	int* grades = new int[courses];

	BA();
	BA(const BA&);
	BA(BA&&);
	virtual ~BA();
	BA& operator=(BA&&);
	BA& operator=(const BA&);

	virtual bool operator < (const Student& rhs) const override;

	void input() override;
	void const print() override;
	bool const milga() const override;

	string studType() const override;

	float const average() const;

	void setGrades(int* grades);
	int* getGrades() const;
};