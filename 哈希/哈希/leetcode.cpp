#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>

using namespace std;

/*
class Solution {
public:
	int divide(int dividend, int divisor) {
		int sign;
		if ((dividend >= 0 && divisor > 0) || (dividend <= 0 && divisor < 0)) {
			sign = 0;
		}
		else {
			sign = 1;
		}
		long a = abs(dividend), cmp = abs(divisor);
		long res = 0, partial_sum = 1;
		int abs_divisor = cmp;
		if (a < cmp) return 0;
		while ((cmp << 1) < a) {
			cmp = cmp << 1;
			partial_sum = partial_sum << 1;
		}
		while (a >= abs_divisor) {
			a -= cmp;
			res += partial_sum;
			//cout << "a: " << a << " cmp: " << cmp << " partial_sum: " << partial_sum << endl;
			while (cmp > a) {
				cmp = cmp >> 1;
				partial_sum = partial_sum >> 1;
			}
		}
		if (sign == 1) {
			if (-res < INT_MIN) return INT_MAX;
			else return -res;
		}
		else {
			if (res > INT_MAX) return INT_MAX;
			else return res;
		}
	}

};

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == 0) return 0;
		if (divisor == 1) return dividend;
		if (divisor == -1) {
			if (dividend > INT_MIN) return -dividend;// ֻҪ������С���Ǹ�����������ֱ�ӷ����෴���ͺ���
			return INT_MAX;// ����С���Ǹ����Ǿͷ�������������
		}
		long a = dividend;
		long b = divisor;
		int sign = 1;
		if ((a > 0 && b < 0) || (a < 0 && b>0)) {
			sign = -1;
		}
		a = a > 0 ? a : -a;
		b = b > 0 ? b : -b;
		long res = div(a, b);
		if (sign > 0)return res > INT_MAX ? INT_MAX : res;
		return -res;
	}
	int div(long a, long b) {  // �ƺ�������ѵ�����������⼸��
		if (a < b) return 0;
		long count = 1;
		long tb = b; // �ں���Ĵ����в�����b
		while ((tb + tb) <= a) {
			count = count + count; // ��С�ⷭ��
			tb = tb + tb; // ��ǰ���Ե�ֵҲ����
		}
		return count + div(a - tb, b);
	}
};
*/