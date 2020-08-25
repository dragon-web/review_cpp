#pragma once
#include"common.h"

typedef struct Node  //���ڵ�
{
	int data;
	struct Node *left;
	struct Node *right;
}NodeList;

typedef struct
{
	NodeList* Elem[MAX_QUEUE_SIZE];
	int       Front, Rear;
}SeqBiTreePtrQueue;  //���нڵ�



NodeList *createBinaryTree(int *arr);
void DLR(NodeList *p);  //�������
void LDR(NodeList *p);	//�������
void LRD(NodeList *p);	//�������
void levelTraversal(NodeList *p); //��α���
void destroyBinaeryTree(NodeList *p); //���ٶ�����
void InitQueue(SeqBiTreePtrQueue *Q);//��ʼ��
int  IsQueueEmpty(SeqBiTreePtrQueue *Q);   //�ж϶����Ƿ�ΪNULL
int  IsQueueFull(SeqBiTreePtrQueue *Q);    //�ж϶����Ƿ���
int  EnterQueue(SeqBiTreePtrQueue *Q, NodeList *x);   //���
int  LeaveQueue(SeqBiTreePtrQueue *Q, NodeList **x);   //����
int  GetQueueFrontElem(SeqBiTreePtrQueue *Q, NodeList **x);  //ȡ����ͷ��Ԫ��
