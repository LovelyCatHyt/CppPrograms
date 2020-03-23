#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
//复数
class Com
{
private:
	double real, image;
public:
	Com()
	{
		real = image = 0;
	}
	Com(double real, double image = 0) :real(real), image(image)
	{
	}
	Com operator +(const Com r) const
	{
		return Com(real + r.real, image + r.image);
	}
	Com operator -(const Com r) const
	{
		return Com(real - r.real, image - r.image);
	}
	Com operator *(const Com r) const
	{
		return Com(real * r.real - image * r.image, real * r.image + image * r.real);
	}
	Com operator =(double real)
	{
		return Com(real);
	}
	friend ostream& operator<<(ostream& out, const Com& toOut);
};
ostream& operator<<(ostream& out, const Com& toOut)
{
	(toOut.real == 0 ? cout : (cout << toOut.real)) << (toOut.image >= 0 ? "+" : "") << toOut.image << 'i';
	return out;
}
int main()
{
	Com a;
	a = 1;
	Com b(1, -3);
	cout << "a    =" << a << endl;
	cout << "b    =" << b << endl;
	cout << "a+b  =" << (a + b) << endl;
	cout << "a-b  =" << (a - b) << endl;
	cout << "a*b  =" << (a * b) << endl;
	return 0;
}