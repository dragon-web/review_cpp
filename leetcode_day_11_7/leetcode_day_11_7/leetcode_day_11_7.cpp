#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isUnivalTree(TreeNode* root) {
		vector<int> dp;
		stack<TreeNode*> temp;
		
		temp.push(root);
		while (temp.size())
		{
			TreeNode p = temp.top();
			temp.pop();

		}


	}
};