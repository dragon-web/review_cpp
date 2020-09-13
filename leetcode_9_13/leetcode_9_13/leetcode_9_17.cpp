#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>

using namespace std;
/*  链表相加 leetcode
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int OverTen = 0;  //进位标志位
		ListNode *MyNode = new ListNode(0); //创建链表头结点，默认值为0
		ListNode *ListHead = MyNode;  //指向链表头结点的指针，用于返回值
		//只要l1、l2、进位标志不为空，就继续循环。循环完成本节点加法，并令MyNode指向新的节点
		while (l1 || l2 || OverTen != 0) {
			int sum = 0;
			sum += OverTen;
			OverTen = 0;
			//l1、l2都有值
			if (l1 && l2) {
				sum += l1->val + l2->val;
				l1 = l1->next;
				l2 = l2->next;
			}
			//若l1有数据
			else if (l1) {
				sum += l1->val;
				l1 = l1->next;
			}
			//若l2有数据
			else if (l2) {
				sum += l2->val;
				l2 = l2->next;
			}
			MyNode->val = sum % 10;  //val保存个位的值
			OverTen = sum / 10;  //标志位OverTen保存十位的值，即：是否进位

			//若满足下次循环的条件，则创建新节点，将指针指向新节点；否则将最后节点的指针指向NULL
			if (l1 || l2 || OverTen != 0) {
				ListNode *newnode = new ListNode(0);
				newnode->next = NULL;
				MyNode->next = newnode;
				MyNode = MyNode->next; //指向新节点
			}
			else
				MyNode->next = NULL;
		}

		return ListHead;
	}
};
*/

//leetcode  求二叉树的深度
//方法1： 层序遍历 


//变态青蛙跳台阶问题

/*
f(n) = 2f(n-1)


*/



int main()
{


	system("pause");
	return 0;
}