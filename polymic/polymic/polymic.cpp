#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>

using namespace std;
/*
class Base {
protected:
	int bi;
public:
	Base()
	{
		bi = 10;
	}
	~Base()
	{
		cout << bi << " ";
	}
};
class Base1 : virtual public Base {
public:
	Base1()
	{
		bi += 6;
	}
	~Base1()
	{
		cout << bi << " ";
	}
};
class Base2 : virtual public Base
{
public:
	Base2()
	{
		bi += 8;
	}
	~Base2()
	{
		cout << bi << " ";
	}
};
class Base4 : public Base2, public Base1
{
public:

	Base4()
	{

	}
	~Base4()
	{
		cout << bi << " " << Base::bi << " " << Base1::bi << " " << Base2::bi << endl;
	}

};

int main()
{
	Base4 b4;

	system("pause");
	return 0;
}
*/

/*
class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}
	virtual void fun()
	{
		cout << "A::Fun()" << endl;
	}

protected:
	int m = 0;
};

class B : public A
{
public:
	B()
	{
		cout << "B()" << endl;
	}
	void print()
	{
		m += 8;
		cout << "m = " << m << endl;
	}

};

int main()
{
	B b;

	system("pause");
	return 0;
}



int main()
{
	const char c1 = std::cin.get(); //¡¾A¡¿
	const char c2 = c1 - 32;          //¡¾B¡¿ 
	c1 -= 32;                       //¡¾C¡¿
	std::cout << c1 << ' ' << c2 << '\n'; //¡¾D¡¿
	system("pause");
	return 0;
}
*/



int main()
{
	const int val = 8, ci = 2;
	int i = 0, k = 1, *p;
	p = &i;   //¡¾A¡¿
	*p = val; //¡¾B¡¿
	p = &k;   //¡¾C¡¿
	//p = &ci;  //¡¾D¡¿

	system("pause");
	return 0;
}