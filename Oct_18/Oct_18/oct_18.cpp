#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>

using namespace std;
/*
int Max(int arr[], int n)
{
	if (n == 0)
		return arr[n];
	else
	{
		return Max(arr,n-1) > arr[n] ? Max(arr,n-1) : arr[n];
	}
}

int main()
{
	int arr[] = { 4,6,8,7,2 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int res = Max(arr, len-1);
	cout << "res = " << res << endl;
	system("pause");
	return 0;
}
*/


void PrintArray(int Array[],int n)
{
	int i;
	for ( i = 0; i < n; i++)
	{
		cout << Array[i] << " ";
	}
	cout << endl;
}
void Swap(int arr[], int &left, int &right)
{
	int temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;
}
void Permutation(int Array[], int p, int q)
{
	if (p == q)
	{
		PrintArray(Array,q+1);
	}
	else
	{
		int i;
		for ( i = p; i <= q; ++i)
		{
			Swap(Array, p, i);
			Permutation(Array, p + 1, q);
			Swap(Array, p, i);
		}
	}
}
int main()
{
	int arr[] = { 1,2,3 };
	Permutation(arr, 0, 2);
	system("pause");
	return 0;
}
