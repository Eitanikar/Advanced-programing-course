#pragma once
#include <cstring>
#include <iostream>
using namespace std;
class Student
{
protected:
	int id;
	string name;
	string familyName;

public:
	bool operator <=(const Student st)const { return id <= st.id; }
	bool operator <(const Student st)const { return id < st.id; }
	bool operator >(const Student st)const { return id > st.id; }
	bool operator >=(const Student st)const { return id >= st.id; }
	bool operator ==(const Student st)const { return id == st.id && name == st.name && familyName == st.familyName; }
	bool operator !=(const Student st)const { return id != st.id || name != st.name || familyName != st.familyName; }

	friend ostream& operator << (ostream&, Student);
	friend istream& operator >> (istream&, Student&);
};

