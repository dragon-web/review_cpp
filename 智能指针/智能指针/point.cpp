#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string>
/*
reinterpret_cast
		const_cast
		dynamic_cast

class A
{
public:
	operator int() { return 1; }
	operator char* () { return NULL; }
};

int main()
{
	A a;
	int n;
	const char *p = "New Dragon Inn";
	n = static_cast<int>(3.14);
	n = static_cast<int>(a);
	p = static_cast<char*>(a);
	system("pause");
	return 0;
}
using namespace std;
class A
{
public:
	int i;
	int j;
	A(int n):i(n),j(n){}
};
int main()
{
	A a(100);
	int &r = reinterpret_cast<int &>(a);
	r = 200;  //��a.i ��ֵ��Ϊ  200
	cout << a.i << " " << a.j << endl;
	system("pause");
	return 0;
}
using namespace std;

int main()
{
	const string s = "Interpertion";
	string &p = const_cast<string &>(s);
	string *ps = const_cast<string &>(&s);
	system("pause");
	return 0;
}
*/

using namespace std;
class Base
{
public:
	virtual ~Base()
	{

	};
};
class A :public Base
{

};
int main()
{
	Base b;
	A a;
	A *a1;
	a1 = reinterpret_cast<A*>(&b);
	if (a1 == NULL)//����鰲ȫ��
	{
		cout << "unsafe reinterpret_cast" << endl;
	}
	a1 = dynamic_cast<A*>(&b);
	if (a1 == NULL)//����鰲ȫ��
	{
		cout << "unsafe dynamic_cast" << endl;
	}
	system("pause");
	return 0;
}