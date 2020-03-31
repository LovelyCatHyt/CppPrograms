#include <iostream>
#include "Date.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
	Date now(2000, 1, 1);
	cout << "待测试的日期是: "; now.Print();
	cout << "100天后是: "; (now + 100).Print();
	cout << "32天前是: "; (now - 32).Print();
	cout << "与2001年2月28日相差: " << (Date(2001, 2, 28) - std::move(now)) << "天\n";
	return 0;
}