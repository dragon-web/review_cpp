#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
// 原理 ： 每趟排序在当前待排序序列中选出关键码最小的记录 ，添加到有序序列中
#include<vector>
using namespace std;


/*


void Select_Sort(int arr[], size_t len)
{
	int min;
	for (int i = 0; i < len - 1; ++i)
	{
		min = i;
		for (int j = i + 1; j < len; ++j)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
			if (min != i)
			{
				int tmp = arr[i];
				arr[i] = arr[min];
				arr[min] = tmp;
			}
		}
	}
}

int main()
{
	int arr[] = { 1,43,5,21,2,4,5,7 };
	size_t len = sizeof(arr) / sizeof(arr[0]);
	Select_Sort(arr, len);
	for (auto &e : arr)
	{
		std::cout << e << " ";
	}
	system("pause");
	return 0;
}





void RadixSort(int *arr, int length) {
	//申请桶空间 
	int* p = (int*)malloc(sizeof(int)*length);
	//将这个桶空间初始化为不可能出现的值 
	memset(p, 0, length * sizeof(int));
	for (int i = 0; i < length; ++i) {
		p[arr[i] - 1] += 1;
	}
	for (int j = 0; j < length; ++j) {
		if (p[j] == 0) continue;
		while (p[j]) {
			printf("%d ", j + 1);
			p[j]--;
		}
	}
}

/*
int main() {
	int arr[] = {
	 4,8,6,9,7,2,2,1,6
	};
	int sz = sizeof(arr) / sizeof(arr[0]);
	RadixSort(arr, sz);
	system("pause");
	return 0;
}


void sort(int a[], int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (a[i] > a[j])
			{
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}
template<class T>
void InsertSort(T* array, int n) {
	int i, j;
	T temp;
	for (i = 1; i < n; i++) {
		j = i;
		temp = array[i];
		while (j > 0 && temp < array[j - 1]) {
			array[j] = array[j - 1];
			j--;
		}
		array[j] = temp;
	}
}

void Bubble_Sort(int *arr, int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0 ; j < len - i - 1; ++j)
		{
			if (arr[j] < arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

int main()
{
	int arr[] = {4,8,6,9,7,2,2,1,6};
	int len = sizeof(arr) / sizeof(arr[0]);
	Bubble_Sort(arr, len);
	for (auto &e : arr)
	{
		cout << e << " ";
	}
	system("pause");
	return 0;
}




#include <iostream>
using namespace std;
void _AdjustDown(int *ar, int left, int right, int start)//调整为大堆
{
	//要注意我们的start是按照left为0传入的
	int i = start + left;//left可能不是0，这个时候最后一个节点的父节点需要加left
	int j = 2 * start + 1 + left;//j和i一个意思，都加left
	while (j <= right)//左子节点存在
	{
		if (j + 1 <= right && ar[j] < ar[j + 1])
			++j;//j指向左右子节点值较大子节点
		if (ar[i] < ar[j])
		{
			swap(ar[i], ar[j]);
			i = j;//改变调整位置
			//j的求法就是先把i还原为0做开始元素下标时的值，然后和0情况一样，只是加一个left
			j = 2 * (i - left) + 1 + left;
		}
		else
			break;
	}
}
void HeapSort(int *ar, int left, int right)
{
	int n = right - left + 1;//待排序元素个数
	int start = n / 2 - 1;//将序列看成一颗完全二叉树，找到最后一个节点的父节点
	while (start >= 0)//调整为大堆
	{
		_AdjustDown(ar, left, right, start);
		--start;
	}
	int end = right;//无序序列的最后一个元素
	while (end > left)
	{
		swap(ar[left], ar[end]);
		--end;
		_AdjustDown(ar, left, end, 0);//再次调整为大堆(只调整根节点)
	}
}
int main()
{
	int ar[] = { 100,6,2,4,9,7,6,8,10,25,14 ,107,1020};
	HeapSort(ar, 3, sizeof(ar) / sizeof(ar[0]) - 1);
	for (auto e : ar)
		cout << e << " ";
	cout << endl;
	system("pause");
	return 0;
}


//快速排序  ： 在冒泡排序中进行的改进


void quickSort(int *arr, int begin, int end)
{
	//如果区间不只一个数
	if (begin < end)
	{
		int temp = arr[begin]; //将区间的第一个数作为基准数
		int i = begin; //从左到右进行查找时的“指针”，指示当前左位置
		int j = end; //从右到左进行查找时的“指针”，指示当前右位置
		//不重复遍历
		while (i < j)
		{
			//当右边的数大于基准数时，略过，继续向左查找
			//不满足条件时跳出循环，此时的j对应的元素是小于基准元素的
			while (i<j && arr[j] > temp)
				j--;
			//将右边小于等于基准元素的数填入右边相应位置
			arr[i] = arr[j];
			//当左边的数小于等于基准数时，略过，继续向右查找
			//(重复的基准元素集合到左区间)
			//不满足条件时跳出循环，此时的i对应的元素是大于等于基准元素的
			while (i < j && arr[i] <= temp)
				i++;
			//将左边大于基准元素的数填入左边相应位置
			arr[j] = arr[i];
		}
		//将基准元素填入相应位置
		arr[i] = temp;
		//此时的i即为基准元素的位置
		//对基准元素的左边子区间进行相似的快速排序
		quickSort(arr, begin, i - 1);
		//对基准元素的右边子区间进行相似的快速排序
		quickSort(arr, i + 1, end);
	}
	//如果区间只有一个数，则返回
	else
		return;
}
int main()
{
	int num[12] = { 23,45,17,11,13,89,72,26,3,17,11,13 };
	int n = 12;
	quickSort(num, 0, n - 1);
	cout << "排序后的数组为：" << endl;
	for (int i = 0; i < n; i++)
		cout << num[i] << ' ';
	cout << endl;
	system("pause");
	return 0;
}
*/
/*
void * operator new (size_t size)
{
	void *p;
	while ((p = malloc(size)) == 0)
	{
		if (_callnewh(size) == 0)
		{
			//抛出异常
		}
	}
	return p;
}


void Swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int Get_Value(int arr[],int start,int end)
{
	int i = start;
	int j = end;
	while (i < j)
	{
		while (i < j && arr[i] <= arr[j])
		{
			j--;
		}
		if (i < j)
		{
			Swap(&arr[i], &arr[j]);
			i++;
		}
		while (i < j && arr[i] <= arr[j])
		{
			i++;
		}
		if (i < j)
		{
			Swap(&arr[i], &arr[j]);
			j--;
		}
	}
	return i;
}

void quick_Sort(int r[],int first,int end)
{
	if (first < end)
	{
		int pos = Get_Value(r, first, end);
		quick_Sort(r, first, pos - 1);
		quick_Sort(r, pos + 1, end);
	}
	
}

int main()
{
	int num[12] = { 23,45,17,11,13,89,72,26,3,17,11,13 };
	int start = 0;
	int end = 12 - 1;
	quick_Sort(num, start, end);
	for (auto &e : num)
	{
		cout << e << " ";
	}
	system("pause");
	return 0;
}

int getStandard(int array[], int i, int j) {
	//基准数据 
	int key = array[i];
	while (i < j) {
		while (i < j && array[j] >= key) {
			j--;
		}
		if (i < j) {
			array[i] = array[j];
		}
		while (i < j && array[i] <= key) {
			i++;
		}
		if (i < j) {
			array[j] = array[i];
		}
	}
	array[i] = key;
	return i;
}

void QuickSort(int array[], int low, int high) {
	if (low < high) {
		int standard = getStandard(array, low, high);
		QuickSort(array, low, standard - 1);
		QuickSort(array, standard + 1, high);
	}
}

void display(int array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}




void _AdjustDown(int *ar, int left, int right, int start)//调整为大堆
{
	//要注意我们的start是按照left为0传入的
	int i = start + left;//left可能不是0，这个时候最后一个节点的父节点需要加left
	int j = 2 * start + 1 + left;//j和i一个意思，都加left
	while (j <= right)//左子节点存在
	{
		if (j + 1 <= right && ar[j] < ar[j + 1])
			++j;//j指向左右子节点值较大子节点
		if (ar[i] < ar[j])
		{
			swap(ar[i], ar[j]);
			i = j;//改变调整位置
			//j的求法就是先把i还原为0做开始元素下标时的值，然后和0情况一样，只是加一个left
			j = 2 * (i - left) + 1 + left;
		}
		else
			break;
	}
}

/*
void HeapSort(int *ar, int left, int right)
{
	int n = right - left + 1;//待排序元素个数
	int start = n / 2 - 1;//将序列看成一颗完全二叉树，找到最后一个节点的父节点
	while (start >= 0)//调整为大堆
	{
		_AdjustDown(ar, left, right, start);
		--start;
	}
	int end = right;//无序序列的最后一个元素
	while (end > left)
	{
		swap(ar[left], ar[end]);
		--end;
		_AdjustDown(ar, left, end, 0);//再次调整为大堆(只调整根节点)
	}
}
*/
void Swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void Bubble_Sort(int *arr,int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j+1], &arr[j]);
			}
		}
	}
}

