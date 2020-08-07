#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string>
#include<stack>
#include<math.h>
using namespace std;
/*
int main()
{
	string str;
	getline(cin, str);
	size_t pos = str.rfind(' ');
	if (pos == string::npos)
	{
		cout << str.size() << endl;
	}
	else {
		cout << str.size() - pos -1<< endl;
	}
	system("pause");
	return 0;
}


int main()
{
	string str("Hello Worldasfa");
	size_t it = str.rfind(' ');
	if (it == string::npos)
	{
		printf("没有找到\n");
		return -1;
	}
	cout << it << endl;

	system("pause");
	return 0;
}*/

//整数反转
/*
int reverse(int x)
{
	stack<int> bp;
	int res = 0;
	int i = 0;
	while (x)
	{
		int temp = x % 10;
		x /= 10;
		bp.push(temp);
	}
	while (!bp.empty())
	{
		int num = bp.top();
		bp.pop();
		res += (int)(num*pow(10, i));
		i++;
	}
	if (x < 0)
	{
		res = 0 - res;
	}
	return res;
}

	int reverse(int x) 
	{
		stack<int> bp;
		double res = 0;
		int i = 0;
		while (x)
		{
			int temp = x % 10;
			x /= 10;
			bp.push(temp);
		}
		while (!bp.empty())
		{
			int num = bp.top();
			bp.pop();
			res += (num*pow(10, i));
			if (abs((int)res) > (int)(pow(2, 31) - 1))
			{
				return 0;
			}
			i++;
		}
		if (x < 0)
		{
			res = 0 - res;
		}
		return (int)res;
	}
int main()
{
	int num;
	cin >> num;
	cout << abs(num) << endl;
	int res = reverse(num);
	cout << res << endl;
	system("pause");
	return 0;
}

class Solution {
public:
	int reverse(int x)
	{
		int ans = 0;
		while (x != 0) {
			if ((ans * 10) / 10 != ans) {
				ans = 0;
				break;
			}
			ans = ans * 10 + x % 10;
			x = x / 10;
		}
		return ans;
	}
	};*/
class Solution {
public:
	int reverse(int x) {
		int rev = 0;
		while (x != 0) {
			int pop = x % 10;
			x /= 10;
			if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
			if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
			rev = rev * 10 + pop;
		}
		return rev;
	}
};
   