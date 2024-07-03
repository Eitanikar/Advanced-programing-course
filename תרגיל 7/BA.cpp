#include"BA.h"
#include"Student.h"

BA::BA() : Student::Student(){
	this->grades = new int[courses];
}

string BA::studType() const {
	return "BA";
}

float BA::Average(int* grades, int courses) {
	float avarege = 0;
	for (int i = 0; i < courses; i++) {
		avarege += grades[i];
	}
	avarege = avarege / courses;
	return avarege;
}

void BA::input() {
	Student::input();
	cout << "and enter a list of student grades" << endl;
	grades = new int[courses];
	for (int i = 0; i < this->courses; i++)
		cin >> grades[i];
}

void const BA::print() {
	Student::print();
	cout << "Grades:	";
	for (int i = 0; i < this->courses; i++) {
		cout << this->grades[i] << " ";
	}
	cout << endl;
}


bool const BA::milga(){
	return (this->courses >= 10 && Average(this->grades, this->courses) > 95 ? true : false);
}

void BA::setGrades(int* grades) {
	this->grades = grades;
}
int* BA::getGrades() const{
	return this->grades;
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