#pragma once
#include <xstring>
#include <vector>
#include <ostream>
#include "StudentList.h"
//#ifndef _STUDENT_H
//#define _STUDENT_H

using std::string;
using std::vector;
using std::ostream;

class Student
{
	string id;
	string name;
	bool isMale;
	short age;
	int score_Chinese;
	int score_Math;
	int score_English;
	static const int cutoffScore = 60;
	friend class StudentList;
public:
	Student();
	Student(string name);
	void Input();
	void PrintInLine();
	int CompareByCh(const void* a,const void* b) { return ((Student*)a)->score_Chinese < ((Student*)b)->score_Chinese; }
	float GetAverage();
	friend ostream& operator<<(ostream& out, Student student);
};

//#endif // !_STUDENT_H