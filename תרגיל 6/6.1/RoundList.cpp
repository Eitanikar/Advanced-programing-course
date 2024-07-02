#include "RoundList.h"
#include "List.h"

#include<iostream>
using namespace std;

void RoundList::addToEnd(int value) {
	Link tmp(value, this->head );
	Link* p = this->head->next;
	while(p->next != this->head) {
		p = p->next;
	}
	p->next= &tmp;
}

int RoundList::search(int n) {
	if (n > 0) {
		int i = 1;
		Link* p = this->head->next;

		while (i <= n) {
			p = p->next;
			i++;
		}
		return p->value;
	}
	else
		return -1;
}