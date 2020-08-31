#pragma once

#include"prim.h"

void ReadArc(unsigned int  adjMat[][vexCounts], vector<Arc> &vertexArc) //保存图的边代价信息
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
	for (unsigned int i = 0; i < Tree.size(); i++)  //检查u,v分别属于哪颗树
	{
		if (find(Tree[i].begin(), Tree[i].end(), u) != Tree[i].end())
			index_u = i;
		if (find(Tree[i].begin(), Tree[i].end(), v) != Tree[i].end())
			index_v = i;
	}

	if (index_u != index_v)   //u,v不在一颗树上，合并两颗树
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
	ReadArc(adjMat, vertexArc);//读取边信息
	sort(vertexArc.begin(), vertexArc.end(), compare);//边按从小到大排序
	vector<vector<VertexData> > Tree(vexCounts); //6棵独立树
	for (unsigned int i = 0; i < vexCounts; i++)
	{
		Tree[i].push_back(i);  //初始化6棵独立树的信息
	}
	for (unsigned int i = 0; i < vertexArc.size(); i++)//依次从小到大取最小代价边
	{
		VertexData u = vertexArc[i].u;
		VertexData v = vertexArc[i].v;
		if (FindTree(u, v, Tree))//检查此边的两个顶点是否在一颗树内
		{
			cout << vextex[u] << "---" << vextex[v] << endl;//把此边加入到最小生成树中
		}
	}
}
