#pragma once
#include "Shape2D.h"
class Circle : public Shape2D
{
private:
	float radius;
public:
	Circle(float radius = 0);
	virtual Shape2D* Copy() const;
	virtual float GetArea() const;
	virtual float GetGirth() const;
	virtual void PrintData() const;
	virtual void Input();
};

