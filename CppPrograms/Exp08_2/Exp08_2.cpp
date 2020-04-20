#include "Student.h"
#include <iostream>

using std::cout;
using std::cin;
using std::string;

int main()
{
    Student stu1, stu2;
    cout << "请输入学生数据, 按照 学号 姓名 性别 专业 电话 地址 的顺序排列\n";
    cin >> stu1;
    cout << stu1;
    stu1.WriteToFile("stu.txt");
    cout << "文件已输出到stu.txt\n";
    stu2 = Student::ReadFromFile("stu.txt");
    cout << "已从文件stu.txt读取\n" << stu2;
    return 0;
}