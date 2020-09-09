#define _CRT_SECURE_NO_WARNINGS 


#include<iostream>
#include<bitset>
#include<vector>
using namespace std;
/*
系统里提供了对于二进制的操作


*/

int main()
{
	bitset<10>bt;
	cout << bt<<endl;
	bt.set(3, 1);
	cout << bt << endl;
	bt.flip();
	cout << bt<<endl;  //对bt进行取反
	bt.set(3, 0);
	cout << bt << endl;
	bt.any();//用来测试是否有一个位为1的，如果有则返回真
	cout << bt.any() << endl;
	cout<<bt.test(1) << endl; //测试第几位是否为1
	cout << bt.to_ulong() << endl;//转换为10进制
	system("pause");
	return 0;
}
