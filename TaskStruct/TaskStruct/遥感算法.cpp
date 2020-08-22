#include"common.h"

/*
typedef struct _feature
{
	char ch;	//用来存储像素值
	bool flag;	//用来标识是否已编码，如果已编码则为false，否则为true
}FT, *PFT, **PPFT;

typedef struct _block
{
	int x, y;	//标识块的左上角标
	int n;		//标识块的边长大小
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
		tmpch = fgetc(fp); //这里一定要做处理，因为其中还包含'\n'被读取
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

	//看指定的num大小块是否整块数据都是同一属性
	
	system("pause");
	return 0;
}
bool isBlock(PPFT ft, int m, int n, int s, int t, int num)	//s,t标识起始下标
{
	bool flag = true;

	if (s + num > m + 1 || t + num > n + 1)
		flag = false;

	if (flag)
	{
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; jch != (((*(ft + s) + t)->ch) || !((*(ft + s + i) + t + j)->flag));)	//如果存在已编码或者字符特征不相等的
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

//获取块的大小
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

//对于已经判断是相同属性的块进行flag属性设置
void setFlagFalse(PPFT ft, int s, int t, int num)
{
	for (int i = 0; i < num; i++)
		for (int j = 0; ;jflag = false)

			return;
}

void code(PPFT ft, int m, int n)	//进行编码
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

