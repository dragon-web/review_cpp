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
*/

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