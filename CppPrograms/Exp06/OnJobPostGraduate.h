#pragma once
#include "Teacher.h"
#include "Student.h"

//在职研究生
class OnJobPostGraduate : public Student
{
protected:
	//工作单位
	string workUnit;
public:
	OnJobPostGraduate();
	~OnJobPostGraduate();
	string GetWorkUnit();
	void PrintData() const;
	void Edit();
	void SetData(char flag);
	void LoopSetData();
};

