#include<iostream>
using namespace std;

int main()
{
	int a, b, c;
	int* p1, * p2, * p3;
	void exchange(int* p1, int* p2, int* p3);
	void swap(int* p1, int* p2);//Doesn't work as expected.
	cout << "Please Input Three number:" << endl;
	cin >> a >> b >> c;
	p1 = &a;
	p2 = &b;
	p3 = &c;
	exchange(p1, p2, p3);//What's the problem after the calling?
	cout << "The Sorted Numbers are: " << endl;
	cout << "a=" << *p1 << endl << "b=" << *p2 << endl << "c=" << *p3 << endl;
	return 0;
}
void exchange(int* p1, int* p2, int* p3)
{
	if (*p1 < *p2) swap(p1, p2);//Bug occurs: "swap" is "std::swap" instead of "::swap"
	if (*p1 < *p3) swap(p1, p3);
	if (*p2 < *p3) swap(p2, p3);
	cout << "The Sorted Numbers are: " << endl;
	cout << "a=" << *p1 << endl << "b=" << *p2 << endl << "c=" << *p3 << endl;
}
void swap(int* p1, int* p2)
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}