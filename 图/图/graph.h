#pragma once

#include"common.h"


#define MAXVEX 4      //��ʼ������Ĭ��Ϊ6,���ڴ�ֱ���޸�
#define MAXEDGE 5     //��ʼ�ߵ���Ĭ��Ϊ5,���ڴ�ֱ���޸�
using namespace std;

//�ô���������ͼ���ڽӱ�
//ע���1:�±�0��λ�ö����ã�����Ҫ�࿪��һ���ռ�
//ע���2:ͷ�����Ϣ�ȿ������ַ�A,B,C,D��Ҳ�������ַ�'1','2'...
//ע���3:�ڴ����ڽӱ�ʱ��ʹ��ͷ�巨���߽�����ͷ���֮��

//������ͼ���ڽӱ��Ϊ����ͼ���ڽӱ���ֻҪɾȥ����һ�δ��뼴��
//EdgeNode *s2 = new EdgeNode;
//s2->adjvex=m; //����ͼ����n��ͷ��m��β
//s2->next = g.adjlist[n].firstedge;
//g.adjlist[n].firstedge=s2;
//��ʱ�������ͼ���ڽӱ��Ǹ��ݶ���ĳ��������õģ������ڽӱ��Ǹ��ݽ�����������õģ������¼���

typedef struct EdgeNode
{
	int adjvex;
	struct EdgeNode *next;
}EdgeNode;               //�߽��

typedef struct
{
	char vextexinfo;     //���ͷ�����Ϣ����A,B,C,D)
	EdgeNode *firstedge; //ָ��ý����ٱ�
}VextexNode, AdjList;     //ͷ���(���ڽӱ�)

typedef struct
{
	int vexNum;                //������
	int edgeNum;               //����
	AdjList adjlist[MAXVEX + 1]; //ͷ�������
}ALGraph;


void InitAdjList(ALGraph &g)
{
	g.vexNum = MAXVEX;
	g.edgeNum = MAXEDGE;
	//��ʼ��ͷ�������(����ͷ��Ϣ)
	for (int i = 1; i <= MAXVEX; i++)
	{
		cout << "�������" << i << "��������Ϣ:";
		cin >> g.adjlist[i].vextexinfo;
		g.adjlist[i].firstedge = NULL; //��ʼ��ָ��ָ���
	}
}

//ͨ�����������ȷ�ϱߣ����õ�������������������±�λ��
/*********************ȷ���ڽӱ������±��λ��*********************/
void Locata(ALGraph &g, char &vex1, char &vex2, int &m, int &n)
{
	for (int i = 1; i <= MAXVEX; i++)
	{
		if (vex1 == g.adjlist[i].vextexinfo)
			m = i;
		if (vex2 == g.adjlist[i].vextexinfo)
			n = i;
	}
}

/******************�����ڽӱ�*******************/
void SetAdjList(ALGraph &g)
{
	char vex1, vex2;
	int m, n;
	for (int i = 1; i <= MAXEDGE; i++) //�м����߾�ѭ������
	{
		cout << "�������" << i << "���ߣ�����A B����ʾA��B��һ���ߣ�";
		cin >> vex1 >> vex2; //����ߵ���Ϣ����ͨ��������������ȷ�ϱߣ�
		Locata(g, vex1, vex2, m, n);//�õ�vex1��vex2���ڽӱ�������±�λ��m��n
		EdgeNode *s1 = new EdgeNode;
		s1->adjvex = n;   //����ͼ����m��ͷ��n��β
		s1->next = g.adjlist[m].firstedge;
		g.adjlist[m].firstedge = s1;

		//Ҫ�ǽ����Ϊ����ͼ���ڽӱ���������δ���ȫ��ɾ��
		EdgeNode *s2 = new EdgeNode;
		s2->adjvex = m;   //����ͼ����n��ͷ��m��β
		s2->next = g.adjlist[n].firstedge;
		g.adjlist[n].firstedge = s2;
	}
}
/******************��ʾ�ڽӱ�*******************/
void ShowAdjList(ALGraph &g)
{
	cout << "��ͼ���ڽӱ����£�" << endl;
	for (int i = 1; i <= g.vexNum; i++)
	{
		EdgeNode *p;
		cout << "���" << i << ":";
		for (p = g.adjlist[i].firstedge; p != NULL; p = p->next)
			cout << p->adjvex << "  ";
		cout << endl;
	}
}



int Minmum(EdgeNode * closedge)  //������С���۱�
{
	int min = INT_MAX;
	int index = -1;
	for (int i = 0; i < vexCounts; i++)
	{
		if (closedge[i].lowestcost < min && closedge[i].lowestcost != 0)
		{
			min = closedge[i].lowestcost;
			index = i;
		}
	}
	return index;
}
