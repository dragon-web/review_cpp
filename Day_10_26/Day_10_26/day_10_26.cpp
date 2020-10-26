#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<vector>

using namespace std;
/*
class Solution {
private:
	vector<int> dp;
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		int col = matrix.size();
		int row = matrix[0].size();
		int i = 0;
		int j = 0;
		int flag;
		while (i < col)
		{
			while (j < row)
			{
				if (i == 0 && j == 0)
				{
					dp.push_back(matrix[i][j]);
					j++;
					continue;
				}
				if (i == 0 && j == matrix[i].size() - 1)
				{
					dp.push_back(matrix[i][j]);
					i++;
					continue;
				}
				if (j == matrix.size() - 1 && i == matrix[i].size() - 1)
				{
					dp.push_back(matrix[i][j]);
					j--;
					continue;
				}
				if (j == 0 && i == matrix.size() - 1)
				{
					dp.push_back(matrix[i][j]);
					j++;
					continue;
				}

			}

		}

	}
};
*/

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> res;
		res.clear();
		int row = matrix.size();  //ÐÐ
		int cloum = matrix[0].size();  //ÁÐ 
		int c = ((row < cloum ? row : cloum) - 1) / 2 + 1;
		for (int i = 0; i < c; i++) {
			for (int j = i; j < cloum - i; j++) {
				res.push_back(matrix[i][j]);
			}
			for (int k = i + 1; k < row - i; k++) {
				res.push_back(matrix[k][cloum - i - 1]);
			}
			for (int m = cloum - i - 2; (m >= i) && (row - i - 1 != i); m--)
				res.push_back(matrix[row - i - 1][m]);
			for (int n = row - i - 2; (n > i) && (cloum - i - 1 != i); n--)
				res.push_back(matrix[n][i]);
		}
		return res;
	}
};



int main()
{


	system("pause");
	return 0;
}