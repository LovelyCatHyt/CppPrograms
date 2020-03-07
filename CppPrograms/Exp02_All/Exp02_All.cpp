//4.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int gcd(int m, int n)
{
	//欧几里得法求最大公约数
	return (m == 0) ? n : gcd(n % m, m);
}

int main()
{
	int a=1, b=1;
	cout << ">Please enter two number a and b: " << endl;
	cin >> a >> b;
	if (a < b) std::swap(a, b);
	cout << ">gcd(" << a << "," << b << ") = " << gcd(a, b);

}

/*
//3.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int n = 0;
	cout << ">Please enter n: " << endl;
	cin >> n;
	int tryCount = 1;
	while (n < 50 || n>10000)
	{
		if (tryCount > 4)
		{
			cout << ">You've tried too many times!";
			return 0;
		}
		cout << ">The number you enter is invalid! Enter again ("<<tryCount<<"/5): " << endl;
		cin >> n;
		tryCount++;
	}
	int sum = 0;
	for (int i = 1; i <= n; sum += i++);
	cout << ">The sum is: " << sum<<endl;
	return 0;
}


//2.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

float GetCost(int consume)
{
	//一行处理一个区间
	if (consume < 20) return consume * 0.6;
	if (consume < 30) return consume - 8;//12+(x-20)=x-8
	return 2 * consume - 38;//22+2(x-30)=2x-38
}

int main()
{
	int consume = 0;
	cout << ">Please enter consume: " << endl;
	cin >> consume;
	cout << ">Cost is: " << GetCost(consume)<<endl;
}

//1.
#include <iostream>
#include <math.h>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	double a, b, c;
	cout << ">Please enter three sides of the triangle:" << endl;
	cin >> a >> b >> c;
	//输入数据检查, 错误则重新输入
	while ((a + b <= c) || (a - b >= c) || (b - a >= c))
	{
		cout << ">Not valid triangle! Please re-enter the values of the three edges:" << endl;
		cin >> a >> b >> c;
	}
	//代入公式
	double s = (a + b + c)/2;
	cout << ">The area of the triangle is: " << sqrt(s * (s - a) * (s - b) * (s - c)) << endl;
}
*/