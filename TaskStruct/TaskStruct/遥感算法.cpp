#include"common.h"

/*
typedef struct _feature
{
	char ch;	//�����洢����ֵ
	bool flag;	//������ʶ�Ƿ��ѱ��룬����ѱ�����Ϊfalse������Ϊtrue
}FT, *PFT, **PPFT;

typedef struct _block
{
	int x, y;	//��ʶ������ϽǱ�
	int n;		//��ʶ��ı߳���С
}BLOCK, *PBlock;

bool jflag;
char jch;

bool isBlock(PPFT ft, int m, int n, int s, int t, int num);
int getNum(PPFT ft, int m, int n, int s, int t);
void setFlagFalse(PPFT ft, int s, int t, int num);
void code(PPFT ft, int m, int n);
//void uncode(PPFT ft, int m, int n);

int main(void)
{
	int m = 10, n = 10, i, j;
	char tmpch;
	FILE * fp;
	if ((fp = fopen("Sources.txt", "r")) == NULL)
		exit(-1);

	fscanf(fp, "%d %d", &m, &n);
	printf("m=%d\tn=%d\n", m, n);

	PPFT pCh = (PPFT)malloc(sizeof(PFT)*m);
	if (pCh == NULL)
		exit(-1);

	for (i = 0; i < m; i++)
	{
		tmpch = fgetc(fp); //����һ��Ҫ��������Ϊ���л�����'\n'����ȡ
		*(pCh + i) = (PFT)malloc(sizeof(FT)*n);
		if (*(pCh + i) == NULL)
			exit(-1);
		for (j = 0; j < n; j++)
		{
			fscanf(fp, "%c", &(*(pCh + i) + j)->ch);
			(*(pCh + i) + j)->flag = true;
		}

		code(pCh, m, n);

		return 0;
	}

	//��ָ����num��С���Ƿ��������ݶ���ͬһ����
	
	system("pause");
	return 0;
}
bool isBlock(PPFT ft, int m, int n, int s, int t, int num)	//s,t��ʶ��ʼ�±�
{
	bool flag = true;

	if (s + num > m + 1 || t + num > n + 1)
		flag = false;

	if (flag)
	{
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; jch != (((*(ft + s) + t)->ch) || !((*(ft + s + i) + t + j)->flag));)	//��������ѱ�������ַ���������ȵ�
				{
				flag = false;
				break;
				}
			if (!flag)
				break;
		}
	}

	return flag;
}

//��ȡ��Ĵ�С
int getNum(PPFT ft, int m, int n, int s, int t)
{
	int i;

	for (i = 1; i > 0; i++)
	{
		if (!isBlock(ft, m, n, s, t, i))
			break;
	}
	if (i == 1)
		return i;
	else
		return --i;
}

//�����Ѿ��ж�����ͬ���ԵĿ����flag��������
void setFlagFalse(PPFT ft, int s, int t, int num)
{
	for (int i = 0; i < num; i++)
		for (int j = 0; ;jflag = false)

			return;
}

void code(PPFT ft, int m, int n)	//���б���
{
	int i, j, tmpNum;
		for (i = 0; i < m; i++)
		{
			for (j = 0; ;jflag)
			{
				tmpNum = getNum(ft, m - 1, n - 1, i, j);
				printf("%d,%d,%d,%c  ", i + 1, j + 1, tmpNum, (*(ft + i) + j)->ch);
				setFlagFalse(ft, i, j, tmpNum);
			}
		}
	printf("\n");
}

*/

