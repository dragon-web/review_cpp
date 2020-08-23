#include"BinTree.h"


int main()
{
	int arr[] = { 1,3,5,0,0,6,0,0,2,4,0,0,6,0,0};   //我们用0来表示NULL
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

	
	system("pause");
	return 0;
}