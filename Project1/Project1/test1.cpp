#define _CRT_SECURE_NO_WARNINGS 

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct BitNode {         //������
	char value;
	struct BitNode* lchild, *rchild;
}BiTree;

//����������
//pre��in��������������������˳��
//L1��r1Ϊ����ı����Ĳ��ҷ�Χ��L2��r2Ϊ��������Ĳ��ҷ�Χ
BiTree *CreateTree(char pre[100], int L1, int r1, char in[100], int L2, int r2) {
	BiTree* root;

	if (L1 <= r1 && L2 <= r2)                       //����������ĵ�һ���ַ�����Ϊ�ؼ��ַ���Ѱ����������д˹ؼ��ַ���λ��
	{                                               //���������λ����ߵ��ַ�Ϊ�ؼ��ַ���ȫ�����ӣ��ұߵ�Ϊ�ؼ��ַ���ȫ���Һ���
		int key = pre[L1];                          //�������� L1 <= r1 && L2 <= r2 ��˵���˽���Լ�û�к���
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
		root->lchild = CreateTree(pre, L1 + 1, L1 + llen, in, L2, midIndex - 1);        //ÿ�ε��ö����������зָ�����Σ����м�һ��ȥ���������������
		root->rchild = CreateTree(pre, L1 + llen + 1, r1, in, midIndex + 1, r2);        //ͬ����������Һ���
		return root;
	}
	root = NULL;
	return root;
}

//�������
void preOrderTraverse(BiTree *root) {

	if (root->lchild)                       //�������ڵ������
		preOrderTraverse(root->lchild);
	if (root->rchild)                       //�����������Һ���
		preOrderTraverse(root->rchild);
	printf("%c ", root->value);             //���������ڵ�ʵ�ֺ������
}

//�����Ϊ1�Ľ��
int countDegreeOne(BiTree* root) {
	int n1, n2;
	int n = 0;
	if (root == NULL) {     //��Ϊ�շ���
		return 0;
	}
	else if ((root->lchild != NULL && root->rchild == NULL) || (root->lchild == NULL && root->rchild != NULL)) {//���˽���Ϊ1���¼
		n++;
	}
	n1 = countDegreeOne(root->lchild);          //���������ж�Ϊ1�ڵ���
	n2 = countDegreeOne(root->rchild);          //�����Һ����ж�Ϊ1�ڵ���
	n = n + n1 + n2;                            //�����������ȫ����Ϊ1�ڵ���
	return n;
}

int main() {
	char pre[100], in[100];
	printf("�ֱ������������������������˳��\n");

	scanf_s("%s", pre, 100);
	scanf_s("%s", in, 100);
	int len1 = strlen(pre);
	int len2 = strlen(in);

	BiTree *root;
	root = CreateTree(pre, 0, len1 - 1, in, 0, len2 - 1);

	printf("����������У�\n");
	preOrderTraverse(root);

	printf("\n��Ϊ1�Ľڵ�����");
	printf("%d\n", countDegreeOne(root));
	system("pause");
	return 0;
}