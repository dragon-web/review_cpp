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
		if (strcmp(name, pcon->dhb[i].name) == 0)//���ҵ�ƥ������������i
			return i;
		i++;
	}
	return -1;

}

void add_peo(pCon pcon)//���Ӵ洢�˺���
{
	//�ж�
	if (pcon->count == PEO_MAX)
	{
		printf("�洢�ռ�����\n");
		return;
	}
	fp = fopen("data.doc", "a+");
	setbuf(fp, NULL);
	if (fp == NULL)
	{
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	int a = 1, b = 1;
	printf("����:>");
	scanf("%s", (pcon->dhb[pcon->count]).name);
	printf("�Ա�:>���У�M ��Ů��F)");
	scanf("%s", (pcon->dhb[pcon->count]).sex);
	a = strcmp("M", (pcon->dhb[pcon->count]).sex);
	b = strcmp("F", (pcon->dhb[pcon->count]).sex);
	if ((a != 0) && (b != 0))
	{
		printf("�Ա����벻�Ϸ�������������\n");
		scanf("%s", (pcon->dhb[pcon->count]).sex);
	}
	printf("����:>");
	scanf("%d", &((pcon->dhb[pcon->count]).age));
	fprintf(fp, "\n������%s �Ա�%s ���䣺%d\n"
		, (pcon->dhb[pcon->count]).name, (pcon->dhb[pcon->count]).sex, (pcon->dhb[pcon->count]).age);
	pcon->count++;
}
void del_peo(pCon pcon)//ɾ������
{
	fp = fopen("data.doc", "w+");
	setbuf(fp, NULL);
	if (fp == NULL)
	{
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	char tmpName[NAME_MAX];
	int ret = 0;
	printf("����������Ҫɾ��������:>");
	scanf("%s", tmpName);
	ret = find(pcon, tmpName);
	if (-1 != ret)
	{
		int j = ret;
		for (; j < pcon->count - 1; j++)
		{
			pcon->dhb[j] = pcon->dhb[j + 1];//�ú�������ݸ�����Ҫɾ��������
		}
		pcon->count--;//�洢��������һλ
		int i;
		for (i = 0; i < pcon->count; i++)
		{
			fprintf(fp, "\n������%s �Ա�%s ���䣺%d\n",
				(pcon->dhb[pcon->count]).name, (pcon->dhb[pcon->count]).sex, (pcon->dhb[pcon->count]).age);
		}
	}
	else
	{
		printf("�Ҳ�����Ҫɾ������Ϣ\n");
	}
}
void search_peo(pCon pcon)//���Һ���
{
	char tmpName[NAME_MAX];
	int ret = 0;
	printf("����������Ҫ���ҵ�����:>");
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
		printf("��������Ҫ���ҵ���Ϣ\n");
	}
}
void modify_peo(pCon pcon)//�޸����ݺ���
{
	fp = fopen("data.doc", "w+");
	setbuf(fp, NULL);
	if (fp == NULL)
	{
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	char tmpName[NAME_MAX];
	int ret = 0;
	printf("����������Ҫ�޸ĵ�����:>");
	scanf("%s", tmpName);
	ret = find(pcon, tmpName);
	if (-1 != ret)//�ҵ��޸�����֮�����¸�ֵ
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
		fprintf(fp, "\n������%s �Ա�%s ���䣺%d\n",
			(pcon->dhb[pcon->count]).name, (pcon->dhb[pcon->count]).sex, (pcon->dhb[pcon->count]).age);
	}
}
void show_peo(pCon pcon)//��ʾ����
{
	int i;
	for (i = 0; i < pcon->count; i++) //��ʾ����ӡ������Ϣ
	{
		printf("%s\t%s\t%d\t\n",
			pcon->dhb[i].name,
			pcon->dhb[i].sex,
			pcon->dhb[i].age
		);
	}
}
void rank_peo(pCon pcon)//����
{
	printf("��������������'1'��������'2'����\n");
	int a = 0, n = pcon->count, i, j;
	struct people temp;
	scanf("%d", &a);
	for (i = 0; i < n - 1; ++i)  //�Ƚ�n-1��
	{
		for (j = 0; j < n - 1 - i; ++j)  //ÿ�ֱȽ�n-1-i��,
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
		for (i = pcon->count - 1; i >= 0; i--) //��ʾ����ӡ������Ϣ
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
		for (i = 0; i < pcon->count; i++) //��ʾ����ӡ������Ϣ
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
	printf("*   1>¼��       2>��ѯ     *\n");
	printf("*   3>�޸�       4>ɾ��  *\n");
	printf("*   5>����       6>�˳�   *\n");
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
		switch (input)//�жϲ����ú���
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
