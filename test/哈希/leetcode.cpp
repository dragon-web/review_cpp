#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
/*
class Solution {
public:
	bool isValid(string s) {
		if (s.size() % 2 != 0)
			return false;
		else
		{
			auto it = s.begin();
			while (it != s.end())
			{
				if (*it == '{')
				{
					if (*(it + 1) != '}')
						return false;
				}
				if (*it == '[')
				{
					if (*(it + 1) != ']')
						return false;
				}
				if (*it == '(')
				{
					if (*(it + 1) != ')')
						return false;
				}
				it++;
			}
			return true;
		}
	}

	};



	//√ø¥Œ»°’ª∂•

class Solution {
public:
	bool isValid(string s) {

		stack<char> bp;
		if (s.size() % 2 != 0)
			return false;
		else
		{
			auto it = s.begin();
			while (it != s.end())
			{
				if (*it == '(' || *it == '[' || *it == '{')
				{
					bp.push(*it);
				}
				if ((*it == '}' || *it == ']' || *it == ')') && bp.size() > 0)
				{
					if (*it == ']')
					{
						if (bp.top() == '[')
							bp.pop();
						else {
							return false;
						}
					}
					if (*it == '}')
					{
						if (bp.top() == '{')
							bp.pop();
						else {
							return false;
						}
					}
					if (*it == ')')
					{
						if (bp.top() == '(')
							bp.pop();
						else {
							return false;
						}
					}
				}
				it++;
			}
			if (bp.size() != 0)
			{
				return false;
			}

			return true;
		}
	}
};
int main()
{
	Solution a;
	string s(")}{({))[{{[}");
	bool res;
	res = a.isValid(s);
	cout << "res = " << res << endl;
	system("pause");
	return 0;
}
*/
