#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>

using namespace std;
/*
class Base
{
public:
	 void fun()
	{
		cout << "Base" << endl;
	}
private:
	int m_a;
	int m_b;
};

class A :public Base
{
public:
	void fun()
	{
		cout << "A" << endl;
	}
	void print()
	{
		cout << "print" << endl;
	}
private:
	int a;
	int b;
};
*/

class Base
{
public:
	 virtual void fun()
	{
		cout << "Base" << endl;
	}
private:
	int m_a;
	int m_b;
};

class A :public Base
{
public:
	void fun()
	{
		cout << "A" << endl;
	}
	void print()
	{
		cout << "print" << endl;
	}
private:
	int a;
	int b;
};
int main()
{
	Base b;

	cout << sizeof(Base) << endl;

	system("pause");
	return 0;
}