#pragma once
#include"graph.h"

#define INFINITE 0xFFFFFFFF   
#define VertexData unsigned int  //��������
#define UINT  unsigned int
#define vexCounts 6  //��������
char vextex[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
struct node
{
	VertexData data;
	unsigned int lowestcost;
}closedge[vexCounts];


int Minmum(struct node * closedge)  //������С���۱�
{
	unsigned int min = INFINITE;
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

void MiniSpanTree_Prim(unsigned int adjMat[][vexCounts], VertexData s)
{
	for (int i = 0; i < vexCounts; i++)
	{
		closedge[i].lowestcost = INFINITE;
	}
	closedge[s].data = s;      //�Ӷ���s��ʼ
	closedge[s].lowestcost = 0;
	for (int i = 0; i < vexCounts; i++)  //��ʼ����������
	{
		if (i != s)
		{
			closedge[i].data = s;
			closedge[i].lowestcost = adjMat[s][i];
		}
	}
	for (int e = 1; e <= vexCounts - 1; e++)  //n-1����ʱ�˳�
	{
		int k = Minmum(closedge);  //ѡ����С���۱�
		cout << vextex[closedge[k].data] << "--" << vextex[k] << endl;//���뵽��С������
		closedge[k].lowestcost = 0; //������Ϊ0
		for (int i = 0; i < vexCounts; i++)  //����v�ж�����С���۱���Ϣ
		{
			if (adjMat[k][i] < closedge[i].lowestcost)
			{
				closedge[i].data = k;
				closedge[i].lowestcost = adjMat[k][i];
			}
		}
	}
}