#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>

using namespace std;
/*

int a[3][100]; //a[1][j]表示底盘在装配线s[1][j]所用时间
int t[3][100]; //t[1][j]表示底盘从s[1][j]移动到s[2][j+1]所用时间
int n;//装配站的数目
int e1, e2; //进入装配线1,2时间
int x1, x2;// 离开时间

int f1[100], f2[100];

int L1[100], L2[100];
//L1[j]记录第一条装配线上,最优解时第j个装配站的前一个装配站是第一条线还是第二条线上
int f, L;  //最优解是f,最小花费时间,L代表最后是从哪里出来的

void fastest_way()  //寻找最快通路
{
	f1[1] = e1 + a[1][1]; //记录装配线1起步用的时间
	f2[1] = e2 + a[2][1];//记录装配线2起步用的时间
	for (int j = 2; j <= n; j++) //局部最少判断

	{
		if ((f1[j - 1] + a[1][j]) < (f2[j - 1] + t[2][j - 1] + a[1][j])) //如果当前线路（线路1）到达下一目的地小于切换后到达下一目的地时间
		{
			f1[j] = f1[j - 1] + a[1][j];
			L1[j] = 1;
		}
		else //否则切换线路
		{
			f1[j] = f2[j - 1] + t[2][j - 1] + a[1][j];  
			L1[j] = 2;
		}
		if ((f2[j - 1] + a[2][j]) < (f1[j - 1] + t[1][j - 1] + a[2][j]))  //同理，如果当前线路（线路2）到达下一目的地小于切换后到达下一目的地时间
		{
			f2[j] = f2[j - 1] + a[2][j];
			L2[j] = 2;
		}
		else
		{
			f2[j] = f1[j - 1] + t[1][j - 1] + a[2][j];
			L2[j] = 1;
		}
	}


	if ((f1[n] + x1) <= (f2[n] + x2))  //计算出站（最后一站）选择线路
	{
		f = f1[n] + x1;
		L = 1;
	}
	else
	{
		f = f2[n] + x2;
		L = 2;
	}

}


void print_station() //打印最终搜寻结果
{
	int i = L;
	cout << endl << "线路: " << L << "站: " << n << endl;
	for (int j = n; j >= 2; j--)
	{
		if (i == 1)
			i = L1[j];
		else
			i = L2[j];
		cout << "线路: " << i << "站: " << j - 1 << endl;
	}
}


int main()
{
	cout << "请输入装配站的数目\n";
	cin >> n;
	cout << "请输入进入装配线1,2所需时间";
	cin >> e1 >> e2;
	cout << "请输入离开装配线1,2所需时间";
	cin >> x1 >> x2;
	cout << "输入装配线1上各站加工时所需时间a1[j]";
	for (int j = 1; j <= n; j++)
		cin >> a[1][j];
	cout << "输入装配线2上各站加工时所需时间a1[j]";
	for (int j = 1; j <= n; j++)
		cin >> a[2][j];
	cout << "请输入装配线1上的站到装配线2上的站所需时间t[1][j]";
	for (int j = 1; j < n; j++) //j<n
		cin >> t[1][j];
	cout << "请输入装配线2上的站到装配线1上的站所需时间t[2][j]";
	for (int j = 1; j < n; j++) //j<n
		cin >> t[2][j];
	cout << "通路为：" << endl;
	fastest_way();
	print_station();
	system("pause");
	return 0;
}
*/