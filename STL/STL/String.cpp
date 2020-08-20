#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<list>
using namespace std;
/*
int main()
{
	int a[5] = { 1 , 2 , 3 , 4 , 5 };
	list<int> ls(a, a + 5);
	list<int>::iterator p = ls.begin();
	advance(p,2);
	cout << "*p = " << *p << endl;
	advance(p, -1);
	cout << "*p = " << *p << endl;
	list<int>::iterator q = ls.end();
	cout << "*q = " << *--q << endl;
	advance(q, -1);
	cout << "*q = " << *q << endl;
	cout << "distance(p,q) = " << distance(p, q) << endl;
	//cout << "distance(p,q) = " << distance(q, p) << endl; //会使程序崩溃，因为只能进行++操作不能进行--操作
	iter_swap(p,q);
	for (auto temp : ls)
	{
		cout << temp << endl;
	}
	for (list<int>::iterator dp = ls.begin(); dp != ls.end(); dp++)
	{
		cout << *dp << endl;
	}

	list<int>::iterator cp = find(ls.begin(), ls.end(), 6);
	if (cp == ls.end())
	{
		cout << "not find" << endl;
	}
	//cout << "*cp = " << *cp << endl;
	
	system("pause");
	return 0;
}*/