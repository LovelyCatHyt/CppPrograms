#include <iostream>
#include "Time.h"

using std::cout;
using std::cin;
using std::cerr;
using std::clog;

int main()
{
	Time t;
	cerr << "请输入时间(h,m,s):";
	cin >> t;
	cerr << "输出该时间对应的小数:";
	cout << t;
	return 0;
}