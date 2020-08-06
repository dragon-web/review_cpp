#define _CRT_SECURE_NO_WARNINGS 
/*
#include<Windows.h>
#include<stdio.h>
typedef struct _SoftArray {
	int len;
	int array[];
}SoftArray;

int main()
{
	int len = 10;

	printf("The struct's size is %d\n", sizeof(SoftArray));
	system("pause");
	return 0;
}
 大小为4
*/

/*
#include<stdio.h>
#include<malloc.h>
#include<Windows.h>
typedef struct _SoftArray {
	int len;
	int array[];
}SoftArray;


int main()
{
	int len = 10;
	SoftArray *p = (SoftArray*)malloc(sizeof(SoftArray) + sizeof(int)*len);
	printf("After the malloc function the struct's size is %d\n",sizeof(SoftArray));
	system("pause");
	return 0;
}
 大小依旧为4


#include<windows.h>
#include<stdio.h>
#include<malloc.h>
typedef struct _SoftArray {
	int len;
	int array[];
}SoftArray;
int main()
{
	int len = 10, i = 0;

	SoftArray *p = (SoftArray*)malloc(sizeof(SoftArray) + sizeof(int)*len);
	p->len = len;
	for (i = 0; i < p->len; i++)
	{
		p->array[i] = i + 1;
	}
	for (i = 0; i < p->len; i++)
	{
		printf("%d\n", p->array[i]);
	}
	for (int i = 0; i < 11; ++i)
	{
		printf("%d", p[i]);
	}
	free(p);
	system("pause");
	return 0;
}





int main(void)
{
	char s[] = "Golden Global View";
	memmove(s, s + 7, strlen(s) + 1 - 7);
	printf("%s", s);
	system("pause");
	return 0;
}
int main(void)
{
	char s[] = "Hello Bit";
	memmove(s, s + 7 ,strlen(s) + 1 - 8); //内存覆盖
	printf("%s", s);
	system("pause");
	return 0;
}
#include <stdio.h>
#include <string.h>
#include<windows.h>

#pragma pack(2)

int main(void)
{
	struct test 
	{
			char a;
			short b;
			int c;
			long d;
	};

	struct C
	{
		char b;
		int a;
		short c;
	};
	struct test t = { 'a',11,11,11 };
	printf("size of struct t = %u\n", sizeof(t));
	printf("size of struct t = %u\n", sizeof(C));
	system("pause");
	return 0;
}
*/
/*
 volatile是一个特征修饰符
（type specifier）.volatile的作用是作为指令关键字，
确保本条指令不会因编译器的优化而省略，且要求每次直接读值。

#include <stdio.h>
#include <string.h>
#include<windows.h>
 int main()
{
	//int a = 666, b = 888;
	//printf("%d\n", a, b);
	 printf("%d", sizeof(void));
	system("pause");
	return 0;
}

#include <unistd.h>

#include <stdio.h>

int main(void) {

	int i = 0;

	for (i = 0; i < 2; i++) {

		pid_t fpid = fork();

		if (fpid == 0)

			printf("hello world!\n");

		else

			printf("hello world!\n");

	}

	return 0;
}
*/
