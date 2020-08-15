#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

/*nt main()
{
	char de = cout.fill('#');
	cout.setf(ios::showpos);
	cout.width(6);
	cout << 123 << "," << -123 << '/';
	cout.unsetf(ios::showpos);
	system("pause");
	cout << hex << showbase << setw(5) << 123 << "," << 124 << ",";
	cout.fill(de);
	cout << oct << 123 << ',' << dec << setw(5) << 124 << endl;
	return 0;
}*/
#include <math.h>
#include <iostream>
using namespace std;

#define ESP pow(10, -10)
char *TriangleType[3] = { "Right", "Acute", "Obtuse" };

class Triangle
{
	friend ostream& operator<<(ostream &_cout, Triangle & t);
public:
	Triangle(double _x = 1, double _y = 1, double _z = 1)
		: x(_x), y(_y), z(_z)
	{}
	~Triangle()
	{}
public:
	void get(double &_x, double &_y, double &_z)
	{
		_x = x;
		_y = y;
		_z = z;
	}
	double getPerimeter()
	{
		return x + y + z;
	}
	double getArea()
	{
		double p = (x + y + z) / 2;
		double temp = p * (p - x) * (p - y) * (p - z);
		return sqrt(p);
	}
	char* getTriangleType()
	{
		if (x < y) swap(x, y);
		if (x < z) swap(x, z);
		double temp = x * x - y * y - z * z;
		if (abs(temp) < ESP)
			return TriangleType[0];
		else if (temp < 0)
			return TriangleType[1];
		else
			return TriangleType[2];
	}
	void set(double _x, double _y, double _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}
private:
	double x;
	double y;
	double z;
};
ostream& operator<<(ostream &_cout, Triangle & t)
{
	cout << "(" << t.x << ", " << t.y << ", " << t.z << ")";
	return _cout;
}
class InvalidArg :public expection, public invalid_argument,public Triangle
{
	try
	{
		if (x + y <= z || x + z <= y || y + z <= x)
			throw (x, y, z);
	}
	catch(x , y, z)
	{
		cout << "不构成三角形" << endl; //这里输出的可以胡写
	}

}