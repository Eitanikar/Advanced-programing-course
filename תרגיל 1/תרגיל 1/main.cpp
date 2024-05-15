#include "Rational.h"
#include <iostream> 
using namespace std;


int main() {
	int num1, num2, num3;
	char junk;

	cout << "part 1. ctor/set/get" << endl;
	cout << "enter a rational number:" << endl;
	cin >> num1 >> junk >> num2;
	Rational rat1;
	rat1.setNumerator(num1);
	rat1.setDenominator(num2);
	cout << "numerator: " << rat1.getNumerator() << endl;
	cout << "denominator: " << rat1.getDenominator() << endl;  cout << endl;
	cout << "enter a rational number: " << endl;
	cin >> num1 >> junk >> num2;
	Rational rat2(num1, num2);
	rat2.print();
	cout << endl << endl;

	cout << "part 2. copy-ctor" << endl;
	Rational rat3(rat2);  rat3.print();
	cout << endl << endl;

	cout << "part 3. equals" << endl;
	if (rat1.equal(rat2))
		cout << "The two numbers are equal" << endl;
	else
		cout << "The two numbers are different" << endl;
	cout << endl;

	cout << "part 4. makeEquals" << endl;
	rat1.makeEquals(rat2);  if (rat1.equal(rat2))
		cout << "The two numbers are equal" << endl;
	else
		cout << "The two numbers are different" << endl;
	cout << endl; 

	cout << "part 5. addOne" << endl;
	Rational ans1; 
	ans1 = rat1.addOne();
	rat1.print();
	cout << " + 1 = ";
	ans1.print();
	cout << endl << endl;

	cout << "part 6. add" << endl;
	Rational ans2;
	ans2 = rat1.add(rat3);
	rat1.print();
	cout << " + ";
	rat3.print();
	cout << " = ";
	ans2.print();
	cout << endl << endl;

	return 0;
}

/*
part 2. copy-ctor
print: in copy constructor
4/12


part 3. equals
print: in copy constructor
The two numbers are different

part 4. makeEquals
print: in copy constructor
The two numbers are equal

part 5. addOne
print: in constructor
print: in constructor
2/12
2/12 + 1 = 14/12
part 6. add
print: in constructor
print: in copy constructor
print: in constructor
2/12 + 4/12 = 1/2


C:\Users\USER\Desktop\Project2\x64\Debug\Project2.exe (process 23072) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .*/