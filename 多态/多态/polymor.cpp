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
	cout << "������ָ��ָ��������ʱ��" << endl;
	pB->f();
	pB->g();
	pB->h();
	cout << endl;

	Derived *pD = (Derived*)pB;
	cout << "������ָ�뱻ǿ��ת��������ָ��ʱ��" << endl;
	pD->f();
	pD->g();
	pD->h();
	cout << endl;

	Derived *pd = new Derived();
	cout << "������ָ��ָ������ʱ��" << endl;
	pd->f();
	pd->g();
	pd->h();
	cout << endl;

	Base *pb = (Base *)pd;
	cout << "������ָ�뱻ǿ��ת���ɸ���ָ��ʱ��" << endl;
	pb->f();
	pb->g();
	pb->h();
	cout << endl;

	Base *pp = new Derived();
	cout << "����ָ��ָ���������ʱ��" << endl;
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
	Base* p = new A();  //��̬������Ҫ�ֶ��ͷ�
	delete p;

	system("pause");
	return 0;
}
*/

/*
���麯����Ϊ��ʵ�ֽӿڵ�
���麯��ʵ���˽ӿڵļ̳�

*/