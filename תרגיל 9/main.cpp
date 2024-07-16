#include"Commander.h"
#include"Officer.h"

#include<iostream>
using namespace std; 

#include <algorithm>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <stack>

//EITAN IKAR / 213450661 /  9

enum option {
	EXIT,
	ADD_NEW_SOLDIER,
	DESERVES_MEDAL,
	HIGHEST_SOCIOMETRIC,
	PRIVATE_MEDAL_COUNT,
	NONCOMBAT_COMMANDER,
	SUPER_SOLDIER,
	REMOVE_OFFICER,
};


void add(list<Soldier*>& soldiersList) {
	cout << "choose a soldier\n"
		<< "enter 1 to add a private\n"
		<< "enter 2 to add a commander\n"
		<< "enter 3 to add an officer\n";
	int op;
	cin >> op;

	Soldier* s = nullptr;

	switch (op) {
		case 1: {
			s = new PrivateSoldier();
			soldiersList.push_back(s);
			break;
		}
		case 2: {
			s = new commander();
			soldiersList.push_back(s);
			break;
		}
		case 3: {
			s = new officer();
			soldiersList.push_back(s);
			break;
		}
		default:{
			cout << "ERROR" << endl;
		}
	}
	s->input();
}

void printMedalList(list<Soldier*>& s) {
	list<Soldier*>::iterator it;
	for (it = s.begin(); it != s.end(); it++) {
		if ((*it)->medal())
			(*it)->print();
	}
}

Soldier* highestSociometricScore(list<Soldier*>& s) {
	list<Soldier*>::iterator it;
	Soldier* ls = nullptr;
	float max = 0;
	bool flag = false;

	for (it = s.begin(); it != s.end(); it++) {
		if ((*it)->soldierType() == "officer") {
			if (((officer*)(*it))->getSocioMetric() > max) {
				flag = true;
				max = ((officer*)(*it))->getSocioMetric();
				ls = *it;
			}
		}			
	}
	if (flag == false)
		return NULL;
	return ls;
}

int main()
{
	list<Soldier*> soldiersList;
	Soldier* s;

	int op = 0;
	cout << "enter 0-7\n";
	cin >> op;
	while (op != EXIT)
	{
		switch (op)
		{
		case ADD_NEW_SOLDIER:
			add(soldiersList);
			break;

		case DESERVES_MEDAL:
			printMedalList(soldiersList);
			break;

		case HIGHEST_SOCIOMETRIC:
			s = highestSociometricScore(soldiersList);
			cout << "Officer with the highest sociometric score: ";
			cout << s->getFirstName() << ' ' << s->getLastName() << endl;
			break;

		case PRIVATE_MEDAL_COUNT:
			cout << "number of privates that received medals : ";
			cout << count_if(soldiersList.begin(), soldiersList.end(), [](Soldier* s) {return s->soldierType() == "private" && s->medal(); });
			cout << endl;
			break;

		case NONCOMBAT_COMMANDER:
			cout << "list of noncombat commanders: ";
			for_each(soldiersList.begin(), soldiersList.end(), [](Soldier* s) {
				if (s->soldierType() == "Commander" && (!((commander*)s)->getCombat()))
					cout << s->getFirstName() << " " << s->getLastName() << endl;
				});
			break;

		case SUPER_SOLDIER:
			if (any_of(soldiersList.begin(), soldiersList.end(), [](Soldier* s) {
				return s->getOperations() > 15;
			}))
				cout << "there is at least one soldier that did more than 15 operations\n";
			else
				cout << "no soldier did more than 15 operations\n";
			break;

		case REMOVE_OFFICER:
			soldiersList.erase(remove_if(soldiersList.begin(), soldiersList.end(), [](Soldier* s) {if (s->soldierType() == "officer" && s->getOperations() == 0) return true; else return false; }), soldiersList.end());
			for_each(soldiersList.begin(), soldiersList.end(), [](Soldier* s) {s->print(); });
			break;
		};
		cout << "enter 0-7\n";
		cin >> op;
	}
}

/*
enter 0-7
choose a soldier
choose a soldier
enter 1 to add a private
enter 1 to add a private
enter 2 to add a commander
enter 2 to add a commander
enter 3 to add an officer
enter 3 to add an officer
enter id, first name, last name and number of operations
enter id, first name, last name and number of operations
enter 8 grades
enter 8 grades
enter 1 if the soldier is combat and 0 if not
enter 1 if the soldier is combat and 0 if not
enter 0-7
enter 0-7
choose a soldier
choose a soldier
enter 1 to add a private
enter 1 to add a private
enter 2 to add a commander
enter 2 to add a commander
enter 3 to add an officer
enter 3 to add an officer
enter id, first name, last name and number of operations
enter id, first name, last name and number of operations
enter 10 grades
enter 10 grades
enter 1 if the soldier is combat and 0 if not
enter 1 if the soldier is combat and 0 if not
enter 0-7
enter 0-7
choose a soldier
choose a soldier
enter 1 to add a private
enter 1 to add a private
enter 2 to add a commander
enter 2 to add a commander
enter 3 to add an officer
enter 3 to add an officer
enter id, first name, last name and number of operations
enter id, first name, last name and number of operations
enter 5 grades
enter 5 grades
enter 1 if the soldier is combat and 0 if not
enter 1 if the soldier is combat and 0 if not
enter 0-7
enter 0-7
choose a soldier
choose a soldier
enter 1 to add a private
enter 1 to add a private
enter 2 to add a commander
enter 2 to add a commander
enter 3 to add an officer
enter 3 to add an officer
enter id, first name, last name and number of operations
enter id, first name, last name and number of operations
enter 2 grades
enter 2 grades
enter 1 if the soldier is combat and 0 if not
enter 1 if the soldier is combat and 0 if not
enter 0-7
enter 0-7
list of noncombat commanders: enter 0-7
list of noncombat commanders: aaa aaa ccc ccc
enter 0-7
*/