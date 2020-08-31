#pragma once

#include"common.h"


#define MAXVEX 4      //起始顶点数默认为6,可在此直接修改
#define MAXEDGE 5     //起始边的数默认为5,可在此直接修改
using namespace std;

//该代码是无向图的邻接表
//注意点1:下标0的位置都不用，所以要多开辟一个空间
//注意点2:头结点信息既可以是字符A,B,C,D，也可以是字符'1','2'...
//注意点3:在创建邻接表时，使用头插法将边结点接在头结点之后

//将无向图的邻接表改为有向图的邻接表，则只要删去下面一段代码即可
//EdgeNode *s2 = new EdgeNode;
//s2->adjvex=m; //无向图现在n是头，m是尾
//s2->next = g.adjlist[n].firstedge;
//g.adjlist[n].firstedge=s2;
//此时这个有向图的邻接表是根据顶点的出度来设置的，而逆邻接表是根据结点的入度来设置的，区分下即可

typedef struct EdgeNode
{
	int adjvex;
	struct EdgeNode *next;
}EdgeNode;               //边结点

typedef struct
{
	char vextexinfo;     //存放头结点信息（如A,B,C,D)
	EdgeNode *firstedge; //指向该结点的临边
}VextexNode, AdjList;     //头结点(即邻接表)

typedef struct
{
	int vexNum;                //顶点数
	int edgeNum;               //边数
	AdjList adjlist[MAXVEX + 1]; //头结点数组
}ALGraph;


void InitAdjList(ALGraph &g)
{
	g.vexNum = MAXVEX;
	g.edgeNum = MAXEDGE;
	//初始化头结点数组(即表头信息)
	for (int i = 1; i <= MAXVEX; i++)
	{
		cout << "请输入第" << i << "个结点的信息:";
		cin >> g.adjlist[i].vextexinfo;
		g.adjlist[i].firstedge = NULL; //初始化指针指向空
	}
}

//通过两个结点来确认边，并得到这两个结点的在数组的下标位置
/*********************确定邻接表数组下标的位置*********************/
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

/******************建立邻接表*******************/
void SetAdjList(ALGraph &g)
{
	char vex1, vex2;
	int m, n;
	for (int i = 1; i <= MAXEDGE; i++) //有几条边就循环几次
	{
		cout << "请输入第" << i << "条边（形如A B，表示A到B的一条边）";
		cin >> vex1 >> vex2; //输入边的信息（即通过输入两顶点来确认边）
		Locata(g, vex1, vex2, m, n);//得到vex1和vex2在邻接表的数组下标位置m和n
		EdgeNode *s1 = new EdgeNode;
		s1->adjvex = n;   //无向图现在m是头，n是尾
		s1->next = g.adjlist[m].firstedge;
		g.adjlist[m].firstedge = s1;

		//要是将其改为有向图的邻接表，则，下面这段代码全部删除
		EdgeNode *s2 = new EdgeNode;
		s2->adjvex = m;   //无向图现在n是头，m是尾
		s2->next = g.adjlist[n].firstedge;
		g.adjlist[n].firstedge = s2;
	}
}
/******************显示邻接表*******************/
void ShowAdjList(ALGraph &g)
{
	cout << "该图的邻接表如下：" << endl;
	for (int i = 1; i <= g.vexNum; i++)
	{
		EdgeNode *p;
		cout << "结点" << i << ":";
		for (p = g.adjlist[i].firstedge; p != NULL; p = p->next)
			cout << p->adjvex << "  ";
		cout << endl;
	}
}



int Minmum(EdgeNode * closedge)  //返回最小代价边
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
