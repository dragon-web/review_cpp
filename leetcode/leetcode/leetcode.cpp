#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<iostream>
/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


struct ListNode
{
	int val;
	struct ListNode *next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{

	//DEV
	int flag1 = 1, flag2 = 1;
	struct ListNode *l = NULL, *p = NULL, *head;
	int temp = 0, flag = 0;
	l = (struct ListNode*)malloc(sizeof(struct ListNode));
	l->val = 0;
	head = l;
	temp = l1->val + l2->val;
	if (temp >= 10)
	{
		temp -= 10;
		flag = 1;
	}
	l->val += temp;
	l1 = l1->next;
	l2 = l2->next;  //链表根本就没连住
	while (l1 != NULL && l2 != NULL)
	{
		p = (struct ListNode*)malloc(sizeof(struct ListNode));
		p->val = 0;
		if (flag == 1)
		{
			p->val = 1;
			flag = 0;
		}
		temp = l1->val + l2->val + p->val;
		if (temp >= 10)
		{
			temp -= 10;
			flag = 1;
		}
		p->val = temp;
		l1 = l1->next;
		l2 = l2->next;
		l->next = p;
		l = p;
	}
	if (l1 == NULL)
		flag1 = 0;
	if (l2 == NULL)
		flag2 = 0;
	if (l1 == NULL && l2 == NULL && flag == 1)
	{
		p = (struct ListNode*)malloc(sizeof(struct ListNode));
		p->val = 1;
		l->next = p;
		p->next = NULL;
		return head;
	}
	if (flag1)
	{
		while (l1->next != NULL)
		{
			if (flag == 1)
			{
				l1->val += 1;
				if (l1->val > 9)
				{
					l1->val -= 10;
					flag = 1;
				}
				else
				{
					flag = 0;
				}
			}
			l->next = l1;
			l = l->next;
			l1 = l1->next;
		}
	}
	if (flag2)
	{
		if (flag == 1)
		{
			l2->val += 1;
		}
		l->next = l2;
		l = l->next;
		l2 = l2->next;
	}
	return head;
}




int main()
{
	struct ListNode*l1, *l2, *l, *p, *head1, *head2;
	int i = 0, j = 0;
	l1 = (ListNode*)malloc(sizeof(struct ListNode));
	l2 = (ListNode*)malloc(sizeof(struct ListNode));
	head1 = l1;
	head2 = l2;
	while (i != -1)
	{
		scanf("%d", &i);
		if (i == -1)break;
		p = (ListNode*)malloc(sizeof(struct ListNode));
		p->val = i;
		l1->next = p;
		l1 = p;
	}
	l1->next = NULL;
	while (j != -1)
	{
		scanf("%d", &j);
		if (j == -1)break;
		p = (ListNode*)malloc(sizeof(struct ListNode));
		p->val = j;
		l2->next = p;
		l2 = p;
	}
	l2->next = NULL;
	l = addTwoNumbers(head1->next, head2->next);
	while (l != NULL)
	{
		printf("%d ", l->val);
		l = l->next;
	}

	system("pasue");
	return 0;

}

