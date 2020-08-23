#include"BinTree.h"

int i = 0;
NodeList *createBinaryTree(int *arr)  //用0来记录NULL
{
	if (arr[i] == 0)
	{
		return NULL;
	}
	else
	{
		NodeList* p = (NodeList*)malloc(sizeof(NodeList));
		assert(p != NULL); //判断p是否为NULL
		p->data = arr[i];
		i++;
		p->left = createBinaryTree(arr);
		i++;
		p->right = createBinaryTree(arr);
		return p;
	}
}

void DLR(NodeList *p)   //先序遍历
{
	if (p != NULL)
	{
		printf("%d ", p->data);
		DLR(p->left);
		DLR(p->right);
	}
}

void LDR(NodeList *p) //中序遍历
{
	if (p != NULL)
	{
		LDR(p->left);
		printf("%d ", p->data);
		LDR(p->right);
	}
}

void LRD(NodeList *p)	//后序遍历
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

// 队列是否为空 ...
int IsQueueEmpty(SeqBiTreePtrQueue *Q)
{
	if (Q->Front == Q->Rear)
		return TRUE;

	return FALSE;
}

// 队列是否为满 ...
int IsQueueFull(SeqBiTreePtrQueue *Q)
{
	if (((Q->Rear + 1) % MAX_QUEUE_SIZE) == Q->Front)
		return TRUE;

	return FALSE;
}

// 入队 ...
int EnterQueue(SeqBiTreePtrQueue *Q, NodeList* x)
{
	if (((Q->Rear + 1) % MAX_QUEUE_SIZE) == Q->Front)
		return FALSE;

	Q->Elem[Q->Rear] = x;
	Q->Rear = (Q->Rear + 1) % MAX_QUEUE_SIZE;
	return TRUE;
}

// 出队 ...
int LeaveQueue(SeqBiTreePtrQueue *Q, NodeList **x)
{
	if (Q->Front == Q->Rear)
		return FALSE;

	*x = Q->Elem[Q->Front];
	Q->Front = (Q->Front + 1) % MAX_QUEUE_SIZE;
	return TRUE;
}

// 取队头元素 ...
int GetQueueFrontElem(SeqBiTreePtrQueue *Q, NodeList **x)
{
	if (Q->Front == Q->Rear)
		return FALSE;

	*x = Q->Elem[Q->Front];
	return TRUE;
}


void levelTraversal(NodeList *p) //层次遍历
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

void destroyBinaeryTree(NodeList *p) //销毁二叉树
{
	if (p != NULL)
	{
		destroyBinaeryTree(p->left);
		destroyBinaeryTree(p->right);
		free(p);
	}
}