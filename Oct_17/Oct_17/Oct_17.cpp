#include<iostream>
#include<stack>
#include<queue>
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
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		//ÖÐÐò±éÀú
		if (pRoot == NULL)
		{
			return NULL;
		}
		stack<TreeNode*> S;
		vector<TreeNode*> res;
		TreeNode* p = pRoot;
		while (p != NULL || S.size())
		{
			while (p != NULL)
			{
				S.push(p);
				p = p->left;
			}
			p = S.top();
			S.pop();
			res.push_back(p);
			p = p->right;
		}
		if (res.size() < k)
		{
			return NULL;
		}
		return res[k - 1];

	}
};

int main()
{
	TreeNode p1(5); // 1
	TreeNode p2(3); // 2
	TreeNode p3(7); // 3
	p1.left = &p2;
	p1.right = &p3;
	p2.left = NULL;
	p2.right = NULL;
	p3.left = NULL;
	p3.right = NULL;
	Solution a;
	auto it = a.KthNode(&p1, 3);
	cout << it->val << endl;

	system("pause");
	return 0;
}