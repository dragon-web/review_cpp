#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
/*
using namespace std;
class Base
{
public:
	Base()
	{
		cout << "Base" << endl;
	}
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
	A()
	{
		cout << "A" << endl;
	}
	void fun()
	{
		cout << "A" << endl;
	}
private:
	int a;
	int b;
};
typedef void(*vfptr)();
void Print(vfptr* ptr)
{
	for (int i = 0; ptr[i] != nullptr; ++i)
	{
		ptr[i]();
	}
}
int main()
{
	/*
	A a;
	Base *p = &a;
	p->fun();
	a.fun();
	//Base b;
	//b = a;
	//b.fun();
	
	Base b;
	printf("%x\n", *(int*)&b);
	vfptr *vfptr_ar = (vfptr *)(*(int *)&b);
	cout << vfptr_ar << endl;
	Print(vfptr_ar);
	system("pause");
	return 0;
}



int main()
{
	const int a = 8;
	//int *p = &a;
	//int *const pc1;
	const int ci = 2, value = 8;
	int i = 0, k = 2;
	int * const pc = &i;
	int * const pc1;    //【A】
	*pc = 8;              //【B】
	pc = &k;              //【C】
	int * const pc = &ci; //【D】
	return 0;

	system("pause");
	return 0;
}

#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	写数据入文件时ifstream file_out("hello.txt");改为 ofstream file_out("hello.txt");
	ifstream file_out("hello.txt");
	char s[20] = "hello world!";
	char p[20];
	int i = 0;
	/* 写hello world 入文件 
	if (file_out.fail())
	{
		cerr << "错误" << endl;
		return 1;
	}
	while (s[i] != '\0')
	{
		file_out.put(s[i]);
		i++;
	}
		/* 重文件中读出*
		for (i = 0; i < 50; i++);
	file_out.seekg(0, ios::beg);
	file_out.getline(p, 20, '\0');
	cout << p << endl;
	file_out.close();
}

using namespace std;
class Base
{
public:
	Base()
	{
		cout << "Base" << endl;
	}
	virtual void fun()
	{
		cout << "Base" << endl;
	}
	virtual Base* Test()
	{
		cout << "Base()" << endl;
		return this;
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
	A * Test()
	{
		cout << "A()" << endl;
		return this;
	}
private:
	int a;
	int b;
};


int main()
{
	A a;
	Base *p = &a;
	p->Test();
	system("pause");
	return 0;
}
*/



using namespace std;
class Base
{
public:
	Base()
	{
		cout << "Base()" << endl;
	}
	
	~Base()
	{
		cout << "~Base()" << endl;
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
		cout << "~A()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int a;
	int b;
};


int main()
{
	A a;

	return 0;
}