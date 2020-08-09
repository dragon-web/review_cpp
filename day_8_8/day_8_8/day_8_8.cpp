#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<cstring>

using namespace std;
//1:内联函数：如果在类的成员内部给出成员函数定义，该函数自动成为内联函数
inline int doubled(int x)
{
	return x * 2;
}
//使用const声明的函数就是常成员函数
//常函数不能更新函数的状态

/*
class myString
{
	char s[80];
public:
	void print()
	{
		cout << s << "\n";
	}
	void set(char *str)
	{
		strcpy(s, str);
	}
};

myString input()
{
	char instr[80];
	myString str;
	cout << "Enter a string:";
	cin >> instr;
	str.set(instr);
	return str;
}

int main()
{
	myString ob;
	ob = input();
	ob.print();
	cout << doubled(12 + 85) << endl;
	system("pause");
	return 0;
}

//友元没有this指针，所以在访问对象的时候要加引用

class my_string
{
	char *s;
public:
	my_string(const char *str);
	my_string(const my_string &obj);
	~my_string()
	{
		if (s)
			delete[] s;
		cout << "Free s\n" << endl;
	}
	void show()
	{
		cout << "show:" << endl;
		cout << s << endl;
	}
};
my_string::my_string(const char* str)
{
	s = new char[strlen(str) + 1];
	cout << "Allocating room for s\n";
	strcpy(s, str);
}
my_string::my_string(const my_string &obj)
{
	s = new char[strlen(obj.s) + 1];
	strcpy(s, obj.s);
	cout << "Copy constructor called. \n";
}

void display(my_string ob)
{
	ob.show();
}

int main()
{
	my_string obj("Hello");
	display(obj);
	obj.show();


	system("pause");
	return 0;
}
*/


//在返回对象时使用复制构造函数


/*
class my_string
{
	char *s;
public:
	my_string(const char *str);
	my_string(const my_string &obj);
	~my_string()
	{
		if (s)
			delete[] s;
		cout << "Free s\n" << endl;
	}
	void show()
	{
		cout << "show:" << endl;
		cout << s << endl;
	}
};
my_string::my_string(const char* str)
{
	s = new char[strlen(str) + 1];
	cout << "Allocating room for s\n";
	strcpy(s, str);
}

my_string::my_string(const my_string &obj)
{
	s = new char[strlen(obj.s) + 1];
	strcpy(s, obj.s);
	cout << "Copy constructor called. \n";
}


void display(my_string ob)
{
	ob.show();
}

my_string input()
{
	char str[80];
	cout << "Enter String:" << endl;
	cin >> str;
	
	my_string ob(str);
	return ob;
}

int main()
{
	my_string obj = input();
	obj.show();
	system("pause");
	return 0;
}
//解决方法是返回一个对象或指针的引用 深拷贝
*/





class my_string
{
	char *s;
public:
	my_string(const char *str);
	//my_string(const my_string& obj);
	void operator= (const my_string& obj);

	~my_string()
	{
		if (s)
			delete[] s;
		cout << "Free s\n" << endl;
	}
	void show()
	{
		cout << "show:" << endl;
		cout << s << endl;
	}
};
my_string::my_string(const char* str)
{
	s = new char[strlen(str) + 1];
	cout << "Allocating room for s\n";
	strcpy(s, str);
}

/*
my_string::my_string(const my_string& obj)
{
	s = new char[strlen(obj.s) +1];
	strcpy(s, obj.s);
	cout << "复制构造" << endl;
}*/

my_string input()
{
	char str[80];
	cout << "Enter String:" << endl;
	cin >> str;

	my_string ob(str);
	return ob;
}
void display(my_string& ob)
{
	ob.show();
}
void my_string::operator= (const my_string& obj)
{
	s = new char[strlen(obj.s) + 1];
	strcpy(s, obj.s);
	cout << "重载等号" << endl;
}

int main()
{
	my_string obj = input();
	obj.show();
	system("pause");
	return 0;
}







