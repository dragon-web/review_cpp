#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		auto it1 = nums1.begin();
		auto it2 = nums2.begin();
		vector<int> res;
		while (it1 != nums1.end())
		{
			while (it2 != nums2.end())
			{
				if (*it1 == *it2)
				{
					res.push_back(*it2);
				}
				it2++;
			}
			it1++;
			it2 = nums2.begin();
		}
		if (res.size() <= 1)
			return res;

		int max = res[0];
		for (int i = 0; i < res.size(); ++i)
		{
			max = max > res[i] ? max : res[i];
		}
		vector<int> dp;
		dp.resize(max + 1,0);
		for (int i = 0; i < res.size(); ++i)
		{
			dp[res[i]]++;
		}
		res.clear();
		for (int i = 0; i < dp.size(); ++i)
		{
			if (dp[i] >= 1)
			{
				res.push_back(i);
			}
		}
		return res;
	}
};

int main()
{
	vector<int> num1 = {4, 9 , 5};
	vector<int> num2 = {9,4,9,8,4};
	Solution a;
	vector<int> res1 = a.intersection(num1, num2);
}



class Solution {
public:
	vector<int> sortedSquares(vector<int>& A) {
		vector<int> res;
		res.resize(A.size(), 0);
		for (int i = 0; i < A.size(); ++i)
		{
			res.push_back(A[i] * A[i]);
		}
		sort(res.begin(), res.end());
	}
};*/
//寻找到最长回文子串

/*
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
*/
class Solution {
public:
	string longestPalindrome(string s)
	{
		if (s.length() < 1)
		{
			return NULL;
		}
		int start = 0, end = 0;
		for (int i = 0; i < s.length(); i++)
		{
			int len1 = expandAroundCenter(s, i, i);
			int len2 = expandAroundCenter(s, i, i + 1);
			int len = max(len1, len2);
			if (len > end - start)
			{
				start = i - (len - 1) / 2;
				end = i + len / 2;
			}
		}
		return s.substr(start, end - start + 1);
	}

	int expandAroundCenter(string s, int left, int right)
	{
		int L = left, R = right;
		while (L >= 0 && R < s.length() && s[L] == s[R])
		{
			L--;
			R++;
		}
		return R - L - 1;
	}
};