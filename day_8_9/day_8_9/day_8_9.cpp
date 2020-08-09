#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>

//保护继承
/*
保护成员能可以被派生类的函数直接访问，但是对于外界是隐藏起来的，外部函数不能直接访问

class A
{
public:
	void setx(int m)
	{
		x = m;
	}
	void sety(int n)
	{
		y = n;
	}
private:
	int y;
protected:
	int x;
};

class B :protected A
{
public:
	void setBx(int m)
	{
		x = m;
	}
	void setBy(int n)
	{
		y = n;
	}
};
using namespace std;

class Student
{
public:
	Student(int N,const char Name[],char s)
	{
		num = N;
		strcpy(name, Name);
		sex = s;
	}
		~Student()
	{
		cout << "析构函数" << endl;
	}
	int getNum()
	{
		return num;
	}
	char* getName()
	{
		return name;
	}
	char getSex()
	{
		return sex;
	}
private:
	int num;
	char name[10];
	char sex;
};


class XiaoMing : public Student
{
private:
	int age;
	char addr[30];
public:
	XiaoMing(int n, const char nam[], char s, int a, const char ad[]):Student(n,nam,a)
	{
		age = a;
		strcpy(addr, ad);
	}
	void show()
	{
		cout << "获取编号"<<getNum() << endl;
		cout << "获取姓名" << getName() << endl;
		cout << "获取性别" << getSex() << endl;
		cout << "获取年龄" << age<< endl;
		cout << "获取地址" << addr<<endl;
	}
};
int main()
{
	XiaoMing xiao(15, "小明", 'A', 52, "安徽芜湖大司马");
	xiao.show();

	system("pause");
	return 0;
}


using namespace std;

class Fa
{
private:
	int m;
public:
	void print()
	{
		cout << "aaa" << endl;	
	}
};
class Stu1 :public Fa
{
public:
	void print()
	{
		cout << "sss" << endl;
	}
};


int main()
{
	Stu1 s;
	s.Fa::print();
	system("pause");
	return 0;
}


using namespace std;

class A
{
public:
	void fun()
	{
		cout << "A" << endl;
	}
};

class B : virtual public A
{
public:
	void funb()
	{
		cout << "B" << endl;
	}
};

class C :virtual public A
{
	void func()
	{
		cout << "C" << endl;
	}
};
class D:public B,public C
{
public:
	void fund()
	{
		cout << "D" << endl;
	}
};

int main()
{
	D d;
	d.fun();
	d.C:: fun();
	d.B::fun();
	system("pause");
	return 0;
}
*/