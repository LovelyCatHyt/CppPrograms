#include <iostream>
#include "Person.h"
#include "../ColorfulConsole/TextAttribute.h"

using std::cout;
using std::endl;
using std::cin;
using WTA = ColorfulConsole::TextAttribute::WarpedTextAttr;

Person::Person()
{
	name = "[Empty]";
	age = 0;
	gender = "[Empty]";
}

Person::~Person()
{
	//cout << "~Person() called. Name:" << name;
}

string Person::GetName()
{
	return name;
}

uint Person::GetAge()
{
	return age;
}

string Person::GetGender()
{
	return gender;
}

void Person::PrintData() const
{
	WTA gray = WTA::WHITE;
	WTA white = WTA::WHITE;
	gray.fore_Intense = false;
	cout << "类型:普通" << gray << " 姓名:" << white << name << gray << " 年龄:" << white << age << gray << " 性别:" << white << gender;
}
void Person::Edit()
{
	char flag;
	cout << WTA::LIGHTBLUE << "请选择要编辑的项目:\n" << WTA::WHITE
		<< "[a]姓名\n"
		"[b]年龄\n"
		"[c]性别\n>";
	cin >> flag;
	SetData(flag);
}

void Person::SetData(char flag)
{
	switch (flag)
	{
	case 'a':
		cout << "请输入姓名:\n>";
		cin >> name;
		cout << "姓名为:" << name << '\n';
		break;
	case 'b':
		cout << "请输入年龄:\n>";
		cin >> age;
		cout << "年龄为:" << age << '\n';
		break;
	case 'c':
		cout << "请输入性别:\n>";
		cin >> gender;
		cout << "性别为:" << gender << '\n';
		break;
	default:
		cout << WTA::LIGHTRED << "未知编辑参数. 所在类:Person";
	}
}

void Person::LoopSetData()
{
	for (int i = 0; i < 3; i++) SetData('a' + i);
}

ostream& operator<<(ostream& out, const Person& person)
{
	person.PrintData();
	return out;
}
