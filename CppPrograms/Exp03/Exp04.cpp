#include <iostream>
#include <vector>
#include "Student.h"
#include "StudentList.h"
#include "StudentList.h"
#include "../ColorfulConsole/TextAttribute.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using WTA = ColorfulConsole::TextAttribute::WarpedTextAttr;

int main()
{
	/*
	cout << WTA::LIGHTBLUE << "aaaa" << endl;
	cout << WTA::WHITE<<"bbbb";
	return 0;*/
	cout << "Welcome to student score manage system!" << endl;
	//开始输入
	int i = 0;
	bool _continue = true;
	StudentList list(0);
	while (_continue)
	{
		WTA gray = WTA::WHITE;
		gray.fore_Intense = false;
		cout << "Please enter the [" << i+1 << "] student's data." << endl;
		list.Add(Student());
		list[i].Input();
		cout << "Continue to input?" << gray << "('y'for continue, the others for finish.)" << WTA::WHITE << endl << ">";
		char temp = 'y';
		cin >> temp;
		_continue = (temp == 'y') || (temp == 'Y');
		i++;
	}
	cout << "Failing grades are marked in " << WTA::LIGHTRED << "red" << WTA::WHITE << "." << endl;
	cout << "Current Data:\n";
	list.PrintTable();
	cout << "Sort by average:\n";
	list.SortByAv();
	list.PrintTable();
	cout << "Maxs and mins:\n";
	list.PrintLimits();
	cout << "↑第一次析构: 临时表格的析构\n";
	cout << "Type an ID to search for a student:\n>";
	string idTemp;
	cin >> idTemp;
	cout << "ID(" << idTemp << ") data:\n";
	cout << WTA::LIGHTBLUE << "ID        Name      Gender  Age   Chinese Math    English Average \n" << WTA::WHITE;
	list.SearchByID(idTemp).PrintInLine();
	cout << "↓第二次析构: 主表格的析构\n";
	return 0;
}

