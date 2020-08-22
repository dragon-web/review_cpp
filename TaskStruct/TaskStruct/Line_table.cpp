#include"common.h"

/*
#define MAX_SIZE 100
typedef int DataType;

typedef struct SeqList
{
	DataType array[MAX_SIZE];
	int size;
}SeqList, *PSeqList;


void InitSeqList(PSeqList seq)    //��ʼ��˳���
{
	memset(seq->array, 0, MAX_SIZE*(sizeof(DataType)));
	seq->size = 0;
}

int Empty(PSeqList seq)     //����
{
	if (seq->size > MAX_SIZE)
		return 1;
	else  return 0;
}

void PushBack(PSeqList seq, DataType data)  //β�巨����Ԫ��
{
	assert(seq);     //���ö��ԣ�����Ƿ�Ϊ��
	if (Empty(seq))
	{
		return;
	}

	seq->array[seq->size] = data;
	seq->size++;
}
void PrintSeqList(PSeqList seq)     //��ӡ˳���
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

void Inverse(PSeqList seq)    //˳��������
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
	InitSeqList(&seq);    //��ʼ��
	PrintSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 5);
	PushBack(&seq, 6);
	PushBack(&seq, 7);    //β�巨����Ԫ��
	PrintSeqList(&seq);
	Inverse(&seq);
	PrintSeqList(&seq);
	system("pause");
	return 0;
}

//����ڵ㵥Ԫ
typedef struct Link {
	int value;//������ 
	struct Link *next;//ָ���� 
}link;
*/
/********************
���� DisplayLink����ʾ��Ϸ��Ա
����1 link *L��������Ϸ��Ա������L
********************
void DisplayLink(link *L) {
	link *p = L;//��¼ͷָ�� 
	printf("%d->", L->value);//��ӡ��һ����Ա���� 
	L = L->next;//ָ�����
	//��ӡ��һ����Ա��ĳ�Ա��Ϣ 
	while (L != p) {
		printf("%d->", L->value);
		L = L->next;
	}
	printf("%d\n\n", L->value);//��ӡ���һ����Աָ��ĳ�Ա,���Կ������һ����Աָ���һ����Ա 
}

/********************
���� InitLink������������num����Ϸ��Ա������L
����1 link **L������L
����2 int num����������
********************
int InitLink(link **L, int num) {
	link *p = NULL;//ͷָ�� 
	link *temp = (link *)malloc(sizeof(link));//��ʱָ��,����ָ����������һ���ڵ� 
	if (!temp) {//����ڵ�����ʧ�� 
		printf("�����ʼ��ʧ��!\n\n");
		exit(1);//�˳����� 
	}
	temp->value = 1;//�����ͷ�ڵ㣬����Ԫ�ڵ㴦,д1 
	temp->next = temp;//βָ��ָ��ͷָ�� 
	p = temp;//ͷָ��ָ������ĵ�һ���ڵ�
	for (int i = 1; i < num; i++) {
		link *new_link = (link *)malloc(sizeof(link));//�����½ڵ� 
		if (!new_link) {
			printf("�����ʼ��ʧ��!\n\n");
			exit(1);//�˳����� 
		}
		//��ʼ���½ڵ� 
		new_link->value = i + 1;
		new_link->next = p;
		temp->next = new_link;//��new_link�ڵ����ӵ���������һ���ڵ�temp��,�����߼���ϵ 
		temp = temp->next;//temp�ڵ�����ƶ�һλ��ָ����������һ���ڵ� 
	}
	*L = p;//Lָ������ͷ 
	printf("����Լɪ����Ϸ,���� %d ����Ϸ��Ա����!\n", num);
	printf("Բ����Ա��λ˳��:");
	DisplayLink(*L);
	return 0;
}
*/
/********************
���� FindAndKillM��Ѱ�ҵ�����ΪM���˲��޳�
����1 int HeadNode��0��ʾ������ͷ�ڵ�����,1��ʾ������ͷ�ڵ�����
����2 link *L������L
����3 int k����Ϸ��ʼ��
����4 int m������m
********************
void FindAndKillM(link *L, int k, int m) {
	link *Per_K = L;//Kǰһ���ڵ� 
	link *Cur_K = L;//K�ڵ� 
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
		Per_K->next = Cur_K->next;//�������Ͻ�Cur_K���ժ����
		printf("���ֱ��Ϊ: %d ����Ϸ��Ա����!\n", Cur_K->value);
		free(Cur_K);
		Cur_K = Per_K->next;//����ʹ��Cur_Kָ��ָ����б�ŵ���һ����ţ���Ϸ����
	}
	printf("\n���Ϊ: %d �ĳ�Աȡ��������ʤ��!\n\n", Cur_K->value);
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