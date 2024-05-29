#pragma once
#include <iostream>
using namespace std;

class RoundVector {
private:
	int capacity;
	//int size;
	int* vec;
	int head;
	int tail;

public:
	//RoundVector();
	RoundVector(int max);//constructor
	RoundVector(const RoundVector& rv);//copy constructor
	RoundVector(RoundVector&& rv);//move constructor
	~RoundVector();//destructor

	void addNext(int n);//add Next item to the vector
	int removeFirst();//remove the first item from the vector by moving head to the next index 
	int firstValue();//return the first item in the vector
	bool isEmpty();//check if the vector is empty
	void clear();//clear the vector by moving head and tail to the first index
	void print();//print the vector
};