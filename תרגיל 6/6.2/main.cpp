#include"MA.h"
#include"PHD.h"

//EITAN IKAR / 213450661 /  6.2

int main()
{
	BA ba[2];
	cout << "Enter details for 2 BA students\n";
	for (int i = 0; i < 2; i++)
		ba[i].input();
	cout << "BA students entitled for milga are: \n";
	for (int i = 0; i < 2; i++)
	{
		if (ba[i].milga())
			ba[i].print();
		//else cout << " Student not entitled for milga\n";
	}
	cout << "Enter details for 2 MA students\n";
	MA ma[2];
	for (int i = 0; i < 2; i++)
		ma[i].input();
	cout << "MA students entitled for milga are: \n";
	for (int i = 0; i < 2; i++)
	{
		if (ma[i].milga())
			ma[i].print();
	}
	cout << "Enter details for 3 PHD students\n";
	PHD phd[3];
	for (int i = 0; i < 3; i++)
		phd[i].input();
	cout << "PHD students entitled for milga are: \n";
	for (int i = 0; i < 3; i++)
	{
		if (phd[i].milga())
			phd[i].print();
	}
	return 0;
}

/*
Enter details for 2 BA students
enter id, first name, last name, number of courses
123 abe avraham 3
and enter a list of student grades
90 100 90
enter id, first name, last name, number of courses
234 yitzhak avramson 10
and enter a list of student grades
100 100 90 100 90 100 90 100 90 100
BA students entitled for milga are:
ID: 234
Name: yitzhak avramson
Grades: 100 100 90 100 90 100 90 100 90 100
Enter details for 2 MA students
enter id, first name, last name, number of courses
345 yaacov jacobson 7
and enter a list of student grades
90 100 90 100 90 100 90
enter 1 if the student does research and 0 if not
0
enter id, first name, last name, number of courses
456 sara emanu 7
and enter a list of student grades
90 100 90 100 90 100 90
enter 1 if the student does research and 0 if not
1
MA students entitled for milga are:
ID: 456
Name: sara emanu
Grades: 90 100 90 100 90 100 90
research: 1
Enter details for 3 PHD students
enter id, first name, last name, number of courses
567 rivka imanu 1
enter number of research hours:
30
enter id, first name, last name, number of courses
678 rachel jacobs 2
enter number of research hours:
20
enter id, first name, last name, number of courses
789 leah jacobs 2
enter number of research hours:
30
PHD students entitled for milga are:
ID: 789
Name: leah jacobs
number of research Hours: 30

C:\Users\USER\Desktop\Project2\x64\Debug\Project2.exe (process 21188) exited with code -2147483645.
Press any key to close this window . . .
*/