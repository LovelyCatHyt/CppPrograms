#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int a, b, c;
	cout << "Please enter three number." << endl;
	cin >> a >> b >> c;
	if (a < b)
	{
		std::swap(a, b);
	}
	if (b < c)
	{
		std::swap(b, c);
	}
	if (a < b)
	{
		std::swap(a, b);
	}
	cout << "Answer is:\na:" << a << "\nb:" << b << "\nc:" << c;
	return 0;
}