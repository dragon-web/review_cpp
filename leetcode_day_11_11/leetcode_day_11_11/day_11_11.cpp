#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>

using namespace std;
/*
class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int temp = m;
		for (int i = m; i <= n; ++i)
		{
			temp &= i;
		}
		return temp;
	}
};


using namespace std;
 //寻找最长公共前缀
class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int num1 = m;
		int num2 = n;
		int count = 0;
		while (num1 != num2)
		{
			num1 >>= 1;
			num2 >>= 1;
			count++;
		}
		n <<= count;
		return n;
	}
};


class Solution
{
public:
	int rangeBitwiseAnd(int m, int n)
	{
		int count = 0; // 统计移位次数
		while (m != n)
		{
			m >>= 1;
			n >>= 1;
			count++;
		}
		n <<= count;
		return n;
	}
};


class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> temp;
		temp.resize(nums.size(), 1);
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				if (nums[j] < nums[i])
				{
					temp[j]++;
					if (temp[j] > temp[i])
					{
						temp[i] = temp[j];
					}
				}
			}
		}
	}
};
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int len = 1, n = (int)nums.size();
		if (n == 0) {
			return 0;
		}
		vector<int> d(n + 1, 0);
		d[len] = nums[0];
		for (int i = 1; i < n; ++i) {
			if (nums[i] > d[len]) {
				d[++len] = nums[i];
			}
			else {
				int l = 1, r = len, pos = 0;
				while (l <= r) {
					int mid = (l + r) >> 1;
					if (d[mid] < nums[i]) {
						pos = mid;
						l = mid + 1;
					}
					else {
						r = mid - 1;
					}
				}
				d[pos + 1] = nums[i];
			}
		}
		return len;
	}
};
*/


class Solution {
public:
	bool isAlienSorted(vector<string>& words, string order) {
		multiset<char> temp;
		for (int i = 0; i < order.size(); ++i)
		{
			temp.insert(order[i]);
		}

	}
};

int main()
{

	system("pause");
	return 0;
}