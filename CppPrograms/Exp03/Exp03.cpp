#include <iostream>
#include <vector>
#include "Student.h"
#include "ColorfulConsole/TextAttribute.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using namespace ColorfulConsole::TextAttribute;

int main()
{
	cout << WarpedTextAttr::LIGHTBLUE << "aaaa" << endl;
	cout << WarpedTextAttr::WHITE<<"bbbb";
	return 0;
	cout << "Welcome to student score manage system!" << endl;
	//开始输入
	int i = 0;
	bool _continue = true;
	vector<Student> stuList(0);
	while (_continue)
	{
		cout << "Please enter the [" << i+1 << "] student's data." << endl;
		stuList.emplace_back();
		stuList[i].Input();
		cout << "Continue to input?('y'for continue, the others for finish.)" << endl<<">";
		char temp = 'y';
		cin >> temp;
		_continue = (temp == 'y') || (temp == 'Y');
		i++;
	}
	Student::PrintTable(stuList);
	cout << "Failing grades are marked in ";
	WarpedTextAttr::LIGHTRed.Apply();
	cout<<"red";
	WarpedTextAttr::WHITE.Apply();
	cout << "." << endl;
	return 0;
}