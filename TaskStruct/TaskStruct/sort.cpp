#include"common.h"

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void print(int *arr,int length)
{
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", arr[i]);
	}
}
void BubbleSort(int *ar, int left, int right)
{
	int n = right - left + 1;
	for (int i = left; i < right - 1; ++i)
	{
		for (int j = left; j < n - i - 1; ++j)
		{
			if (ar[j] > ar[j + 1])
			{
				Swap(&ar[j], &ar[j + 1]);
			}
		}
	}
}
int GetMidIndex(int *ar, int left, int right)
{
	int mid = (left + right) / 2;
	if (ar[left] > ar[mid] && ar[left] < ar[right])
		return left;
	if (ar[mid] > ar[left] && ar[mid] < ar[right])
		return mid;
	return right;
}

int _Partition_1(int *ar, int left, int right)
{
	int key = ar[left];
	while (left < right)
	{
		while (left < right && ar[right] >= key)
			right--;
		Swap(&ar[left], &ar[right]);
		while (left < right && ar[left] < key)
			left++;
		Swap(&ar[left], &ar[right]);
	}
	return left;
}







int main()
{
	int array[20];
	for (int i = 0; i < 20; ++i)
	{
		array[i] = rand() % 100;
	}
	print(array, 20);
	time_t start = clock();
	BubbleSort(array, 0, 19);
	time_t end = clock();
	//printf("InsertSort: %u\n", end - start);
	printf("\n");
	print(array, 20);
	system("pause");
	return 0;
}