#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
 /*
class Solution {
public:
	void dfs(TreeNode* root, TreeNode* p, int d, int x, int& depth, TreeNode** parent) {
		if (root == NULL) return;
		if (root->val == x) {
			*parent = p;
			depth = d;
			return;
		}
		dfs(root->left, root, d + 1, x, depth, parent);
		dfs(root->right, root, d + 1, x, depth, parent);
	}
	bool isCousins(TreeNode* root, int x, int y) {
		int dx = 0;
		int dy = 0;
		TreeNode* px = NULL;
		TreeNode* py = NULL;
		dfs(root, NULL, 0, x, dx, &px);
		dfs(root, NULL, 0, y, dy, &py);
		return (dx == dy) && (px != py);
	}
};


class Solution {
public:
	void dfs(TreeNode* root, TreeNode** pre, int p, int& depth, int x, TreeNode* dp)
	{
		if (root == NULL)
		{
			return;
		}
		if (root->val == x)
		{
			depth = p;
			*pre = dp;
			return;
		}
		dfs(root->left, pre, p + 1, depth, x, root);
		dfs(root->right, pre, p + 1, depth, x, root);
	}
	bool isCousins(TreeNode* root, int x, int y) {
		int dx = 0;
		int dy = 0;
		TreeNode* px = NULL;
		TreeNode* py = NULL;
		dfs(root, &px, 0, dx, x, NULL);
		dfs(root, &py, 0, dy, y, NULL);
		return (dx == dy)&& (px == py);
	}
};
*/


  class Solution {
  public:

	  bool isMirr(TreeNode* p, TreeNode* q)
	  {
		  if (!q && !p)
		  {
			  return true;
		  }
		  if (!p || !q)
			  return false;
		  return isMirr(p->left, q->right) && isMirr(p->right, q->left);
	  }
	  bool isSymmetric(TreeNode* root) {
		  if (root == NULL)
			  return true;
		  return isMirr(root->left, root->right);
	  }
  };
int main()
{
	Solution a;
	Solution a;
	TreeNode a1(1);
	TreeNode a2(2);
	TreeNode a3(3);
	TreeNode a4(4);
	TreeNode a5(5);
	a1.left = &a2;
	a1.right = &a3;
	a2.left = NULL;
	a2.right = &a4;
	a3.left = NULL;
	a3.right = &a5;
	a4.right = NULL;
	a4.right = NULL;
	a5.left = NULL;
	a5.right = NULL;
	cout<<a.isCousins(&a1, 4, 5)<<endl;
	system("pause");
	return 0;
}