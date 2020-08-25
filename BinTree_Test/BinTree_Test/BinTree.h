#pragma once
#include"common.h"

typedef struct Node  //树节点
{
	int data;
	struct Node *left;
	struct Node *right;
}NodeList;

typedef struct
{
	NodeList* Elem[MAX_QUEUE_SIZE];
	int       Front, Rear;
}SeqBiTreePtrQueue;  //队列节点



NodeList *createBinaryTree(int *arr);
void DLR(NodeList *p);  //先序遍历
void LDR(NodeList *p);	//中序遍历
void LRD(NodeList *p);	//后序遍历
void levelTraversal(NodeList *p); //层次遍历
void destroyBinaeryTree(NodeList *p); //销毁二叉树
void InitQueue(SeqBiTreePtrQueue *Q);//初始化
int  IsQueueEmpty(SeqBiTreePtrQueue *Q);   //判断队列是否为NULL
int  IsQueueFull(SeqBiTreePtrQueue *Q);    //判断队列是否满
int  EnterQueue(SeqBiTreePtrQueue *Q, NodeList *x);   //入队
int  LeaveQueue(SeqBiTreePtrQueue *Q, NodeList **x);   //出队
int  GetQueueFrontElem(SeqBiTreePtrQueue *Q, NodeList **x);  //取队列头部元素
