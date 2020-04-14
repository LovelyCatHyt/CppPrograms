#include "Triangle.h"
#include <cmath>
#include "LittleToolkit.h"

Triangle::Triangle(Point a, Point b, Point c):pA(a), pB(b), pC(c)
{
}

Shape2D* Triangle::Copy() const
{
	return new Triangle(pA, pB, pC);
}

float Triangle::GetArea() const
{
	return abs((pA.x * pB.y + pA.y * pC.x + pB.x * pC.y - pA.x * pC.y - pA.y * pB.x - pB.y * pC.x) / 2);
}

float Triangle::GetGirth() const
{
	return pA.Dis(pB) + pB.Dis(pC) + pC.Dis(pA);
}

void Triangle::PrintData() const
{
	cout << WTA::LIGHTBLUE << "三角形: 三点坐标: " << WTA::LIGHTRED << '(' << pA << WTA::LIGHTRED << ')' << WTA::WHITE << ','
		<< WTA::LIGHTRED << '(' << pB << WTA::LIGHTRED << WTA::LIGHTRED << ')' << WTA::WHITE << ','
		<< WTA::LIGHTRED << '(' << pC << WTA::LIGHTRED << WTA::LIGHTRED << ')' << WTA::WHITE << ',' << WTA::WHITE;
	PrintPair(" 周长: ", GetGirth());
	PrintPair(" 面积: ", GetArea());
}

void Triangle::Input()
{
	cout << "请输入三角形的三点坐标:";
	cout << "第" << WTA::LIGHTBLUE << 1 << WTA::WHITE << "点:";
	pA.Input();
	cout << "第" << WTA::LIGHTBLUE << 2 << WTA::WHITE << "点:";
	pB.Input();
	cout << "第" << WTA::LIGHTBLUE << 3 << WTA::WHITE << "点:";
	pC.Input();
}
