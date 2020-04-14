#pragma once
#include "Shape2D.h"

//柱体
class Podetium
{
	Shape2D* base;
	float height;
public:
	Podetium();
	Podetium(Shape2D* base, float height);
	~Podetium();
	//底面
	Shape2D* GetBase()const;
	//设置底面
	void SetBase(const Shape2D* base);
	//高度
	float GetHeight()const;
	void SetHeight(float height);
	//体积
	float GetVolume()const;
	//表面积
	float GetArea()const;
	//输入信息
	void Input();
	//打印信息
	void PrintData()const;
};