#include <iomanip>
#include "Time.h"

using std::cerr;
using std::endl;

Time::Time(float h, float m, float s): hour(h),minute(m),second(s)
{
}

ostream& operator<<(ostream& os, const Time& t)
{
	float temp = t.hour + t.minute / 60.0 + t.second / 3600.0;
	os << std::setprecision(4) << std::setiosflags(std::ios::fixed) << temp << endl;
	return os;
}

istream& operator>>(istream& is, Time& t)
{
	is >> t.hour >> t.minute >> t.second;
	if (t.minute < 0 || t.minute>60 || t.second < 0 || t.second>60)
	{
		cerr << "时间输入格式错误!" << endl;
	}
	return is;
}
