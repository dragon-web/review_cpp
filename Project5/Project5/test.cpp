#define _CRT_SECURE_NO_WARNINGS 

#define NAME_MAX 20
#define SEX_MAX 5
#define PEO_MAX 1000

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct people
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
}*pPeople;

typedef struct contact
{
	struct people dhb[PEO_MAX];
	int count;
}*pCon;

void add_peo(pCon pcon);
void del_peo(pCon pcon);
void search_peo(pCon pcon);
void modify_peo(pCon pcon);
void show_peo(pCon pcon);
void rank_peo(pCon pcon);


FILE *fp;
int find(pCon pcon, char * name)
{
	int i = 0;
	while (i < pcon->count)
	{
		if (strcmp(name, pcon->dhb[i].name) == 0)//查找到匹配的姓名就输出i
			return i;
		i++;
	}
	return -1;

}

void add_peo(pCon pcon)//增加存储人函数
{
	//判断
	if (pcon->count == PEO_MAX)
	{
		printf("存储空间已满\n");
		return;
	}
	fp = fopen("data.doc", "a+");
	setbuf(fp, NULL);
	if (fp == NULL)
	{
		printf("文件打开失败\n");
		exit(0);
	}
	int a = 1, b = 1;
	printf("姓名:>");
	scanf("%s", (pcon->dhb[pcon->count]).name);
	printf("性别:>（男：M ，女：F)");
	scanf("%s", (pcon->dhb[pcon->count]).sex);
	a = strcmp("M", (pcon->dhb[pcon->count]).sex);
	b = strcmp("F", (pcon->dhb[pcon->count]).sex);
	if ((a != 0) && (b != 0))
	{
		printf("性别输入不合法，请重新输入\n");
		scanf("%s", (pcon->dhb[pcon->count]).sex);
	}
	printf("年龄:>");
	scanf("%d", &((pcon->dhb[pcon->count]).age));
	fprintf(fp, "\n姓名：%s 性别：%s 年龄：%d\n"
		, (pcon->dhb[pcon->count]).name, (pcon->dhb[pcon->count]).sex, (pcon->dhb[pcon->count]).age);
	pcon->count++;
}
void del_peo(pCon pcon)//删除函数
{
	fp = fopen("data.doc", "w+");
	setbuf(fp, NULL);
	if (fp == NULL)
	{
		printf("文件打开失败\n");
		exit(0);
	}
	char tmpName[NAME_MAX];
	int ret = 0;
	printf("请输入你所要删除的姓名:>");
	scanf("%s", tmpName);
	ret = find(pcon, tmpName);
	if (-1 != ret)
	{
		int j = ret;
		for (; j < pcon->count - 1; j++)
		{
			pcon->dhb[j] = pcon->dhb[j + 1];//用后面的数据覆盖所要删除的数据
		}
		pcon->count--;//存储人数减少一位
		int i;
		for (i = 0; i < pcon->count; i++)
		{
			fprintf(fp, "\n姓名：%s 性别：%s 年龄：%d\n",
				(pcon->dhb[pcon->count]).name, (pcon->dhb[pcon->count]).sex, (pcon->dhb[pcon->count]).age);
		}
	}
	else
	{
		printf("找不到所要删除的信息\n");
	}
}
void search_peo(pCon pcon)//查找函数
{
	char tmpName[NAME_MAX];
	int ret = 0;
	printf("请输入你所要查找的姓名:>");
	scanf("%s", tmpName);
	ret = find(pcon, tmpName);
	if (ret != -1)
	{
		printf("%s\t%s\t%d\t\n",
			pcon->dhb[ret].name,
			pcon->dhb[ret].sex,
			pcon->dhb[ret].age);

	}
	else
	{
		printf("不存在所要查找的信息\n");
	}
}
void modify_peo(pCon pcon)//修改数据函数
{
	fp = fopen("data.doc", "w+");
	setbuf(fp, NULL);
	if (fp == NULL)
	{
		printf("文件打开失败\n");
		exit(0);
	}
	char tmpName[NAME_MAX];
	int ret = 0;
	printf("请输入你所要修改的姓名:>");
	scanf("%s", tmpName);
	ret = find(pcon, tmpName);
	if (-1 != ret)//找到修改姓名之后重新赋值
	{
		printf("name:>");
		scanf("%s", (pcon->dhb[ret]).name);
		printf("sex:>");
		scanf("%s", (pcon->dhb[ret]).sex);
		printf("age:>");
		scanf("%d", &((pcon->dhb[ret]).age));
	}
	int i; for (i = 0; i < pcon->count; i++)
	{
		fprintf(fp, "\n姓名：%s 性别：%s 年龄：%d\n",
			(pcon->dhb[pcon->count]).name, (pcon->dhb[pcon->count]).sex, (pcon->dhb[pcon->count]).age);
	}
}
void show_peo(pCon pcon)//显示函数
{
	int i;
	for (i = 0; i < pcon->count; i++) //显示并打印所有信息
	{
		printf("%s\t%s\t%d\t\n",
			pcon->dhb[i].name,
			pcon->dhb[i].sex,
			pcon->dhb[i].age
		);
	}
}
void rank_peo(pCon pcon)//排序
{
	printf("按年龄排序，输入'1'升序，输入'2'降序\n");
	int a = 0, n = pcon->count, i, j;
	struct people temp;
	scanf("%d", &a);
	for (i = 0; i < n - 1; ++i)  //比较n-1轮
	{
		for (j = 0; j < n - 1 - i; ++j)  //每轮比较n-1-i次,
		{
			if (pcon->dhb[j].age < pcon->dhb[j + 1].age)
			{
				temp = pcon->dhb[j];
				pcon->dhb[j] = pcon->dhb[j + 1];
				pcon->dhb[j + 1] = temp;
			}
		}
	}
	if (a == 1)
	{
		for (i = pcon->count - 1; i >= 0; i--) //显示并打印所有信息
		{
			printf("%s\t%s\t%d\t\n",
				pcon->dhb[i].name,
				pcon->dhb[i].sex,
				pcon->dhb[i].age
			);
		}
	}
	else
	{
		for (i = 0; i < pcon->count; i++) //显示并打印所有信息
		{
			printf("%s\t%s\t%d\t\n",
				pcon->dhb[i].name,
				pcon->dhb[i].sex,
				pcon->dhb[i].age
			);
		}
	}


}

void show_menu()
{
	printf("***************************\n");
	printf("*   1>录入       2>查询     *\n");
	printf("*   3>修改       4>删除  *\n");
	printf("*   5>排序       6>退出   *\n");
	printf("***************************\n");
}
int main()
{
	struct contact my_contact;
	int input = 1;
	my_contact.count = 0;
	while (input)
	{
		show_menu();
		printf("please input:>");
		scanf("%d", &input);
		switch (input)//判断并调用函数
		{
		case 1:
		{
			add_peo(&my_contact);
			system("cls");
			break;
		}
		case 2:
		{
			search_peo(&my_contact);
			break;
		}
		case 3:
		{
			modify_peo(&my_contact);
			system("cls");
			break;
		}

		case 4:
		{
			del_peo(&my_contact);
			system("cls");
			break;
		}
		case 5:
		{
			rank_peo(&my_contact);
			break;
		}

		case 6:
		{
			exit(0);
			break;
		}
		default:
			break;
		}
	}
	return 0;
}
