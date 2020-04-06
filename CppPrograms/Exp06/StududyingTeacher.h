#pragma once
#include "Teacher.h"
#include "Student.h"
class StududyingTeacher : public Teacher, public Student
{
public:
	StududyingTeacher();
	~StududyingTeacher();
	void PrintData() const;
	void Edit();
	void SetData(char flag);
	void LoopSetData();
};

