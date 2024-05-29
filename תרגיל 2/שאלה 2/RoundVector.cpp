#include "RoundVector.h"

RoundVector::RoundVector(int max) {//constructor
	capacity = max;
	vec = new int[max + 1];
	cout << "in constructor" << endl;
}

RoundVector::RoundVector(const RoundVector& rv) {//copy constructor
	capacity = rv.capacity;
	vec = new int[capacity + 1];
	for (int i = 0; i < capacity; i++)
		vec[i] = rv.vec[i];
	head = rv.head;
	tail = rv.tail;
	cout << "in copy constructor" << endl;
}

RoundVector::RoundVector(RoundVector&& rv) {//move constructor
	this->capacity = rv.capacity;
	this->vec = rv.vec;
	this->head = rv.head;
	this->tail = rv.tail;
	rv.vec = nullptr;
	cout << "in move constructor" << endl;
}

RoundVector::~RoundVector() {//destructor
	if (vec)
		delete[] vec;
	cout << "in destructor" << endl;
}

void RoundVector::addNext(int n) {//add Next item to the vector
	if (((tail + 1) % (capacity + 1)) == head) {
		cout << "Vector is full\n";
	}
	else {
		vec[tail] = n;
		tail = (tail + 1) % (capacity + 1);
	}
}

int RoundVector::removeFirst() {//remove the first item from the vector by moving head to the next item index's
	int fst = vec[head];
	head = (head + 1) % (capacity + 1);
	return fst;
}

int RoundVector::firstValue() {//return the first item in the vector
	return vec[head];
}

bool RoundVector::isEmpty() {//check if the vector is empty
	if (head == tail)
		return true;
	else
		return false;
}

void RoundVector::clear() {//clear the vector by moving head and tail to the beginning
	head = 0;
	tail = 0;
}

void RoundVector::print() {//print the vector
	int i = head;
	while (i != tail) {
		cout << vec[i] << " ";
		i = (i + 1) % (capacity + 1);
	}
	cout << endl;
}

//void RoundVector::initialize(int n) {
//	size = n;
//	vec = new int[size];
//	for (int i = 0; i < size; i++)
//		cin >> vec[i];
//}