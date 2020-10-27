#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
/*
class Solution {
public:
	bool JudgeNum(int num)
	{
		vector<int> temp;
		for (int i = 2; i <= num; ++i)
		{
			while ( num % i == 0)
			{
				num /= i;
				temp.push_back(i);
			}
		}
		auto it = temp.begin();
		while (it != temp.end())
		{
			if (*it == 2 || *it == 3 || *it == 5)
				it++;
			else {
				break;
			}
		}
		if (it != temp.end() || temp.size() == 0)
		{
			return false;
		}
		else {
			return true;
		}
	}
	int GetUglyNumber_Solution(int index) {
		if (index == 1)
			return 1;
		if (index == 2)
			return 3;
		if (index == 3)
			return 5;
		else
		{
			vector<int> dp;
			int count = 3;
			int i;
			for (i = 6; i < 2147483647 && count < index; ++i)
			{
				if (JudgeNum(i))
				{
					count++;
					cout << i << " ";
				}
			}
			return i-1;
		}
	}
};

int main()
{
	Solution a;
	int num = a.GetUglyNumber_Solution(9);
	//cout << num << endl;
	system("pause");
	return 0;
}
*/

class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		if (index <= 0) return 0;
		vector<int> ugly(index);
		ugly[0] = 1;
		int  p2 = 0, p3 = 0, p5 = 0;
		for (int i = 1; i < index; ++i) {
			ugly[i] = min(ugly[p2] * 2, min(ugly[p3] * 3, ugly[p5] * 5));
			if (ugly[i] == ugly[p2] * 2) ++p2;
			if (ugly[i] == ugly[p3] * 3) ++p3;
			if (ugly[i] == ugly[p5] * 5) ++p5;
		}
		return ugly[index - 1];
	}
};