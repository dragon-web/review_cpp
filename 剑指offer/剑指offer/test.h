#pragma once
#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>

using namespace std;

//是个非常耗费时间的解法
/*
bool Find(int target, vector<vector<int>> array) {
		vector<vector<int>>::iterator it1 = array.begin();
		int i = 0;
		for (int i = 0; i < array.size(); ++i)
		{
			for (int j = 0; j < array[i].size(); ++j)
			{
				if (array[i][j] == target)
					return true;
			}
		}
		return false;
}

bool Find(int target, vector<vector<int>> array) {
	vector<vector<int>>::iterator it1 = array.begin();
	for (int i = 0; i < array.size(); ++i)
	{
		if (*array[i].begin() > target || *array[i].end() < target)
		{
			continue;
		}
		else
		{
			for (int j = 0; j < array[i].size(); ++j)
			{
				if (array[i][j] == target)
					return true;
			}
		}
	}
	return false;
}

char* replaceSpace(char *str, int length) {


	for (int i = 0; i < length; ++i)
	{
		if (str[i] == ' ')
		{
			char *p = new char[length + 2];
			strcpy(p, str);
			length += 2;
			for (int j = length - 1; j > i; --j)
			{
				p[j] = p[j - 1];
			}
			p[i] = '%';
			p[i + 1] = '2';
			p[i + 2] = '0';
			p[length - 1] = '\0';
			return p;
		}
	}
}
*/
class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == nullptr || length <= 0) return; // 养成良好习惯，判空操作
		int cnt = 0;  // 空格的个数
		for (int i = 0; i != length; ++i) {
			if (str[i] == ' ') ++cnt;
		}
		if (!cnt) return; // 没有空格，直接返回
		int new_length = length + cnt * 2;
		for (int i = length; i >= 0; --i) {
			if (str[i] == ' ') {
				str[new_length--] = '0';
				str[new_length--] = '2';
				str[new_length--] = '%';
			}
			else {
				str[new_length--] = str[i];
			}
		}
	}
};

/*
struct Person {
	int age;
};

void funDStruct(struct Person **person, int a, int b);

void funCStruct(void(*funDStruct)(struct Person **, int, int), int a, int b) {
	struct Person *funCp = NULL;
	funCp = (struct Person *) malloc(sizeof(struct Person));
	printf("funCStruct funCp地址:%p\n", funCp);  //打印出funCp指针的地址
	funDStruct(&funCp, a, b);

	printf("funCStruct funCp地址:%p\n", funCp);
}

void funDStruct(struct Person **person, int a, int b) {
	//    struct Person *funDp = person;
	//    printf("funDStruct funDp地址:%p\n", &funDp);

	struct Person *newPerson = NULL;
	newPerson = (struct Person *) malloc(sizeof(struct Person));
	*person = newPerson;
	printf("funDStruct newPerson地址:%p\n", newPerson);
}

int main() {
	funCStruct(funDStruct, 1, 2);
	system("pause");
	return 0;
}
*/
