#pragma once
#include"graph.h"

#define INFINITE 0xFFFFFFFF   
#define VertexData unsigned int  //顶点数据
#define UINT  unsigned int
#define vexCounts 6  //顶点数量
char vextex[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
struct node
{
	VertexData data;
	unsigned int lowestcost;
}closedge[vexCounts];


int Minmum(struct node * closedge)  //返回最小代价边
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
	closedge[s].data = s;      //从顶点s开始
	closedge[s].lowestcost = 0;
	for (int i = 0; i < vexCounts; i++)  //初始化辅助数组
	{
		if (i != s)
		{
			closedge[i].data = s;
			closedge[i].lowestcost = adjMat[s][i];
		}
	}
	for (int e = 1; e <= vexCounts - 1; e++)  //n-1条边时退出
	{
		int k = Minmum(closedge);  //选择最小代价边
		cout << vextex[closedge[k].data] << "--" << vextex[k] << endl;//加入到最小生成树
		closedge[k].lowestcost = 0; //代价置为0
		for (int i = 0; i < vexCounts; i++)  //更新v中顶点最小代价边信息
		{
			if (adjMat[k][i] < closedge[i].lowestcost)
			{
				closedge[i].data = k;
				closedge[i].lowestcost = adjMat[k][i];
			}
		}
	}
}