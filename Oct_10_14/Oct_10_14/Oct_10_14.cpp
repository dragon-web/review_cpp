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
		// rotateArray[left] >= rotateArray[right] ȷ����ת
		while (rotateArray[left] >= rotateArray[right]) {
			// �ֽ��
			if (right - left == 1) {
				mid = right;
				break;
			}//if
			mid = left + (right - left) / 2;
			// rotateArray[left] rotateArray[right] rotateArray[mid]�������
			// �޷�ȷ���м�Ԫ��������ǰ�滹�Ǻ���ĵ���������
			// ֻ��˳�����
			if (rotateArray[left] == rotateArray[right] && rotateArray[left] == rotateArray[mid]) {
				return MinOrder(rotateArray, left, right);
			}//if
			// �м�Ԫ��λ��ǰ��ĵ���������
			// ��ʱ��СԪ��λ���м�Ԫ�صĺ���
			if (rotateArray[mid] >= rotateArray[left]) {
				left = mid;
			}//if
			// �м�Ԫ��λ�ں���ĵ���������
			// ��ʱ��СԪ��λ���м�Ԫ�ص�ǰ��
			else {
				right = mid;
			}//else
		}//while
		return rotateArray[mid];
	}
private:
	// ˳��Ѱ����Сֵ
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


// ������������KС�Ľڵ�  ����������������������

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

//����12345 ��ʵ����ʲô�������
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

//�ս�Ҫ�зǵݹ����Ӳ��ͷ
