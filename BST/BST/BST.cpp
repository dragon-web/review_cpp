#define _CRT_SECURE_NO_WARNINGS 
#define DataType int
#include<iostream>
#define N 10

using namespace std;

struct BiNode
{
	DataType data;
	BiNode* lchild, *rchild;
};

class BiSortTree {
private:
	BiNode* root;
private:
	void insertBST(BiNode* &bt, DataType key);
	void release(BiNode* bt);
	bool deleteBST(BiNode* &bt, DataType key);
	void deleteNode(BiNode* &bt);
	BiNode *searchBST(BiNode *bt, DataType key);

public:
	BiSortTree(DataType array[], int arrayLength);
	~BiSortTree() { release(root); }
	BiNode* searchBST(int key)
	{
		searchBST(root, key);
	}
	bool deleteBST(int key)
	{
		return deleteBST(root, key);
	}
	void inOrder() {
		inOrder(root);
	}
	void inOrder(BiNode *bt);
	BiNode* getRoot()
	{
		return this->root;
	}

};

void BiSortTree::insertBST(BiNode* &bt, DataType key)
{
	if (bt == NULL)
	{
		bt = new BiNode;
		bt->data = key;
		bt->lchild = NULL;
		bt->rchild = NULL;
	}
	else
	{
		if (key < bt->data)
			insertBST(bt->lchild, key);
		else
			insertBST(bt->rchild, key);
	}

}
BiSortTree::BiSortTree(DataType array[], int arrayLength)
{
	root = NULL;
	for (int i = 0; i < arrayLength; ++i)
	{
		insertBST(root, array[i]);
	}
}
BiNode* BiSortTree::searchBST(BiNode *bt, DataType key)
{
	if (bt == NULL)
	{
		return NULL;
	}
	else
	{
		if (key == bt->data)
			return bt;
		else if (key < bt->data)
			return searchBST(bt->lchild,key);
		else
			return searchBST(bt->rchild, key);

	}

}
bool BiSortTree::deleteBST(BiNode* &bt, DataType key)
{
	if (bt == NULL)
		return false;
	else
	{
		if (bt->data == key)
		{
			deleteNode(bt);
		}
		else if (key < bt->data)
		{
			return deleteBST(bt->rchild, key);
		}
		else
		{
			return deleteBST(bt->rchild, key);
		}
		return true;
	}
}

void BiSortTree::deleteNode(BiNode* &bt)
{
	BiNode *p,*parent,*pre;
	if (bt->lchild == NULL && bt->rchild == NULL) //Ҷ�ӽڵ�
	{
		p = bt;
		bt = NULL; //Ԥ��Ұָ��
		delete p;
	}
	else if (bt->rchild == NULL)
	{
		p = bt;
		bt = bt->lchild;
		delete p;
	}
	else if (bt->lchild == NULL)
	{
		p = bt;
		bt = bt->rchild;
		delete p;
	}
	else   //������������Ϊ��
	{
		parent = bt;
		pre = bt->lchild;
		while (pre->rchild) //ת��Ȼ�����ҵ���ͷ���ҵ������������ڵ㣩
		{
			parent = pre;
			pre = pre->rchild;
		}
		bt->data = pre->data;
		if (parent != bt)  //�ж��Ƿ�ֻ��һ��
		{
			parent->rchild = pre->lchild;
		}
		else
		{
			parent->lchild = pre->lchild;
		}
		delete pre;
	}
}


void BiSortTree::release(BiNode *bt)
{
	if (bt == NULL)
		return;
	else
	{ 
		release(bt->lchild);
		release(bt->rchild);
		free(bt);
	}
}

void BiSortTree::inOrder(BiNode *bt)
{
	if (bt == NULL)
		return;
	else
	{
		inOrder(bt->lchild);
		cout << bt->data << " ";
		inOrder(bt->rchild);
	}
}
int main()
{

	int arr[N];
	for (int i = 0;i < 10;++i)
	{
		arr[i]	= rand() % 10;
	}
	BiSortTree res(arr, N);
	res.inOrder(res.getRoot());
	system("pause");
	return 0;
}
