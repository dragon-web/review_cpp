#define _CRT_SECURE_NO_WARNINGS 

//AOE������������

#include"path.h"





int main()
{
	ALGraph mygraph(res,8,10);
	mygraph.printTable(mygraph.GetVerTexNode(), 8, 10);
	cout << "װ��·��Ϊ" << endl;
	Assemb(mygraph.GetVerTexNode(), 8, 10);
	PlanPath(mygraph.GetVerTexNode(), 8, 10);
	system("pause");
	return 0;
}