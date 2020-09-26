#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	bool isMinor(TreeNode* p, TreeNode* q)
	{
		if ((!p && !q) && q->val == p->val)
			return true;
		if (!p || !q)
			return false;
	}
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == NULL)
		{
			return true;
		}
		return isMinor(pRoot->left, pRoot->right);
	}
};