#include"BinTree.h"

int i = 0;
NodeList *createBinaryTree(int *arr)  //��0����¼NULL
{
	if (arr[i] == 0)
	{
		return NULL;
	}
	else
	{
		NodeList* p = (NodeList*)malloc(sizeof(NodeList));
		assert(p != NULL); //�ж�p�Ƿ�ΪNULL
		p->data = arr[i];
		i++;
		p->left = createBinaryTree(arr);
		i++;
		p->right = createBinaryTree(arr);
		return p;
	}
}

void DLR(NodeList *p)   //�������
{
	if (p != NULL)
	{
		printf("%d ", p->data);
		DLR(p->left);
		DLR(p->right);
	}
}

void LDR(NodeList *p) //�������
{
	if (p != NULL)
	{
		LDR(p->left);
		printf("%d ", p->data);
		LDR(p->right);
	}
}

void LRD(NodeList *p)	//�������
{
	if (p != NULL)
	{
		LRD(p->left);
		LRD(p->right);
		printf("%d ", p->data);
	}
}

void InitQueue(SeqBiTreePtrQueue *Q)
{
	Q->Front = 0;
	Q->Rear = 0;
}

// �����Ƿ�Ϊ�� ...
int IsQueueEmpty(SeqBiTreePtrQueue *Q)
{
	if (Q->Front == Q->Rear)
		return TRUE;

	return FALSE;
}

// �����Ƿ�Ϊ�� ...
int IsQueueFull(SeqBiTreePtrQueue *Q)
{
	if (((Q->Rear + 1) % MAX_QUEUE_SIZE) == Q->Front)
		return TRUE;

	return FALSE;
}

// ��� ...
int EnterQueue(SeqBiTreePtrQueue *Q, NodeList* x)
{
	if (((Q->Rear + 1) % MAX_QUEUE_SIZE) == Q->Front)
		return FALSE;

	Q->Elem[Q->Rear] = x;
	Q->Rear = (Q->Rear + 1) % MAX_QUEUE_SIZE;
	return TRUE;
}

// ���� ...
int LeaveQueue(SeqBiTreePtrQueue *Q, NodeList **x)
{
	if (Q->Front == Q->Rear)
		return FALSE;

	*x = Q->Elem[Q->Front];
	Q->Front = (Q->Front + 1) % MAX_QUEUE_SIZE;
	return TRUE;
}

// ȡ��ͷԪ�� ...
int GetQueueFrontElem(SeqBiTreePtrQueue *Q, NodeList **x)
{
	if (Q->Front == Q->Rear)
		return FALSE;

	*x = Q->Elem[Q->Front];
	return TRUE;
}


void levelTraversal(NodeList *p) //��α���
{
	SeqBiTreePtrQueue Queue;
	InitQueue(&Queue);
	EnterQueue(&Queue, p);
	while (!IsQueueEmpty(&Queue))
	{
		GetQueueFrontElem(&Queue, &p);
		LeaveQueue(&Queue,&p);
		printf("%d ", p->data);
		if(p->left != NULL)
		EnterQueue(&Queue,p->left);
		if(p->right != NULL)
		EnterQueue(&Queue,p->right);
	}
}

void destroyBinaeryTree(NodeList *p) //���ٶ�����
{
	if (p != NULL)
	{
		destroyBinaeryTree(p->left);
		destroyBinaeryTree(p->right);
		free(p);
	}
}