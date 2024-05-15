#include"Rational.h"
#include<iostream>
using namespace std;

Rational::Rational()
{
	this->numerator = 0;
	this->denumirator = 1;
	cout << "print: in constructor" << endl;
}

Rational::Rational(int x, int y) {//parametric constructor
	if (y < 0 && x < 0) {
		y = -y;
		x = -x;
		this->numerator = x;
		this->denumirator = y;
	}
	if (y < 0 && x > 0) {
		y = -y;
		this->numerator = x;
		this->denumirator = y;
	}
	if (y == 0) {
		y = 1;
		this->numerator = x;
		this->denumirator = y;
	}
	else {
		this->numerator = x;
		this->denumirator = y;
	}
	cout << "print: in constructor" << endl;
}

Rational::Rational(const Rational& r) { // copy constructor
	this->numerator = r.numerator;
	this->denumirator = r.denumirator;
	cout << "print: in copy-constructor" << endl;
}

void Rational::setNumerator(int x) {
	this->numerator = x;
}

int Rational::getNumerator() {
	return numerator;
}

void Rational::setDenominator(int denum) {
	if (denum == 0)
		this->denumirator = 1;
	if (denum < 0 && this->numerator > 0 || denum < 0 && this->numerator < 0) {
		denum = -denum;
		int temp = this->numerator;
		this->numerator = temp * -1;
		this->denumirator = denum;
	}
	else
		this->denumirator = denum;
	//minuscheck(this->numerator, this->denumirator);
}

int Rational::getDenominator() {
	return denumirator;
}

void Rational::print() {
	//if (denumirator == 1) {
	//	cout << getNumerator();
	//	return;
	//}
	if (getNumerator() < 0 && getDenominator() < 0 || getNumerator() > 0 && getDenominator() < 0) {
		int n = getNumerator() * -1, m = getDenominator() * -1;
		setNumerator(n);
		setDenominator(m);
	}
	cout << getNumerator() << '/' << getDenominator();
	return;
}

bool Rational::equal(Rational r) {
	if (this->numerator == r.numerator && this->denumirator == r.denumirator)
		return true;
	if (this->numerator == (-1 * r.numerator) && (this->denumirator * -1) == r.denumirator || (this->numerator * -1) == r.numerator && this->denumirator == (-1 * r.denumirator))
		return true;
	return false;
}

void Rational::reduce() {
	//the method reduct the fraction
	/*if (numerator % denumirator == 0) {
		numerator /= denumirator;
		denumirator = 1;
	}
	if (denumirator % numerator == 0) {
		denumirator /= numerator;
		numerator = 1;
	}
	int maximum = max(numerator, denumirator);
	for (int i = maximum; i > 0; i--) {
		if (numerator % i == 0 && denumirator % i == 0) {
			numerator /= i;
			denumirator /= i;
		}
	}*/
	int temp, max;
	if (getNumerator() > getDenominator())
		max = getNumerator();
	else
		max = getDenominator();
	
	for (int i = 1; i <= max; i++) {
		if (getNumerator() % i == 0 && getDenominator() % i == 0) {
			temp = i;
		}
	}
	this->numerator = numerator / temp;
	this->denumirator = denumirator / temp;
}

Rational Rational::add(Rational r) {
	Rational ans;
	ans.setNumerator(this->numerator * r.getDenominator() + this->denumirator * r.getNumerator());
	ans.setDenominator(r.getDenominator() * this->denumirator);
	ans.reduce();
	return ans;
}

Rational Rational::addOne() {
	Rational ans;
	ans.numerator = (this->numerator + this->denumirator);
	ans.denumirator = this->denumirator;
	if (ans.numerator < 0)
		ans.numerator = (ans.numerator * -1);
	if (ans.denumirator < 0)
		ans.denumirator = (ans.numerator * -1);
	return ans;
}