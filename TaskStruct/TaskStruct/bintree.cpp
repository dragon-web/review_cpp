#include"common.h"
/*
typedef struct node    
{
	char data;
	struct node *lchild;
	struct node *rchild;
}BTNode;

BTNode *create(char *str, int n)    // �����������ʽ��Ӧ�Ķ����� 
{
	BTNode *root = NULL;   //ʼ��ָ��ǰ�Ѿ����ɵĶ������ĸ�
	BTNode *p = NULL;       //ʼ��ָ��ǰ��������
	char ch;
	int j = 0;
	ch = str[j];
	while (ch != '\0' && j < n)
	{
		switch (ch)
		{
		case '0':   //���ֵĴ��� 
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			p = new BTNode;
			p->data = ch;
			if (root == NULL)
				root = p;
			else if (root->rchild == NULL)
				root->rchild = p;
			else
				root->rchild->rchild = p;
			break;
		case'+': //ɨ�赽'+''-',��Ϊ��ǰ����� 
		case'-':
			p = new BTNode;
			p->data = ch;
			p->rchild = NULL;
			p->lchild = root;
			root = p;
			root->rchild = NULL;
			break;
		case'*':    //'*'��'/'�Ĵ���
		case'/':
			if (root->data >= '0' && root->data <= '9' || root->data == '*' || root->data == '/')
			{
				p = new BTNode;
				p->data = ch;
				p->rchild = NULL;
				p->lchild = root;
				root = p;
			}
			else
			{
				p = new BTNode;
				p->data = ch;
				p->lchild = root->rchild;
				root->rchild = p;
				p->rchild = NULL;
			}
			break;
		}
		j++;
		ch = str[j];
	}
	return root;
}
int result(BTNode *b)  
{
	int n1, n2;
	if (b->data >= '0'&&b->data <= '9')
		return (b->data - '0');
	n1 = result(b->lchild);//�������ӱ��ʽ 
	n2 = result(b->rchild);//�������ӱ��ʽ 
	switch (b->data)
	{
	case'+':
		b->data = n1 + n2; break;
	case'-':
		b->data = n1 - n2; break;
	case'*':
		b->data = n1 * n2; break;
	case'/':
		b->data = n1 / n2; break;
	}
	return b->data;
}
int main()
{
	BTNode *b = NULL, *q = NULL;
	char str[100];
	printf("���������Ҫ��Ĵ������ʽ��");
	scanf("%s", str);
	int n = 0, i = 0;
	n = strlen(str);
	b = create(str, n);
	printf("�ñ��ʽ��ֵΪ��%d\n", result(b));

	system("pause");
	return 0;
}
*/