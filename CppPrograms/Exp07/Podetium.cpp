#include "Podetium.h"
#include "LittleToolkit.h"

using std::cout;
using std::string;
using WTA = ColorfulConsole::TextAttribute::WarpedTextAttr;

Podetium::Podetium()
{
	base = nullptr;
	height = 0;
}

Podetium::Podetium(Shape2D* base, float height) : base(base), height(height)
{
}

Podetium::~Podetium()
{
	delete base;
}

Shape2D* Podetium::GetBase() const
{
	return base->Copy();
}

void Podetium::SetBase(const Shape2D* base)
{
	this->base = base->Copy();
}

float Podetium::GetHeight() const
{
	return height;
}

void Podetium::SetHeight(float height)
{
	this->height = height;
}

float Podetium::GetVolume() const
{
	return base->GetArea() * height;
}

float Podetium::GetArea() const
{
	return base->GetArea() * 2 + base->GetGirth() * height;
}

void Podetium::Input()
{
	base->Input();
	cout << "请输入柱体的高度:\n>";
	std::cin >> height;
}

void Podetium::PrintData() const
{

	cout << WTA::LIGHTBLUE << "底面: " << WTA::LIGHTGREEN << '[' << WTA::WHITE; base->PrintData(); cout << WTA::LIGHTGREEN << "] ";
	PrintPair(" 高: ",height);
	PrintPair(" 体积: ", GetVolume());
	PrintPair(" 表面积: ", GetArea());
	cout << '\n';
}
