#include<iostream>

using namespace std;

/*
typedef struct LNode
{
	int data;
	struct LNode *link;
}LNode,*LinkList;

int AdjustList(LinkList L)
{
	int count = 0;
	LNode *p = L;
	LNode* q = p->link;
	LNode * temp = L;
	while (q != NULL)  //ɾ������
	{
		if (q->data % 2 != 0)
		{
			p ->link = q->link;
			free(q);
			q = p->link;
			continue;
		}
		else
		{
			p = p->link;
			q = q->link;
		}
	}
	while (temp != NULL)  //ѭ������
	{
		temp = temp->link;
		count++;    // ͳ�ƽڵ����ͷ
	}
	temp->link = L; 
	return count;
}*/

typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

void output_Lchild(BiTree T)  
{
	
	if (T != NULL)
	{
		fun(T, T->lchild);
		fun(T, T->rchild);
	}
}
int fun(BiTree T, BiTree pPre)
{
	if (pPre == NULL)
		return;
	if (T->lchild == pPre)
		printf("%c ", pPre->data);
	fun(pPre, pPre->lchild);
	fun(pPre, pPre->rchild);
}




int main()
{
	



	system("pause");
	return 0;
}