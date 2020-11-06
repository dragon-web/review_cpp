#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<stack>

using namespace std;
/*
class Solution {
public:
	bool buddyStrings(string A, string B) {
		if (A.size() != B.size()) return false;
		if (A == B) {
			unordered_map<char, int> hash;
			for (char c : A) hash[c] += 1;
			for (char c : A) {
				if (hash[c] > 1) return true;
			}
			return false;
		}
		else {
			int first = -1, second = -1;
			for (int i = 0; i < A.size(); i++) {
				if (A[i] != B[i]) {
					if (first == -1)
						first = i;
					else if (second == -1)
						second = i;
					else return false;
				}
			}
			return (second != -1 && A[first] == B[second] && A[second] == B[first]);
		}
	}
};
*/

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		vector<int> dp;
		vector<int> dp1;
		stack<ListNode*> temp;
		ListNode* p = head;
		ListNode* tail = head;
		while (p != NULL)
		{
			dp.push_back(p->val);
			temp.push(p);
			p = p->next;
		}
		while (temp.size())
		{
			int num = temp.top()->val;
			dp1.push_back(num);
			temp.pop();
		}
		if (dp1 == dp)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	
	system("pause");
	return 0;
}