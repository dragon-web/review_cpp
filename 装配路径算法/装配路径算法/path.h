#pragma once
#define DataType string
#define MAX_VERTEX 10
#include<iostream>
#include<stack>
#include<string>
#include<vector>

using namespace std;
/*
使用邻接表进行装配路径图的构造，然后借助栈这一数据结构实现拓扑排序。
（1）：从AOV网中选择一个没有前驱的顶点并且输出；
（2）：从AOV网中删去该顶点，并且删除所有以该顶点为尾的弧；
（3）：重复上述两个步骤，到全部顶点都被输出，或者AOV网中不存在没有前驱的顶点；
算法实现：
1：栈S初始化，累加器count初始化
2：扫描顶点表，将没有前驱的顶点压栈
3：当栈S非空时进行循环
3.1 vj = 栈顶元素；输出vj；累加器加一；
3.2 将顶点vj的各个临界点的入度减一；
3.3 将新的入度为0的顶点入栈
*/




string res[8]= { "Begin","Base1","Base2","Base3","Base4","Devered1","Devered2","Last" };

struct ArcNode  //边表
{
	int adjvex;     //记录下一个顶点标号
	ArcNode *next;
};

struct VertexNode  //顶点表
{
	DataType vertex;  //记录下一个顶点的
	ArcNode *firstEdge;
	size_t IN;  //记录入度
};
class ALGraph
{
private:
	VertexNode adjust[MAX_VERTEX];
	int vertexNum, arcNum;  //顶点个数  边的个数
public:
	ALGraph(DataType v[], int n, int e);
	void printTable(VertexNode *p, int n, int e);
	VertexNode* GetVerTexNode()   //获取顶点表
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
		cout << "请输入两个相连顶点编号以及两点的路径:(中间以空格隔开)" << endl;
		cin >> vi >> vj ;
		ArcNode * s;
		s = new ArcNode;
		s->adjvex = vj;  //存储终点
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

VertexNode* ScannerTable(VertexNode *p, int n, int e)   //扫描顶点表找出入度为0的顶点
{
	int count = 0;
	int i = 0;
	auto it = p;
	while (count < n)
	{
		if (it->IN == 0)
		{
			auto temp = it->firstEdge;
			while (temp != NULL)  //循环将后面连接的顶点的入度减一
			{
				p[temp->adjvex].IN--;  //去除掉相连点的弧
				temp = temp->next;
			}
			it->IN--;  //去除掉自身标记
			return it;
		}
		it++;
		count++;
	}
		return NULL;
}

stack<VertexNode*> Last;

void Assemb(VertexNode *p, int n, int e)  //装配
{
	stack<VertexNode*> dp;
	int count = 0; //定义累加器
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
	cout << "你要拆解的零件" << endl;
	cin >> str;
	//规划拆解路径
	cout << "拆解路径" << endl;
	while (str != Last.top()->vertex && !Last.empty())
	{
		cout << Last.top()->vertex << "->";
		Last.pop();
	}
	cout << "安装路径" << endl;
	while(!Last.empty())
	{
		cout << Last.top()->vertex << "->";
		Last.pop();
	}

}