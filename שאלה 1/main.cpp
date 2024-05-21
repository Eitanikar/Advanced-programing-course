
/*eitan ikar / 213450661 / exc 2 q 1 */
#include<iostream>
#include <cmath>
#include "Polygon.h"
using namespace std;

int main() {
	int num, x, y;
	char junk;
	Point temp;
	cout << "enter number of sides:" << endl;
	cin >> num;
	while (num <= 0) {
		cout << "ERROR" << endl;
		cin >> num;
	}
	Polygon p1(num); 
	cout << "enter the point values:" << endl;
	for (int i = 0; i < num; i++) {               //set p1
		cin >> junk >> x >> junk >> y >> junk;
		temp.setX(x);
		temp.setY(y);
		p1.setPoint(temp, i);
	}

	cout << "enter number of sides:" << endl;
	cin >> num;
	while (num <= 0) {
		cout << "ERROR" << endl;
		cin >> num;
	}

	Polygon p2(num);

	cout << "enter the point values:" << endl;
	for (int i = 0; i < num; i++) {               //set p2
		cin >> junk >> x >> junk >> y >> junk;
		temp.setX(x);
		temp.setY(y);
		p2.setPoint(temp, i);
	}

	if (p1.isIdentical(p2)) {
		cout << "equal" << endl;
		cout << "perimeter: " << round(p1.perImeter()) << endl;
	}
	else {
		cout << "not equal" << endl;
		cout << "perimeter: " << round(p1.perImeter()) << endl;
		cout << "perimeter: " << round(p2.perImeter()) << endl;
	}
	return 0;
}