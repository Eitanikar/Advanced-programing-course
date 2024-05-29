#include<iostream>
using namespace std;
#include"RoundVector.h" 

// Eitan ikar / 213450661 / exc 2 q 2

RoundVector input(int capacity) {
	RoundVector newVec(capacity);
	cout << "Enter " << capacity << " numbers:" << endl;
	for (int i = 0; i < capacity; i++) {
		int num;
		cin >> num;
		newVec.addNext(num);
	}
	return move(newVec);
}

enum OPTIONS { STOP, TEST1, TEST2, TEST3 };

int main() {
	int choice;  do {
		cout << "Enter your choice 0-3:" << endl;
		cin >> choice;   switch (choice) {
		case TEST1: {    cout << "--- Test 1 --- constructor --" << endl;
			RoundVector rv1(4);
			rv1.addNext(10);
			rv1.addNext(11);
			rv1.addNext(12);
			rv1.addNext(13);
			rv1.print();
			rv1.addNext(14);
			rv1.print();
			cout << rv1.firstValue() << endl;
			break;
		}
		case TEST2: {
			cout << "--- Test 2 --- copy constructor --" << endl;
			RoundVector rv1(4);
			rv1.addNext(10);
			rv1.addNext(11);
			rv1.addNext(12);
			rv1.addNext(13);
			RoundVector rv2(rv1);
			rv2.print();
			cout << rv2.firstValue() << endl;
			cout << rv2.removeFirst() << endl;
			rv2.print();
			rv2.addNext(14);
			rv2.print();
			rv2.addNext(15);
			rv2.print();
			cout << rv2.removeFirst() << endl;
			cout << rv2.removeFirst() << endl;
			rv2.print();
			rv2.addNext(15);
			rv2.addNext(16);
			rv2.print();
			rv2.addNext(17);
			cout << rv2.firstValue() << endl;
			break;
		}
		case TEST3: {
			cout << "--- Test 3 --- move constructor --" << endl;
			RoundVector rv3 = input(6);
			rv3.print();
			rv3.addNext(7);
			cout << rv3.removeFirst() << endl;
			rv3.print();
			cout << rv3.removeFirst() << endl;
			rv3.print();
			cout << rv3.removeFirst() << endl;
			rv3.print();
			cout << rv3.removeFirst() << endl;
			rv3.print();
			cout << rv3.removeFirst() << endl;
			rv3.print();
			cout << rv3.removeFirst() << endl;
			if (!rv3.isEmpty())
				rv3.removeFirst();
			rv3.addNext(7);
			rv3.addNext(8);
			cout << rv3.firstValue() << endl;
			rv3.print();
			rv3.clear();
			rv3.addNext(9);
			rv3.addNext(10);
			rv3.addNext(11);
			cout << rv3.firstValue() << endl;
			rv3.print();
			break;
		}
		default:
			break;
		}
	} while (choice);
}

/*Enter your choice 0-3:
1
--- Test 1 --- constructor --
in constructor
10 11 12 13
Vector is full
10 11 12 13
10
in destructor
Enter your choice 0-3:
2
--- Test 2 --- copy constructor --
in constructor
in copy constructor
10 11 12 13
10
10
11 12 13
11 12 13 14
Vector is full
11 12 13 14
11
12
13 14
13 14 15 16
Vector is full
13
in destructor
in destructor
Enter your choice 0-3:
3
--- Test 3 --- move constructor --
in constructor
Enter 6 numbers:
1 2 3 4 5 6
in move constructor
in destructor
1 2 3 4 5 6
Vector is full
1
2 3 4 5 6
2
3 4 5 6
3
4 5 6
4
5 6
5
6
6
7
7 8
9
9 10 11
in destructor
Enter your choice 0-3:
0

C:\Users\USER\Desktop\Project2\x64\Debug\Project2.exe (process 25884) exited with code 0.
Press any key to close this window . . .
*/