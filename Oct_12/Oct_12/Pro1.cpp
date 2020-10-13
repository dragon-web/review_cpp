#include"common.h"

void pererror_function(int error_code) {
	switch (error_code) {
	case InsertError: printf("Fail to insert node\n"); break;
	case DeleteError: printf("Fail to delete node\n"); break;
	case SearchError: printf("Fail to searching node\n"); break;
	case SearchMaxError: printf("Fail to search max node\n"); break;
	case SearchMinError: printf("Fail to search min node\n"); break;
	case SearchSuccessorError: printf("Fail to search sucessor\n"); break;
	case searchPredecessorError: printf("Fail to search predecessor\n"); break;
	case FailDeleteAllError: printf("Fail to delete all node\n"); break;

	default:printf("Error\n"); break;
	}
}
//只能用非递归写
BinarySearchTreeNode *insert(BinarySearchTreeNode **Tree, int X ) {
	int flag = 1; // flag == 1 时，表示左树出 flag == 2 时，表示右树出
	if (*Tree == NULL)
	{
		*Tree = (BinarySearchTreeNode*)malloc(sizeof(BinarySearchTreeNode));
		if (*Tree == NULL)
		{
			pererror_function(InsertError);
			return NULL;
		}
		(*Tree)->left = NULL;
		(*Tree)->right = NULL;
		(*Tree)->parent = NULL;
		(*Tree)->value = X;
	}
	else
	{
		BinarySearchTreeNode* p = *Tree;
		BinarySearchTreeNode* pre = NULL;
		while (p)
		{
			if (p->value >= X)
			{
				pre = p;
				p = p->left;
				flag = 1;
			}
			else {
				pre = p;
				p = p->right;
				flag = 2;
			}
		}
		p = (BinarySearchTreeNode*)malloc(sizeof(BinarySearchTreeNode));
		if (*Tree == NULL)
		{
			pererror_function(InsertError);
			return NULL;
		}
		p->left = NULL;
		p->right = NULL;
		p->value = X;
		p->parent = pre;
		if (flag == 1)
		{
			pre->left = p;
		}
		else
		{
			pre->right = p;
		}
	}
	
	return *Tree;
}


/*
BinarySearchTreeNode *searchNode(BinarySearchTreeNode *Tree, int X) {
	if (Tree == NULL)
	{
		pererror_function(SearchError);
		return NULL;
	}
	else
	{
		if (X == Tree->value)
			return Tree;
		else if (X < Tree->value)
			return searchNode(Tree->left, X);
		else
			return searchNode(Tree->right, X);
	}
}

BinarySearchTreeNode *findMaxNode(BinarySearchTreeNode *Tree) {
	if (Tree == NULL)
	{
		pererror_function(SearchMaxError);
		return NULL;
	}
	else
	{
		BinarySearchTreeNode *p = Tree;
		BinarySearchTreeNode *temp;
		while (p != NULL)
		{
			temp = p;
			p = p->right;
		}
		return temp;
	}
}


BinarySearchTreeNode *findMinNode(BinarySearchTreeNode *Tree) {
	if (Tree == NULL)
	{
		pererror_function(SearchMinError);
		return NULL;
	}
	else
	{
		BinarySearchTreeNode *p = Tree;
		BinarySearchTreeNode *temp;
		while (p != NULL)
		{
			temp = p;
			p = p->left;
		}
		return temp;
	}
}

void deleteNode(BinarySearchTreeNode* &bt)
{
	BinarySearchTreeNode *p, *parent, *pre;
	if (bt->left == NULL && bt->right == NULL) //叶子节点
	{
		p = bt;
		bt = NULL; //预防野指针
		free(p);
	}
	else if (bt->right == NULL)
	{
		p = bt;
		bt = bt->left;
		free(p);
	}
	else if (bt->left == NULL)
	{
		p = bt;
		bt = bt->right;
		free(p);
	}
	else   //左右子树均不为空
	{
		parent = bt;
		pre = bt->left;
		while (pre->right) //转左，然后向右到尽头（找到右子树中最大节点）
		{
			parent = pre;
			pre = pre->right;
		}
		bt->value = pre->value;
		if (parent != bt)  //判断是否只有一层
		{
			parent->right = pre->left;
		}
		else
		{
			parent->left = pre->left;
		}
		 free(pre);
	}
}
BinarySearchTreeNode *deleteBST(BinarySearchTreeNode *Tree, int X) {
	if (Tree == NULL)
	{
		pererror_function(DeleteError);
		return false;
	}
	else
	{
		if (Tree->value == X)
		{
			deleteNode(Tree);
		}
		else if (X < Tree->value)
		{
			return deleteBST(Tree->right,X);
		}
		else
		{
			return deleteBST(Tree->right,X);
		}
		return ;
	}
}



BinarySearchTreeNode *findSuccessorNode(BinarySearchTreeNode *Tree, int X) {
	//Write your own code below
}


BinarySearchTreeNode *findPredecessorNode(BinarySearchTreeNode *Tree, int X) {
	//Write your own code below
}

void makeEmptyNode(BinarySearchTreeNode *Tree) {
	if (Tree == NULL)
		return;
	else
	{
		makeEmptyNode(Tree->left);
		makeEmptyNode(Tree->right);
		free(Tree);
	}
}

*/

int main() {

	BinarySearchTreeNode *root = NULL;

	insert(&root, 10);
	insert(&root, 20);
	insert(&root, 5);
	insert(&root, 1);
	insert(&root, 15);
	insert(&root, 21);
	insert(&root, 30);
	insert(&root, 100);
	insert(&root, 40);
	insert(&root, 50);


	/*node = searchNode(root, 1);
	if (node != NULL)
		printf("%d \n", node->value);

	node = searchNode(root, 13);
	if (node != NULL)
		printf("%d \n", node->value);

	node = findMaxNode(root);
	if (node != NULL)
		printf("%d \n", node->value);

	node = findMinNode(root);
	if (node != NULL)
		printf("%d \n", node->value);

	node = findSuccessorNode(root, 15);
	if (node != NULL)
		printf("%d \n", node->value);

	node = findPredecessorNode(root, 15);
	if (node != NULL)
		printf("%d \n", node->value);

	deleteBST(root, 15);

	makeEmptyNode(root);

	node = searchNode(root, 10);
	if (node != NULL)
		printf("%d \n", node->value);
	*/
}
