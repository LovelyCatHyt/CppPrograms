//#define ASBINARY //二进制模式
#include "Student.h"
#include <fstream>
#include <iomanip>

using std::ofstream;
using std::ifstream;
using std::ios;
using std::endl;

Student::Student() : no(0),name(""), gender('m'),major("None"),phoneNumber("00000000000"),address("")
{

}

void Student::WriteToFile(string fileName)
{
#if ASBINARY 1
	ofstream out = ofstream(fileName, ios::out | ios::binary);
	out.write((char*)this, sizeof(Student));
#else
	ofstream out = ofstream(fileName, ios::out);
	out << no << ' ';
	out << name << ' ';
	out << gender << ' ';
	out << major << ' ';
	out << phoneNumber << ' ';
	out << address << ' ';
	out << endl;
#endif
	out.close();
}

Student Student::ReadFromFile(string fileName)
{
	Student temp;
#if ASBINARY 1
	ifstream in = ifstream(fileName, ios::in | ios::binary);
	in.read((char*)&temp, sizeof(Student));
#else
	ifstream in = ifstream(fileName, ios::in);
	in >> temp.no >> temp.name >> temp.gender >> temp.major >> temp.phoneNumber >> temp.address;
#endif
	in.close();
	return temp;
}

ostream& operator<<(ostream& out, const Student& stu)
{
	out << "学号     姓名    性别  专业            电话        地址\n";
	out << std::left << std::setw(9) << stu.no;
	out << std::left << std::setw(8) << stu.name;
	out << std::left << std::setw(6) << stu.gender;
	out << std::left << std::setw(16) << stu.major;
	out << std::left << std::setw(12) << stu.phoneNumber;
	out << std::left << std::setw(14) << stu.address;
	out << endl;
	return out;
}

istream& operator>>(istream& in, Student& stu)
{
	in >> stu.no >> stu.name >> stu.gender >> stu.major >> stu.phoneNumber >> stu.address;
	return in;
}
