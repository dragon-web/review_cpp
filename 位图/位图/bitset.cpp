#define _CRT_SECURE_NO_WARNINGS 


#include<iostream>
#include<bitset>
#include<vector>
using namespace std;
/*
ϵͳ���ṩ�˶��ڶ����ƵĲ���


*/

int main()
{
	bitset<10>bt;
	cout << bt<<endl;
	bt.set(3, 1);
	cout << bt << endl;
	bt.flip();
	cout << bt<<endl;  //��bt����ȡ��
	bt.set(3, 0);
	cout << bt << endl;
	bt.any();//���������Ƿ���һ��λΪ1�ģ�������򷵻���
	cout << bt.any() << endl;
	cout<<bt.test(1) << endl; //���Եڼ�λ�Ƿ�Ϊ1
	cout << bt.to_ulong() << endl;//ת��Ϊ10����
	system("pause");
	return 0;
}
