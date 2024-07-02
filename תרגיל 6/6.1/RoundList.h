#pragma once
#include "List.h"

class RoundList : protected List {

public:
	void addToEnd(int value);
	int search(int n);
};