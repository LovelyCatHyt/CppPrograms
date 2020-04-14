#pragma once
#include <ostream>
using std::ostream;
//2D点
class Point
{
public:
	float x, y;
	Point(float x = 0, float  y = 0);
	//两点距离
	float Dis(const Point& other) const;
	//从控制台输入数据
	void Input();
	//打印数据
	void Print() const;
};
ostream& operator<<(ostream& out, const Point& p);

