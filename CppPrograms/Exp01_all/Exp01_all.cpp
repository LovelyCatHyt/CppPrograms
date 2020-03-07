//#include <iostream>
//using namespace std;
//int main()
//{
//	return 0;
//}

//7.
#include <iostream>
using namespace std;
int main()
{
	string toOperate;
	cout << ">Please enter a positive integer:"<<endl;
	cin >> toOperate;
	int digit = toOperate.length();//位数可直接得到
	cout << ">Digit: " << digit << endl;
	//分别输出每位数
	cout << ">Print seperatedly: ";
	for (int i = 0; i < digit - 1; i++)
	{
		cout << toOperate[i] << " | ";
	}
	cout << toOperate[digit - 1] << endl;
	//逆序输出每位数
	cout << ">Reversed: ";
	for (int i = digit -1; i >=0; i--)
	{
		cout << toOperate[i];
	}
	return 0;
}

//6.
//#include <iostream>
//#include <string>
//using namespace std;
//
//void CountCharType(string toCount, int& letter, int& number, int& space, int& _else)
//{
//	int length = toCount.length();
//	letter = number = space = 0;
//	for (int i = 0; i < length; i++)
//	{
//		if ((toCount[i] >= 'A' && toCount[i] <= 'Z') || (toCount[i] >= 'a' && toCount[i] <= 'z')) letter++;
//		if (toCount[i] >= '0' && toCount[i] <= '9') number++;
//		if (toCount[i] == ' ') space++;
//	}
//	_else = length - letter - number - space;
//}
//
//int main()
//{
//	string input;
//	int letter = 0, number = 0, space = 0, _else = 0;
//	cout << ">Please input a string:" << endl;
//	getline(cin, input);
//	CountCharType(input, letter, number, space, _else);
//	cout << ">Letter: " << letter << ", Number: " << number << ", Space: " << space << ", Else:" << _else << endl;
//	return 0;
//}

//5.
//#include <iostream>
//using namespace std;
//void SimpleEncoder(char cString[], int size)
//{
//	for (int i = 0; i < size && cString[i] != 0; i++)
//	{
//		cString[i] += 4;
//	}
//}
//
//int main()
//{
//	char cString[64];
//	cout << ">Please cString a string to encode:" << endl;
//	cin >> cString;
//	SimpleEncoder(cString, 64);
//	cout << ">Result:\""<<cString<<"\"\n";
//	return 0;
//}

//4.
//#include<iostream>
//using namespace std;
//int main()
//{
//	int i, j, m, n;
//	i = 8;
//	j = 10;
//	m = ++i + j++;   //在此给出m的值=19,i=9,j=11
//	n = (++i) + (++j) + m;  //在此给出n的值=41,i=10,j=12
//	cout << i << '\t' << j << '\t' << m << '\t' << n << endl;
//	return 0;
//}


//3.
//#include <iostream>
//using namespace std;
//int main()
//{
//	int a, b, c;
//	int f(int x, int y, int z);
//	cin >> a >> b >> c;
//	c = f(a, b, c);
//	cout << c << endl;
//	return 0;
//}
//int f(int x, int y, int z)
//{
//	int m;
//	if (x < y)  m = x;
//	else m = y;
//	if (z < m)  m = z;
//	return(m);
//}


//2.
//#include <iostream>
//using namespace std;
//int main()
//{
//	int a, b, c;
//	a = 10;
//	b = 23;
//	c = a + b;
//	cout << "a + b = ";
//	cout << c;
//	cout << endl;
//	return 0;
//}

//1.
//#include <iostream>
//
//int main()
//{
//	int a = 1, b = 2;
//	int c;
//	c = a + b;
//	std::cout << "a + b = " << a + b;
//	return 0;
//}
