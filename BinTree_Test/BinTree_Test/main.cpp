#include"BinTree.h"


int main()
{
	//int arr[] = { 1,3,5,0,0,6,0,0,2,4,0,0,6,0,0};   //我们用0来表示NULL
	int arr[] = {1,5,7,0,0,96,0,0,2,4,0,0,8,0,0};   //我们用0来表示NULL
	NodeList* q = createBinaryTree(arr);
	printf("前序遍历为:\n");
	DLR(q);
	printf("\n中序遍历为:\n");
	LDR(q);
	printf("\n后序遍历为:\n");
	LRD(q);
	printf("\n层次遍历为：\n");
	levelTraversal(q);
	destroyBinaeryTree(q);
	printf("删除成功\n");
	system("pause");
	return 0;
}