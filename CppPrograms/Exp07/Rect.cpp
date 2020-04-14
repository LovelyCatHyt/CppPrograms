#include <iostream>
#include "Rect.h"
#include "LittleToolkit.h"

Rect::Rect(float width, float height) : width(width), height(height)
{
}

Shape2D* Rect::Copy() const
{
	return new Rect(width, height);
}

float Rect::GetArea() const
{
	return width * height;
}

float Rect::GetGirth() const
{
	return 2 * (width + height);
}



void Rect::PrintData() const
{
	PrintPair("矩形: 长: ", height);
	PrintPair(" 宽: ", width);
	PrintPair(" 面积: ", GetArea());
	PrintPair(" 周长: ", GetGirth());
}

void Rect::Input()
{
	cout << "请输入宽:\n>";
	std::cin >> width;
	cout << "请输入长:\n>";
	std::cin >> height;
}
