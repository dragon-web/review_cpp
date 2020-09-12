#define _CRT_SECURE_NO_WARNINGS 

/*
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

void thread_primer(int p)
{
	int i = p;
	int j = 2;
	int flag = 1;
	for (j = 2; j < i / 2; j++)
	{
		if (i % j == 0)
		{
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		printf("%d 是质数\n", i);
	}
}

int main()
{
	for (int i = 20000; i <= 20200; ++i)
	{
		thread_primer(i);
	}
	system("pause");
	return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
void thread_primer(int p)
{
	int i = p;
	int j = 2;
	int flag = 1;
	for (j = 2; j < i / 2; j++)
	{
		if (i % j == 0)
		{
			flag = 0;
			break;
		}

	}
	if (flag)
	{
		printf("%d 是质数", i);
	}

}

int main()
{
	int i = 20007;
	thread_primer(i);
	system("pause");
	return 0;
}
*/
/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/


#include<iostream>

using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
  /*
  class Solution {
  public:
	  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		  size_t length1 = 0, length2 = 0;
		  ListNode* p = l1;
		  ListNode* q = l2;
		  ListNode* temp1 = l1;
		  ListNode* temp2 = l2;
		  int length;
		  int count = 1; //表示进位
		  while (p != NULL)
		  {
			  p = p->next;
			  length1++;
		  }
		  while (q != NULL)
		  {
			  q = q->next;
			  length2++;
		  }
		  if (length1 == 0)
		  {
			  return l2;
		  }
		  if (length2 == 0)
		  {
			  return l1;
		  }
		  length = length1 > length2 ? length1 : length2;  //选出最大长度
		  ListNode* res = (ListNode*)malloc(sizeof(ListNode)*(length + 1));
		  while (length)
		  {
			  temp1->val = temp1 == NULL ? 0 : temp1->val;
			  temp2->val = temp2 == NULL ? 0 : temp2->val;
			  res->val = temp1->val + temp2->val + count;
			  if (res->val > 10)
			  {
				  res->val %= 10;
				  count = 1;
			  }
			  else
			  {
				  count = 0;
			  }
			  length--;
		  }
	  }
  };
  */
  //这个版本不行

  class Solution {
  public:
	  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		  int num1 = 0;
		  int num2 = 0;
		  ListNode* p = l1;
		  ListNode* q = l2;
		  ListNode* res = (ListNode*)malloc(sizeof(ListNode));
		  ListNode* head = res;
		  ListNode* temp = res;
		  int count = 0; //表示进位
		  while (p != NULL || q != NULL || count == 1)
		  {
			  temp = (ListNode*)malloc(sizeof(ListNode));
			  num1 = p == NULL ? 0 : p->val;
			  num2 = q == NULL ? 0 : q->val;
			  temp->val = num1 + num2 + count;
			  if (temp->val >= 10)
			  {
				  temp->val %= 10;
				  count = 1;
			  }
			  else
			  {
				  count = 0;
				  num1 = 0;
				  num2 = 0;
			  }
			  res->next = temp;
			  res = res->next;
			  if(p != NULL)
			  p = p->next;
			  if(q != NULL)
			  q = q->next;
	      }
		  res->next = NULL;
		  res = head->next;
		  free(head);
		  return res; 
	  }
  };


  int main()
  {
	  Solution a;
	  ListNode l1(7);
	  ListNode l2(0);
	  ListNode l3(8);
	
	  ListNode A1(2);
	  ListNode A2(4);
	  ListNode A3(3);
	  l1.next = &l2;
	  l2.next = &l3;
	  A1.next = &A2;
	  A2.next = &A3;
	 auto res = a.addTwoNumbers(&l1, &A1);
	 while (res != NULL)
	 {
		 cout << res->val << " ";
		 res = res->next;
	 }
	  system("pause");
	  return 0;
  }