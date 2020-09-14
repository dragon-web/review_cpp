#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0) return 0;
		int first = 0, last = rotateArray.size() - 1;
		while (first < last) { // ���ʣ��һ��Ԫ�أ���Ϊ��
			if (rotateArray[first] < rotateArray[last]) { // ��ǰ�˳�
				return rotateArray[first];
			}
			int mid = first + ((last - first) >> 1);
			if (rotateArray[mid] > rotateArray[last]) { // ���1
				first = mid + 1;

			}
			else if (rotateArray[mid] < rotateArray[last]) { //���2
				last = mid;
			}
			else { // ���3
				--last;
			}
		}
		return rotateArray[first];
	}
};