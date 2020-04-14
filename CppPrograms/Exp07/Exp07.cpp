#include "LittleToolkit.h"
#include <stdlib.h>
#include "Rect.h"
#include "Circle.h"
#include "Triangle.h"
#include "Podetium.h"
int main()
{
    //防止控制台背景颜色与输出文本不协调
    system("color 0f");
    Podetium pdt1 = Podetium(new Rect(),0);
    Podetium pdt2 = Podetium(new Circle(), 0);
    Podetium pdt3 = Podetium(new Triangle(), 0);
    cout << WTA::WHITE << "请输入长方体的数据.";
    pdt1.Input();
    pdt1.PrintData();
    cout << WTA::WHITE << "请输入圆柱的数据.";
    pdt2.Input();
    pdt2.PrintData();
    cout << WTA::WHITE << "请输入三棱柱的数据.";
    pdt3.Input();
    pdt3.PrintData();

}