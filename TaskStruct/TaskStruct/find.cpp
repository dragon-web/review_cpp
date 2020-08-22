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
			return bin_search(key, mid + 1, high, k);        /*在序列的后半部分查找*/
		else
			return bin_search(key, low, mid - 1, k);            /*在序列的前半部分查找*/
	}
}
/*
int main()
{
	int n, i, addr;
	int A[10] = { 2,3,5,7,8,10,12,15,19,21 };
	printf("测量数据\n");
	for (i = 0; i < 10; i++)
		printf("%d ", A[i]);                                
	printf("\n输出查找元素\n");
	scanf("%d", &n);                                
	addr = bin_search(A, 0, 9, n);
	if (-1 != addr)                                
		printf("该元素为下标为:%d\n ",addr);
	else printf("没有该元素 %d\n", n);       
	system("pause");
	return 0;
}
*/