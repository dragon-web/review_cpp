#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{

	string frame;
	string brick;
	while (cin >> frame >> brick)
	{
		int i = frame.size();
		int j = brick.size();
		int maxsize = i > j ? i : j;
		int minsize = i < j ? i : j;
		const int distance = maxsize - minsize;
		vector<int> p[distance];
		vector<int> dp(i);
		vector<int> dp1(j);
		vector<int> dp2;
		int temp1 = atoi(frame.c_str());
		int temp2 = atoi(brick.c_str());
		while (distance)
		{


		}
		auto temp3 = dp2.begin();
		int min = *temp3;
		for (int i = 0; i < dp2.size(); ++i)
		{
			min < dp2[i] ? min : dp2[i];
		}
			cout << min << endl;
	system("pause");
	return 0;
}


	/*
	˼·:ת���ִ���Ȼ����ӣ�ƽ����Ҫ���������룬��������ú͵�������С������Сδ������
	
	
	*/