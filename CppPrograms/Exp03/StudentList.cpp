#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "StudentList.h"
#include "Student.h"
#include "ColorfulConsole/TextAttribute.h"

using std::cout;
using std::cin;
using std::endl;
using WTA = ColorfulConsole::TextAttribute::WarpedTextAttr;

StudentList::StudentList()
{
	stuArray = NULL;
	size = 0;
}

StudentList::StudentList(int size) :size(size)
{
	stuArray = new Student[size];
}

StudentList::~StudentList()
{
	delete[] stuArray;
	cout << "本程序由" << WTA::LIGHTBLUE << "胡韵涛" << WTA::WHITE << "编写\n";
}

int StudentList::GetSize()
{
	return size;
}

void StudentList::Extend(unsigned int offset)
{
	Student* newList = new Student[size + offset];
	//Copy
	for (int i = 0; i < size; i++)
	{
		newList[i] = stuArray[i];
	}
	//Redir
	delete[] stuArray;
	stuArray = newList;
	size++;
}

Student& StudentList::Add(Student newStudent)
{
	Extend(1);
	return stuArray[size - 1] = newStudent;
}

void StudentList::PrintTable()
{
	cout << WTA::LIGHTBLUE << "ID        Name      Gender  Age   Chinese Math    English Average \n" << WTA::WHITE;
	for (int i = 0; i < size; i++) stuArray[i].PrintInLine();
	////平均成绩
	//int total_Chinese = 0;
	//int total_Math = 0;
	//int total_English = 0;
	//for (int i = 0; i < size; i++)
	//{
	//	total_Chinese += stuArray[i].score_Chinese;
	//	total_Math += stuArray[i].score_Math;
	//	total_English += stuArray[i].score_English;
	//}
	//total_Chinese /= size;
	//total_Math /= size;
	//total_English /= size;
	//WTA::LIGHTGREEN.Apply();
	//cout << "          Average                 ";
	//if (total_Chinese < Student::cutoffScore) WTA::LIGHTRED.Apply();
	//cout << std::left << std::setw(8) << total_Chinese;
	//WTA::LIGHTGREEN.Apply();
	//if (total_Math < Student::cutoffScore) WTA::LIGHTRED.Apply();
	//cout << std::left << std::setw(8) << total_Math;
	//WTA::LIGHTGREEN.Apply();
	//if (total_English < Student::cutoffScore) WTA::LIGHTRED.Apply();
	//cout << std::left << std::setw(8) << total_English;
	//WTA::LIGHTGREEN.Apply();
	//float average = ((float)total_Chinese + (float)total_Math + (float)total_English) / 3.0f;
	//if (average < Student::cutoffScore) WTA::LIGHTRED.Apply();
	//cout << std::left << std::setw(8) << average;
	//收尾
	cout << WTA::WHITE << endl;
}

void StudentList::PrintLimits()
{
	StudentList tempTable(0);
	//Create
	tempTable.Add(Student("Max"));
	tempTable.Add(Student("Min"));
	tempTable.Add(Student("Average"));
	//Set Ref
	Student& max	= tempTable[0];
	Student& min	= tempTable[1];
	Student& aver	= tempTable[2];
	//Init
	max.score_Chinese	= min.score_Chinese	= stuArray[0].score_Chinese;
	max.score_Math		= min.score_Math	= stuArray[0].score_Math;
	max.score_English	= min.score_English = stuArray[0].score_English;
	aver.score_Chinese	= aver.score_English= aver.score_Math = 0;
	for (int i = 0; i < size; i++)
	{
		//max(PS:Tab排版是真的舒服)
		max.score_Chinese	= (max.score_Chinese	< stuArray[i].score_Chinese)	? stuArray[i].score_Chinese : max.score_Chinese;
		max.score_Math		= (max.score_Math		< stuArray[i].score_Math)		? stuArray[i].score_Math	: max.score_Math;
		max.score_English	= (max.score_English	< stuArray[i].score_English)	? stuArray[i].score_English : max.score_English;
		//min
		min.score_Chinese	= (min.score_Chinese	> stuArray[i].score_Chinese)	? stuArray[i].score_Chinese : min.score_Chinese;
		min.score_Math		= (min.score_Math		> stuArray[i].score_Math)		? stuArray[i].score_Math	: min.score_Math;
		min.score_English	= (min.score_English	> stuArray[i].score_English)	? stuArray[i].score_English : min.score_English;
		//aver
		aver.score_Chinese	+= stuArray[i].score_Chinese;
		aver.score_Math		+= stuArray[i].score_Math;
		aver.score_English	+= stuArray[i].score_English;
	}
	aver.score_Chinese	/= (float)size;
	aver.score_Math		/= (float)size;
	aver.score_English	/= (float)size;
	//Print them
	tempTable.PrintTable();
}

Student& StudentList::operator[](int index)
{
	return stuArray[index];
}
void StudentList::SortByAv()
{
	Sort([](void const* a, void const* b)->int {return ((Student*)a)->GetAverage() > ((Student*)b)->GetAverage(); });
}
inline void StudentList::Sort(int(__cdecl* compareFunc)(void const*, void const*))
{
	//一行搞定
	qsort(stuArray, size, sizeof(Student), compareFunc);
}

Student StudentList::SearchByID(string id)
{
	for (int i = 0; i < size; i++)
	{
		if (stuArray[i].id == id) return stuArray[i];
	}
	return Student("*NotFound*");
}

