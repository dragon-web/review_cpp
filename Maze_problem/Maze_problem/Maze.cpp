#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<memory.h>

//������ȱ�����DFS ջ��  ������ȱ�����BFS ���У�

#define ROW 10
#define COL 10

/*�Թ���λ����Ϣ*/
typedef struct position
{
	int x;
	int y;
}position;

/*���Թ��еĵ�ǰλ�õ���Ϣ��Ҳ����ջ�Ļ���Ԫ��*/
typedef struct SElem
{
	int di;
	position seat;
}SElem;

/*��ʽջ�нڵ�Ķ���*/
typedef struct position_stack
{
	SElem p;
	struct position_stack *next;
}*Stack_pNode, Stack_Node;

void InitStack(Stack_pNode *Link)
{
	*Link = NULL;
}

void push(Stack_pNode *Link, SElem e)
{
	Stack_pNode new_SElem = (Stack_pNode)calloc(1, sizeof(Stack_Node));
	new_SElem->p = e;
	new_SElem->next = NULL;
	if (*Link == NULL)
		*Link = new_SElem;
	else
	{
		new_SElem->next = *Link;
		*Link = new_SElem;
	}
}

int pop(Stack_pNode *Link, SElem *e)
{
	if (*Link == NULL)
		return 0;
	*e = (*Link)->p;
	Stack_pNode q = *Link;
	*Link = (*Link)->next;
	free(q);
	return 1;
}

int top(Stack_pNode Link, SElem *e)
{
	if (Link == NULL)
		return 0;
	*e = Link->p;
	return 1;
}

int empty(Stack_pNode Link)
{
	if (Link == NULL)
		return 1;
	else
		return 0;
}

void reverse(Stack_pNode *Link)
{
	Stack_pNode p, q, r;
	if (*Link == NULL || (*Link)->next == NULL)
		return;
	r = *Link;
	p = (*Link)->next;
	q = NULL;
	while (p) {
		r->next = q;
		q = r;
		r = p;
		p = p->next;
	}
	r->next = q;
	*Link = r;
}

void print(Stack_pNode Link)
{
	Stack_pNode r = Link;
	while (r) {
		printf("(%d,%d) -> ", r->p.seat.x, r->p.seat.y);
		r = r->next;
	}
	printf("exit\n");
}

int curstep = 1;/*��¼��ǰ���㼣����д��̽��ǰ����ÿһ����ȷ��·��*/
/*�Թ���ͼ��1����ǽ��λ�ã�0������е�·����Χ��һȦǽ*/
int m[ROW + 2][COL + 2] = {
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1,
	1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1,
	1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1,
	1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1,
	1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1,
	1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1,
	1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1,
	1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1,
	1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};
/*�������ȼ��趨������Ϊ��ǰλ�õ��ң��£����ϣ���λ����Ϣ�С������б���
ǰ���ķ���--������±�*/

position dir_set[4] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

