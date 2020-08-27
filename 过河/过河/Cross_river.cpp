#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<iostream>
#include<string.h>


using namespace std;


//����ģ�ͣ�ʹ��2���������ݱ�ʾ��ͬ�ˣ�����ʹ��һ��������ʾ��ǰ�ľ��棬 255Ϊ��ʼ��0Ϊ���� 
enum { POLICE = 0x80, THIEF = 0x40, DAD = 0x20, BOY1 = 0x10, BOY2 = 0x8, MOM = 0x4, GIRL1 = 0x2, GIRL2 = 0x1, ALL = 0xff, OK = 0 };
//�жϼ���A�Ƿ����ڼ���B
bool test1(int A, int B)
{
	return (A&B) == A;
}
//�жϼ���A�Ƿ���Ժ�ƽ�ദ 
bool test2(int A)
{
	//С͵�����ھ��첻�ڵ�����£����������ദ 
	if (!test1(POLICE, A) && test1(THIEF, A) && A != THIEF) return 0;
	//���費���ڰְֲ��ڵ�����£��Ͷ����ദ 
	if (!test1(DAD, A) && test1(MOM, A) && (test1(BOY1, A) || test1(BOY2, A))) return 0;
	//�ְֲ��������費�ڵ�����£���Ů���ദ 
	if (!test1(MOM, A) && test1(DAD, A) && (test1(GIRL1, A) || test1(GIRL2, A))) return 0;
	return 1;
}
//��ӡ��� 
void print(int A, int k)
{
	static const char*name[8] = { "Ů��","Ů��","����","����","����","�ְ�","С͵","����" };
	char str[32] = { 0 };
	int i, j;
	for (i = 1, j = 0; j < 8; i <<= 1, ++j)
		if (test1(i, A))
		{
			if (*str)
				strcat(str, "+");
			strcat(str, name[j]);
		}
	printf("%d:%s\n", k, str);
}
//������� ,A�ǵ�ǰû���ӵ��˵ļ��ϣ�n�ǵڼ�����answer������飬finded״̬������� 
void DFS(int A, int n, int* answer, bool *finded)
{
	int i;
	//�ݹ����ķǵݹ���ڣ��ҵ���һ��� 
	if (A == OK)
	{
		for (i = 0; i < n; i++) print(answer[i], i + 1);
		return;
	}
	if (n >= 20) return;//���ܳ���20�㣬������� 
	//�˴���� 
	static int a[15] = { POLICE | THIEF,POLICE | DAD,POLICE | BOY1,POLICE | BOY2,POLICE | MOM,POLICE | GIRL1,POLICE | GIRL2,
					POLICE,DAD | BOY1,DAD | BOY2,DAD | MOM,DAD,MOM | GIRL1,MOM | GIRL2,MOM };
	int B = ALL - A;//�ѹ����˵ļ��� 
	if (n & 1)//����
		for (i = 0; i < 15; i++)
		{
			//���׼�������ϴ����˲��ڼ��ϵ��У����ԣ� 
			if (!test1(a[i], B)) continue;
			//���׼�������ϴ������ߺ�ʣ�µ��˲��ܺ�ƽ�ദ������
			//���׼�������ϴ����˵���԰�����԰����ܺ�ƽ�ദ������
			if (!test2(A + a[i]) || !test2(B - a[i])) continue;
			//������ֹ���״̬�����ԣ��������ظ�· 
			if (finded[A + a[i] + 256]) continue;
			//�������־���������һ���������ݹ�
			answer[n] = a[i];
			finded[A + a[i] + 256] = 1;
			DFS(A + a[i], n + 1, answer, finded);
		}
	else//ȥ 
		for (i = 0; i < 15; i++)
		{
			//���׼�������ϴ����˲��ڼ��ϵ��У����ԣ� 
			if (!test1(a[i], A)) continue;
			//���׼�������ϴ������ߺ�ʣ�µ��˲��ܺ�ƽ�ദ������
			//���׼�������ϴ����˵���԰�����԰����ܺ�ƽ�ദ������
			if (!test2(A - a[i]) || !test2(B + a[i])) continue;
			//������ֹ���״̬�����ԣ��������ظ�· 
			if (finded[A - a[i]]) continue;
			//�������־���������һ���������ݹ�
			answer[n] = a[i];
			finded[A - a[i]] = 1;
			DFS(A - a[i], n + 1, answer, finded);
		}
}
int main()
{
	bool finded[512] = { 0 };//��ʾ״̬���򵥵�ʹ��1--255��ʾ�����˵���ϣ������������λ�ã���������512 
	int answer[20];
	DFS(ALL, 0, answer, finded);
	system("pause");
	return 0;
}


