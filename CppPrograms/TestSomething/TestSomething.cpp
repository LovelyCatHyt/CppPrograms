//#include <iostream>
//using namespace std;
//
//class Point
//{
//	int index;
//	int x, y;
//	void Init()
//	{
//		cout << "Point[" << index << "] initialized." << endl;
//	}
//public:
//	static int count;
//	Point()
//	{
//		x = y = 0;
//		index = count++;
//		Init();
//	}
//	Point(int x, int y)
//	{
//		this->x = x;
//		this->y = y;
//		index = count++;
//		Init();
//	}
//};
//
//int Point::count;
//
//int main()
//{
//	Point orgin;
//	return 0;
//}

#include<iostream>
#include<math.h>
using namespace std;

void f(int a[])
{
	int b;
	cout << "int[]: " << sizeof(a) << endl;
	cout << "int:   " << sizeof(int) << endl;
	cout << "int *: " << sizeof(&b) << endl;
	cout << "long long: " << sizeof((long long)1) << endl;
}

int main()
{
	int a[3];
	f(a);	
	return 0;
}
