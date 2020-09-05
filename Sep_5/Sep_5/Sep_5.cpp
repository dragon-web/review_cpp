#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
/*
int Add(int num1, int num2)
{
	while (num2 != 0) {
		int c = ((num1 & num2)) << 1;
		num1 ^= num2; //记录不为和不为0的值
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


//ord是将字符串首字母转换成ascii值； chr将ascii转换成字母

//   &lt;小于（less than）
//   &gt; 大于（greater than）

//   内联函数在运行时是将该函数的目标代码插入每个调用该函数的地方
//注意是编译的的时候不是运行的时候

//函数重载是指在同一作用域内 ，可以有一组具有相同函数名 ，不同参数列表 的函数，这组函数被称为重载函数。由定义知道，和函数返回类型无关
/*
注意和返回类型无关
*/

/*
优先使用对象组合，而不是继承”是面向对象设计的第二原则。
组合也叫“对象持有”，就是在类中定义另一类型的成员，继承会破坏类的独立性，增加系统的复杂性，
一般系统的继承层次不超过3层。
组合拥有良好的扩展性，支持动态组合，因此请优先考虑组合方法。
*/












