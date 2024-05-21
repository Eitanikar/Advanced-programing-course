#pragma once
#include "Point.h"
#include "Polygon.h"


class Polygon {
private:
	Point* array;
	int size;
public:
	Polygon();
	Polygon(int size);
	Polygon(const Polygon& p);
	~Polygon();
	Point* getArray();
	int getSize();
	void setPoint(Point p, int index);
	float perImeter();
	bool isIdentical(Polygon p);
};