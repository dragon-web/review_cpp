#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<cstring>

using namespace std;
//1:�����������������ĳ�Ա�ڲ�������Ա�������壬�ú����Զ���Ϊ��������
inline int doubled(int x)
{
	return x * 2;
}
//ʹ��const�����ĺ������ǳ���Ա����
//���������ܸ��º�����״̬

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

//��Ԫû��thisָ�룬�����ڷ��ʶ����ʱ��Ҫ������

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


//�ڷ��ض���ʱʹ�ø��ƹ��캯��


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
//��������Ƿ���һ�������ָ������� ���
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
	cout << "���ƹ���" << endl;
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
	cout << "���صȺ�" << endl;
}

int main()
{
	my_string obj = input();
	obj.show();
	system("pause");
	return 0;
}







