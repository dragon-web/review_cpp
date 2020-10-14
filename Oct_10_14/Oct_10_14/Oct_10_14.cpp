#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>

using namespace std;

/*
void PrintTest()
{
	int i = 0;
	printf("%d \n", i);
}

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int size = rotateArray.size();
		if (size == 0) {
			return 0;
		}//if
		int left = 0, right = size - 1;
		int mid = 0;
		// rotateArray[left] >= rotateArray[right] 确保旋转
		while (rotateArray[left] >= rotateArray[right]) {
			// 分界点
			if (right - left == 1) {
				mid = right;
				break;
			}//if
			mid = left + (right - left) / 2;
			// rotateArray[left] rotateArray[right] rotateArray[mid]三者相等
			// 无法确定中间元素是属于前面还是后面的递增子数组
			// 只能顺序查找
			if (rotateArray[left] == rotateArray[right] && rotateArray[left] == rotateArray[mid]) {
				return MinOrder(rotateArray, left, right);
			}//if
			// 中间元素位于前面的递增子数组
			// 此时最小元素位于中间元素的后面
			if (rotateArray[mid] >= rotateArray[left]) {
				left = mid;
			}//if
			// 中间元素位于后面的递增子数组
			// 此时最小元素位于中间元素的前面
			else {
				right = mid;
			}//else
		}//while
		return rotateArray[mid];
	}
private:
	// 顺序寻找最小值
	int MinOrder(vector<int> &num, int left, int right) {
		int result = num[left];
		for (int i = left + 1; i < right; ++i) {
			if (num[i] < result) {
				result = num[i];
			}//if
		}//for
		return result;
	}
};


// 二叉搜索数第K小的节点  将这个二叉搜索数中序遍历

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{

	}


};


int cal(const char *p, int &num)
{
	num = 0;
	int count = 0;
	for (; *p; p++, count++)
	{
		num += *p - '0';
	}
	return count;
}

//输入12345 其实不是什么怪异输出
int main()
{
//	PrintTest();
	/*char str[100];
	int count, num;
	cin >> str;
	count = cal(str, num);
	cout << count << "," << num << endl;

	system("pause");
	return 0;
}*/

//终将要啃非递归这块硬骨头
