#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<iostream>
#include<string.h>


using namespace std;


//建立模型，使用2的整数次幂表示不同人，所以使用一个整数表示当前的局面， 255为初始，0为结束 
enum { POLICE = 0x80, THIEF = 0x40, DAD = 0x20, BOY1 = 0x10, BOY2 = 0x8, MOM = 0x4, GIRL1 = 0x2, GIRL2 = 0x1, ALL = 0xff, OK = 0 };
//判断集合A是否属于集合B
bool test1(int A, int B)
{
	return (A&B) == A;
}
//判断集合A是否可以和平相处 
bool test2(int A)
{
	//小偷不能在警察不在的情况下，和其他人相处 
	if (!test1(POLICE, A) && test1(THIEF, A) && A != THIEF) return 0;
	//妈妈不能在爸爸不在的情况下，和儿子相处 
	if (!test1(DAD, A) && test1(MOM, A) && (test1(BOY1, A) || test1(BOY2, A))) return 0;
	//爸爸不能在妈妈不在的情况下，和女儿相处 
	if (!test1(MOM, A) && test1(DAD, A) && (test1(GIRL1, A) || test1(GIRL2, A))) return 0;
	return 1;
}
//打印结果 
void print(int A, int k)
{
	static const char*name[8] = { "女儿","女儿","妈妈","儿子","儿子","爸爸","小偷","警察" };
	char str[32] = { 0 };
	int i, j;
	for (i = 1, j = 0; j < 8; i <<= 1, ++j)
		if (test1(i, A))
		{
			if (*str)
				strcat(str, "+");
			strcat(str, name[j]);
		}
	printf("%d:%s\n", k, str);
}
//深搜求解 ,A是当前没过河的人的集合，n是第几步，answer结果数组，finded状态标记数组 
void DFS(int A, int n, int* answer, bool *finded)
{
	int i;
	//递归程序的非递归出口，找到了一组解 
	if (A == OK)
	{
		for (i = 0; i < n; i++) print(answer[i], i + 1);
		return;
	}
	if (n >= 20) return;//不能超过20层，否则回溯 
	//乘船组合 
	static int a[15] = { POLICE | THIEF,POLICE | DAD,POLICE | BOY1,POLICE | BOY2,POLICE | MOM,POLICE | GIRL1,POLICE | GIRL2,
					POLICE,DAD | BOY1,DAD | BOY2,DAD | MOM,DAD,MOM | GIRL1,MOM | GIRL2,MOM };
	int B = ALL - A;//已过河人的集合 
	if (n & 1)//回来
		for (i = 0; i < 15; i++)
		{
			//如果准备测试上船的人不在集合当中，忽略； 
			if (!test1(a[i], B)) continue;
			//如果准备测试上船的人走后，剩下的人不能和平相处，忽略
			//如果准备测试上船的人到达对岸后，与对岸不能和平相处，忽略
			if (!test2(A + a[i]) || !test2(B - a[i])) continue;
			//如果出现过此状态，忽略，避免走重复路 
			if (finded[A + a[i] + 256]) continue;
			//接受这种境况，向下一轮搜索，递归
			answer[n] = a[i];
			finded[A + a[i] + 256] = 1;
			DFS(A + a[i], n + 1, answer, finded);
		}
	else//去 
		for (i = 0; i < 15; i++)
		{
			//如果准备测试上船的人不在集合当中，忽略； 
			if (!test1(a[i], A)) continue;
			//如果准备测试上船的人走后，剩下的人不能和平相处，忽略
			//如果准备测试上船的人到达对岸后，与对岸不能和平相处，忽略
			if (!test2(A - a[i]) || !test2(B + a[i])) continue;
			//如果出现过此状态，忽略，避免走重复路 
			if (finded[A - a[i]]) continue;
			//接受这种境况，向下一轮搜索，递归
			answer[n] = a[i];
			finded[A - a[i]] = 1;
			DFS(A - a[i], n + 1, answer, finded);
		}
}
int main()
{
	bool finded[512] = { 0 };//表示状态，简单的使用1--255表示各种人的组合，结合那条船的位置，所以用了512 
	int answer[20];
	DFS(ALL, 0, answer, finded);
	system("pause");
	return 0;
}


