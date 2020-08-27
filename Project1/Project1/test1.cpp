#define _CRT_SECURE_NO_WARNINGS 

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct BitNode {         //二叉树
	char value;
	struct BitNode* lchild, *rchild;
}BiTree;

//创建二叉树
//pre和in二叉树先序和中序遍历的顺序
//L1和r1为先序的遍历的查找范围，L2和r2为中序遍历的查找范围
BiTree *CreateTree(char pre[100], int L1, int r1, char in[100], int L2, int r2) {
	BiTree* root;

	if (L1 <= r1 && L2 <= r2)                       //将先序遍历的第一个字符设置为关键字符，寻找中序遍历中此关键字符的位置
	{                                               //在中序遍历位置左边的字符为关键字符的全部左孩子，右边的为关键字符的全部右孩子
		int key = pre[L1];                          //若不满足 L1 <= r1 && L2 <= r2 则说明此结点以及没有孩子
		int midIndex = -1;
		for (int i = L2; i <= r2; i++)
		{
			if (in[i] == key)
			{
				midIndex = i;
				break;
			}
		}
		int llen = midIndex - L2;

		root = (BiTree*)malloc(sizeof(BiTree));
		root->value = key;
		root->lchild = CreateTree(pre, L1 + 1, L1 + llen, in, L2, midIndex - 1);        //每次调用都将遍历序列分割成三段，用中间一段去构造二叉树的左孩子
		root->rchild = CreateTree(pre, L1 + llen + 1, r1, in, midIndex + 1, r2);        //同理构造二叉树右孩子
		return root;
	}
	root = NULL;
	return root;
}

//后序遍历
void preOrderTraverse(BiTree *root) {

	if (root->lchild)                       //遍历根节点的左孩子
		preOrderTraverse(root->lchild);
	if (root->rchild)                       //遍历根结点的右孩子
		preOrderTraverse(root->rchild);
	printf("%c ", root->value);             //最后输出根节点实现后序遍历
}

//计算度为1的结点
int countDegreeOne(BiTree* root) {
	int n1, n2;
	int n = 0;
	if (root == NULL) {     //根为空返回
		return 0;
	}
	else if ((root->lchild != NULL && root->rchild == NULL) || (root->lchild == NULL && root->rchild != NULL)) {//若此结点度为1则记录
		n++;
	}
	n1 = countDegreeOne(root->lchild);          //计算左孩子中度为1节点数
	n2 = countDegreeOne(root->rchild);          //计算右孩子中度为1节点数
	n = n + n1 + n2;                            //计算二叉树中全部度为1节点数
	return n;
}

int main() {
	char pre[100], in[100];
	printf("分别输入二叉树的先序和中序遍历顺序\n");

	scanf_s("%s", pre, 100);
	scanf_s("%s", in, 100);
	int len1 = strlen(pre);
	int len2 = strlen(in);

	BiTree *root;
	root = CreateTree(pre, 0, len1 - 1, in, 0, len2 - 1);

	printf("后序遍历序列：\n");
	preOrderTraverse(root);

	printf("\n度为1的节点数：");
	printf("%d\n", countDegreeOne(root));
	system("pause");
	return 0;
}