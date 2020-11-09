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
int main()
{
	char a = '\72';
	// \为转义字符，\72转义为一个八进制数72，也就是十进制数的58
	//赋值给a，a就是一个ascii码为58的字符。
	cout << a << endl;
	system("pause");
	return 0;
}
class Solution {
public:
	string addStrings(string num1, string num2) {
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		int len = num1.size() > num2.size() ? num1.size() : num2.size();
		string res;
		res.resize(len + 1);
		int temp = 0; // 表示进位 
		for (int i = 0; i < len + 1; ++i)
		{
			int temp1;
			int temp2;
			if (i >= num1.size())
			{
				temp1 = 0;
			}
			else
			{
				temp1 = num1[i] - '0';
			}
			if (i >= num2.size())
			{
				temp2 = 0;
			}
			else
			{
				temp2 = num2[i] - '0';
			}
			res[i] = (temp1 + temp2 + temp) % 10 + '0';
			temp = (temp1 + temp2 + temp) / 10;
		}
		if (res[res.size()-1] == '0')
		{
			res = res.substr(0, res.size()-1);
		}
			reverse(res.begin(), res.end());
			return res;
	}
};


int main()
{
	Solution a;
	string num1 = "96549851219";
	string num2 = "1";
	auto res = a.addStrings(num1, num2);
	cout << res << endl;
	system("pause");
	return 0;
}
class Solution {
public:
	int StrToInt(string str) {
		return atoi(str.c_str());
	}
};*/

class Solution {
public:
	int StrToInt(string str) {
		int flag = 0;
		int i = 0;
		int count = 0;
		if (str[0] == '-')
		{
			flag = 1;
			i = 1;
		}
		if (str[0] == '+')
		{
			flag = 2;
			i = 1;
		}
		for (i; i < str.size(); ++i)
		{
			if (str[i] < '0' || str[i] > '9')
			{
				return 0;
			}
			count = count * 10 * i + (str[i] - '0');
		}
		return count;
	}
};


int main()
{
	Solution a;
	string num1 = "+2147483647";
	string num2 = "1";
	auto res = a.StrToInt(num1);
	cout << res << endl;
	system("pause");
	return 0;
}