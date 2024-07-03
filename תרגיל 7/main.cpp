#include"BA.h"
#include"MA.h"
#include"PHD.h"

//EITAN IKAR / 213450661 /  7

enum Degree { 
	Ba = 1, 
	Ma, 
	PHd 
};

Student* Student::addStudent() {
	cout << "Enter degree: 1 for BA, 2 for MA, or 3 for PhD\n";
	int choice;
	cin >> choice;
	Student* tmp;
	switch (choice)
	{
		case 1:
			tmp = new BA;
			tmp->input();
			return tmp;
			break;

		case 2:
			tmp = new MA;
			tmp->input();
			return tmp;
			break;

		case 3:
			tmp = new PHD;
			tmp->input();
			return tmp;
			break;

	default:
		throw "Exception: no such degree\n";
		break;
	}
}

int main()
{
	Student** students;
	int size = 0;
	cout << "Enter the number of students:" << endl;
	cin >> size;
	students = new Student * [size];
	for (int i = 0; i < size; i++)
	{
		cout << endl << "Student " << i + 1 << " of " << size << endl;
		try {
			students[i] = students[i]->addStudent();
		}
		catch (const char* msg) {
			cout << msg << endl;
			i--;
		}
	}
	cout << endl << "Students entitled for milga are:\n";

	for (int i = 0; i < size; i++){
		if (students[i]->milga()) {
			cout << endl;
			students[i]->print();
		}
	}
	
	for (int i = 0; i < size; i++)
	{
		if(students[i] != nullptr)
			delete students[i];
	}
	if(students != nullptr)
		delete[] students;
return 0;
}

/*
Enter number of students:
3
Student 1 of 3
Enter degree: 1 for BA, 2 for MA, or 3 for PhD
1
enter id, first name, last name, number of courses

123 Reuven Reuveni 3
and enter a list of student grades
90 95 100
Student 2 of 3
Enter degree: 1 for BA, 2 for MA, or 3 for PhD
1
enter id, first name, last name, number of courses

234 Shimon Shimoni 10
and enter a list of student grades
95 95 95 95 95 95 95 95 95 95
Student 3 of 3
Enter degree: 1 for BA, 2 for MA, or 3 for PhD
1
enter id, first name, last name, number of courses

345 Levi Levi 10
and enter a list of student grades
96 95 95 95 95 95 95 95 95 95
Students entitled for milga are:
ID: 345
Name: Levi Levi
Grades: 96 95 95 95 95 95 95 95 95 95

C:\Users\USER\Desktop\Project2\x64\Debug\Project2.exe (process 30252) exited with code 0.
Press any key to close this window . . .
*/