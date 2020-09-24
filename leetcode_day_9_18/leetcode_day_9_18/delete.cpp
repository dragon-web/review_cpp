#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>

using namespace std;

/*
��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻������
��������ͷָ�롣 ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
*/
/*
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
class Solution {
public:
	bool Find(vector<int> & dp, ListNode* p)
	{
		auto it = dp.begin();
		int flag = 0;
		while (it != dp.end())
		{
			if (*it == p->val)
			{
				flag = 1;
				return false;  //˵���ҵ��ظ�����Ҫɾ������ڵ�
			}
			it++;
		}
		if (flag == 0)  //˵��û���ҵ�
		{
			dp.push_back(p->val);
			return true;
		}
		return false;
	}
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL)
		{
			return pHead;

		}
		vector<int> dp;
		dp.push_back(pHead->val);
		if (pHead != NULL)
		{
			ListNode* temp = pHead;
			ListNode* pst = pHead->next;
			while (pst != NULL)
			{
				if (!Find(dp, pst))
				{
					temp->next = pst->next;
					pst = temp->next;
				}
				temp = temp->next;
				pst = pst->next;
			}
			return pHead;
		}
		return pHead;
	}
};


int main()
{
	Solution a;
	ListNode l1(1);
	ListNode l2(2);
	ListNode l3(3);
	ListNode l4(3);
	ListNode l5(4);
	ListNode l6(4);
	ListNode l7(5);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	l6.next = &l7;
	auto res = a.Solution::deleteDuplication(&l1);
	while (res != NULL)
	{
		cout << res->val << " ";
		res = res->next;
	}
	system("pause");
	return 0;
}




using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
class Solution {
public:
	
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead != NULL)
		{
			ListNode* res;
			ListNode* head = new ListNode(0);
			ListNode* temp = head;
			ListNode* p1 = pHead;
			ListNode* p2 = pHead;
			int count = 0;
			while (p1 != NULL)
			{
				while (p2 != NULL)
				{
					if (p1->val == p2->val)
					{
						count++;
					}
					p2 = p2->next;
				}
				if (count == 1)
				{
					res = new ListNode(p1->val);
					temp->next = res;
					temp = temp->next;
				}
				count = 0;
				p1 = p1->next;
				p2 = pHead;
			}
			return head->next;
		}
		else
		{
			return pHead;
		}
	}
	
};


int main()
{
	Solution a;
	ListNode l1(1);
	ListNode l2(2);
	ListNode l3(3);
	ListNode l4(3);
	ListNode l5(4);
	ListNode l6(4);
	ListNode l7(5);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	l6.next = &l7;
	auto res = a.Solution::deleteDuplication(&l1);
	while (res != NULL)
	{
		cout << res->val << " ";
		res = res->next;
	}
	system("pause");
	return 0;
}
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int Count_One(int num)
	{
		int tes = 0;
		while (num != 0)
		{
			if (num % 10 == 1)
			{
				tes++;

			}
			num /= 10;

		}
		return tes;

	}

	int NumberOf1Between1AndN_Solution(int n)
	{
		int sum = 0;
		int count = 0;
		for (int i = 1; i <= n; ++i)
		{
			count = Count_One(i);
			sum += count;
			count = 0;

		}
		return sum;
	}
};

int main()
{
	int num = 13;
	Solution a;
	int res = a.NumberOf1Between1AndN_Solution(num);
	cout << res << endl;
	system("pause");
	return 0;
}
