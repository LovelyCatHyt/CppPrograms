#pragma once

//2D规则几何形状
class Shape2D
{
public:
    //复制数据相同的一个Shape2D
    virtual Shape2D* Copy()const = 0;
    //面积
    virtual float GetArea()const = 0;
    //周长
    virtual float GetGirth()const = 0;
    //打印信息
    virtual void PrintData()const = 0;
    //从控制台输入信息
    virtual void Input() = 0;
};