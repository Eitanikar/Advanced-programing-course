#include "Polygon.h"
#include <iostream>
using namespace std;

Polygon::Polygon() {//empty constructor
	this->array = nullptr;
	this->size = 0;
	cout << "in empty constructor" << endl;
}

Polygon::Polygon(int size) {//parameteric constructor
	this->array = new Point[size];
	this->size = size;
	cout << "in one parameter constructor"<<endl;
}

Polygon::Polygon(const Polygon& p) {//copy constructor
	this->array = p.array;
	this->size = p.size;
	cout << "in copy constructor" << endl;
}

Polygon::~Polygon() {//destructor
	if (array)
		delete[] array;
	array = nullptr;
	cout << "in destructor" << endl;
}

Point* Polygon::getArray() {
	Point* newarray = new Point[this->size];
	for (int i = 0; i < this->size; i++) {
		newarray[i] = this->array[i];
	}
	return newarray;
}

int Polygon::getSize() {
	return this->size;
}

void Polygon::addPoint(Point p, int index) {
	this->array[index].setX(p.getX());
	this->array[index].setY(p.getY());
}

float Polygon::perimeter() {//calculate the perimeter of the polygon
	float dist=0;
	for (int i = 0; i < this->size -1; i++) {
		dist += this->array[i].distance(this->array[i + 1]);
	}
	dist += this->array[this->size -1].distance(this->array[0]);
	return dist;
}

bool Polygon::isIdentical(Polygon p) {//check if two polygons are equal
	if (this->size != p.getSize())
		return false;
	bool flag;
	for (int i = 0; i < this->size; i++) {
		flag = false;
		for (int j = 0; j < this->size; j++) {
			if (this->array[i].distance(p.array[j]) == 0)
				flag = true;
		}
		if (!flag)
			return false;
	}
	return true;
}

/*Point::Point() {
	this->x = 0;
	this->y = 0;
}

Point::Point(float x, float y) {
	this->x = x;
	this->y = y;
}

Point::Point(const Point& p) {
	this->x = p.x;
	this->y = p.y;
}

void Point::setX(float x) {
	this->x = x;
}

void Point::setY(float y) {
	this->y = y;
}

float Point::getX() {
	return this->x;
}

float Point::getY() {
	return this->y;
}

float Point::distance(Point p) {
	float dis;
	dis = sqrt(powf(this->x - p.x, 2) + powf(this->y - p.y, 2));
	return dis;
}*/