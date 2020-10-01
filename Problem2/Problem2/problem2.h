#pragma once

#include"common.h"
typedef struct node {
	int val;
	struct node *next;
	struct node* prev;
} node_t;


bool insert(node_t *head, int X);
bool _delete(node_t *head, int X);
bool find(node_t *head, int X);
int findkth(node_t *head, int index);
void printlist(node_t *head);
bool isEmpty(node_t *head);
bool makeEmpty(node_t *head);
