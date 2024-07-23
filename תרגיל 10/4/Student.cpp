#include "Student.h"

ostream& operator<<(ostream& os, Student std)
{
	os << std.id << ' ' << std.name << ' ' << std.familyName;

	return os;
}

istream& operator>>(istream& is, Student& std)
{
	is >> std.id >> std.name >> std.familyName;
	return is;
}
