#pragma once
#include"common.h"


const int MAX_VERTEX = 10; //图最大顶点数
using namespace std;
char arr[] = { 'A','B','C','D','E' };
struct ArcNode  //边表
{
	int adjvex;     //表示边的权值
	ArcNode *next;
};

struct VertexNode  //顶点表
{
	DataType vertex;
	ArcNode *firstEdge;
};
class ALGraph
{
private:
	VertexNode adjust[MAX_VERTEX];
	int vertexNum, arcNum;  //顶点个数  边的个数
public:
	ALGraph(DataType v[], int n, int e);
	//~ALGraph();
	void printTable(VertexNode *p, int n, int e);
	VertexNode* GetVerTexNode()
	{
		return this->adjust;
	}
};

ALGraph::ALGraph(DataType v[], int n, int e)
{
	vertexNum = n;
	arcNum = e;
	for (int i = 0; i < vertexNum; ++i)
	{
		adjust[i].vertex = v[i];
		adjust[i].firstEdge = NULL;
	}
	for (int j = 0; j < arcNum; j++)
	{
		int vi;
		int vj;
		cout << "请输入两个相连顶点编号:(中间以空格隔开)" << endl;
		cin >> vi >> vj;
		ArcNode * s;
		s = new ArcNode;
		s->adjvex = vj;  //存储终点
		s->next = adjust[vi].firstEdge;
		adjust[vi].firstEdge = s;
	}
}

void ALGraph::printTable(VertexNode *p, int n, int e)
{
	VertexNode* temp = p;
	for (int i = 0; i < n; ++i)
	{
		auto temp1 = temp->firstEdge;
		cout << temp->vertex << "->";
		while (temp1 != NULL)
		{
			cout << arr[temp1->adjvex] << "->";
			temp1 = temp1->next;
		}
		cout << "NULL" << endl;
		temp++;
	}
}

/*
int main()
{
	ALGraph myalgraph(arr,5,7);
	myalgraph.printTable(myalgraph.GetVerTexNode(), 5, 7);


	system("pause");
	return 0;
}
*/