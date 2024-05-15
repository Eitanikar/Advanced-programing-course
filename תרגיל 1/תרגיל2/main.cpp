#include "Employee.h"	
#include<iostream>
#include <cstring>
using namespace std;

//Eitan ikar /213450662 /excercise 1 question 1

int main() {

	Employee most, less, tempE; //creating the most, less and tempE objects

	int num1, num2;
	float numf1 , tempsalary;
	char name[21];
	
	less.setid(999999); //setting the less id to the highest possible number
	less.setamount(0.0); //setting the less amount to the lowest possible number
	most.setid(0); //setting the most id to the lowest possible number	
	most.setwage(0); //setting the most wage to 0	
	most.sethours(0.0); //setting the most hours to 0	
	most.setamount(0.0); //setting the most amount to 0

	cout << "enter details, to end enter 0:" << endl;
	cin >> num1;
	tempE.setid(num1);
	while (tempE.getid()) { //while the id is not 0
		cin >> name;
		tempE.setname(name);
		cin >> num1;
		tempE.setwage(num1);
		cin >> num1;
		tempE.sethours(num1);
		cin >> numf1;
		tempE.setamount(numf1);
		tempsalary = tempE.salary();

		if(tempE.getamount() < 0 || tempE.getamount() > 99999 || tempE.getamount() < 0 || tempE.getwage() < 0 || tempE.gethours() < 0 || tempE.getid() < 0)
			cout << "ERROR" << endl;
		else {

			if (less.getamount() > tempE.getamount() || less.getamount() == 0.0) //if the less amount is bigger than the temp amount
			{
				less.setamount(tempE.getamount());
				less.setname(tempE.getname());
				less.setid(tempE.getid());
			}
			if (most.salary() < tempE.salary() || most.getamount() == 0.0) //if the most wage is smaller than the temp wage
			{
				most.setwage(tempE.getwage());
				most.setname(tempE.getname());
				most.setid(tempE.getid());
				most.sethours(tempE.gethours());
				most.setamount(tempE.getamount());
			}
		}
		//cout << "enter worker details; to exit, press 0." << endl;
		cin >> num1;
		tempE.setid(num1);
	}
	cout << "minimum collected: " << less.getid() << " " << less.getname() << " " << less.getamount() << endl;
	cout << "highest salary: " << most.getid() << " " << most.getname() << " " << most.salary() << endl;
	return 0;
}

/*print: in constructor
print: in constructor
print: in constructor
enter details, to end enter 0:
12345 moshe   50  40  2000 13579 rivka 120  55  3450 97531 sara  35  100   5632 0
minimum collected: 2000 moshe 12345
highest salary: 3450 rivka 13579

C:\Users\USER\Desktop\Project2\x64\Debug\Project2.exe (process 7332) exited with code 0.
Press any key to close this window . . .*/