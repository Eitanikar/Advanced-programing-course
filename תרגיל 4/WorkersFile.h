#pragma once
#include"Worker.h"
#include <iostream>
#include<fstream>
using namespace std;


enum FILE_STATUS { ERROR, CLOSED, OPEN_R, OPEN_W };

class WorkersFile {
	string FileName;
	fstream iofile;
	FILE_STATUS status;
	int size;

	bool openNewFileForWriting();//create new file
	bool openFileForReading();//open file for reading
	void closeFile();//close file

public:
	WorkersFile(string);//constructor
	WorkersFile(const WorkersFile& w);//copy constructor
	~WorkersFile();//destructor

	friend istream& operator>>(istream&, WorkersFile&);//read from console
	friend ostream& operator<<(ostream&, WorkersFile&);//write to console

	void sort(bool flag = true);//sort by salary

	Worker operator[](int n);//return worker by index
	WorkersFile& operator+=(float);//increase salary
	WorkersFile operator+(WorkersFile&);//merge two files
};