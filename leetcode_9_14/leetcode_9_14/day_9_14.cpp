#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<vector>

using namespace std;


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