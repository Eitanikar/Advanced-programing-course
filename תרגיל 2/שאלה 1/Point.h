#pragma once
#include <cmath>
#include <iostream>
using namespace std;


class Point {
private:
	float x;
	float y;
public:
	Point();
	Point(float x, float y);
	Point(const Point& p);
	void setX(float x);
	void setY(float y);
	float getX();
	float getY();
	//void setPoint(Point p);
	float distance(Point p);
};

//friend istream& operator>> (istream& is, const Point P) {
	//	cout << "Enter point's details:" << endl;
	//	Employee temp(p.x, p.y);
	//	is >> temp.x;
	//	is >> temp.y;
	//	return is;
	//}