#include"problem2.h"


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

bool makeEmpty(node_t *head) {
	node_t* p = head;
	node_t* temp = p->next;
	while (p != NULL)
	{
		temp = p;
		p = p->next;
		free(temp);
	}
	printf("The LinkList has been empty\n");
	return true;
}

int findkth(node_t *head, int index) {
	int count = 0;
	node_t * p = head->next;
	while (p != NULL)
	{
		if (count == index)
		{
			printf("The value of index is %d \n",p->val);
			return p->val;
		}
		p = p->next;
		count++;
	}
	pererror_function(3);
	return -1;
}

bool isEmpty(node_t *head) {
	if (head->next == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool _delete(node_t *head, int X) {
	
	if (head->next != NULL)
	{
		bool flag = find(head, X);
		if (flag)
		{
			node_t* p = head;
			node_t* q = p->next;
			while (q != NULL)
			{
				if (q->val == X)
				{
					p->next = q->next;
					free(q);
					return true;
				}
				q = q->next;
				p = p->next;
			}
			pererror_function(1);
		}
	}
	return false;
}

bool find(node_t *head, int X) {
	node_t* p = head->next;
	while (p != NULL)
	{
		if (p->val == X)
		{
			printf("%d has been found\n",X);
			return true;
		}
		p = p->next;
	}
	pererror_function(2);
	return false;
}

void printlist(node_t *head) {
	node_t *p = head->next;
	while (p != NULL)
	{
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
}

bool insert(node_t *head, int X) {
	node_t *temp = (node_t*)malloc(sizeof(node_t) * 1);
	node_t *p = head->next;
	temp->val = X;
	temp->next = NULL;
	if (head->next == NULL)
	{
		head->next = temp;
		return true;
	}
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = temp;
	return true;
}
