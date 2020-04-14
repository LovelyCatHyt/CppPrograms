#pragma once
//专门用来偷懒的玩意儿, 一个#include相当于一堆#include
#include <iostream>
#include "../ColorfulConsole/TextAttribute.h"

using WTA = ColorfulConsole::TextAttribute::WarpedTextAttr;
using std::string;
using std::cout;

//把长长的格式控制写成函数, 让代码看起来短一点
inline void PrintPair(string lable, float value)
{
	cout << WTA::LIGHTBLUE << lable << WTA::WHITE << value;
}