#define _CRT_SECURE_NO_WARNINGS 


#include<iostream>
#include<time.h>
using namespace std;
/*
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


/*
int  Binary_Search(int arr[], int k, int left, int right)
{
	int mid = left + (right - left) / 2;
	while (left <= right)
	{
		if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else if (arr[mid] < k)
		{
			left = left - 1;
		}
		else  if (arr[mid] == k)
		{
			return mid;
		}
	}
	return -1;
}

int  Binary_Search(int arr[], int k, int left, int right)
{
	int mid = 0;
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] == k)
		{
			return mid;
		}
		else if (arr[mid] > k)
		{
			right = mid;
			continue;
		}
		else if (arr[mid] < k)
		{
			left = k;
			continue;
		}
	}
	return -1;
}

int main()
{
	int arr[10] = { 1 ,7 ,4, 0 ,9 ,4 ,8 ,8 ,2 ,4 };
	for (auto &e : arr)
	{
		cout << e << " ";
	}
	cout << endl;
	int res = Binary_Search(arr, 9, 0,9);

	cout <<res<< endl;
	system("pause");
	return 0;
}

void Swap(int arr[], int &left, int &right)
{
	int temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;
}

void heapify(int tree[], int n , int i)  // n 是多少个节点  i表示第几个节点
{
	if (i >= n)
	{
		return;
	}
	int c1 = 2 * i + 1;
	int c2 = 2 * i + 2;
	int max = i;
	if (c1 < n && tree[c1] > tree[max])
	{
		max = c1;
	}
	if (c2 < n && tree[c2] > tree[max])
	{
		max = c2;
	}
	if (max != i)
	{
		Swap(tree, max, i);
		heapify(tree, n, max);
	}
}

void Heap_Sort()
{
	int tree[] = { 1, 2 , 3 };
	int n = 3;
	heapify(tree, n, 0);
	for (auto &e : tree)
	{
		cout << e << " ";
	}
}

int main()
{
	Heap_Sort();
	system("pause");
	return 0;
}



#include<iostream>
#include<vector>
using namespace std;

// 递归方式构建大根堆(len是arr的长度，index是第一个非叶子节点的下标)
void adjust(vector<int> &arr, int len, int index)
{
	int left = 2 * index + 1; // index的左子节点
	int right = 2 * index + 2;// index的右子节点

	int maxIdx = index;
	if (left<len && arr[left] > arr[maxIdx])    
		maxIdx = left;
	if (right<len && arr[right] > arr[maxIdx])  
		maxIdx = right;
	if (maxIdx != index)
	{
		swap(arr[maxIdx], arr[index]);
		adjust(arr, len, maxIdx);
	}
}

// 堆排序
void heapSort(vector<int> &arr, int size)
{
	// 构建大根堆（从最后一个非叶子节点向上）
	for (int i = size / 2 - 1; i >= 0; i--)  //从最后一个非叶子节点进行调整
	{
		adjust(arr, size, i);
	}
	// 调整大根堆
	for (int i = size - 1; i >= 1; i--)
	{
		swap(arr[0], arr[i]);           // 将当前最大的放置到数组末尾
		adjust(arr, i, 0);              // 将未完成排序的部分继续进行堆排序
	}
}

int main()
{
	vector<int> arr = { 8, 1, 14, 3, 21, 5, 7, 10 , 8 , 7 };
	heapSort(arr, arr.size());
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << endl;
	}
	system("pause");
	return 0;
}
*/

