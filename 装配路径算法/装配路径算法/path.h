#pragma once
#define DataType char
#define MAX_VERTEX 10
#include<iostream>
#include<stack>
#include<string>

using namespace std;

struct ArcNode  //�߱�
{
	int adjvex;     //��¼��һ��������
	ArcNode *next;
	unsigned int  IN;//��¼���
};

struct VertexNode  //�����
{
	DataType vertex;
	ArcNode *firstEdge;
};
class ALGraph
{
private:
	VertexNode adjust[MAX_VERTEX];
	int vertexNum, arcNum;  //�������  �ߵĸ���
public:
	ALGraph(DataType v[], int n, int e);
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
		unsigned int WEIGHT;
		cout << "���������������������Լ������·��:(�м��Կո����)" << endl;
		cin >> vi >> vj >> WEIGHT;
		ArcNode * s;
		s = new ArcNode;
		s->adjvex = vj;  //�洢�յ�
		s->next = adjust[vi].firstEdge;
		s->weight = WEIGHT;
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




