#include <iostream>
#include <string>
using namespace std;

int main()
{
	char cString[30];
	string str;
	cout << ">Enter a string:" << endl;
	cin.getline(cString,30);
	str = cString;
	cout << "The string is :\"" << str << "\"\0balabala" << endl;
}