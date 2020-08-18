#define _CRT_SECURE_NO_WARNINGS 


#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<iostream>
#include<map>
/***********************单词结构体***********************/
struct word {
	char name[30];
	int num;
	struct word *next;
};
/**********************读取单词并统计出现频率*********************/
void readfile(struct word*&head)   
{
	FILE *fp;
	if ((fp = fopen("in.txt", "r")) == NULL)
	{
		printf("无法打开此文件!\n");
		exit(0);
	}
	char ch, temp[30];
	struct word *p;
	while (!feof(fp))
	{
		int i = 0;
		ch = fgetc(fp);
		temp[0] = ' ';
		while ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || temp[0] == ' ')
		{
			if (ch >= 'a'&&ch <= 'z' || ch >= 'A'&&ch <= 'Z')
			{
				temp[i] = ch;
				i++;
			}
			ch = fgetc(fp);
			if (feof(fp)) break;
		}
		temp[i] = '\0';
		p = head->next;
		while (p)
		{
			if (!_stricmp(temp, p->name))
			{
				p->num++; break;
			}
			p = p->next;
		}
		if (!p&&temp[0] != '\0')
		{
			p = new word;
			strcpy(p->name, temp);
			p->num = 1;
			p->next = head->next;
			head->next = p;
		}
	}
}
void print(struct word*&head)
{
	struct word* p = head->next;
	while (p != NULL)
	{
		printf("%s : %d\n", p->name, p->num);
		p = p->next;
	}
}




/*
int main()
{
	struct word *head;
	head = new word;
	head->next = NULL;
	readfile(head);
	print(head);
	//sort(head);
	system("pause");
	return 0;
}
*/








