#define _CRT_SECURE_NO_WARNINGS 

//��������ķ��� ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
/*
#include<Windows.h>
#include<stdio.h>
#include<math.h>
unsigned int reverse_bit(unsigned int value)
{
	int i = 31;
	int m;
	int sum = 0;
	while (value != 0)
	{
		m = value & 1;
		value = value >> 1;
		sum = sum + m * pow(2, i);
		i--;
	}
	return sum;
}
int main()
{
	unsigned long int a;
	a = reverse_bit(25);
	printf("%u", a);
	system("pause");
	return 0;
}*/
/*
#include<Windows.h>
#include<stdio.h>
#include<math.h>
int main()
{
	int m = 0;
	int n = 0;
	int num = 0;
	int count = 0;
	printf("������������:\n");
	scanf("%d%d", &m, &n);
	num = m ^ n; //��λ���
	while (num)
	{
		count++;
		num = num & (num - 1);
	}
	printf("count=%d", count);
	system("pause");
	return 0;
}
n & (n - 1)������n�����һλΪ1��λ���0
*/

