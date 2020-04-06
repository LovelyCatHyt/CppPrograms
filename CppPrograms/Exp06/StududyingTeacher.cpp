#include "StududyingTeacher.h"
#include "Teacher.h"
#include "Student.h"
#include <iostream>
#include "../ColorfulConsole/TextAttribute.h"

using std::cout;
using std::endl;
using std::cin;
using WTA = ColorfulConsole::TextAttribute::WarpedTextAttr;

StududyingTeacher::StududyingTeacher():Teacher(),Student()
{
}

StududyingTeacher::~StududyingTeacher()
{
	//DoNothing
}

void StududyingTeacher::PrintData() const
{
	WTA gray = WTA::WHITE;
	WTA white = WTA::WHITE;
	gray.fore_Intense = false;
	cout << "类型:在读教师" << gray << " 姓名:" << white << name << gray << " 年龄:" << white << age << gray << " 性别:" << white << gender
		<< gray << " 学号:" << white << stuNumber << gray << " 班级:" << white << classNumber << " 专业:" << major
		<< gray << " 工号:" << white << GetJobNumber() << gray << " 职称:" << white << GetRank() << " 工资:" << white << GetSalary();
}

void StududyingTeacher::Edit()
{
	char flag;
	cout << WTA::LIGHTBLUE << "请选择要编辑的项目:\n" << WTA::WHITE
		<< "[a]姓名\n"
		"[b]年龄\n"
		"[c]性别\n"
		"[d]学号\n"
		"[e]班级\n"
		"[f]专业\n"
		"[g]入学成绩\n"
		"[h]工号\n"
		"[i]职称\n"
		"[j]工资\n>";
	cin >> flag;
	SetData(std::tolower(flag));
}

void StududyingTeacher::SetData(char flag)
{
	if (flag < 'h')
	{
		Student::SetData(flag);
	}
	else if (flag < 'k')
	{
		Teacher::SetData(flag - 4);
	}
	else
	{
		cout << WTA::LIGHTRED << "未知参数. 当前类:StudyingTeacher";
	}
}

void StududyingTeacher::LoopSetData()
{
	for (int i = 0; i < 10; i++) SetData('a' + i);
}
