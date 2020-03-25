#pragma	once
class Student;
#include "ColorfulConsole/TextAttribute.h"
#include <iostream>
using std::string;

class StudentList
{
private:
	Student* stuArray;
	int size;
public:
	StudentList();
	StudentList(int size);
	~StudentList();
	int GetSize();
	void Extend(unsigned int offset);
	Student& Add(Student newStudent);
	void SortByAv();
	void Sort(int(__cdecl* compareFunc)(void const*, void const*));
	Student SearchByID(string id);
	void PrintTable();
	void PrintLimits();
	Student& operator[](int index);
};
