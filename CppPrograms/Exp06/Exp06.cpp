#include <iostream>
#include <vector>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "OnJobPostGraduate.h"
#include "StududyingTeacher.h"
#include "../ColorfulConsole/TextAttribute.h"

using std::cout;
using std::cin;
using std::vector;
using WTA = ColorfulConsole::TextAttribute::WarpedTextAttr;
vector<Person*> persons;

//遍历每个元素执行操作
void ForEach(vector<Person*> list, void(*function)(Person* p))
{
    for (auto iter = list.begin(); iter != list.end(); iter++) function(*iter);
}

//造 人
Person* CreatePerson()
{
    cout << "请选择要输入的类型:\n";
    cout << "[0]普通\n"
        "[1]学生\n"
        "[2]教师\n"
        "[3]在职研究生\n"
        "[4]在读教师\n>";
    short flag;
    Person* temp;
    cin >> flag;
    switch (flag)
    {
    case 0: temp = new Person(); break;
    case 1: temp = new Student(); break;
    case 2: temp = new Teacher(); break;
    case 3: temp = new OnJobPostGraduate(); break;
    case 4: temp = new StududyingTeacher(); break;
    default:
        temp = new Person();
        cout << WTA::LIGHTRED << "未知类型!\n" << WTA::WHITE;
        break;
    }
    temp->LoopSetData();
    return temp;
}

//搜索
void Search()
{
    cout << "请输入要查询的人员姓名:\n>";
    string name;
    cin >> name;
    bool found = false;
    for (auto iter = persons.begin(); iter != persons.end(); iter++)
    {
        if (name == (*iter)->GetName())
        {
            cout << "查询结果:\n";
            cout << **iter << '\n';
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "查无此人!";
    }
}

//编辑
void Edit()
{
    WTA darkGray(0);
    darkGray.fore_Intense = true;
    cout << darkGray << "请选择要编辑的人员编号,从" << WTA::WHITE << '0' << darkGray << "到" << WTA::WHITE << (persons.size() - 1) << darkGray << '.';
    cout << WTA::WHITE << "\n>";
    int index = 0;
    cin >> index;
    persons[index]->Edit();
}

//添加
void Add()
{
    persons.push_back(CreatePerson());
}

//主菜单:继续则返回true
bool MainMenu()
{
    cout << "当前数据:\n";
    //遍历输出
    ForEach(persons, [](Person* each) {cout << *each << '\n'; });
    cout << "请选择使用的功能:\n"
        "[0]查询\n"
        "[1]修改\n"
        "[2]添加\n"
        "其他数字为退出系统\n>";
    int num = 0;
    cin >> num;
    if (cin.bad() || cin.fail())
    {
        cin.clear(); cin.ignore();
        return false;
    }
    switch (num)
    {
    case 0: Search(); break;
    case 1: Edit(); break;
    case 2: Add(); break;
    default:
        return false;
        break;
    }
    return true;
}

int main()
{
    bool continueInput = true;
    int count = 0;
    while (continueInput)
    {
        cout << "正在输入第" << WTA::LIGHTBLUE << count << WTA::WHITE << "组数据:\n";
        persons.push_back(CreatePerson());
        count++;
        cout << WTA::LIGHTGREEN << "继续输入数据?确认则输入y\n"<<WTA::WHITE<<'>';
        char temp;
        cin >> temp;
        continueInput = temp == 'y' || temp == 'Y';
    }
    //循环菜单直至退出
    while (MainMenu());
    cout << WTA::LIGHTBLUE << "感谢使用本系统!" << WTA::WHITE;
    //循环释放
    ForEach(persons, [](Person* each) {delete each; });
    return 0;
}