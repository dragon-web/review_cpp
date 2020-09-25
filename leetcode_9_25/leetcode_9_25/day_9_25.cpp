#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<list>
using namespace std;

/*
class Solution {
public:
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
	int LastRemaining_Solution(int n, int m)
	{
		ListNode* head = new ListNode(0);
		ListNode* tail = head;
		int temp = 1;
		while (temp < n)
		{
			ListNode* p = new ListNode(temp);
			temp++;
			tail->next = p;
			tail = tail->next;
		}
		temp = 0;
		while()
	}
};
*/

/*
class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		list<int> dp;
		int temp = 0;
		while (temp < n)
		{
			dp.push_back(temp);
			temp++;
		}
		int i = 0;
		auto it = dp.begin();
		while (n != 1)
		{
			if (i == m - 1)
			{
				it = dp.erase(it);
				if (it == dp.end())
				{
					it = dp.begin();
				}
				n--;
				i = 0;
			}
			i++;
			it++;
			if (it == dp.end())
			{
				it = dp.begin();
			}
		}
		return *dp.begin();
	}
};
*/

class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n <= 0) return -1;
		list<int> lt;
		for (int i = 0; i < n; ++i)
			lt.push_back(i);
		int index = 0;
		while (n > 1) {
			index = (index + m - 1) % n;
			auto it = lt.begin();
			std::advance(it, index); // 让it向后移动index个位置    
			lt.erase(it);
			--n;
		}
		return lt.back();
	}
};

int main()
{
	Solution a;
	int res = a.LastRemaining_Solution(1010, 27);
	cout << res << endl;
	system("pause");
	return 0;
}
