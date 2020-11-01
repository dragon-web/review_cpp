#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<stack>
#include<map>
#include<set>
#include<string>
#include<unordered_map>
#include<unordered_set>

using namespace std;
/*
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode* p1 = headA;
		ListNode* p2 = headB;
		if (p1 == NULL || p2 == NULL)
		{
			return NULL;
		}
		while (p1 != p2)
		{
			if (p1 == NULL)
			{
				p1 = headB;
				continue;
			}
			if (p2 == NULL)
			{
				p2 = headA;
				continue;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		return p1;
	}
};
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA || !headB) {
			return nullptr;
		}
		ListNode *pA = headA, *pB = headB;
		while (pA != pB) {
			pA = pA == nullptr ? headB : pA->next;
			pB = pB == nullptr ? headA : pB->next;
		}
		return pA;
	}
};

class Solution {
public:
	bool isAnagram(string s, string t) {
		multiset<char> temp1;
		for (int i = 0; i < s.size(); ++i)
		{
			temp1.insert(s[i]);
		}
		multiset<char> temp2;
		for (int i = 0; i < t.size(); ++i)
		{
			temp2.insert(t[i]);
		}
		return temp1 == temp2;
	}
};

int main()
{
	/*pair<int, string> v1 = { 1,"abc" };
	pair<int, string>v2 = { 2,"sa" };
	cout << v2.first << endl;
	multiset<int> dp;
	for (int i = 0; i < 10; ++i)
	{
		dp.insert(i);
	}
	dp.insert(3);
	dp.insert(4);
	dp.insert(5);
	for (auto &e : dp)
	{
		cout << e << " ";
		cout << dp.count(3) << endl;
	}


	map<string, string> a = { { "Test" ,"sbha"} };
	pair<string, string> a1 = { "el","sbha" };
	a.insert(a1);
	
	a.insert( a.begin(),make_pair("hl","sbha") );
	cout << a.size() << endl;
	for (auto & e : a)
	{
		cout<<e.first<<" "<< e.second<<endl;
	}
	system("pause");
	return 0;
}*/


int main()
{
	unordered_multiset<int> hset = { 43,31,435,5,6535,2,13,14,14,4545 };
	 
	for (auto &e : hset)
	{
		cout << e << endl;
	}

	system("pause");
	return 0;
}