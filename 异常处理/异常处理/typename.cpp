#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>

using namespace std;
/*
template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<class T>
T Inc(int n)
{
	return 1 + n;
}
template<class T1,class T2>
T2 print(T1 arg1, T2 arg2)
{
	cout << arg1 << " " << arg2 << endl;
	return arg2;
}
template<class T1,class T2>
T2 print(T1 arg1, T2 arg2)
{
	cout << arg1 << " " << arg2 << endl;
	return arg2;
}

//设计：求一个数组中最大元素模板
*/


template<class T1, class T2>
T1& find_Max(T1 *arr,T2 length,T1& max)
{
	max = arr[0];
	for (int i = 0; i < length; ++i)
	{
		max = max > arr[i] ? max : arr[i];
	}
	return max;
}

int main()
{
	//cout << Inc<double>(10) << endl;
	int max;
	int arr[] = { 12,551,852,96,71,26,325,1234,856,95852 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int x = find_Max(arr, sz, max);
	cout << "max = " << max << endl;
	system("pause");
	return 0;
}