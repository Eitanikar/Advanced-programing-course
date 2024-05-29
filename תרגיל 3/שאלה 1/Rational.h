#pragma once
#include <iostream>
#include <cmath>
using namespace std;

//EITAN IKAR / EXC 3 Q 1 / 213450661

class Rational {
private:
	int numerator;
	int denumirator;
public:
	Rational() { //deafult constructor
		this->numerator = 1;
		this->denumirator = 1;
	};

	 Rational(int x, int y) { //parametric constructor
		if (y < 0) {
			y = -y;
		}
		if (y == 0) {
			y = 1;
		}
		this->numerator = x;
		this->denumirator = y;
	}; 

	Rational(const Rational& r) { // copy constructor
		this->numerator = r.numerator;
		this->denumirator = r.denumirator;
	};

	void setNumerator(int numerator) {
		this->numerator = numerator;
	}

	int getnuminator() {
		return numerator;
	}

	void setDenominator(int denumirator) {
		if (denumirator == 0)
			this->denumirator = 1;
		this->denumirator = denumirator;
		minuscheck(this->numerator, this->denumirator);
	}

	int getDenominator() {
		return denumirator;
	}
	
	void minuscheck(int numerator, int denumirator) {	//the method check if the numerator/denominator are positive and change them according to the instructions

		if (this->numerator < 0 && this->denumirator < 0) {
			this->numerator *= -1; this->denumirator *= -1;
		}
		if(this->numerator >= 0 && this->denumirator < 0)
			this->denumirator *= -1;

		if (this->numerator <= 0 && this->denumirator > 0)
			this->numerator *= -1;
	}

	void print() {
		if (denumirator == 1) {
			cout << getnuminator() << endl;
			return;
		}
		cout << getnuminator() << '/' << getDenominator() << " ";
		return;
	}

	void reduce() { //the method reduct the fraction
		if (numerator % denumirator == 0) {
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
		}
	}

	//OPERTORS:
	Rational operator+ (const Rational r) {
		Rational temp;
		const int x = numerator * r.denumirator;
		const int y = denumirator * r.numerator;
		temp.numerator = x + y;
		temp.denumirator = r.denumirator * denumirator;
		temp.reduce();
		return temp;
	};

	Rational operator- (const Rational r) {
		Rational temp;
		const int x = numerator * r.denumirator;
		const int y = denumirator * r.numerator;
		temp.numerator = x - y;
		temp.denumirator = r.denumirator * denumirator;
		temp.reduce();
		return temp;
	}

	Rational operator* (const Rational r) {
		Rational temp;
		temp.numerator = numerator * r.numerator;
		temp.denumirator = denumirator * r.denumirator;
		temp.reduce();
		return temp;
	}

	Rational operator/ (const Rational r) {
		Rational temp;
		temp.numerator = numerator * r.denumirator;
		temp.denumirator = denumirator * r.numerator; 
		temp.reduce();
		return temp;
	}

	bool operator==(const Rational r) {
		Rational temp1 = *this;
		Rational temp2 = r;
		temp1.reduce();
		temp2.reduce();
		if (temp1.numerator == temp2.numerator && temp1.denumirator == temp2.denumirator)
			return true;
		return false;
	}

	bool operator!=(const Rational r) {
		Rational temp1 = *this;
		Rational temp2 = r;
		temp1.reduce();
		temp2.reduce();
		if (temp1.numerator != temp2.numerator || temp1.denumirator != temp2.denumirator)
			return true;
		return false;
	}
	
	Rational operator++() { //pre ++ operator
		this->numerator = numerator + denumirator;
		this->denumirator = denumirator;
		return *this;
	}

	Rational operator++(int) { //post ++ operator
		Rational temp(*this);
		this->numerator = numerator + denumirator;
		this->denumirator = denumirator;
		return temp;
	}

	Rational operator--() { //pre -- operator
		this->numerator = numerator - denumirator;
		this->denumirator = denumirator;
		return *this;
	}

	Rational operator--(int) { //post -- operator
		Rational temp(*this);
		this->numerator = numerator - denumirator;
		this->denumirator = denumirator;
		return temp;
	}

	bool operator<(const Rational r) {
		Rational temp1 = *this;
		Rational temp2 = r;
		temp1.reduce();
		temp2.reduce();
		if (this->denumirator >= r.denumirator) {
			if (this->numerator < numerator) {
				return true;
			}
		}
		return false;
	}

	bool operator<=(const Rational r) {
		return !(*this > r);
	}

	bool operator>(const Rational r) {
		Rational temp1 = *this;
		Rational temp2 = r;
		temp1.reduce();
		temp2.reduce();
		if (this->denumirator <= r.denumirator) {
			if (this->numerator > r.numerator) {
				return true;
			}
		}
		return false;
	}

	bool operator>=(const Rational r) {
		return !(*this < r);
	}
};
//enter your choice :
//1
//enter a rational number :
//1 / 5
//x = ++y;
//before operation y is : 1 / 5
//
//after operation x is : 6 / 5
//
//y is : 6 / 5
//
//enter your choice :
//3
//enter a rational number :
//1 / 5
//x = --y;
//before operation y is : 1 / 5
//
//after operation x is : -4 / 5
//
//y is : -4 / 5
//
//enter your choice :
//0
//
//C : \Users\USER\Desktop\Project1\x64\Debug\Project1.exe(process 26080) exited with code 0.
//Press any key to close this window . . .
