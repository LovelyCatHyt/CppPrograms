#pragma once
#include "Person.h"
#include "Student.h"
//学生
class Student : virtual public Person
{
protected:
	//学号
	uint stuNumber;
	//班级
	unsigned short classNumber;
	//专业
	string major;
	//入学成绩
	float entranceScore;
public:
	Student();
	virtual ~Student();
	virtual void PrintData() const;
	virtual void Edit();
	virtual void SetData(char flag);
	virtual void LoopSetData();
};

