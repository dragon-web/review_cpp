#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>

using namespace std;
 
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
				Dele(min, head);
				p = p->next;
			}
		}
	}
};

class Solution {
public:
	ListNode* findMiddle(ListNode* head) {
		ListNode* chaser = head;
		ListNode* runner = head->next;
		while (runner != NULL && runner->next != NULL) {
			chaser = chaser->next;
			runner = runner->next->next;
		}
		return chaser;
	}

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL) {
			return l2;
		}
		if (l2 == NULL) {
			return l1;
		}
		ListNode* dummy = new ListNode(0);
		ListNode* head = dummy;
		while (l1 != NULL && l2 != NULL) {
			if (l1->val > l2->val) {
				head->next = l2;
				l2 = l2->next;
			}
			else {
				head->next = l1;
				l1 = l1->next;
			}
			head = head->next;
		}
		if (l1 == NULL) {
			head->next = l2;
		}
		if (l2 == NULL) {
			head->next = l1;
		}
		return dummy->next;
	}

	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}
		ListNode* middle = findMiddle(head);
		ListNode* right = sortList(middle->next);
		middle->next = NULL;
		ListNode* left = sortList(head);
		return mergeTwoLists(left, right);
	}
};


int main()
{


	system("pause");
	return 0;
}