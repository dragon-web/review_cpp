#include<iostream>
#include<list>
#include<vector>

using namespace std;
/*
template <typename T>

void Print(const vector<T> &p)
{
	typename vector<T>::const_iterator i;
	for (i = p.begin(); i != p.end(); ++p);
	{
		cout << *i << " ";
	}
	cout << endl;
}

int main()
{
	/*vector<int> dp(5,78);
	vector<int> dp1(2,1);
	vector<int>::iterator p = dp.begin() + 1;
	auto q = dp.insert(p,12);  //insert 返回的是p的位置
	auto temp = dp1.insert(dp1.begin(), dp.begin(), dp.end());  //注意迭代器
	cout << "dp1.size() = " << dp1.size() << endl;
	int arr[] = { 1 , 2 , 3 , 4 , 5 };
	int arr1[] = { 5 , 6 };
	vector<int> dp(arr, arr + 5);
	vector<int> dp1(arr1, arr1 + 2);
	auto it = dp.erase(dp.begin());//删除当下迭代器后会自动后移
	//auto it1 = dp.erase(dp.begin(), dp.end());//删除也是一个左闭右开
	//Print(dp1);
	swap(dp, dp1);
	system("pause");
	return 0;
}

int main()
{
	vector<vector<int>> dp(3);
	for (int i = 0; i < dp.size(); ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			dp[i].push_back(j);
		}
	}

	for (int i = 0; i < dp.size(); ++i)
	{
		for (int j = 0; j < dp[i].size(); ++j)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	
	system("pause");
	return 0;
}
*/ //二维vector<vector<int>>





  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {


	}
};
