#include <iostream>
#include "Student.h"
#include "../ColorfulConsole/TextAttribute.h"

using std::cout;
using std::endl;
using std::cin;
using WTA = ColorfulConsole::TextAttribute::WarpedTextAttr;

Student::Student() : Person()
{
	stuNumber = 0;
	classNumber = 0;
	major = "[Empty]";
	entranceScore = 0;
}

Student::~Student()
{
	//Do nothing
}

void Student::PrintData() const
{
	WTA gray = WTA::WHITE;
	WTA white = WTA::WHITE;
	gray.fore_Intense = false;
	cout << "类型:学生" << gray << " 姓名:" << white << name << gray << " 年龄:" << white << age << gray << " 性别:" << white << gender
		<< gray << " 学号:" << white << stuNumber << gray << " 班级:" << white << classNumber << " 专业:" << major << gray << " 入学成绩:" << white << entranceScore;
}

void Student::Edit()
{
	char flag;
	cout << WTA::LIGHTBLUE << "请选择要编辑的项目:\n" << WTA::WHITE
		<< "[a]姓名\n"
		"[b]年龄\n"
		"[c]性别\n"
		"[d]学号\n"
		"[e]班级\n"
		"[f]专业\n"
		"[g]入学成绩\n>";
	cin >> flag;
	SetData(std::tolower(flag));
}

void Student::SetData(char flag)
{
	if (flag < 'd')
	{
		Person::SetData(flag);
	}
	else
	{
		switch (flag)
		{
		case 'd':cout << "请输入学号:\n>";			cin >> stuNumber;		cout << "学号为:" << stuNumber << '\n';			break;
		case 'e':cout << "请输入班级(两位数):\n>";	cin >> classNumber;		cout << "班级为:" << classNumber << '\n';		break;
		case 'f':cout << "请输入专业:\n>";			cin >> major;			cout << "专业为:" << major << '\n';				break;
		case 'g':cout << "请输入入学成绩:\n>";		cin >> entranceScore;	cout << "入学成绩为:" << entranceScore << '\n';	break;
		default:
			cout << WTA::LIGHTRED << "未知参数. 当前类:Student";
			break;
		}
	}
}

void Student::LoopSetData()
{
	for (int i = 0; i < 7; i++) SetData('a' + i);
}

