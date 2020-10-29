#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string>
#include<vector>

using namespace std;
/*
int lengthOfLastWord(string s) {
	if (s.size() == 0)
	{
		return 0;
	}
	int pos = s.rfind(' ');
	if (pos == string::npos)
		return s.size();
	return s.size() - pos - 1;
}


int main()
{

	string a("s");
	int ad = lengthOfLastWord(a);
	cout << ad << endl;
	system("pause");
	return 0;
}
*/
/*
class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& A) {
		vector<int> temp;
		size_t len1 = A.size();
		size_t  len2 = A[0].size();
		vector<vector<int>> dp;
		dp.resize(len2);
		temp.resize(len1*len2);
		while ()
		{

		}


		return dp;
	}
};


class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& A) {
		int ro = A.size();
		int co = A[0].size();
		vector<vector<int>> res(co);
		for (int i = 0; i < co; ++i) {
			for (int j = 0; j < ro; ++j)
				res[i].push_back(A[j][i]); 
		}
		return res;
	}
};
*/

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int count = nums.size() / 2;
		int temp = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = 0; j < nums.size(); ++j)
			{
				if (nums[i] == nums[j])
				{
					temp++;
				}
				if (temp >= count)
				{
					return nums[j];
				}
			}
			temp = 0;
		}
	}
};

int main()
{
	
	system("pause");
	return 0;
}


