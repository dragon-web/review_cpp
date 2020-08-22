#include "common.h" 


int bin_search(int key[], int low, int high, int k)
{
	int mid;
	if (low > high)
		return -1;
	else {
		mid = (low + high) / 2;
		if (key[mid] == k)
			return mid;
		if (k > key[mid])
			return bin_search(key, mid + 1, high, k);        /*�����еĺ�벿�ֲ���*/
		else
			return bin_search(key, low, mid - 1, k);            /*�����е�ǰ�벿�ֲ���*/
	}
}
/*
int main()
{
	int n, i, addr;
	int A[10] = { 2,3,5,7,8,10,12,15,19,21 };
	printf("��������\n");
	for (i = 0; i < 10; i++)
		printf("%d ", A[i]);                                
	printf("\n�������Ԫ��\n");
	scanf("%d", &n);                                
	addr = bin_search(A, 0, 9, n);
	if (-1 != addr)                                
		printf("��Ԫ��Ϊ�±�Ϊ:%d\n ",addr);
	else printf("û�и�Ԫ�� %d\n", n);       
	system("pause");
	return 0;
}
*/