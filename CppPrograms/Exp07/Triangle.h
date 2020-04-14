#pragma once
#include "Shape2D.h"
#include "Point.h"
class Triangle : public Shape2D
{
private:
	Point pA, pB, pC;
public:
	Triangle(Point a = Point(), Point b = Point(), Point c = Point());
	virtual Shape2D* Copy() const;
	virtual float GetArea() const;
	virtual float GetGirth() const;
	virtual void PrintData() const;
	virtual void Input();
};

