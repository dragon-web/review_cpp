#include"BinTree.h"


int main()
{
	int arr[] = { 1,3,5,0,0,6,0,0,2,4,0,0,6,0,0};   //������0����ʾNULL
	NodeList* q = createBinaryTree(arr);
	printf("ǰ�����Ϊ:\n");
	DLR(q);
	printf("\n�������Ϊ:\n");
	LDR(q);
	printf("\n�������Ϊ:\n");
	LRD(q);
	printf("\n��α���Ϊ��\n");
	levelTraversal(q);
	destroyBinaeryTree(q);

	
	system("pause");
	return 0;
}