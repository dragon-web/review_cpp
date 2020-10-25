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
template<typename T>
void Swap(T *a, T * b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

template<class T>
void Shell_Sort(T *array, int n ,int d)
{
	int i, j;
	T temp;
	for (d = n/2; d >= 1; d/=2) {
		j = i - d;
		temp = array[i];
		while (j > 0 && temp < array[j]) {
			array[j] = array[j + d];
			j -= d;
		}
		array[j + d ] = temp;
	}

}

int main()
{
	int arr[10] = { 1 ,7 ,4, 0 ,9 ,4 ,8 ,8 ,2 ,4 };
	for (auto &e : arr)
	{
		cout << e << " ";
	}
	cout << endl;
	Shell_Sort(arr, 10,3);
	for (auto &e : arr)
	{
		cout << e << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}


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

void heapify(int tree[], int n , int i)  // n �Ƕ��ٸ��ڵ�  i��ʾ�ڼ����ڵ�
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

// �ݹ鷽ʽ���������(len��arr�ĳ��ȣ�index�ǵ�һ����Ҷ�ӽڵ���±�)
void adjust(vector<int> &arr, int len, int index)
{
	int left = 2 * index + 1; // index�����ӽڵ�
	int right = 2 * index + 2;// index�����ӽڵ�

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

// ������
void heapSort(vector<int> &arr, int size)
{
	// ��������ѣ������һ����Ҷ�ӽڵ����ϣ�
	for (int i = size / 2 - 1; i >= 0; i--)  //�����һ����Ҷ�ӽڵ���е���
	{
		adjust(arr, size, i);
	}
	// ���������
	for (int i = size - 1; i >= 1; i--)
	{
		swap(arr[0], arr[i]);           // ����ǰ���ķ��õ�����ĩβ
		adjust(arr, i, 0);              // ��δ�������Ĳ��ּ������ж�����
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

//�鲢����
//����˼�룬�����������������ϵ��������й鲢��һ����������
//�ڲ��������õıȽ϶��ͨ�����ö�·�鲢���򣬽�λ�����ڵ��������������й鲢��һ��
//�ѵ�����ν���������������кϲ���һ������������
//���η��ĵ���Ӧ��
//

template<typename T> // �������c���Կ�ʹ��,��Ҫʹ�����(class)�r����O��"С�"(<)���\���ӹ���
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