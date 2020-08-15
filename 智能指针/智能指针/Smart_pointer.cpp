#define _CRT_SECURE_NO_WARNINGS 
#define  MAX(x,y)  (x)>(y)?(x):(y)

#include<iostream>

using namespace std;
/*
int main()
{
	
	system("pause");
	return 0;
}
int func(int a, int b)
{
	static int m = 0, i = 2;
	i += m + 1;
	m = i + a + b;
	return m;
}

void fun(char *c, int d)

{

	*c = *c + 1;

	d = d + 1;

	printf("%c, %c", *c, d);

}*/

	/*char c3[] = "a\x41\\bcde\106F";
	cout << strlen(c3) << endl;

	int sum = 4; int pad = 5;

	pad = sum++, pad++, ++pad;

	printf("%d\n", pad);
	int   a = 25, b = 025, c = 0x25;

	int x = 12;

		printf("%-6d##\n", x);

	int n = 'e';

	switch (n--)

	{

	default: printf("error ");

	case 'a':

	case 'b': printf("good "); break;//break跳出

	case 'c': printf("pass ");

	case 'd': printf("warn ");

	}
	int n = 5;

	if (n++ >= 6)  //先取值后运算n=6

		printf("%d\n", n);

	else

		printf("%d\n", ++n);  //先运算后取值n=7


	int a = 10, b = 50, c = 30;

	if (a > b)

		a = b;

	b = c;

	c = a;

	printf("a=%d b=%d c=%d\n", a, b, c);


	int i, j;
	for (i = 0, j = 3; i <= j; i += 2, j--)
		printf("%d\n", i);
	int x = 1, y = 0, a = 0, b = 0;

	switch (x)

	{
	case 1:

		switch (y)

		{
		case 0:a++; break;

		case 1:b++; break;

		}

	case 2:     a++; b++; break;

	}

	printf("%d  %d\n", a, b);
	

		int a = 100;

		if (a > 100)

			printf("%d\n", a > 100);

		else

			printf("%d\n", a <= 100);
	{int i, s = 1, sum = 0;
	for (i = 1; i <= 5; i++)
	{
		s = s * i;  sum = sum + s;
	}
	printf("%d", sum);
	}
	{ int i, s = 0, sign = 1;
	for (i = 1; i <= 100; i++)
	{
		s = s + sign * i;
		sign = sign * (-1);
	}
	printf("%d", s);
	}

	system("pause");
	return 0;
}

int f(int a, int b)
{
	int c;
	if (a > b)  c = 1;
	else if (a == b)  c = 0;
	else c = -1;

	return c;

}

#define Y(x) x+2

int func(int a, int b)

{

	static int m = 0, i = 2;

	i += m + 1;

	m = i + a + b;

	return m;

}
int f(int a)

{

	int b = 0;

	static int c = 3;

	b++; c++;

	return a + b + c;

}
enum data { a1, a2 = 7, a3, a4 = 15 };
int main()

{

	int b = 0;

	struct  ex

	{

		int x, y;

	}a[2] = { 1,2,3,4 }, *p = a;

	b = b + p->x + p->y*(p + 1)->x;
	cout << b;
	system("pause");
	return 0;
}
*/