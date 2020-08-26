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




#include <iostream>
using namespace std;
class Base {
public:
	virtual void f() { cout << "Base::f" << endl; }
	virtual void g() { cout << "Base::g" << endl; }
	void h() { cout << "Base::h" << endl; }

};
class Derived :public Base
{
public:
	virtual void f() { cout << "Derived::f" << endl; }
	void g() { cout << "Derived::g" << endl; }
	void h() { cout << "Derived::h" << endl; }
};


int main()
{
	Base *pB = new Base();
	cout << "当基类指针指向基类对象时：" << endl;
	pB->f();
	pB->g();
	pB->h();
	cout << endl;

	Derived *pD = (Derived*)pB;
	cout << "当父类指针被强制转换成子类指针时：" << endl;
	pD->f();
	pD->g();
	pD->h();
	cout << endl;

	Derived *pd = new Derived();
	cout << "当子类指针指向子类时候" << endl;
	pd->f();
	pd->g();
	pd->h();
	cout << endl;

	Base *pb = (Base *)pd;
	cout << "当子类指针被强制转换成父类指针时：" << endl;
	pb->f();
	pb->g();
	pb->h();
	cout << endl;

	Base *pp = new Derived();
	cout << "父类指针指向子类对象时候：" << endl;
	pp->f();
	pp->g();
	pp->h();
	cout << endl;

	system("pause");
	return 0;
}


class Base
{
public:
	void fun()
	{
		cout << "Base" << endl;
	}
	~Base()
	{
		cout << "~Base" << endl;
	}
private:
	int m_a;
	int m_b;
};

class A :public Base
{
public:
	A()
	{
		cout << "A" << endl;
	}
	void fun()
	{
		cout << "A" << endl;
	}
	~A()
	{
		cout << "~A" << endl;
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
	Base* p = new A();  //动态申请需要手动释放
	delete p;

	system("pause");
	return 0;
}
*/

/*
纯虚函数是为了实现接口的
纯虚函数实现了接口的继承

*/