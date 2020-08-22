#include"common.h"

/*
#define MAX_SIZE 100
typedef int DataType;

typedef struct SeqList
{
	DataType array[MAX_SIZE];
	int size;
}SeqList, *PSeqList;


void InitSeqList(PSeqList seq)    //初始化顺序表
{
	memset(seq->array, 0, MAX_SIZE*(sizeof(DataType)));
	seq->size = 0;
}

int Empty(PSeqList seq)     //判满
{
	if (seq->size > MAX_SIZE)
		return 1;
	else  return 0;
}

void PushBack(PSeqList seq, DataType data)  //尾插法插入元素
{
	assert(seq);     //设置断言，检测是否为空
	if (Empty(seq))
	{
		return;
	}

	seq->array[seq->size] = data;
	seq->size++;
}
void PrintSeqList(PSeqList seq)     //打印顺序表
{
	int i = 0;
	assert(seq);
	if (Empty(seq))
	{
		return;
	}
	for (i = 0; i < seq->size; i++)
	{
		printf("%d ", seq->array[i]);
	}
	printf("\n");
}

void Inverse(PSeqList seq)    //顺序表的逆置
{
	int i = 0;
	int temp = 0;
	assert(seq);
	if (Empty(seq))
	{
		return;
	}

	for (i = 0; i < (seq->size) / 2; i++)
	{
		temp = seq->array[i];
		seq->array[i] = seq->array[seq->size - 1 - i];
		seq->array[seq->size - 1 - i] = temp;
	}
}

int main()
{
	SeqList seq;
	InitSeqList(&seq);    //初始化
	PrintSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 5);
	PushBack(&seq, 6);
	PushBack(&seq, 7);    //尾插法插入元素
	PrintSeqList(&seq);
	Inverse(&seq);
	PrintSeqList(&seq);
	system("pause");
	return 0;
}

//链表节点单元
typedef struct Link {
	int value;//数据域 
	struct Link *next;//指针域 
}link;
*/
/********************
函数 DisplayLink：显示游戏成员
参数1 link *L：保存游戏成员的链表L
********************
void DisplayLink(link *L) {
	link *p = L;//记录头指针 
	printf("%d->", L->value);//打印第一个成员数据 
	L = L->next;//指针后移
	//打印第一个成员后的成员信息 
	while (L != p) {
		printf("%d->", L->value);
		L = L->next;
	}
	printf("%d\n\n", L->value);//打印最后一个成员指向的成员,可以看到最后一个成员指向第一个成员 
}

/********************
函数 InitLink：建立包含有num个游戏成员的链表L
参数1 link **L：链表L
参数2 int num：链表容量
********************
int InitLink(link **L, int num) {
	link *p = NULL;//头指针 
	link *temp = (link *)malloc(sizeof(link));//临时指针,总是指向链表的最后一个节点 
	if (!temp) {//如果节点申请失败 
		printf("链表初始化失败!\n\n");
		exit(1);//退出程序 
	}
	temp->value = 1;//如果无头节点，则首元节点处,写1 
	temp->next = temp;//尾指针指向头指针 
	p = temp;//头指针指向链表的第一个节点
	for (int i = 1; i < num; i++) {
		link *new_link = (link *)malloc(sizeof(link));//申请新节点 
		if (!new_link) {
			printf("链表初始化失败!\n\n");
			exit(1);//退出程序 
		}
		//初始化新节点 
		new_link->value = i + 1;
		new_link->next = p;
		temp->next = new_link;//将new_link节点链接到链表的最后一个节点temp上,建立逻辑关系 
		temp = temp->next;//temp节点向后移动一位，指向链表的最后一个节点 
	}
	*L = p;//L指向链表头 
	printf("本次约瑟夫环游戏,共有 %d 个游戏成员参与!\n", num);
	printf("圆桌成员座位顺序:");
	DisplayLink(*L);
	return 0;
}
*/
/********************
函数 FindAndKillM：寻找到报数为M的人并剔除
参数1 int HeadNode：0表示建立有头节点链表,1表示建立无头节点链表
参数2 link *L：链表L
参数3 int k：游戏起始人
参数4 int m：报数m
********************
void FindAndKillM(link *L, int k, int m) {
	link *Per_K = L;//K前一个节点 
	link *Cur_K = L;//K节点 
	if (Per_K->value == k && m == 1) {
		while (Per_K->next != L) {
			Per_K = Per_K->next;
		}
	}
	while (Cur_K->value != k) {
		Per_K = Cur_K;
		Cur_K = Cur_K->next;
	}
	while (Cur_K->next != Cur_K) {
		for (int i = 1; i < m; i++) {
			Per_K = Cur_K;
			Cur_K = Cur_K->next;
		}
		Per_K->next = Cur_K->next;//从链表上将Cur_K结点摘下来
		printf("该轮编号为: %d 的游戏成员出列!\n", Cur_K->value);
		free(Cur_K);
		Cur_K = Per_K->next;//继续使用Cur_K指针指向出列编号的下一个编号，游戏继续
	}
	printf("\n编号为: %d 的成员取得了最终胜利!\n\n", Cur_K->value);
	free(Cur_K);
}
link *L;
int main(void) {
	InitLink(&L, 8);
	FindAndKillM(L, 3, 2);
	system("pause");
	return 0;
}
*/