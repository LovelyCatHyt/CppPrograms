#include <iostream>
#include <iomanip>
#include "Student.h"
#include "ColorfulConsole/TextAttribute.h"

using std::cout;
using std::cin;
using std::endl;
using WTA = ColorfulConsole::TextAttribute::WarpedTextAttr;

Student::Student()
{
	id = name = "";
	isMale = true;
	age = 0;
	score_Chinese = score_Math = score_English = 0;
}

Student::Student(string name)
{
	this->name = name;
	id = "x";
	isMale = true;
	age = 0;
	score_Chinese = score_Math = score_Math = 0;
}

void Student::Input()
{
	WTA::WHITE.Apply();
	cout << "Please enter the student's id:\n>";
	cin >> id;
	cout << "Please enter the student's name:\n>";
	cin >> name;
	cout << "Please enter the student's gender, 1 for male, 0 for female:\n>";
	cin >> isMale;
	if (cin.fail())
	{
		cin.clear();
		isMale = false;
	}
	cout << "Please enter the student's age:\n>";
	cin >> age;
	cout << "Please enter the student's Chinese score:\n>";
	cin >> score_Chinese;
	cout << "Please enter the student's Math score:\n>";
	cin >> score_Math;
	cout << "Please enter the student's English score:\n>";
	cin >> score_English;
	cout << WTA::LIGHTGREEN << "Student \"" << name << "\"(" << id << ") data input finished.\n" << WTA::WHITE;
}

void Student::PrintInLine()
{
	if (id != "x") 
	{
		//如果不是特殊标记
		cout << std::left << std::setw(10) << WTA::WHITE << id;
		cout << std::left << std::setw(10) << name;
		cout << std::left << std::setw(8) << (isMale ? "Male" : "Female");
		cout << std::left << std::setw(6) << age;
	}
	else
	{
		cout << std::left << std::setw(10) << "" << std::setw(10) << name << std::setw(14) << "";
	}
	if (score_Chinese < cutoffScore) WTA::LIGHTRED.Apply();
	cout << std::left << std::setw(8) << score_Chinese;
	WTA::WHITE.Apply();
	if (score_Math < cutoffScore) WTA::LIGHTRED.Apply();
	cout << std::left << std::setw(8) << score_Math;
	WTA::WHITE.Apply();
	if (score_English < cutoffScore) WTA::LIGHTRED.Apply();
	cout << std::left << std::setw(8) << score_English;
	WTA::WHITE.Apply();
	float average = ((float)score_Chinese + (float)score_Math + (float)score_English) / 3.0f;
	if (average < cutoffScore) WTA::LIGHTRED.Apply();
	cout << std::left << std::setw(8) << average;
	WTA::WHITE.Apply();
	cout << endl;
}

float Student::GetAverage()
{
	return 1.0 / 3.0 * (score_Chinese + score_Math + score_Math);
}

ostream& operator<<(ostream& out, Student student)
{
	student.PrintInLine();
	return out;
}

