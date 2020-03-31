#include <iostream>
#include "Date.h"
using std::cout;
using std::endl;

unsigned int Date::dton() const
{
	return dton(*this);
}

bool Date::IsLeap() const
{
	return IsLeap(year);
}

bool Date::IsLeap(const unsigned int year)
{
	return (year % 4 == 0) && (year % 100) || year % 400 == 0;
}

Date Date::operator++(int)
{
	Date temp = *this;
	day++;
	const unsigned short* months = (IsLeap() ? leapMonths : normalMonths);
	if (day > months[month - 1])
	{
		month++;
		day = 1;
	}
	if (month > 12)
	{
		year++; month = 1;
	}
	return temp;
}

Date Date::operator--(int)
{
	Date temp = *this;
	day--;
	const unsigned short* months = (IsLeap() ? leapMonths : normalMonths);
	if (!day)
	{
		month--;
		day = month > -1 ? months[month] : 0;
	}
	if (month == 0 )
	{
		year--;
		month = 11;
		day = 31;
	}
	return temp;
}

unsigned int Date::dton(const Date& date)
{
	unsigned int count_400 = (date.year - 1) / 400;
	unsigned int count_100 = (date.year - 1) / 100;
	unsigned int count_4 = (date.year - 1) / 4;
	unsigned int dayInYear = 0;
	if (date.IsLeap())
	{
		for (int i = 0; i < date.month - 1; i++)
		{
			dayInYear += leapMonths[i];
		}
	}
	else
	{
		for (int i = 0; i < date.month - 1; i++)
		{
			dayInYear += normalMonths[i];
		}
	}
	return date.year * 365 + count_4 - count_100 + count_400 + dayInYear + date.day - 366;
}

Date Date::ntod(unsigned int day)
{
	Date temp(day / 365);
	while (temp.dton() < day) temp++;
	while (temp.dton() > day) temp--;
	/*while (temp.dton() < day)
	{
		cout << "[ntod]temp.dton() = " << temp.dton() << endl;
		temp++;
	}*/
	return temp;
}

Date::Date(unsigned short year, unsigned short month, unsigned short day) :year(year), month(month), day(day)
{
}

Date Date::operator+(int day)
{
	return ntod((dton() + day));
}

Date Date::operator-(int day)
{
	return ntod((dton() - day));
}

int Date::operator-(Date&& another)
{
	return dton() - another.dton();
}

void Date::Print()
{
	cout << year << "Äê" << month << "ÔÂ" << day << "ÈÕ" << endl;
}
