#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<memory.h>

//深度优先遍历（DFS 栈）  广度优先遍历（BFS 队列）

#define ROW 10
#define COL 10

/*迷宫中位置信息*/
typedef struct position
{
	int x;
	int y;
}position;

/*在迷宫中的当前位置的信息，也是入栈的基本元素*/
typedef struct SElem
{
	int di;
	position seat;
}SElem;

/*链式栈中节点的定义*/
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

int curstep = 1;/*纪录当前的足迹，填写在探索前进的每一步正确的路上*/
/*迷宫地图。1代表墙的位置，0代表可行的路，周围有一圈墙*/
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
/*方向优先级设定。依次为当前位置的右，下，左。上，在位置信息中。保存有本次
前进的方向--数组的下标*/

position dir_set[4] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

/*推断当前位置是否可行。即推断是路。还是墙*/
int pass(position p)
{
	if (m[p.x][p.y])
		return 0;
	else
		return 1;
}
/*将当前的步数填写在走的每一步正确的路上，当发现走不通时，会把当时写的信息

用‘1’抹掉，代表走不通。
*/
void footPrint(position p)
{
	m[p.x][p.y] = curstep;
}
/*计算下一步的坐标。di代表方向。本函数仅仅负责计算下一步坐标。不推断优先级*/
void nextPos(position *p, int di)
{
	(*p).x += dir_set[di].x;
	(*p).y += dir_set[di].y;
}
/*如上面的footPrint()凝视中提到的，当发现当前路走不通时，会用‘1’把走不通的

路堵上。

*/
void markPrint(position p)
{
	m[p.x][p.y] = 1;
}
/*迷宫程序的主函数。形參是一个指向不带头节点的栈的指针的指针，一个開始位置

，一个结束位置*/
int find_path(Stack_pNode * Maze_stack, position start, position end)
{
	position curpos = start;/*定义一个位置变量。用来保存当前的位置信息

*/
	SElem e;/*栈的元素。包含位置信息，和前进的方向*/
	do
	{
		if (pass(curpos)) { /*假设当前节点是路，则要将当前节点入栈。

并计算下一步前进方向*/
			footPrint(curpos);/*在前进节点上纪录当前的步数*/
			e.seat = curpos;/*保存位置信息*/
			e.di = 0;/*保存方向信息。默觉得向右*/
			push(Maze_stack, e);/*将位置信息入栈*/
			++curstep;/*步数加1*/
			if (curpos.x == end.x && curpos.y == end.y)/*假设当

前节点是出口。则返回运行成功的标识*/
return 1;
			nextPos(&curpos, e.di);/*计算下一步的坐标。是依据当

前位置信息计算的，即已经入栈了的信息*/
		}
		else {/*假设当前节点是墙。则须要从栈取出之前走过的路，即沿原

路返回，在返回的过程中，还要不断的推断有没有其它的路*/
			if (!empty(*Maze_stack)) {/*假设栈中有元素*/
				pop(Maze_stack, &e);
				--curstep;
				while (e.di == 3 && !empty(*Maze_stack)) {/*

边向前回溯，边推断是否有其它的路可走*/
					markPrint(e.seat);/*用"墙"覆盖之前

填写的步数信息*/
					pop(Maze_stack, &e);
					--curstep;
				}
				if (e.di < 3) {/*当找到了一个还有其它的路可

走之前走过的一个方块（最坏的情况是回到起始位置）*/
					++e.di;/*按优先级改变之前的行走方向

*/
					push(Maze_stack, e);/*再次入栈*/
					++curstep;/*再次将步数加1*/
					curpos = e.seat;/*再次纪录如今的位

置*/
					nextPos(&curpos, e.di);/*再次计算下

次的方向，有了以上的准备，即将进行下一次的循环*/
				}//end if
			}//end if
		}//end else
	} while (!empty(*Maze_stack));
	return 0;
}

/*打印迷宫*/
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
void initmaze(int g, int h) {//生成迷宫
	int a, b;
	printf("迷宫图形:\n");
	for (a = 0; a < g; a++)
	{
		for (b = 0; b < h; b++)
			printf(m[a][b] ? "#" : " ");//输出迷宫图形
		printf("\n");
	}
}

int main()
{
	//stack_test();
	initmaze(ROW + 2, COL + 2);
	position start = { 1, 1 };/*迷宫入口*/
	position end = { 10, 10 };/*迷宫出口*/
	Stack_pNode maze_stack;/*声明一个栈，一会儿用来存放在迷宫中走过的位

置*/
	
	InitStack(&maze_stack);/*初始化栈*/
	if (find_path(&maze_stack, start, end)) {
		reverse(&maze_stack);/*因为栈中存放的是倒置的信息，须要将栈

倒置*/
		print(maze_stack);/*打印带有走过的步数信息的迷宫地图*/
	}
	else {
		printf("无通路\n");
	}
	printMaze();
	system("pause");
	return 0;
}