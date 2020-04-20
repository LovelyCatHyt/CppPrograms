#include <iostream>
#pragma once

using std::string;
using std::ostream;
using std::istream;

class Student
{
private:
	//学号
	long long no;
	//姓名
	char name[8];
	//性别:'m'->Male, 'f'->Female
	char gender;
	//专业
	char major[15];
	//电话号码
	char phoneNumber[12];
	//地址
	char address[30];
public:
	Student();
	void WriteToFile(string fileName);
	friend ostream& operator<<(ostream& out, const Student& stu);
	friend istream& operator>>(istream& in, Student& stu);
	static Student ReadFromFile(string fileName);
};

