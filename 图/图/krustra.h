#pragma once

#include"prim.h"

void ReadArc(unsigned int  adjMat[][vexCounts], vector<Arc> &vertexArc) //����ͼ�ıߴ�����Ϣ
{
	Arc * temp = NULL;
	for (unsigned int i = 0; i < vexCounts; i++)
	{
		for (unsigned int j = 0; j < i; j++)
		{
			if (adjMat[i][j] != INFINITE)
			{
				temp = new Arc;
				temp->u = i;
				temp->v = j;
				temp->cost = adjMat[i][j];
				vertexArc.push_back(*temp);
			}
		}
	}
}
bool compare(Arc  A, Arc  B)
{
	return A.cost < B.cost ? true : false;
}
bool FindTree(VertexData u, VertexData v, vector<vector<VertexData> > &Tree)
{
	unsigned int index_u = INFINITE;
	unsigned int index_v = INFINITE;
	for (unsigned int i = 0; i < Tree.size(); i++)  //���u,v�ֱ������Ŀ���
	{
		if (find(Tree[i].begin(), Tree[i].end(), u) != Tree[i].end())
			index_u = i;
		if (find(Tree[i].begin(), Tree[i].end(), v) != Tree[i].end())
			index_v = i;
	}

	if (index_u != index_v)   //u,v����һ�����ϣ��ϲ�������
	{
		for (unsigned int i = 0; i < Tree[index_v].size(); i++)
		{
			Tree[index_u].push_back(Tree[index_v][i]);
		}
		Tree[index_v].clear();
		return true;
	}
	return false;
}
void MiniSpanTree_Kruskal(unsigned int adjMat[][vexCounts])
{
	vector<Arc> vertexArc;
	ReadArc(adjMat, vertexArc);//��ȡ����Ϣ
	sort(vertexArc.begin(), vertexArc.end(), compare);//�߰���С��������
	vector<vector<VertexData> > Tree(vexCounts); //6�ö�����
	for (unsigned int i = 0; i < vexCounts; i++)
	{
		Tree[i].push_back(i);  //��ʼ��6�ö���������Ϣ
	}
	for (unsigned int i = 0; i < vertexArc.size(); i++)//���δ�С����ȡ��С���۱�
	{
		VertexData u = vertexArc[i].u;
		VertexData v = vertexArc[i].v;
		if (FindTree(u, v, Tree))//���˱ߵ����������Ƿ���һ������
		{
			cout << vextex[u] << "---" << vextex[v] << endl;//�Ѵ˱߼��뵽��С��������
		}
	}
}
