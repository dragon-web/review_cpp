#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 从上往下打印出二叉树的每个节点，同层节点从左至右打印




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
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		queue<int> dp;
		dp.push(root->val);

	}
};


int main()
{


	return 0;
}