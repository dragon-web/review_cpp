#pragma once
#include"common.h"

#define MAX_SIZE 100


bool insert(int **L, int X, int* length);
bool _delete(int **L, int X, int *length);// Because delete is unqualfied ID
bool   find(int *L, int X, int length);
int  findkth(int *L, int X, int length);
void printlist(int *L, int length);
bool isEmpty(int *L);
bool makeEmpty(int **L);
