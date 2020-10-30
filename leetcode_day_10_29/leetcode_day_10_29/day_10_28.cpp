#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>

using namespace std;
/*
int lengthOfLastWord(string s) {
	if (s.size() == 0)
	{
		return 0;
	}
	int pos = s.rfind(' ');
	if (pos == string::npos)
		return s.size();
	return s.size() - pos - 1;
}


int main()
{

	string a("s");
	int ad = lengthOfLastWord(a);
	cout << ad << endl;
	system("pause");
	return 0;
}
*/
/*
class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& A) {
		vector<int> temp;
		size_t len1 = A.size();
		size_t  len2 = A[0].size();
		vector<vector<int>> dp;
		dp.resize(len2);
		temp.resize(len1*len2);
		while ()
		{

		}


		return dp;
	}
};


class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& A) {
		int ro = A.size();
		int co = A[0].size();
		vector<vector<int>> res(co);
		for (int i = 0; i < co; ++i) {
			for (int j = 0; j < ro; ++j)
				res[i].push_back(A[j][i]); 
		}
		return res;
	}
};


class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int count = nums.size() / 2;
		int temp = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = 0; j < nums.size(); ++j)
			{
				if (nums[i] == nums[j])
				{
					temp++;
				}
				if (temp >= count)
				{
					return nums[j];
				}
			}
			temp = 0;
		}
	}
};


struct ListNode {
	int val;
 	struct ListNode *next;
  };
 

class Solution {
public:
	ListNode* FindMin(ListNode* head)
	{
		ListNode*p = head;
		ListNode* temp = p;
		while (p != NULL)
		{
			if (temp->val > p->val)
			{
				temp = p;
			}
			p = p->next;
		}
		return temp;
	}
	ListNode* Dele(ListNode* tar, ListNode* head)
	{
		ListNode* Phead = head;
		if (head == tar)
		{
			head = head->next;
			delete tar;
		}
		else
		{
			while (Phead != NULL)
			{
				if (Phead->next == tar)
				{
					return Phead;
				}
				Phead = Phead->next;
			}
		}
	}

	ListNode* sortList(ListNode* head) {
		if (head == NULL)
		{
			return head;
		}
		else {
			ListNode* Head = new ListNode;
			ListNode* tail = Head;
			ListNode* p = head;
			while (p != NULL)
			{
				ListNode* min = FindMin(head);
				ListNode* temp = new ListNode;
				temp->val = min->val;
				temp->next = NULL;
				tail->next = temp;
				tail->next = NULL;
				Dele(min, head);

				p = p->next;
			}

		}
	}
};
int main()
{
	
	system("pause");
	return 0;
}



class Solution {
public:
	int longestWPI(vector<int>& hours) {
		stack<int> temp;
		stack<int> res;
		vector<int>::iterator it = hours.begin();
		while (it != hours.end())
		{
			if (*it > 8)
			{
				temp.push(*it);
			}
			it++;
		}


	}
};*/

class Solution {
public:
	bool threeConsecutiveOdds(vector<int>& arr) {
		vector<int> dp;
		auto it = arr.begin();
		while (it != arr.end())
		{
			if (*it % 2 == 0)
			{
				dp.push_back(*it);
				if (dp.size() >= 3)
					return true;
			}
			else
			{
				dp.clear();
			}
			it++;
		}
		return false;
	}
};
int main()
{

	system("pause");
	return 0;
}