/*�ƶϵ�ǰλ���Ƿ���С����ƶ���·������ǽ*/
int pass(position p)
{
	if (m[p.x][p.y])
		return 0;
	else
		return 1;
}
/*����ǰ�Ĳ�����д���ߵ�ÿһ����ȷ��·�ϣ��������߲�ͨʱ����ѵ�ʱд����Ϣ

�á�1��Ĩ���������߲�ͨ��
*/
void footPrint(position p)
{
	m[p.x][p.y] = curstep;
}
/*������һ�������ꡣdi�����򡣱������������������һ�����ꡣ���ƶ����ȼ�*/
void nextPos(position *p, int di)
{
	(*p).x += dir_set[di].x;
	(*p).y += dir_set[di].y;
}
/*�������footPrint()�������ᵽ�ģ������ֵ�ǰ·�߲�ͨʱ�����á�1�����߲�ͨ��

·���ϡ�

*/
void markPrint(position p)
{
	m[p.x][p.y] = 1;
}
/*�Թ���������������΅���һ��ָ�򲻴�ͷ�ڵ��ջ��ָ���ָ�룬һ���_ʼλ��

��һ������λ��*/
int find_path(Stack_pNode * Maze_stack, position start, position end)
{
	position curpos = start;/*����һ��λ�ñ������������浱ǰ��λ����Ϣ

*/
	SElem e;/*ջ��Ԫ�ء�����λ����Ϣ����ǰ���ķ���*/
	do
	{
		if (pass(curpos)) { /*���赱ǰ�ڵ���·����Ҫ����ǰ�ڵ���ջ��

��������һ��ǰ������*/
			footPrint(curpos);/*��ǰ���ڵ��ϼ�¼��ǰ�Ĳ���*/
			e.seat = curpos;/*����λ����Ϣ*/
			e.di = 0;/*���淽����Ϣ��Ĭ��������*/
			push(Maze_stack, e);/*��λ����Ϣ��ջ*/
			++curstep;/*������1*/
			if (curpos.x == end.x && curpos.y == end.y)/*���赱

ǰ�ڵ��ǳ��ڡ��򷵻����гɹ��ı�ʶ*/
return 1;
			nextPos(&curpos, e.di);/*������һ�������ꡣ�����ݵ�

ǰλ����Ϣ����ģ����Ѿ���ջ�˵���Ϣ*/
		}
		else {/*���赱ǰ�ڵ���ǽ������Ҫ��ջȡ��֮ǰ�߹���·������ԭ

·���أ��ڷ��صĹ����У���Ҫ���ϵ��ƶ���û��������·*/
			if (!empty(*Maze_stack)) {/*����ջ����Ԫ��*/
				pop(Maze_stack, &e);
				--curstep;
				while (e.di == 3 && !empty(*Maze_stack)) {/*

����ǰ���ݣ����ƶ��Ƿ���������·����*/
					markPrint(e.seat);/*��"ǽ"����֮ǰ

��д�Ĳ�����Ϣ*/
					pop(Maze_stack, &e);
					--curstep;
				}
				if (e.di < 3) {/*���ҵ���һ������������·��

��֮ǰ�߹���һ�����飨�������ǻص���ʼλ�ã�*/
					++e.di;/*�����ȼ��ı�֮ǰ�����߷���

*/
					push(Maze_stack, e);/*�ٴ���ջ*/
					++curstep;/*�ٴν�������1*/
					curpos = e.seat;/*�ٴμ�¼����λ

��*/
					nextPos(&curpos, e.di);/*�ٴμ�����

�εķ����������ϵ�׼��������������һ�ε�ѭ��*/
				}//end if
			}//end if
		}//end else
	} while (!empty(*Maze_stack));
	return 0;
}

/*��ӡ�Թ�*/
void printMaze()
{
	int i, j;
	for (i = 0; i < ROW + 2; ++i)
	{
		for (j = 0; j < COL + 2; ++j) {
			printf("%2d ", m[i][j]);
		}
		printf("\n");
	}

}
void initmaze(int g, int h) {//�����Թ�
	int a, b;
	printf("�Թ�ͼ��:\n");
	for (a = 0; a < g; a++)
	{
		for (b = 0; b < h; b++)
			printf(m[a][b] ? "#" : " ");//����Թ�ͼ��
		printf("\n");
	}
}

int main()
{
	//stack_test();
	initmaze(ROW + 2, COL + 2);
	position start = { 1, 1 };/*�Թ����*/
	position end = { 10, 10 };/*�Թ�����*/
	Stack_pNode maze_stack;/*����һ��ջ��һ�������������Թ����߹���λ

��*/
	
	InitStack(&maze_stack);/*��ʼ��ջ*/
	if (find_path(&maze_stack, start, end)) {
		reverse(&maze_stack);/*��Ϊջ�д�ŵ��ǵ��õ���Ϣ����Ҫ��ջ

����*/
		print(maze_stack);/*��ӡ�����߹��Ĳ�����Ϣ���Թ���ͼ*/
	}
	else {
		printf("��ͨ·\n");
	}
	printMaze();
	system("pause");
	return 0;
}