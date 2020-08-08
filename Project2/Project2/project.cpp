#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<Windows.h>
#include<iostream>
using namespace std;
/*
int main()
{
	const char* str[3] = { "stra","strb","strc" };
	const char *p = str[0];
	int i = 0;
	while (i < 3)
	{
		printf("%s\n", p);
		++i;
	}
	system("pause");
	return 0;
}


int main()
{
	char s[20];
	strcpy(s, "Hello,World");
//	strcpy(s, "Hell");
	printf("s[]=%6.3s", s);
	system("pause");
	return 0;
}


#include<iostream>

using namespace std;

int main()
{
	const char* str[3] = { "stra","strb","strc" };
    auto p = str;
	cout << typeid(p).name << endl;
	int i = 0;
	while (i < 3)
	{
		printf("%s\n", p[i]);
		++i;
	}
	system("pause");
	return 0;
}

using namespace std;

int main()
{
	int a = 5;
	int * const p = &a;
	cout << *p << endl;
	a = 6;
	cout << *p << endl;
	system("pause");
	return 0;
}
int main()
{
    int a = 5;
	int b = 6;
	int const * p = &a;
	cout << *p << endl;
	p = &b;
	cout << *p << endl;

	system("pause");
	return 0;
}


int main()
{
	const char * p = "str";
	cout << p << endl;
	p = "asdnaj";
	cout << p << endl;
	system("pause");
	return 0;
}
*/


int main()
{
	char const * str[3] = { "stra","strb","strc" };
	char const *p = str[0];
	int i = 0;
	char const * res[3] = str;
	auto deal = str;
	cout << typeid(deal).name() << endl;
	cout << typeid(str).name() << endl;
	while (i < 3)
	{
		printf("%s\n", *(deal++));
		++i;
	}
	i = 0;
	while(i < 3)
	{
		printf("%s\n", p++);
		++i;
	}
	/*while (i < 3)
	{
		printf("%s\n", p++);
		++i;
	}*/
	
	system("pause");
	return 0;
}



/*
int main()
{
	char const * str[3] = { "stra","strb","strc" };
	//char const *p = str[0];
	int i = 0;
	i = 0;
	while (i < 3)
	{
		printf("%s\n", str[i]);
		++i;
	}
	system("pause");
	return 0;
}*/