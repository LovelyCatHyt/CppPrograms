#include <iostream>
using namespace std;

namespace MyTools
{
	template<typename T>
	T Max(T* toFindArray, int size)
	{
		T temp = toFindArray[0];
		for (int i = 0; i < size; i++)
		{
			if (temp < toFindArray[i])
			{
				temp = toFindArray[i];
			}
		}
		return temp;
	}
}
int main()
{
	int n = 0;
	std::string* list = NULL;
	cout << ">Please enter the number of the string list:";
	cin >> n;
	list = new string[n];
	cout << ">Then enter " << n << " line of strings:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}
	string max = MyTools::Max<string>(list, n);
	cout << ">max:" << max<<endl;
	delete []list;
	return 0;
}