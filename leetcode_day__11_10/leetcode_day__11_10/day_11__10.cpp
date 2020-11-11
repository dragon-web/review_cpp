#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<vector>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
*/




class Solution {
public:
	void dfs(TreeNode* root,int x,int &depth,TreeNode** pre,TreeNode* p)
	{
		if (root == NULL)
		{
			return;
		}
		if (x == root->val)
		{
			*pre = p;
			depth = x;
			return;
		}
		dfs(root->left, x + 1, depth, pre, p);
		dfs(root->right, x + 1, depth, pre, p);
	}
	bool isCousins(TreeNode* root, int x, int y) {
		int depthx = 0;
		int depthy = 0;
		TreeNode* prex = NULL;
		TreeNode* prey = NULL;
		dfs(root,x,depthx,);
	}
};



using namespace std;
/*
class Solution {
public:
	int add(vector<int> nums)
	{
		int count = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			count += nums[i];
		}
		return count;
	}
	int maxSubArray(vector<int>& nums) {
		
		int max = nums[0];
		for (int k = 0; k < nums.size(); ++k)
		{
			max = max > nums[k] ? max : nums[k];
		}
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = i + 1; j < nums.size(); ++j)
			{
				vector<int>temp;
				for (int k = i; k <= j; ++k)
				{
					temp.push_back(nums[k]);
				}
				if (max < add(temp))
				{
					max = add(temp);
				}
			}
		}
		return max;
	}
};


int main()
{


	system("pause");
	return 0;
}*/



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