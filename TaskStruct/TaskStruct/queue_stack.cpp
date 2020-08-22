#include"common.h"

//#define M 100
/*
typedef int ElemType;
typedef struct
{
	ElemType data[M];
	int top;
}Stack;

//��ʼ��ջ
void InitStack(Stack *s)
{
	s->top = -1;
}
int Push(Stack *s, ElemType e)
{
	if (s->top == M - 1)
	{
		printf("ջ��\n");
		return 0;
	}
	s->top++;
	s->data[s->top] = e;
	return 1;
}

//�ж��Ƿ�Ϊ��
int Empty(Stack *s)
{
	if (s->top == -1)
		return 1;
	else
		return 0;
}
//��ջ
int Pop(Stack *s, ElemType *e)
{
	if (Empty(s))
	{
		printf("\n Stack is free");
		return 0;
	}
	*e = s->data[s->top];
	s->top--;
	return 1;
}

void Conversion(int N)
{
	int e;
	Stack *s = (Stack *)malloc(sizeof(Stack));
	InitStack(s);
	int X;
	printf("������ת���Ľ��ƣ�");
	scanf("%d", &X);
	while (N)
	{
		Push(s, N%X);
		N = N / X;
	}
	while (!Empty(s))
	{
		Pop(s, &e);
		printf("%d", e);
	}
}

int main()
{

	int n, m;
	while (1)
	{
		printf("1:����ת����2���˳�\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:	printf("������ʮ���Ƶ�����ֵ: ");
			scanf("%d", &m);
			Conversion(m);
			printf("\n");
			break;
		case 2:	exit(0);
		default:	printf("error\n");
		}
	}
}


typedef int DataType;

#define MAX_SIZE (100)

typedef struct Stack {

	DataType arr[MAX_SIZE];
	int top;
}Stack;

void StackInit(Stack *stack)
{
	stack->top = 0;
}

void StackDestory(Stack *stack)
{
	stack->top = 0;
}

void StackPush(Stack *stack, DataType data)
{
	assert(stack->top < MAX_SIZE);
	stack->arr[stack->top++] = data;
}


void StackPop(Stack *stack)
{
	assert(stack->top > 0);
	stack->top--;
}

DataType StackTop(const Stack *stack)
{
	assert(stack->top > 0);
	return stack->arr[stack->top - 1];
}

int stackSize(Stack *stack)
{
	return stack->top;
}

int StackFull(Stack *stack)
{
	return stack->top >= MAX_SIZE;
}

int StackEmpty(Stack *stack)
{
	return stack->top <= 0;
}



//����������ƥ��������
void correct(const char *exp, int max)
{
	Stack stack;
	char ch;
	char leftBracket;
	int i = 0;
	StackInit(&stack);


	for (i = 0; i < max; i++)
	{
		ch = exp[i];

		switch (ch)
		{
		case '(':
		case '[':
		case '{':
			StackPush(&stack, (DataType)ch);
			break;
		case ')':
		case ']':
		case '}':
			if (StackEmpty(&stack))
			{
				printf("�����Ŷ�\n");
				StackDestory(&stack);
				return;
			}

			leftBracket = (char)StackTop(&stack);
			StackPop(&stack);

			if (leftBracket == '(' && ch != ')')
			{
				printf("��ƥ��\n");
				return;
			}

			if (leftBracket == '[' && ch != ']')
			{
				printf("��ƥ��\n");
				return;
			}
			if (leftBracket == '{' && ch != '}')
			{
				printf("��ƥ��\n");
				return;
			}
		default:
			break;
		}
	}
	if (!StackEmpty(&stack))
	{
		printf("�����Ŷ�\n");
		return;
	}
	printf("ƥ������\n");
}

void TestBracket()
{
	const char *seq[] = {
		"(())assakc{[(])}",
		"(()))abc{}[]}",
		"(()()aasckasjc{[]}",
		"(())abc{[](())}"
	};
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		correct(seq[i], strlen(seq[i]));
	}
}

int main()
{
	TestBracket();

	system("pause");
	return 0;
}
*/