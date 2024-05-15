#pragma once
#include<cmath>

//EITAN IKAR / EXC.1 Q.1 / 213450661
class Rational {
private:
	int numerator;
	int denumirator;
public:
	Rational();  //default constructor

	Rational(int x, int y); //constructor

	Rational(const Rational& r); //copy constructor

	void setNumerator(int numerator);

	int getNumerator();

	void setDenominator(int denumirator);

	int getDenominator();

	void print();

	bool equal(Rational r);

	void makeEquals(Rational& r) {
		r.numerator = this->numerator;
		r.denumirator = this->denumirator;
	}

	void reduce();

	Rational add(Rational r);

	Rational addOne();
};