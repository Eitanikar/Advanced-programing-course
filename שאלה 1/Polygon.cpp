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
	this->array = new Point[p.size];
	this->size = p.size;
	for (int i = 0; i < p.size; i++) {
		this->array[i] = p.array[i];
	}
	cout << "in copy constructor" << endl;
}

Polygon::~Polygon() {//destructor
	if (array)
		delete[] array;
	array = nullptr;
	cout << "in destructor" << endl;
}

Point* Polygon::getArray() {//return the array of points
	return this->array;
}

int Polygon::getSize() {
	return this->size;
}

void Polygon::setPoint(Point p, int index) {//set a point in the polygon
	this->array[index].setX(p.getX());
	this->array[index].setY(p.getY());
}

float Polygon::perImeter() {//calculate the perimeter of the polygon
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