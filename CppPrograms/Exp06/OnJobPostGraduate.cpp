#include "OnJobPostGraduate.h"
#include "Teacher.h"
#include "Student.h"
#include <iostream>
#include "../ColorfulConsole/TextAttribute.h"

using std::cout;
using std::endl;
using std::cin;
using WTA = ColorfulConsole::TextAttribute::WarpedTextAttr;

OnJobPostGraduate::OnJobPostGraduate() : Student()
{
	workUnit = "[Empty]";
}

OnJobPostGraduate::~OnJobPostGraduate()
{
	//DoNothing
}

string OnJobPostGraduate::GetWorkUnit()
{
	return workUnit;
}

void OnJobPostGraduate::PrintData() const
{
	WTA gray = WTA::WHITE;
	WTA white = WTA::WHITE;
	gray.fore_Intense = false;
	cout << "类型:在职研究生" << gray << " 姓名:" << white << name << gray << " 年龄:" << white << age << gray << " 性别:" << white << gender
		<< gray << " 学号:" << white << stuNumber << gray << " 班级:" << white << classNumber << " 专业:" << major << gray << " 入学成绩:" << white << entranceScore
		<< gray << " 工作单位:" << white << workUnit;
}

void OnJobPostGraduate::Edit()
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
		"[h]工作单位\n>";
	cin >> flag;
	SetData(std::tolower(flag));
}

void OnJobPostGraduate::SetData(char flag)
{
	if (flag < 'h')
	{
		Student::SetData(flag);
	}else if(flag == 'h')
	{
		cout << "请输入工作单位:\n>";
		cin >> workUnit;
		cout << "专业为:" << workUnit << '\n';
	}
	else
	{
		cout << WTA::LIGHTRED << "未知参数. 当前类:OnJobPostGraduate";
	}
}

void OnJobPostGraduate::LoopSetData()
{
	for (int i = 0; i < 8; i++) SetData('a' + i);
}
