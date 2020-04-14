#include "Point.h"
#include <cmath>
#include "LittleToolkit.h"

Point::Point(float x, float y) : x(x), y(y)
{
}

float Point::Dis(const Point& other) const
{
	return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}

void Point::Input()
{
	cout << "ºá×ø±ê:\n>";
	std::cin >> x;
	cout << "×Ý×ø±ê:\n>";
	std::cin >> y;
}

void Point::Print() const
{
	cout << WTA::WHITE << x << ", " << y;
}

ostream& operator<<(ostream& out, const Point& p)
{
	p.Print();
	return out;
}
