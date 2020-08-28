#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include"test.h"
using namespace std;



struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};


ListNode* ReverseList(ListNode* pHead)
{
	if (pHead == NULL || pHead->next == NULL)
	{
		return pHead;
	}
	ListNode *p = new ListNode(0);
	ListNode *head = p;
	ListNode *last = pHead;
	while (last->next != NULL)
	{
		last = last->next;
	}
	p->next = NULL;
	ListNode *q = pHead;
	ListNode *temp = q->next;
	while (q != NULL)
	{
		q->next = p;
		p = q;
		q = temp;
		if (temp != NULL)
			temp = temp->next;
	}
	pHead->next = NULL;
	free(head);
	return last;
}


ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	ListNode* p = pListHead;
	ListNode* q = p;
	size_t count = 0;
	size_t temp = 0;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	if (k > count)
	{
		return NULL;
	}
	if (k <= count)
	{
		while (temp != count - k && q != NULL)
		{
			temp++;
			q = q->next;
		}
	}
	return q;
}

vector<int> printListFromTailToHead(ListNode* head) {
	vector<int> dp;
	ListNode *p = head;
	while (p != NULL)
	{
		dp.push_back(p->val);
		p = p->next;
	}
	return dp;
}


int main()
{

	ListNode p1(67);
	ListNode p2(0);
	ListNode p3(24);
	ListNode p4(58);
	p1.next = &p2;
	p2.next = &p3;
	p3.next = &p4;
	p4.next = NULL;
	vector<int> p = printListFromTailToHead(&p1);
	std::reverse(p.begin(), p.end());
	for (auto &e : p)
	{
		cout << e << " ";
	}

	system("pause");
	return 0;
}















	/*auto temp = ReverseList(&p1);
	vector<vector<int>> dp(3);
	cout << typeid(dp).name() << endl;
	
	/*for (int i = 0; i < dp.size(); ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			dp[i].push_back(i+j);
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	char str[] = { 'w','e',' ','t','\0' };
	int sz = strlen(str);
	char* p = replaceSpace(str, sz);


	system("pause");
	return 0;
}

*/