void Select_Sort(int *arr, int len)
{
	for (int i = 0; i < len; ++i)
	{
		for (int j = i + 1; j < len; ++j)
		{
			if (arr[i] > arr[j])
			{
				Swap(&arr[i], &arr[j]);
			}
		}
	}
}

/*
void Insert_Sort(int *arr, int len)
{
	int i, j;
	int temp;
	for (i = 0; i <len; ++i)
	{
		j = i;
		temp = arr[i];
		while (j > 0 && temp < arr[j - 1])
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = temp;
	}
}

*/
void Insert_Sort(int* arr,int len)
{
	int i, j, temp;
	for (i = 0; i < len; ++i)
	{
		j = i;
		temp = arr[i];
		while (j > 0 && arr[j-1] > temp)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = temp;
	}
}


int Adjust(int*arr ,int left,int right)
{
	int i = 0;
	int j = right;
	while (i < j && arr[i] <= arr[j])
	{
		j--;
	}
	if (i < j)
	{
		Swap(&arr[i], &arr[j]);
		i++;
	}
	while (i < j && arr[i] <= arr[j])
	{
		i++;
	}
	if (i < j)
	{
		Swap(&arr[i], &arr[j]);
		j--;
	}
	return i;
}

void Quic(int* arr,int left,int right)
{
	if (left < right)
	{
		int pos = Adjust(arr, left, right);
		Quic(arr,left,pos - 1);
		Quic(arr,pos + 1,right);
	}
}

int main()
{
	int ar[] = { 100,6,2,4,9,7,6,8,10,25,14 ,107,1020 };
	int length = sizeof(ar) / sizeof(ar[0]);
	Insert_Sort(ar,length);
	for (auto e : ar)
		cout << e << " ";
	cout << endl;
	system("pause");
	return 0;
}








