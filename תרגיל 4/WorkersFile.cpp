#include "WorkersFile.h"
#include<string>
#include<iostream>
//#include "Worker.h"
using namespace std;

bool WorkersFile::openNewFileForWriting() {//open file for writing

    if (status != CLOSED) {
        cout << "ERROR" << endl;
        return false;
    }

    this->iofile.open(this->FileName, fstream::out);
    if (!(this->iofile)) {
        this->status = ERROR;
        cout << "ERROR" << endl;
        return false;
    }
    this->status = OPEN_W;
    return true;
}

bool WorkersFile::openFileForReading() {//open file for reading

    if (this->status != CLOSED) {
        cout << "ERROR" << endl;
        return false;
    }

   this->iofile.open(this->FileName , fstream::in);
    if (!(this->iofile)) {
        this->status = ERROR;
        cout << "ERROR" << endl;
        return false;
    }
    status = OPEN_R;
    return true;
}

void WorkersFile::closeFile() {//close file
    if (this->iofile) {
        this->iofile.close();
        this->status = CLOSED;
    }
}

WorkersFile::WorkersFile(string name) {//constructor
    this->FileName = name;
    this->size = 0;
    this->status = CLOSED;
    this->openNewFileForWriting();
    this->closeFile();
}

WorkersFile::WorkersFile(const WorkersFile& w) {//copy constructor
    this->FileName = w.FileName;
    this->size = w.size;
    this->status = CLOSED;
}

WorkersFile::~WorkersFile() {
    this->closeFile();
}

istream& operator>>(istream& is, WorkersFile& wf) {//read workers
    Worker w;
    if (wf.status == OPEN_W)
        exit(-1);
    if (wf.status == CLOSED)
        wf.openNewFileForWriting();
    wf.size = 0;
    is >> w;
    while (!(0 == w))
    {
        wf.iofile << w;
        wf.size++;
        is >> w;
    }
    wf.closeFile();
    return is;
}

ostream& operator<<(ostream& os, WorkersFile& wf) {//print workers
    Worker w;
    if (wf.status == CLOSED)
        wf.openFileForReading();
    if (wf.status != OPEN_R)
        exit(-1);

    for (int s = 0; s < wf.size; s++)
    {
        wf.iofile >> w;
        os << w;
    }
    wf.closeFile();
    return os;
}

void WorkersFile::sort(bool flag){
    Worker tmp;
    Worker* arr = new Worker[this->size];
    if (this->status != CLOSED) exit(-1);
    this->openFileForReading();
    for (int i = 0; i < this->size; i++)
    {
        this->iofile >> arr[i];
    }
    this->closeFile();
    for (int i = 1; i < this->size; i++)
    {
        for (int j = 0; j < this->size - i; j++)
        {
            if (flag && arr[j + 1] < arr[j])
            {
                tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
            else if (!flag && arr[j] < arr[j + 1])
            {
                tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    this->openNewFileForWriting();
    for (int i = 0; i < this->size; i++)
    {
        this->iofile << arr[i];
    }
    this->closeFile();
    delete[] arr;
}

Worker WorkersFile::operator[](int n) {//return worker by index

    Worker temp;
    if (!(n < this->size))
        exit(-1);
    if (this->status != CLOSED)
        exit(-1);
    this->openFileForReading();
    for (int s = 0; s <= n; s++)
        this->iofile >> temp;
    this->closeFile();
    return temp;
}

WorkersFile& WorkersFile::operator+=(float bonus) {//add bonus to all workers
    Worker* arr = new Worker[size];
    if (this->status != CLOSED)
        exit(-1);
    this->openFileForReading();

    for (int i = 0; i < size; i++) {
        iofile >> arr[i];
    }
    this->closeFile();
    for (int i = 0; i < size; i++) {
        arr[i] += bonus;
    }
    this->openNewFileForWriting();
    for (int i = 0; i < size; i++) {
        iofile << arr[i];
    }
    this->closeFile();
    return *this;
}

WorkersFile WorkersFile::operator+(WorkersFile& w) {//merge two files
    //fstream i;
    WorkersFile merge("file.txt");
    merge.openNewFileForWriting();
    merge.iofile << *this;
    merge.iofile << w;
    merge.size = w.size + this->size;
    merge.closeFile();
    return merge;
}