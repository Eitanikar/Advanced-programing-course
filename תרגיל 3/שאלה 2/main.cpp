#include"MyDate.h"
#include<iostream>
using namespace std;

//EITAN IKAR / 213450661 /exc 3 q 2

enum OPERATOR {
	EXIT, UPDATE, ADD_PRE, ADD_POST, EQUAL, GREATER_THAN, LESS_THAN, D_EQUAL
};

int main() {
	int day, mon, year;
	char junk;
	int code;
	MyDate d2;
	cout << "Enter a date" << endl;
	cin>> day >> junk >> mon >> junk >> year;
	MyDate d1(day, mon, year);
	d1.print();
	cout << endl;
	cout << "Enter a code" << endl;
	cin >> code;
	while (code != EXIT) {
		switch (code) {
			case UPDATE:
				cout << "Enter a date" << endl;
				cin >> day >> junk >> mon >> junk >> year;
				d1.setDate(day, mon, year);
				d1.print();
				cout << endl;
				break;
			case ADD_PRE:
				d2.setDate(day, mon, year);
				d2 = ++d1;
				d1.print();
				cout << endl;
				d2.print();
				cout << endl;
				break;
			case ADD_POST:
				d1.setDate(day, mon, year);
				d2 = d1++;
				d2.print();
				cout << endl;
				d1.print();
				cout << endl;
				break;
			case EQUAL:
				cout << "Enter a date" << endl;
				cin >> day >> junk >> mon >> junk >> year;
				d2.setDate(day, mon, year);
				d1 = d2;
				d1.print();
				cout << endl;
				break;
			case GREATER_THAN:
				cout << "Enter a date" << endl;
				cin >> day >> junk >> mon >> junk >> year;
				d2.setDate(day, mon, year);
				d1.print();
				cout << " > ";
				d2.print();
				if (d1 > d2)
					cout << " : true\n";
				else
					cout << " : false\n";
				break;
			case LESS_THAN:
				cout << "Enter a date" << endl;
				cin >> day >> junk >> mon >> junk >> year;
				d2.setDate(day, mon, year);
				d1.print();
				cout << " > ";
				d2.print();
				if (d1 < d2)
					cout << " : true\n";
				else
					cout << " : false\n";
				break;
			case D_EQUAL:
				cout << "Enter a date" << endl;
				cin >> day >> junk >> mon >> junk >> year;
				d2.setDate(day, mon, year);
				d1.print();
				cout << " == ";
				d2.print();
				if (d1 == d2)
					cout << " : true\n";
				else 
					cout << " : false\n";
				break;
		}
		cout << "Enter a code" << endl;
		cin >> code;
	}
	return 0;
}
/*Enter a date
17/12/2002
17/12/2002
Enter a code
1
Enter a date
18/12/2001
18/12/2001
Enter a code
2
19/12/2001

19/12/2001

Enter a code
3
19/12/2001

20/12/2001

Enter a code
4
Enter a date
17/12/2002
17/12/2002

Enter a code
5
Enter a date
17/12/2002
d1 > d2:false
Enter a code
6
Enter a date
17/12/2002
d1 < d2:false
Enter a code
7
Enter a date
17/12/2002
d1 == d2:true
Enter a code
0

C:\Users\USER\Desktop\Project1\x64\Debug\Project1.exe (process 30184) exited with code 0.
Press any key to close this window . . .
*/