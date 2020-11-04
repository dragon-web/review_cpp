#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
// ԭ�� �� ÿ�������ڵ�ǰ������������ѡ���ؼ�����С�ļ�¼ ����ӵ�����������
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
	//����Ͱ�ռ� 
	int* p = (int*)malloc(sizeof(int)*length);
	//�����Ͱ�ռ��ʼ��Ϊ�����ܳ��ֵ�ֵ 
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
void _AdjustDown(int *ar, int left, int right, int start)//����Ϊ���
{
	//Ҫע�����ǵ�start�ǰ���leftΪ0�����
	int i = start + left;//left���ܲ���0�����ʱ�����һ���ڵ�ĸ��ڵ���Ҫ��left
	int j = 2 * start + 1 + left;//j��iһ����˼������left
	while (j <= right)//���ӽڵ����
	{
		if (j + 1 <= right && ar[j] < ar[j + 1])
			++j;//jָ�������ӽڵ�ֵ�ϴ��ӽڵ�
		if (ar[i] < ar[j])
		{
			swap(ar[i], ar[j]);
			i = j;//�ı����λ��
			//j���󷨾����Ȱ�i��ԭΪ0����ʼԪ���±�ʱ��ֵ��Ȼ���0���һ����ֻ�Ǽ�һ��left
			j = 2 * (i - left) + 1 + left;
		}
		else
			break;
	}
}
void HeapSort(int *ar, int left, int right)
{
	int n = right - left + 1;//������Ԫ�ظ���
	int start = n / 2 - 1;//�����п���һ����ȫ���������ҵ����һ���ڵ�ĸ��ڵ�
	while (start >= 0)//����Ϊ���
	{
		_AdjustDown(ar, left, right, start);
		--start;
	}
	int end = right;//�������е����һ��Ԫ��
	while (end > left)
	{
		swap(ar[left], ar[end]);
		--end;
		_AdjustDown(ar, left, end, 0);//�ٴε���Ϊ���(ֻ�������ڵ�)
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


//��������  �� ��ð�������н��еĸĽ�


void quickSort(int *arr, int begin, int end)
{
	//������䲻ֻһ����
	if (begin < end)
	{
		int temp = arr[begin]; //������ĵ�һ������Ϊ��׼��
		int i = begin; //�����ҽ��в���ʱ�ġ�ָ�롱��ָʾ��ǰ��λ��
		int j = end; //���ҵ�����в���ʱ�ġ�ָ�롱��ָʾ��ǰ��λ��
		//���ظ�����
		while (i < j)
		{
			//���ұߵ������ڻ�׼��ʱ���Թ��������������
			//����������ʱ����ѭ������ʱ��j��Ӧ��Ԫ����С�ڻ�׼Ԫ�ص�
			while (i<j && arr[j] > temp)
				j--;
			//���ұ�С�ڵ��ڻ�׼Ԫ�ص��������ұ���Ӧλ��
			arr[i] = arr[j];
			//����ߵ���С�ڵ��ڻ�׼��ʱ���Թ����������Ҳ���
			//(�ظ��Ļ�׼Ԫ�ؼ��ϵ�������)
			//����������ʱ����ѭ������ʱ��i��Ӧ��Ԫ���Ǵ��ڵ��ڻ�׼Ԫ�ص�
			while (i < j && arr[i] <= temp)
				i++;
			//����ߴ��ڻ�׼Ԫ�ص������������Ӧλ��
			arr[j] = arr[i];
		}
		//����׼Ԫ��������Ӧλ��
		arr[i] = temp;
		//��ʱ��i��Ϊ��׼Ԫ�ص�λ��
		//�Ի�׼Ԫ�ص����������������ƵĿ�������
		quickSort(arr, begin, i - 1);
		//�Ի�׼Ԫ�ص��ұ�������������ƵĿ�������
		quickSort(arr, i + 1, end);
	}
	//�������ֻ��һ�������򷵻�
	else
		return;
}
int main()
{
	int num[12] = { 23,45,17,11,13,89,72,26,3,17,11,13 };
	int n = 12;
	quickSort(num, 0, n - 1);
	cout << "����������Ϊ��" << endl;
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
			//�׳��쳣
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
	//��׼���� 
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




void _AdjustDown(int *ar, int left, int right, int start)//����Ϊ���
{
	//Ҫע�����ǵ�start�ǰ���leftΪ0�����
	int i = start + left;//left���ܲ���0�����ʱ�����һ���ڵ�ĸ��ڵ���Ҫ��left
	int j = 2 * start + 1 + left;//j��iһ����˼������left
	while (j <= right)//���ӽڵ����
	{
		if (j + 1 <= right && ar[j] < ar[j + 1])
			++j;//jָ�������ӽڵ�ֵ�ϴ��ӽڵ�
		if (ar[i] < ar[j])
		{
			swap(ar[i], ar[j]);
			i = j;//�ı����λ��
			//j���󷨾����Ȱ�i��ԭΪ0����ʼԪ���±�ʱ��ֵ��Ȼ���0���һ����ֻ�Ǽ�һ��left
			j = 2 * (i - left) + 1 + left;
		}
		else
			break;
	}
}

/*
void HeapSort(int *ar, int left, int right)
{
	int n = right - left + 1;//������Ԫ�ظ���
	int start = n / 2 - 1;//�����п���һ����ȫ���������ҵ����һ���ڵ�ĸ��ڵ�
	while (start >= 0)//����Ϊ���
	{
		_AdjustDown(ar, left, right, start);
		--start;
	}
	int end = right;//�������е����һ��Ԫ��
	while (end > left)
	{
		swap(ar[left], ar[end]);
		--end;
		_AdjustDown(ar, left, end, 0);//�ٴε���Ϊ���(ֻ�������ڵ�)
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








