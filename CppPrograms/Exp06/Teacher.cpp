#include "Teacher.h"
#include <iostream>
#include "../ColorfulConsole/TextAttribute.h"

using std::cout;
using std::endl;
using std::cin;
using WTA = ColorfulConsole::TextAttribute::WarpedTextAttr;

uint Teacher::GetJobNumber() const
{
	return jobNumber;
}

void Teacher::SetJobNumber(uint number)
{
	jobNumber = number;
}

string Teacher::GetRank() const
{
	return rank;
}

void Teacher::SetRank(uint rank)
{
	this->rank = rank;
}

float Teacher::GetSalary() const
{
	return salary;
}

void Teacher::SetSalary(float salary)
{
	this->salary = salary;
}

Teacher::Teacher(): Person()
{
	jobNumber = 0;
	rank = "[Empty]";
	salary = 0;
}

Teacher::~Teacher()
{
	//DoNothing
}

void Teacher::PrintData() const
{
	WTA gray = WTA::WHITE;
	WTA white = WTA::WHITE;
	gray.fore_Intense = false;
	cout << "类型:教师" << gray << " 姓名:" << white << name << gray << " 年龄:" << white << age << gray << " 性别:" << white << gender
		<< gray << " 工号:" << white << jobNumber << gray << " 职称:" << white << rank << " 工资:" << white << salary;
}

void Teacher::Edit()
{
	char flag;
	cout << WTA::LIGHTBLUE << "请选择要编辑的项目:\n" << WTA::WHITE
		<< "[a]姓名\n"
		"[b]年龄\n"
		"[c]性别\n"
		"[d]工号\n"
		"[e]职称\n"
		"[f]工资\n>";
	cin >> flag;
	SetData(std::tolower(flag));
}

void Teacher::SetData(char flag)
{
	if (flag < 'd')
	{
		Person::SetData(flag);
	}
	else
	{
		switch (flag)
		{
		case 'd':cout << "请输入工号:\n>";	cin >> jobNumber;	cout << "工号为:" << jobNumber << '\n';	break;
		case 'e':cout << "请输入职称:\n>";	cin >> rank;		cout << "职称为:" << rank << '\n';		break;
		case 'f':cout << "请输入工资:\n>";	cin >> salary;		cout << "工资为:" << salary << '\n';		break;
		default:
			cout << WTA::LIGHTRED << "未知参数. 当前类:Teacher";
			break;
		}
	}
}

void Teacher::LoopSetData()
{
	for (int i = 0; i < 6; i++) SetData('a' + i);
}
