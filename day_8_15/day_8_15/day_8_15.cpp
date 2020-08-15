#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>


using namespace std;
/*
class A
{
protected:
	int m_data = 0;
public:
	A()
	{
		cout << "A(int a)" << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "B()" << endl;
		m_data += 10;
	}
};

int main()
{
	B b;
	cout << sizeof(b) << endl;
	system("pause");
	return 0;
}*/


/*
int main()
{
	const int ci = 2, value = 8;
	int i = 0;
	const int * const cpc1 = &ci;
	const int * const cpc2 = &i; //【A】
	//*cpc1 = value;               //【B】
	//cpc1 = &i;                   //【C】
	//cpc2 = &ci;

	system("pause");
	return  0;
}
*/
/*
int main()
{

	void myfunc(int x = 0, int y = 100); //【A】
	myfunc(1, 2);                    //【B】
	myfunc(10);                      //【C】
	myfunc();
	system("pause");
	return 0;
}
void myfunc(int x = 0, int y = 100) { //【D】
	std::cout << "x: " << x << ", y: " << y << "\n";
}


void myfunc(int x = 0, int y = 100); //【A】
int main() {
	myfunc(1, 2);                    //【B】
	myfunc(10);                      //【C】
	myfunc();
	system("pause");
	return 0;
}
//  重定义默认参数
void myfunc(int x = 0, int y = 100) { //【D】
	std::cout << "x: " << x << ", y: " << y << "\n";
}

void myfunc(int x, int y) { //【D】
	std::cout << "x: " << x << ", y: " << y << "\n";
}
#include <iostream>
using namespace std;
float myfunc(float i);
double myfunc(double i);
double myfunc(double i, double j = 0);
int main() {
	cout << myfunc(10.1f) << endl;
	cout << myfunc(1.1f + 3.0) << endl; //【A】
	cout << myfunc(10.1);           //【B】
	cout << myfunc(10.1, 1.2) << endl; //【C】
	cout << myfunc(10);             //【D】
	system("pause");
	return 0;
}
float myfunc(float i) {
	return i;
}
double myfunc(double i) {
	return -i;
}
double myfunc(double i, double j) {
	return i + j;
}

//拷贝构造函数
class CExample
{
private:
	int a;
public:
	//构造函数
	CExample(int b)
	{
		a = b;
		printf("constructor is called\n");
	}
	//拷贝构造函数
	CExample(const CExample & c)
	{
		a = c.a;
		printf("copy constructor is called\n");
	}
	//析构函数
	~CExample()
	{
		cout << "destructor is called\n";
	}
	void Show()
	{
		cout << a << endl;
	}
};
int main()
{
	CExample A(100);
	CExample B = A;
	B.Show();
	system("pause");
	return 0;
}

#include <iostream> 

class MyClass {
	int m;
public:
	MyClass(int x = 0) 
	{
	m = x;
	cout << "构造函数" << endl;
	}
	MyClass(const MyClass &x) { 
	m = x.m; 
	cout << "拷贝构造函数" << endl;
	}
	//...... 
	MyClass &f1(MyClass &x) const { 
		return x; }
	const MyClass &f2(const MyClass& x) const {
		return x;
	}
};
int main() {
	MyClass x0;
	MyClass y(2);
	x0 = y;           //【A】
	MyClass x1 = y;   //【B】  只有B是拷贝构造函数

	x0.f1(y);       //【C】
	x0.f2(y);       //【D】

	system("pause");
	return 0;
}

#include <iostream>
using namespace std;
template <class T>
inline void swapargs(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}
int main() {
	int i = 10, j = 20;
	double x = 10.1f, y = 23.3;
	char a = 'x', b = 'z';
	//...... 
	swapargs(i, j);           //【A】
	swapargs<double>(x, y);   //【B】
	swapargs(a, b);           //【C】
	swapargs<int>(i, b);      //【D】
	//......  
	return 0;
}

#include <iostream>  
using namespace std;
namespace NS {
	 int i = 0, j = 0, k = 0; //对于i的定义
}
int k = 6;
int main() {
	int i = 8;  
	 using NS::i;   //又把i定义了一下                  //【A】
	cout << NS::i << ',' << NS::j << ',' << NS::k << ',' << ::k << endl;
	cout << i << ',' << k << endl;
	using NS::j;                    //【B】
	cout << NS::i << ',' << NS::j << ',' << NS::k << ',' << ::k << endl;
	cout << i << ',' << j << ',' << k << endl;
	using NS::k;                    //【C】
	cout << NS::i << ',' << NS::j << ',' << NS::k << ',' << ::k << endl;
	cout << i << ',' << j << ',' << k << endl;  //【D】
	system("pause");
	return 0;
}

#include <iostream>
int main() {
	bool b = false;
	std::cout << b << ',';
	b = 7;
	std::cout << b << ',';
	b = 3 == 4;
	std::cout << b << '\n';

	system("pause");
	return 0;
}

#include <iostream>  
int x = 1;
void func() {
	std::cout << x << ',' << ::x << ';';
	int x = 2;
	std::cout << x << ',' << ::x << ';';
	{
		std::cout << x << ',' << ::x << ';';
		int x = 3;
		std::cout << x << ',' << ::x << ';';
	}
	std::cout << x << ',' << ::x << ';';
}
int main() {
	std::cout << x << ',' << ::x << ';';
	func();
	std::cout << x << ',' << ::x << '\n';
	system("pause");
	return 0;
}
#include <iostream> 
int & min(int &x, int &y) {
	return (x < y ? x : y);
}
int main() {
	int a = 10, b = 20, c = 30;
	std::cout << "a=" << a << ",b=" << b << ",c=" << c << ';';
	min(a, b) = 50;
	std::cout << "a=" << a << ",b=" << b << ",c=" << c << ';';
	min(c, b) = 50;
	std::cout << "a=" << a << ",b=" << b << ",c=" << c << std::endl;
	system("pause");
	return 0;
}


#include <iostream>  
int main() {
	int j = 10, k = 11;
	int &i = j;
	std::cout << j << ' ' << i << ';';
	i = k;
	k = 12;
	std::cout << i << ' ' << j << ' ' << k << '\n';
	system("pause");
	return 0;
}


#include <iostream>
using namespace std;
void swap1(int x, int y);
void swap2(int &x, int &y);
void swap3(int *x, int *y);
void swap4(int *x, int *y);
int main() {
	int i = 10, j = 20;
	cout << i << ',' << j << ';';  
	swap1(j, i);
	cout << i << ',' << j << ';';
	swap2(j, i);
	cout << i << ',' << j << ';';
	swap3(&j, &i);
	cout << i << ',' << j << ';';
	swap4(&j, &i);
	cout << i << ',' << j << endl;
	system("pause");
	return 0;
}
void swap1(int x, int y) {
	int temp;
	temp = x;
	x = y;
	y = temp;
}
void swap2(int &x, int &y) {
	int temp;
	temp = x;
	x = y;
	y = temp;
}
void swap3(int *x, int *y) {
	int *temp;
	temp = x;
	x = y;
	y = temp;
}
void swap4(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void Swap(int **a, int **b)
{
	int **temp = a;
	a = b;
	b = temp;
}
int main()
{
	int a = 12;
	int *temp1 = &a;
	int b = 3;
	int *temp2 = &b;
	Swap(&temp1, &temp2);
	cout << "a = " << a << "b = " << b << endl;
		system("pause");
	return 0;
}


#include <iostream> 
int f1(int n) {
	int fac;
	for (fac = 1; n > 0; n--) fac *= n;
	return fac;
}
int f2(int &n) {
	int fac;
	for (fac = 1; n > 0; n--) fac *= n;
	return fac;
}
int f3(const int &n) {
	int fac, m;
	for (fac = 1, m = n; m > 0; m--) fac *= m;
	return fac;
}
int main() {
	int n, fac;
	std::cout << "4!=" << f1(4) << ' ';
	n = 5, fac = f1(n);
	std::cout << n << "!=" << fac << ';';
	n = 5, fac = f2(n);
	std::cout << n << "!=" << fac << ';';
	std::cout << "4!=" << f3(4) << ' ';
	n = 5, fac = f3(n);
	std::cout << n << "!=" << fac << std::endl;
	system("pause");
	return 0;
}
#include <iostream>
using namespace std;
void f(int x);
void f(short x);
void f(double x);
int main() {
	int i = 10;
	long l = 100L;
	double d = 10.1;
	short s = 99;
	float r = 11.5F;
	f(i);
	f(d);
	f(s);
	f((int)l);
	f(r);
	cout << endl;
	system("pause");
	return 0;
}
void f(int x) {
	cout << "f(int):" << x << ',';
}
void f(short x) {
	cout << "f(short):" << x << ',';
}
void f(double x) {
	cout << "f(double):" << x << ',';
	
}
*/


