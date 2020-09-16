#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/*
  struct TreeNode {
	  int val;
	  TreeNode *left;
	  TreeNode *right;
	  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
	int Size(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		else
		{
			return Size(root->left) + Size(root->right) + 1;
		}
	}
	vector<int> preorderTraversal(TreeNode* root) {
		int N = Size(root);
		vector<int> res(N);
		stack<TreeNode*> S;
		S.push(root);
		int i = 0;
		while (S.size())
		{
			TreeNode* p = S.top();
			S.pop();
			if (p->right != NULL)
				S.push(p->right);
			if (p->left != NULL)
				S.push(p->left);
			res[i] = p->val;
			i++;
		}
		return res;
	}
};

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 


  class Solution {
  public:
	  int Size(TreeNode *root)
	  {
		  if (root == NULL)
			  return 0;
		  return Size(root->left) + Size(root->right) + 1;
	  }
	  vector<int> inorderTraversal(TreeNode* root) {
		  int N = Size(root);
		  vector<int> res(N);
		  if (N == 0)
		  {
			  return res;
		  }
		  else
		  {
			  int i = 0;
			  TreeNode* q = root;
			  stack<TreeNode*> dp;
			  do {
				  if (dp.size())
					  q = dp.top();
				  while (q != NULL)
				  {
					  dp.push(q);
					  q = q->left;
				  }
				  if(dp.size())
				    q = dp.top();
					  res[i] = q->val;
					  i++;
				  dp.pop();
				  if (q->right != NULL)
				  {
					  dp.push(q->right);
				  }
			  } while (dp.size()|| q != NULL);
		  }
		  return res;
	  }
  };


  */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
	int Size(TreeNode *root)
	{
		if (root == NULL)
			return 0;
		return Size(root->left) + Size(root->right) + 1;
	}
	TreeNode* GoToLeft(TreeNode* p)
	{
		TreeNode* temp = p;
		while (temp != NULL)
		{
			temp = temp->left;
		}
		return temp;
	}

	vector<int> inorderTraversal(TreeNode* root) {
		int N = Size(root);
		vector<int> res(N);
		stack<TreeNode*> dp;
		TreeNode* temp1 = GoToLeft(root);
		dp.push(temp1);
		while (temp1)
		{
			dp.push(temp1);
			if (temp1->right)
			{
				temp1 = GoToLeft()
			}
		}




	}
};








  int main()
  {
	  Solution a;
	  TreeNode a1(1);
	  TreeNode a2(2);
	  TreeNode a3(3);
	  TreeNode a4(4);
	  a1.left = &a2;
	  a2.left = &a4;
	  a1.right = &a3;
	  vector<int> res = a.inorderTraversal(&a1);
	  system("pause");
	  return 0;
  }