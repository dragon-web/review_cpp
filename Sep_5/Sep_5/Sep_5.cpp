#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
/*
int Add(int num1, int num2)
{
	while (num2 != 0) {
		int c = ((num1 & num2)) << 1;
		num1 ^= num2; //��¼��Ϊ�Ͳ�Ϊ0��ֵ
		num2 = c;    //  

	}
	return num1;

}

int main()
{

	int num1 = 7;
	int  num2 = 3;
	printf("%3d", Add(num1, num2));

	return 0;
}

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
}
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		ListNode *ta = pHead1, *tb = pHead2;
		while (ta != tb) {
			ta = ta ? ta->next : pHead2;
			tb = tb ? tb->next : pHead1;
		}
		return ta;
	}
};
*/


//ord�ǽ��ַ�������ĸת����asciiֵ�� chr��asciiת������ĸ

//   &lt;С�ڣ�less than��
//   &gt; ���ڣ�greater than��

//   ��������������ʱ�ǽ��ú�����Ŀ��������ÿ�����øú����ĵط�
//ע���Ǳ���ĵ�ʱ�������е�ʱ��

//����������ָ��ͬһ�������� ��������һ�������ͬ������ ����ͬ�����б� �ĺ��������麯������Ϊ���غ������ɶ���֪�����ͺ������������޹�
/*
ע��ͷ��������޹�
*/

/*
����ʹ�ö�����ϣ������Ǽ̳С������������Ƶĵڶ�ԭ��
���Ҳ�С�������С������������ж�����һ���͵ĳ�Ա���̳л��ƻ���Ķ����ԣ�����ϵͳ�ĸ����ԣ�
һ��ϵͳ�ļ̳в�β�����3�㡣
���ӵ�����õ���չ�ԣ�֧�ֶ�̬��ϣ���������ȿ�����Ϸ�����
*/












