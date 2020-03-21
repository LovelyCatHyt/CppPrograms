#include <iostream>
#include <iomanip>
#include "Student.h"
#include "ColorfulConsole/TextAttribute.h"

using std::cout;
using std::cin;
using std::endl;
using namespace ColorfulConsole::TextAttribute;

Student::Student()
{
	id = name = "";
	isMale = true;
	age = 0;
	score_Chinese = score_Math = score_English = 0;
}

void Student::Input()
{
	WarpedTextAttr::WHITE.Apply();
	cout << "Please enter the student's id:" << endl << ">";
	cin >> id;
	cout << "Please enter the student's name:" << endl << ">";
	cin >> name;
	cout << "Please enter the student's gender, 1 for male, 0 for female:" << endl << ">";
	cin >> isMale;
	if (cin.fail()) 
	{
		cin.clear();
		isMale = false;
	}
	cout << "Please enter the student's age:" << endl << ">";
	cin >> age;
	cout << "Please enter the student's Chinese score:" << endl << ">";
	cin >> score_Chinese;
	cout << "Please enter the student's Math score:" << endl << ">";
	cin >> score_Math;
	cout << "Please enter the student's English score:" << endl << ">";
	cin >> score_English;
	WarpedTextAttr::LIGHTGreen.Apply();
	cout << "Student \"" << name << "\"\(" << id << "\) data input finished.";
	WarpedTextAttr::WHITE.Apply();
}

void Student::PrintInLine()
{
	WarpedTextAttr::WHITE.Apply();
	cout << std::left << std::setw(10) << id;
	cout << std::left << std::setw(10) << name;
	cout << std::left << std::setw(8) << (isMale ? "Male" : "Female");
	cout << std::left << std::setw(6) << age;
	if (score_Chinese < cutoffScore) WarpedTextAttr::LIGHTRed.Apply();
	cout << std::left << std::setw(8) << score_Chinese;
	WarpedTextAttr::WHITE.Apply();
	if (score_Math < cutoffScore) WarpedTextAttr::LIGHTRed.Apply();
	cout << std::left << std::setw(8) << score_Math;
	WarpedTextAttr::WHITE.Apply();
	if (score_English < cutoffScore) WarpedTextAttr::LIGHTRed.Apply();
	cout << std::left << std::setw(8) << score_English;
	WarpedTextAttr::WHITE.Apply();
	float average = ((float)score_Chinese + (float)score_Math + (float)score_English) / 3.0f;
	if (average < cutoffScore) WarpedTextAttr::LIGHTRed.Apply();
	cout << std::left << std::setw(8) << average;
	WarpedTextAttr::WHITE.Apply();
	cout << endl;
}

void Student::PrintTable(vector<Student> stuList)
{
	WarpedTextAttr::LIGHTBLUE.Apply();
	cout << "ID        Name      Gender  Age   Chinese Math    English Average " << endl;
	WarpedTextAttr::WHITE.Apply();
	vector<Student>::iterator i;
	for (i = stuList.begin(); i != stuList.end(); i++) i->PrintInLine();
	//平均成绩
	int total_Chinese = 0;
	int total_Math = 0;
	int total_English = 0;
	for (vector<Student>::iterator i = stuList.begin(); i != stuList.end(); i++)
	{
		total_Chinese += i->score_Chinese;
		total_Math += i->score_Math;
		total_English += i->score_English;
	}
	total_Chinese /= stuList.size();
	total_Math /= stuList.size();
	total_English /= stuList.size();
	WarpedTextAttr::LIGHTGreen.Apply();
	cout << "----------Average-----------------";
	if (total_Chinese < cutoffScore) WarpedTextAttr::LIGHTRed.Apply();
	cout << std::left << std::setw(8) << total_Chinese;
	WarpedTextAttr::LIGHTGreen.Apply();
	if (total_Math < cutoffScore) WarpedTextAttr::LIGHTRed.Apply();
	cout << std::left << std::setw(8) << total_Math;
	WarpedTextAttr::LIGHTGreen.Apply();
	if (total_English < cutoffScore) WarpedTextAttr::LIGHTRed.Apply();
	cout << std::left << std::setw(8) << total_English;
	WarpedTextAttr::LIGHTGreen.Apply();
	float average = ((float)total_Chinese + (float)total_Math + (float)total_English) / 3.0f;
	if (average < cutoffScore) WarpedTextAttr::LIGHTRed.Apply();
	cout << std::left << std::setw(8) << average;
	//收尾
	cout << endl;
	WarpedTextAttr::WHITE.Apply();
}