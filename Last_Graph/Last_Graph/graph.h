#pragma once
#include"common.h"


const int MAX_VERTEX = 10; //ͼ��󶥵���
using namespace std;
char arr[] = { 'A','B','C','D','E' };
struct ArcNode  //�߱�
{
	int adjvex;     //��ʾ�ߵ�Ȩֵ
	ArcNode *next;
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
		cout << "��������������������:(�м��Կո����)" << endl;
		cin >> vi >> vj;
		ArcNode * s;
		s = new ArcNode;
		s->adjvex = vj;  //�洢�յ�
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