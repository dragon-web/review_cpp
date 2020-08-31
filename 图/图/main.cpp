#define _CRT_SECURE_NO_WARNINGS 
#include"graph.h"


int main()
{
	ALGraph g;
	InitAdjList(g);
	SetAdjList(g);
	ShowAdjList(g);
	system("pause");
	return 0;
}