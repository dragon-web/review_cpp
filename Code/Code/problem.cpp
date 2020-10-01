#include"problem.h"

void pererror_function(int error_code) {
	switch (error_code) {
	case 0: printf("Fail to insert node\n"); break;
	case 1: printf("Fail to delete node\n"); break;
	case 2: printf("Fail to searching node\n"); break;
	case 3: printf("Fail to search k-th node\n"); break;
	case 4: printf("Fail to delete all the  node\n"); break;
	default: printf("Unexpected exception\n"); break;
	}
}

bool makeEmpty(int **L) {
	if (*L != NULL)
	{
		free(*L);
		*L = NULL;
	}
	return true;
}
bool isEmpty(int *L) {
	if (L == NULL)
	{
		printf("List is Empty\n");
		return true;
	}
	return false;
}

int findkth(int *L, int index, int length) {
	if (index >= length)
	{
		pererror_function(3);
		return -1;
	}
	else {
		return L[index];
	}
}

bool find(int *L, int X, int length) {
	int i = 0;
	for (i = 0; i < length; ++i)
	{
		if (L[i] == X)
		{
			printf("The index of NUm is %d\n", i);
			return true;
		}
	}
	printf("%d Not Find\n",X);
	return false;
}

bool _delete(int **L, int X, int *length) {
	bool flag = find(*L, X, *length);
	if (flag)
	{
		int i = 0;
		int j;
		for (i; i < *length; ++i)
		{
			if ((*L)[i] == X)
			{
				for (j = i + 1; j < *length; ++j)
				{
					(*L)[j - 1] = (*L)[j];
				}
				(*length)--;
				printf("%d:Delete Success\n", X);
				return true;
			}
		}
	}
	printf("%d:", X);
	pererror_function(1);
	return false;
}

void printlist(int *L, int length) {
	int i = 0;
	for (i = 0; i < length; ++i)
	{
		printf("%d ", L[i]);
	}
	printf("\n");
}

bool insert(int **L, int X, int* length) {
	if (*length >= MAX_SIZE)
	{
		pererror_function(0);
		return false;
	}
	(*length)++;
	(*L)[*length - 1] = X;
	return true;
}
