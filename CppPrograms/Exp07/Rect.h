#pragma once
#include "Shape2D.h"

//¾ØÐÎ
class Rect : public Shape2D
{
private:
	float width, height;
public:
	Rect(float width = 0, float height = 0);
	virtual Shape2D* Copy() const;
	virtual float GetArea() const;
	virtual float GetGirth() const;
	virtual void PrintData() const;
	virtual void Input();
};

