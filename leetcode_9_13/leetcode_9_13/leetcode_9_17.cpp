#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>

using namespace std;
/*  ������� leetcode
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int OverTen = 0;  //��λ��־λ
		ListNode *MyNode = new ListNode(0); //��������ͷ��㣬Ĭ��ֵΪ0
		ListNode *ListHead = MyNode;  //ָ������ͷ����ָ�룬���ڷ���ֵ
		//ֻҪl1��l2����λ��־��Ϊ�գ��ͼ���ѭ����ѭ����ɱ��ڵ�ӷ�������MyNodeָ���µĽڵ�
		while (l1 || l2 || OverTen != 0) {
			int sum = 0;
			sum += OverTen;
			OverTen = 0;
			//l1��l2����ֵ
			if (l1 && l2) {
				sum += l1->val + l2->val;
				l1 = l1->next;
				l2 = l2->next;
			}
			//��l1������
			else if (l1) {
				sum += l1->val;
				l1 = l1->next;
			}
			//��l2������
			else if (l2) {
				sum += l2->val;
				l2 = l2->next;
			}
			MyNode->val = sum % 10;  //val�����λ��ֵ
			OverTen = sum / 10;  //��־λOverTen����ʮλ��ֵ�������Ƿ��λ

			//�������´�ѭ�����������򴴽��½ڵ㣬��ָ��ָ���½ڵ㣻�������ڵ��ָ��ָ��NULL
			if (l1 || l2 || OverTen != 0) {
				ListNode *newnode = new ListNode(0);
				newnode->next = NULL;
				MyNode->next = newnode;
				MyNode = MyNode->next; //ָ���½ڵ�
			}
			else
				MyNode->next = NULL;
		}

		return ListHead;
	}
};
*/

//leetcode  ������������
//����1�� ������� 


//��̬������̨������

/*
f(n) = 2f(n-1)


*/



int main()
{


	system("pause");
	return 0;
}