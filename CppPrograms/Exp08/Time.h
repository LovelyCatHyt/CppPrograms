#include <iostream>
#pragma once

using std::ostream;
using std::istream;

class Time
{
private:
	float hour;
	float minute;
	float second;
public:
	Time(float h = 0, float m = 0, float s = 0);
	friend ostream& operator<<(ostream& os, const Time& t);
	friend istream& operator>>(istream& is, Time& t);
};

