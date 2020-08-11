#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
//用相同的方法实现不同的功能

/*
int main()
{
	int sum, pad, pAd;
	sum = pad = 5;
	pAd = ++sum, pAd++, ++pad;
	printf("%d\n", pad);
	system("pause");
	return 0;
}
数组指针
int main()
{
	int arr[3][2] = {1,2,3,4,5,6};
	int(*p)[2] = arr;
	printf("%d\n", **p); 
	printf("%d\n", **(++p)); 
	printf("%d\n",*(*p+1)); 
	system("pause");
	return 0;
}



#include <iostream>
using namespace std;
void fun(int *p1, int *p2, int *t)
{
	t = (int *)malloc(sizeof(int));
	*t = *p1 + *(p2++);
}
int main()
{
	int a[2] = { 1,2 };
	int b[2] = { 10,20 };
	int *t = a;
	fun(a, b, t);
	cout << *t << endl;
	system("pause");
	return 0;
}


#include <iostream>
using namespace std;
void fun(int *p1, int *p2, int **t)
{
	*t = (int *)malloc(sizeof(int));
	**t = *p1 + *(p2++);
}
int main()
{
	int a[2] = { 1,2 };
	int b[2] = { 10,20 };
	int *t = a;
	fun(a, b, &t);
	cout << *t << endl;
	system("pause");
	return 0;
}
*/