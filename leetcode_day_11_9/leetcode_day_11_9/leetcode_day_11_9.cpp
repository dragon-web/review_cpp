#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<stack>

using namespace std;

/*
class Solution {
public:
	bool Judge(int num)
	{
		for (int i = 2; i <= num; ++i)
		{
			if (num % i == 0)
			{
				if (  i != 3 || i != 5 || i != 7)
				{
					return false;
				}
			}
		}
		return true;
	}
	int getKthMagicNumber(int k) {
		int count = 0;
		if (k == 1)
		{
			return 1;
		}
		else
		{
			int j;
			for (j = 2; count < k; ++j)
			{
				if (Judge(j))
				{
					count++;
				}
			}
			return j;
		}
	}
};

class Solution {
public:

	bool Judge(int num)
	{
		bool flag = 0;
		for (int i = 2; i <= num; ++i)
		{
			if (num % i == 0)
			{
				if (i == 3 || i == 5 || i == 9)
				{
					continue;
				}
				else
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag == 1)
		{
			return false;
		}
		return true;
	}

	int getKthMagicNumber(int k) {
		if (k == 1)
		{
			return 1;
		}
		else
		{
			int count = 1;
			int j;
			for (j = 2; count < k; ++j)
			{
				if (Judge(j))
				{
					count++;
				}
			}
			return j - 1;
		}
	}
};

class Solution {
public:
	int getKthMagicNumber(int k) {
		vector<int> dp(k, 0);
		dp[0] = 1;
		int p3 = 0, p5 = 0, p7 = 0;
		for (int i = 1; i < k; i++) {
			dp[i] = min(min(dp[p3] * 3, dp[p5] * 5), dp[p7] * 7);
			if (dp[p3] * 3 == dp[i])
				p3++;
			if (dp[p5] * 5 == dp[i])
				p5++;
			if (dp[p7] * 7 == dp[i])
				p7++;
		}
		return dp[k - 1];
	}
};

int main()
{
	Solution a;
	cout << a.getKthMagicNumber(5)<<endl;
	system("pause");
	return 0;
}

*/
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}
	void push(int x) {
			if (!Sta2.empty())
			{
				if (Sta2.top() > x)
				{
					Sta2.pop();
					Sta2.push(x);
				}
			}
			else
			{
				Sta2.push(x);
			}
			Sta1.push(x);
	}

	void pop() {
		Sta1.pop();
	}

	int top() {
		return Sta1.top();
	}

	int min() {
		return Sta2.top();
	}
private:
	stack<int> Sta1;
	stack<int> Sta2;
};

int main()
{

	system("pause");
	return 0;
}


/*
class MinStack {
public:
	MinStack() {
	}
	void push(int x) {
		stack.push(x);
		if (Min_stack.empty())
		{
			Min_stack.push(x);
		}
		else
		{
			if (stack.top() < Min_stack.top())
			{
				Min_stack.push(stack.top());
			}
			else
			{
				Min_stack.push(Min_stack.top());
			}
		}
	}

	void pop() {
		stack.pop();
		Min_stack.pop();
	}

	int top() {
		int result = stack.top();
		return result;
	}

	int min() {
		return Min_stack.top();
	}
	stack<int> Min_stack;
	stack<int> stack;
};
*/