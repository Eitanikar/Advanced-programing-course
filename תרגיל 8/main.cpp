#include<iostream>
using namespace std; 
#include"MA.h"
#include"PHD.h"

#include <algorithm>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <stack>

//EITAN IKAR / 213450661 /  7

enum Degree {
	end = 0,
	Ba = 1, 
	Ma, 
	PHd 
};

Student* addStudent() {
	cout << "Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish\n";
	int choice;
	cin >> choice;
	Student* tmp;
	switch (choice)
	{
		case 0: {
			cout << "------------------------------------------------------------\n";
			tmp = nullptr;
			return tmp;
			break;
		}
		case 1: {
			tmp = new BA;
			tmp->input();
			return tmp;
			break;
		}
		case 2: {
			tmp = new MA;
			tmp->input();
			return tmp;
			break;
		}
		case 3:{
			tmp = new PHD;
			tmp->input();
			return tmp;
			break; 
		}
		default:{
			throw "Exception: no such degree\n";
			//break;
		}
	}
}

int main()
{
	// רשימה מקושרת של מצביעים ל-Student
	list<Student*> studentsList;
	Student* student{};

	// קלוט סטודנטים מהמשתמש עד שיבחר לסיים ע"י הקלט 0
	
	//while ((addStudent()) != nullptr) {
	//	try{
	//		studentsList.push_back(student);
	//	}
	//	catch (const char* msg){
	//		cout << msg << endl;
	//	}
	//};
	
	/*cout << "Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish" << endl;
	cin >> n;
	while (n)
	{
		count++;
		try
		{
			addStudent();
			studentsList.push_back(student);
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
		cout << "Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish" << endl;
		cin >> n;
	}*/

	int n, count = 0;
	do {
		count++;
		try {
			student = addStudent();
			if(student)
				studentsList.push_back(student);
		}
		catch (const char* msg) {
			cout << msg << endl;
		}
	} while ((student) != nullptr);


	// וקטורים עבור כל סוג של סטודנט
	vector<BA> baStudents;
	vector<MA> maStudents;
	vector<PHD> phdStudents;
	list<Student*>::iterator it = studentsList.begin();

	// העברת הסטודנטים מהליסט לווקטורים לפי סוגם
	for (it; it != studentsList.end(); it++) {
		//string type = student->studType();
		if ((*it)->studType() == "BA") {
			baStudents.push_back(*((BA*)(*it)));
		}
		else if ((*it)->studType() == "MA") {
			maStudents.push_back(*((MA*)(*it)));
		}
		else if ((*it)->studType() == "PHD") {
			phdStudents.push_back(*((PHD*)(*it)));
		}
		// שחרור זיכרון של הסטודנט מהליסט
		delete student;
	}
	//cout << "------------------------------------------------------------" << endl;

	// מיון הווקטורים בסדר לא-יורד
	vector<BA>::iterator ib_begin = baStudents.begin();
	vector<BA>::iterator ib_bend = baStudents.end();
	vector<MA>::iterator im_begin = maStudents.begin();
	vector<MA>::iterator im_end = maStudents.end();
	vector<PHD>::iterator ip_begin = phdStudents.begin();
	vector<PHD>::iterator ip_end = phdStudents.end();

	sort(ib_begin, ib_bend);
	sort(im_begin, im_end);
	sort(ip_begin, ip_end);

	// תורים ומחסנית עבור כל סוג של סטודנט
	queue<BA> q_ba;
	queue<MA> q_ma;
	stack<PHD> s_phd;

	vector<BA>::const_reverse_iterator rev_it_ba = baStudents.rbegin();
	vector<MA>::const_reverse_iterator rev_it_ma = maStudents.rbegin();
	vector<PHD>::const_iterator rev_it_phd = phdStudents.begin();

	// הכנסת הסטודנטים לתורים ולמחסנית
	for (int i = 0; i < baStudents.size(); i++)
	{
		q_ba.push(*rev_it_ba);
		++rev_it_ba;
	}

	for (int i = 0; i < maStudents.size(); i++)
	{
		q_ma.push(*rev_it_ma);
		++rev_it_ma;
	}

	for (int i = 0; i < phdStudents.size(); i++)
	{
		s_phd.push(*rev_it_phd);
		++rev_it_phd;
	}

	// הדפסת הסטודנטים לפי הסדר המבוקש
	int a = q_ba.size();
	for (int i = 0; i < a; i++)
	{
		q_ba.front().print();
		q_ba.pop();
		cout << endl;
	}

	int b = q_ma.size();
	for (int i = 0; i < b; i++)
	{
		q_ma.front().print();
		q_ma.pop();
		cout << endl;
	}

	int c = s_phd.size();
	for (int i = 0; i < c; i++)
	{
		s_phd.top().print();
		s_phd.pop();
		cout << endl;
	}

return 0;
};

/*
Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish
1
enter id, first name, last name, number of courses
123 Reuven Reuveni 10
and enter a list of student grades
100 100 100 100 100 100 100 100 100 100
Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish
1
enter id, first name, last name, number of courses
234 Shimon Shimoni 10
and enter a list of student grades
95 95 95 95 95 95 95 95 95 95
Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish
1
enter id, first name, last name, number of courses
345 Levi Levi 10
and enter a list of student grades
99 99 99 99 99 99 99 99 99 99
Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish
1
enter id, first name, last name, number of courses
444 Ploni Almoni 0
and enter a list of student grades
Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish
2
enter id, first name, last name, number of courses
555 Yehuda Yehuda 7
and enter a list of student grades
95 95 95 95 95 95 95
enter 1 if the student does research and 0 if not
1
Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish
2
enter id, first name, last name, number of courses
678 Dan Dani 7
and enter a list of student grades
97 97 97 97 97 97 97
enter 1 if the student does research and 0 if not
1
Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish
3
enter id, first name, last name, number of courses
789 Naphtali Naphtali 2
enter number of research hours:
26
Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish
7
Exception: no such degree

Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish
3
enter id, first name, last name, number of courses
890 Gad Gadi 2
enter number of research hours:
32
Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish
3
enter id, first name, last name, number of courses
901 Asher Asher 1
enter number of research hours:
36
Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish
0
------------------------------------------------------------
------------------------------------------------------------
BA student*** Scholarship ***
ID:     0
Name:
Grades: 100 100 100 100 100 100 100 100 100 100

BA student*** Scholarship ***
ID:     0
Name:
Grades: 99 99 99 99 99 99 99 99 99 99

BA student
ID:     0
Name:
Grades:

BA student
ID:     0
Name:
Grades: 95 95 95 95 95 95 95 95 95 95

MA student*** Scholarship ***
ID:     0
Name:
Grades: 97 97 97 97 97 97 97

research:       YES

MA student*** Scholarship ***
ID:     0
Name:
Grades: 95 95 95 95 95 95 95

research:       YES

PHD student
ID:     -842150451
Name:
number of research Hours:       36

PHD student
ID:     -842150451
Name:
number of research Hours:       32

PHD student
ID:     -842150451
Name:
number of research Hours:       26


C:\Users\USER\Desktop\Project2\x64\Debug\Project2.exe (process 1596) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/