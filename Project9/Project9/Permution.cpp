#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>

using namespace std;

void PrintArray(int Array[],int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << Array[i] << " ";
	}
	cout << endl;
}

void Swap(int arr[], int left, int right)
{
	int temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;
}

void Permution(int arr[], int p, int q)
{
	if (p == q)
	{
		PrintArray(arr, p+1);
	}
	else
	{
		for (int i = p; i <= q; ++i)
		{
			Swap(arr, p, i);
			Permution(arr, p + 1, q);
			Swap(arr, i, p);
		}
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5 };
	Permution(arr, 0,4);
	system("pause");
	return 0;
}