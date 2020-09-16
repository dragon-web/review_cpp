#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<math.h>
using namespace std;

/*
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0) return 0;
		int first = 0, last = rotateArray.size() - 1;
		while (first < last) { // 最后剩下一个元素，即为答案
			if (rotateArray[first] < rotateArray[last]) { // 提前退出
				return rotateArray[first];
			}
			int mid = first + ((last - first) >> 1);
			if (rotateArray[mid] > rotateArray[last]) { // 情况1
				first = mid + 1;

			}
			else if (rotateArray[mid] < rotateArray[last]) { //情况2
				last = mid;
			}
			else { // 情况3
				--last;
			}
		}
		return rotateArray[first];
	}
};
*/

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int> res(0);
		int mul = array[0] *array[0];
		if (array.size())
		{
			for (int i = 0; i < array.size(); ++i)
			{
				for (int j = 0; j < array.size(); ++j)
				{
					if (i != j && array[i] + array[j] == sum)
					{
						if (array[i] * array[j] < mul)
						{
							mul = array[i] * array[j];
							res.resize(2);
							res[0] = array[i] > array[j] ? array[j] : array[i];
							res[1] = array[i] < array[j] ? array[j] : array[i];
						}
					}
				}
			}
			if (res.size() == 2)
				return res;
		}
		return res;
	}
};

int main()
{
	vector<int>dp = { 1,2,4,7,11,15 };
	int sz = 15;
	Solution a;
	a.FindNumbersWithSum(dp, sz);
	system("pause");
	return 0;
}