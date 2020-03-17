#pragma once
#include <xstring>
#include <vector>
using std::string;
using std::vector;

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
public:
	Student();
	void Input();
	void PrintInLine();
	static void PrintTable(vector<Student> stuList);
};

