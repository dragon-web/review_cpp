#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


//暴力枚举法
/*
class Solution {
public:
	bool IsPalindrome(string s)
	{
		int front = 0;
		int tail = s.size() - 1;
		while (front <= tail)
		{
			if (s[front] != s[tail])
			{
				return false;
			}
			else
			{
				front++;
				tail--;
			}
		}
		return true;
	}
	string longestPalindrome(string s) {
		if (s.size() == 1)
		{
			return s;
		}
		int maxlen_size = 0;
		string maxlen;
		string temp;
		for (int i = 0; i < s.size() - 1; ++i)
		{
			for (int j = i; j < s.size(); ++j)
			{
				 temp = s.substr(i, j - i + 1);
				if (IsPalindrome(temp) && temp.size() >= maxlen_size)
				{
					maxlen_size = temp.size();
					maxlen = temp;
				}
			}
		}
		return maxlen;
	}
};

//思想：一个回文去掉两头以后依旧是回文



class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.size();
		if (len == 0 || len == 1)
			return s;
		int start = 0;//回文串起始位置
		int max = 1;//回文串最大长度
		vector<vector<int>>  dp(len, vector<int>(len));//定义二维动态数组
		for (int i = 0; i < len; i++)//初始化状态
		{
			dp[i][i] = 1;
			if (i < len - 1 && s[i] == s[i + 1])
			{
				dp[i][i + 1] = 1;
				max = 2;
				start = i;
			}
		}
		for (int l = 3; l <= len; l++)//l表示检索的子串长度，等于3表示先检索长度为3的子串
		{
			for (int i = 0; i + l - 1 < len; i++)
			{
				int j = l + i - 1;//终止字符位置
				if (s[i] == s[j] && dp[i + 1][j - 1] == 1)//状态转移
				{
					dp[i][j] = 1;
					start = i;
					max = l;
				}
			}
		}
		return s.substr(start, max);//获取最长回文子串
	}
};



int main()
{
	string str = "iopsajhffgvrnyitusobwcxgwlwniqchfnssqttdrnqqcsrigjsxkzcmuoiyxzerakhmexuyeuhjfobrmkoqdljrlojjjysfdslyvckxhuleagmxnzvikfitmkfhevfesnwltekstsueefbrddxrmxokpaxsenwlgytdaexgfwtneurhxvjvpsliepgvspdchmhggybwupiqaqlhjjrildjuewkdxbcpsbjtsevkppvgilrlspejqvzpfeorjmrbdppovvpzxcytscycgwsbnmspihzldjdgilnrlmhaswqaqbecmaocesnpqaotamwofyyfsbmxidowusogmylhlhxftnrmhtnnljjhhcfvywsqimqxqobfsageysonuoagmmviozeouutsiecitrmkypwknorjjiaasxfhsftypspwhvqovmwkjuehujofiabznpipidhfxpoustquzyfurkcgmioxacleqdxgrxbldcuxzgbcazgfismcgmgtjuwchymkzoiqhzaqrtiykdkydgvuaqkllbsactntexcybbjaxlfhyvbxieelstduqzfkoceqzgncvexklahxjnvtyqcjtbfanzgpdmucjlqpiolklmjxnscjcyiybdkgitxnuvtmoypcdldrvalxcxalpwumfx";
	Solution a;
	auto res = a.longestPalindrome(str);
	cout << res << endl;
	system("pause");
	return 0;
}
*/

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		for (int i = 0; i < n; ++i)
		{
			nums1[m - 1 + i] = nums2[i];
		}
		auto it = nums1.begin();
		for (int i = 0; i < m + n; ++i)
		{
			it++;
		}
		sort(nums1.begin(), it);
	}
};

int main()
{
	Solution a;
	vector<int> num1 = { 1,2,3,0,0,0 };
	vector<int> num2 = { 2,5,6 };
	a.merge(num1, 3, num2, 3);
	
	for (auto &e : num1)
	{
		cout << e << " ";
	}
	system("pause");
	return 0;
}















