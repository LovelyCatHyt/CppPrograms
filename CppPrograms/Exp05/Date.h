#pragma once
//日期
class Date
{
private:
	constexpr static unsigned short normalMonths[] =	{ 31,28,31,30,31,30,31,31,30,31,30,31 };
	constexpr static unsigned short leapMonths[] =		{ 31,29,31,30,31,30,31,31,30,31,30,31 };
	unsigned short year, month, day;
	Date operator++(int);
	Date operator--(int);
	static unsigned int dton(const Date& date);
	static Date ntod(unsigned int day);
public:
	//初始化函数
	Date(unsigned short year = 1, unsigned short month = 1, unsigned short day = 1);
	unsigned int dton() const;
	bool IsLeap() const;
	static bool IsLeap(const unsigned int year);
	Date operator+(int day);
	Date operator-(int day);
	int operator-(Date&& another);
	void Print();
};