//归并排序
//基本思想，将两个或者两个以上的有序序列归并成一个有序序列
//内部排序中用的比较多的通常采用二路归并排序，将位置相邻的两个有序子序列归并成一个
//难点是如何将两个有序的子序列合并成一个有序子序列
//分治法的典型应用
//
/*
template<typename T> // 整數或浮點數皆可使用,若要使用物件(class)時必須設定"小於"(<)的運算子功能
void merge_sort(T arr[], int len) {
	T *a = arr;
	T *b = new T[len];
	for (int seg = 1; seg < len; seg += seg) {
		for (int start = 0; start < len; start += seg + seg) {
			int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
			int k = low;
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			while (start1 < end1 && start2 < end2)
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			while (start1 < end1)
				b[k++] = a[start1++];
			while (start2 < end2)
				b[k++] = a[start2++];
		}
		T *temp = a;
		a = b;
		b = temp;
	}
	if (a != arr) {
		for (int i = 0; i < len; i++)
			b[i] = a[i];
		b = a;
	}
	delete[] b;
}


int main()
{ 
	int arr[] = { 8, 1, 14, 3, 21, 5, 7, 10 , 8 , 7 };

	system("pause");
	return 0;
}



template<typename T>
void Swap(T *a, T * b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

template<class T>
void Shell_Sort(T *array, int n, int d)
{
		
	
}


int main()
{
	int arr[10] = { 1 ,7 ,4, 0 ,9 ,4 ,8 ,8 ,2 ,4 };
	for (auto &e : arr)
	{
		cout << e << " ";
	}
	cout << endl;
	Shell_Sort(arr, 10, 3);
	for (auto &e : arr)
	{
		cout << e << " ";
	}

	int *p = new int(2);
	cout << endl;
	system("pause");
	return 0;
}



void Swap(int arr[], int &left, int &right)
{
	int temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;
}

void heapify(int tree[], int n, int i)  // n 是多少个节点  i表示第几个节点
{
	if (i >= n)
	{
		return;
	}
	int c1 = 2 * i + 1;
	int c2 = 2 * i + 2;
	int max = i;
	if (c1 < n && tree[c1] > tree[max])
	{
		max = c1;
	}
	if (c2 < n && tree[c2] > tree[max])
	{
		max = c2;
	}
	if (max != i)
	{
		Swap(tree, max, i);
		heapify(tree, n, max);
	}
}

void Heap_Sort()
{
	int tree[] = { 1 ,7 ,4, 0 ,9 ,4 ,8 ,8 ,2 ,4 };
	int n = sizeof(tree) / sizeof(tree[0]);
	heapify(tree, n, 0);
	for (auto &e : tree)
	{
		cout << e << " ";
	}
}

int main()
{
	Heap_Sort();
	system("pause");
	return 0;
}


/*
void *__CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc)
{
	// try to allocate size bytes
	void *p;
	while ((p = malloc(size)) == 0)
		if (_callnewh(size) == 0)
		{
			// report no memory
			// 如果申请内存失败了，这里会抛出bad_alloc 类型异常
			static const std::bad_alloc nomem;
			_RAISE(nomem);
		}
	return (p);
}*/


#include <iostream>
using namespace std;
template<typename T>
void adjust(T* arr, int sign, int len) {
	T temp = arr[sign];
	//每一次循环都更新该父节点为根的完全二叉树最大堆
	for (int i = sign * 2 + 1; i < len; i = i * 2 + 1) {
		if (i + 1 < len && arr[i + 1] > arr[i])
			i++;
		//判断子节点 大于父节点 
		if (arr[i] > temp) {
			arr[sign] = arr[i];
			sign = i;
		}
	}
	arr[sign] = temp;
}

template<typename T>
void swap(T* arr, int x, int y) {
	T temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}
template<typename T>
void sort(T* arr, int length) {
	//1.从所有非叶子节点 构建初始大顶堆
	for (int i = length / 2 - 1; i >= 0; i--) {
		adjust(arr, i, length);
	}
	//
	for (int i = length - 1; i; i--) {
		//2.交换最大堆 和 相对的最后一个元素
		swap(arr, i, 0);
		//3.重新调整堆结构
		adjust(arr, 0, i);
	}
}
template<typename T>
void print(const T* ar, int len) {
	for (int j = 0; j < len; j++) {
		cout << j << " :  " << ar[j] << endl;
	}
}
int main()
{
	int arr[] = { 0,2,1,4,3,6,8,9,7,5 };
	sort(arr, 10);
	print(arr, 10);
	system("pause");
	return 0;
}



