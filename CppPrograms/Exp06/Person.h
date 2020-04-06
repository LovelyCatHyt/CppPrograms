#pragma once
#include <string>
#include <ostream>
using std::string;
using std::ostream;
typedef unsigned int uint;
//人
class Person
{
protected:
	//姓名
	string name;
	//年龄
	uint age;
	//性别
	string gender;
public:
	Person();
	virtual ~Person();
	string GetName();
	uint GetAge();
	string GetGender();
	//打印数据
	virtual void PrintData() const;
	//编辑数据
	virtual void Edit();
	//根据具体参数设置数据
	virtual void SetData(char flag);
	//遍历每个数据进行设置
	virtual void LoopSetData();
	friend ostream& operator<<(ostream& out, const Person& person);
};

