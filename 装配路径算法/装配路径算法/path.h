#pragma once
#define DataType string
#define MAX_VERTEX 10
#include<iostream>
#include<stack>
#include<string>
#include<vector>

using namespace std;
/*
ʹ���ڽӱ����װ��·��ͼ�Ĺ��죬Ȼ�����ջ��һ���ݽṹʵ����������
��1������AOV����ѡ��һ��û��ǰ���Ķ��㲢�������
��2������AOV����ɾȥ�ö��㣬����ɾ�������Ըö���Ϊβ�Ļ���
��3�����ظ������������裬��ȫ�����㶼�����������AOV���в�����û��ǰ���Ķ��㣻
�㷨ʵ�֣�
1��ջS��ʼ�����ۼ���count��ʼ��
2��ɨ�趥�����û��ǰ���Ķ���ѹջ
3����ջS�ǿ�ʱ����ѭ��
3.1 vj = ջ��Ԫ�أ����vj���ۼ�����һ��
3.2 ������vj�ĸ����ٽ�����ȼ�һ��
3.3 ���µ����Ϊ0�Ķ�����ջ
*/




string res[8]= { "Begin","Base1","Base2","Base3","Base4","Devered1","Devered2","Last" };

struct ArcNode  //�߱�
{
	int adjvex;     //��¼��һ��������
	ArcNode *next;
};

struct VertexNode  //�����
{
	DataType vertex;  //��¼��һ�������
	ArcNode *firstEdge;
	size_t IN;  //��¼���
};
class ALGraph
{
private:
	VertexNode adjust[MAX_VERTEX];
	int vertexNum, arcNum;  //�������  �ߵĸ���
public:
	ALGraph(DataType v[], int n, int e);
	void printTable(VertexNode *p, int n, int e);
	VertexNode* GetVerTexNode()   //��ȡ�����
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
		adjust[i].IN = 0;
	}
	for (int j = 0; j < arcNum; j++)
	{
		int vi;
		int vj;
		cout << "���������������������Լ������·��:(�м��Կո����)" << endl;
		cin >> vi >> vj ;
		ArcNode * s;
		s = new ArcNode;
		s->adjvex = vj;  //�洢�յ�
		s->next = adjust[vi].firstEdge;
		adjust[vj].IN++;
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
			cout << res[temp1->adjvex] << "->";
			temp1 = temp1->next;
		}
		cout << "NULL" << endl;
		temp++;
	}
}

VertexNode* ScannerTable(VertexNode *p, int n, int e)   //ɨ�趥����ҳ����Ϊ0�Ķ���
{
	int count = 0;
	int i = 0;
	auto it = p;
	while (count < n)
	{
		if (it->IN == 0)
		{
			auto temp = it->firstEdge;
			while (temp != NULL)  //ѭ�����������ӵĶ������ȼ�һ
			{
				p[temp->adjvex].IN--;  //ȥ����������Ļ�
				temp = temp->next;
			}
			it->IN--;  //ȥ����������
			return it;
		}
		it++;
		count++;
	}
		return NULL;
}

stack<VertexNode*> Last;

void Assemb(VertexNode *p, int n, int e)  //װ��
{
	stack<VertexNode*> dp;
	int count = 0; //�����ۼ���
	VertexNode* pp = ScannerTable(p, n, e);
	dp.push(pp);
	Last.push(pp);
	while (!dp.empty())
	{
		cout <<dp.top()->vertex << "->";
		dp.pop();
		count++;
		auto temp = ScannerTable(p, n, e);
		if (temp != NULL)
		{
			dp.push(temp);
			Last.push(temp);
		}
	}
	cout << endl;
}

void PlanPath(VertexNode *p, int n, int e)
{
	string str;
	cout << "��Ҫ�������" << endl;
	cin >> str;
	//�滮���·��
	cout << "���·��" << endl;
	while (str != Last.top()->vertex && !Last.empty())
	{
		cout << Last.top()->vertex << "->";
		Last.pop();
	}
	cout << "��װ·��" << endl;
	while(!Last.empty())
	{
		cout << Last.top()->vertex << "->";
		Last.pop();
	}

}