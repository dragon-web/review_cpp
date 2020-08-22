
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 100
#define NOT_FOUND -1
//�����нṹ�壺
struct line
{
	char text[MAX_LEN];  //�����ı�
	int num;  //�к�
	struct line *next; //ָ����һ���е�ָ��
	struct line *prior; //ָ��ǰһ���е�ָ��
};
int lnum;
struct line *start; 	   //ָ�����Ա��е�һ�е�ָ��
struct line *last; 	   //ָ�����Ա������һ�е�ָ��
struct line *find(int);    //����ָ�����Ƿ����
void patchup(int, int);    //�Ե�ǰ���Ժ��ÿ�е��кż�1��
void delete_text(int);     //ɾ��һ������
void list();   //��ʾ�ļ���ȫ������
void save();   //�����ļ�
void load();   //���ļ�����ʼ�����Ա�
void insert(char str[], int linenum, int position); //�������ֵ�һ�е��м�
void printline(int linenum);   //��ӡһ������
void deletestr(int linenum, int position, int lenth); //ɾ��һ���ַ���
int findstr(char * to_find);  //�����ַ���
int menu_select();        //��ʾ���˵�
int menu_select_insert();//��ʾ���빦���Ӳ˵�
int menu_select_delete();//��ʾɾ�������Ӳ˵�
int menu_select_print(); //��ʾ��ӡ�����Ӳ˵�
int menu_select_move();  //��ʾ�ƶ������Ӳ˵�
void enter(int linenum); //����һ������
void enter_empty(int linenum); //����һ���հ���
//���к�����ϵͳ���������ṩϵͳ�����棬ͨ��ѡ����ת��ִ�в��롢ɾ��������̡������ļ��ȹ��ܵĽ��档
int main(void)
{
	char str[MAX_LEN];
	int choice;
	int linenum = 1;
	int number = 0;
	start = NULL;
	last = NULL;
	load(); //���ļ�����ʼ�����Ա�
	do {
		choice = menu_select();
		switch (choice)
		{
		case 1:		//ִ�в��빦��	
			choice = menu_select_insert();//��ʾ�����Ӳ˵�
			switch (choice)
			{
			case 1:   //����һ��
				printf("\t�к�:");
				scanf("%d", &linenum);
				enter(linenum);
				break;
			case 2:  //���뵽ָ���е�ָ����
				printf("�������λ��һ�кţ�");
				scanf("%d", &linenum);
				printf("�������λ��-�кţ�");
				scanf("%d", &number);
				printf("Ҫ������ַ�����");
				scanf("%s", str);
				insert(str, linenum, number);
				break;

			case 3:   //�˳�����
				break;
			}
			break;
		case 2:			//ִ��ɾ������
			choice = menu_select_delete();  // ɾ���Ӳ˵�
			switch (choice)
			{
			case 1:   //ɾ��ָ����
				printf("\t�к�:");
				scanf("%d", &linenum);
				break;
			case 2:   //ɾ��ָ�����ַ���
				printf("Ҫɾ�����ַ�����");
				scanf("%s", str);
				number = findstr(str);
				if (number == NOT_FOUND)
					printf("û���ҵ�");
				else
					deletestr(lnum, number, strlen(str));
				break;
			case 3: 	//�˳�ɾ��
				break;
			}
			break;
		case 3:  	//ִ����ʾ����
			choice = menu_select_print(); //��ʾ�Ӳ˵�
			switch (choice) 	//��ʾָ����
			{
			case 1:
				printf("\t�к�:");
				scanf("%d", &linenum);
				printline(linenum);
				break;
			case 2:		//��ʾȫ��
				list();
				break;
			case 3:		//�˳���ʾ
				break;
			}
			break;
		case 4:			//ִ�в��ҹ���
			printf("������Ҫ���ҵ��ַ�����");
			scanf("%s", str);
			number = findstr(str);
			if (number == NOT_FOUND)
				printf("û���ҵ�");
			else
				printf("Ҫ���ҵ��ַ��������к�:%d���к�:%d\n", lnum, number + 1);
			break;
		case 5:		//ִ���滻����
			printf("���뱻�滻���ַ�����");
			scanf("%s", str);
			number = findstr(str);
			if (number == NOT_FOUND)
				printf("û���ҵ�");
			else
			{
				deletestr(lnum, number, strlen(str));
				printf("Ҫ�滻���ַ�����");
				scanf("%s", str);
				insert(str, lnum, number + 1);
			}
			break;

		case 6:     //ִ���ƶ�����
			choice = menu_select_move();   //�ƶ��Ӳ˵�
			switch (choice)
			{
			case 1:   // �����ƶ�һ��
				printf("����Ҫ�ƶ����ַ��������кţ�");
				scanf("%d", &linenum);
				enter_empty(linenum);
				break;
			case 2:   //�����ƶ�һ��
				printf("����Ҫ�ƶ����ַ��������кţ�");
				scanf("%d", &linenum);
				delete_text(linenum - 1);
				break;
			case 3:   //�����ƶ�һ��
				printf("����Ҫ�ƶ����ַ��������кţ�");
				scanf("%d", &linenum);
				printf("����Ҫ�ƶ����ַ��������кţ�");
				scanf("%d", &number);
				str[0] = ' ';
				str[1] = '\0';
				insert(str, linenum, number);
				break;
			case 4:   //�����ƶ�
				printf("����Ҫ�ƶ����ַ��������кţ�");
				scanf("%d", &linenum);
				printf("����Ҫ�ƶ����ַ��������кţ�");
				scanf("%d", &number);
				if (number <= 0)
					printf("���в�����");
				else
					deletestr(linenum, number - 2, 1);
				break;
			case 5:   //�˳��ƶ�
				break;
			}
			break;
		case 7:		//ִ�д��̹���
			save();
			break;
		case 8:		//ִ�ж����ļ�����
			load();
			break;
		case 9:		//ִ���˳�����
			exit(0);
			break;
		}
	} while (1);
	return 0;
}
//���к��������˵����ܵ���ʾ���棬�书����˵�����˵���ѡ��
int menu_select()
{
	int c;
	printf("\n\t\t1.����\n");
	printf("\t\t2.ɾ��\n");
	printf("\t\t3.��ʾ\n");
	printf("\t\t4.����\n");
	printf("\t\t5.�滻\n");
	printf("\t\t6.�ƶ�\n");
	printf("\t\t7.�ļ�����\n");
	printf("\t\t8.װ���ļ�\n");
	printf("\t\t9.�˳�\n");
	do
	{
		printf("\n\n\t\t�밴����ѡ��");
		scanf("%d", &c);
	} while (!(c >= 1 && c <= 9));
	return(c);
}

//���к����ǲ����Ӳ˵����ܵ���ʾ���棬�书����˵���ڲ���˵���ѡ��ĺ��塣
int menu_select_insert()
{
	int c;
	printf("\n\t\t1.����һ������\n");
	printf("\t\t2.����һ������\n");
	printf("\t\t3.�����ϼ��˵�\n");
	do {
		printf("\n\n\t\t�밴����ѡ��");
		scanf("%d", &c);
	} while (!(c >= 1 && c <= 3));
	return(c);
}
//���к�����ɾ���Ӳ˵����ܵ���ʾ���棬�书����˵����ɾ���Ӳ˵���ѡ��ĺ��塣
int menu_select_delete()
{
	int c;
	printf("\n\t\t1.ɾ��һ������\n");
	printf("\t\t2.ɾ��һ������\n");
	printf("\t\t3.�����ϼ��˵�\n");
	do {
		printf("\n\n\t\t�밴����ѡ��");
		scanf("%d", &c);
	} while (!(c >= 1 && c <= 3));
	return(c);
}
//���к�������ʾ�Ӳ˵����ܵ���ʾ���棬�书����˵������ʾ�Ӳ˵���ѡ��ĺ���
int menu_select_print()
{
	int c;
	printf("\n\t\t1.��ʾһ��\n");
	printf("\t\t2.ȫ����ʾ\n");
	printf("\t\t3.�����ϼ��˵�\n");
	do {
		printf("\n\n\t\t�밴����ѡ��");
		scanf("%d", &c);
	} while (!(c >= 1 && c <= 3));
	return(c);
}
//���к������ƶ��Ӳ˵����ܵ���ʾ���棬�书����˵�����ƶ��Ӳ˵���ѡ��ĺ���
int menu_select_move()
{
	int c;
	printf("\n\t\t1.�����ƶ�һ��\n");
	printf("\t\t2.�����ƶ�һ��\n");
	printf("\t\t3.�����ƶ�һ��\n");
	printf("\t\t4.�����ƶ�һ��\n");
	printf("\t\t5.�����ϼ��˵�\n");
	do {
		printf("\n\n\t\t�밴����ѡ��");
		scanf("%d", &c);
	} while (!(c >= 1 && c <= 5));
	return(c);
}
//���к����Ĺ�������ָ�����к� linenum������һ�����֡�
void enter(int linenum)
{
	struct line * info, *q, *p;
	p = start;
	q = NULL;
	while (p && p->num != linenum) //�ҵ�������
	{
		q = p;
		p = p->next;
	}
	if (p == NULL && (q->num + 1) != linenum)	//ָ���в����ڣ����ܲ���
	{
		printf("������кŲ�����");
	}
	else // ָ���д��ڣ����в���
	{
		info = (struct line *)malloc(sizeof(struct line));
		printf("����Ҫ������ַ���");
		scanf("%s", info->text);
		info->num = linenum;
		if (linenum == 1)  //�����ڵ�һ��
		{
			info->next = p;
			p->prior = info;
			info->prior = NULL;
			start = info;
		}
		else if (q->num != linenum)  //���������һ��
		{
			q->next = info;
			info->next = p;
			info->prior = q;
		}
		else     //������������
		{
			q->next = info;
			info->next = p;
			p->prior = info;
			info->prior = q;
		}
		while (p)   //������ǲ��������һ�У������к�����кŶ���1
		{
			p->num = p->num + 1;
			p = p->next;
		}
	}
}

//���к�����Ϊ���������ṩ��һ���������������Ĺ����ǵ��ı����ݲ����ļ��м�ʱ
//����������ݵ��кű�������1����ɾ��ʱ����ɾ�����ı�������кűؼ�1.
void patchup(int n, int incr)
{
	struct line *i;
	i = find(n);
	i = i->next;
	while (i)
	{
		i->num = i->num + incr;
		i = i->next;
	}
}
//���к����Ĺ�������ָ���д�����һ���հ��С�
void enter_empty(int linenum)
{
	struct line *info, *p;
	info = (struct line *)malloc(sizeof(struct line));
	if (!info)
	{
		printf("\t���ڴ治����\n");
		exit(0);
	}
	info->text[0] = ' ';
	info->text[1] = '\0';
	info->num = linenum;
	if (find(linenum))    //���Ҫ���˵��кŴ��ڣ�����в���
	{
		p = start;
		if (linenum == 1)    //����������
		{
			info->next = p;
			start = info;
			info->prior = NULL;
			p->prior = info;
		}
		else  //������������
		{
			while (p->next->num != linenum)
				p = p->next;
			info->next = p->next;
			p->next->prior = info;
			p->next = info;
			info->prior = p;
		}
		patchup(linenum, 1);
	}
	else
		printf("���в�����");
}

//���к����Ĺ����ǲ������ֵ�һ�е��м䡣Ҫ�ǲ���λ�ú�����λ���м��м�����Ჹȫ�ո�
void insert(char str[], int linenum, int position)
{
	struct line * info;
	int len, i;
	int lenth;
	char rest_str[MAX_LEN], nostr[2] = { " " };
	info = start;
	while (info && info->num != linenum)   //��ѯҪ�������
	{
		info = info->next;
	}
	if (info == NULL)
		printf("�����ڸ��У�\n");
	else if (position < 0)
		printf("�����ڸ��У�\n");
	else    //����к��ж����ڣ�����в���
	{
		lenth = strlen(info->text);
		if (lenth < position)	//�����д��ڱ����ļ�����
		{
			len = position - lenth - 1;
			for (i = 0; i < len; i++)
				strcat(info->text, nostr);   //������Ĳ��ֲ���ո��
			strcat(info->text, str);    //�����ַ����е�δβ
		}
		else   //�������ڱ������ֵ��м�
		{
			strcpy(rest_str, &info->text[position - 1]);
			strcpy(&info->text[position - 1], str);
			strcat(info->text, rest_str);
		}
	}
}

//���к����Ĺ�����ɾ��ָ���С�ָ��λ�á�����Ϊ lenth��һ�����֡�
void deletestr(int linenum, int position, int lenth)
{
	struct line * info;
	char rest_str[MAX_LEN];
	info = find(linenum);
	if (info == NULL)
		printf("����û���ַ���n");
	else
	{
		if (strlen(info->text) <= (position + lenth))  //���е��ַ�����<=��ɾ�����к�+ɾ�����ȣ�ֱ���ڵ�ǰλ�ò���'\0'
			info->text[position] = '\0';
		else
		{
			strcpy(rest_str, &info->text[position + lenth]);
			strcpy(&info->text[position], rest_str);
		}
	}
}
//���к����Ĺ�����ɾ��ָ���к� lineup�����֡�
void delete_text(int linenum)
{
	struct line * info, *p;
	info = start;
	while ((info->num < linenum) && info)
		info = info->next;
	if (info->next == NULL)
		printf("���в�����");
	else
	{
		p = info->next;
		if (start == info) //���ɾ�����ǵ�һ��
		{
			start = info->next;
			if (start)  //���ɾ���󣬲�Ϊ��
				start->prior = NULL;
			else  //ɾ����Ϊ��
				last = NULL;
		}
		else
		{
			info->prior->next = info->next;  //ָ���е���һ��ָ��ָ���е���һ��
			if (info != last) //����������һ��
				info->next->prior = info->prior;  //�޸�����һ�е�ָ��ͷ��ָ�� 
			else  //��������һ�У��޸�βָ��
				last = info->prior;
		}
		free(info);
		while (p)
		{
			p->num = p->num - 1;
			p = p->next;
		}
	}
}
//���к����Ĺ����ǲ���һ�����֡�
int findstr(char * to_find)
{
	struct line * info;
	int i = 0, find_len, found = 0, position;
	char substring[MAX_LEN];
	info = start;
	lnum = 0;  //ƥ�䵽���к�
	find_len = strlen(to_find);
	while (info && !found)   //��ѯ
	{
		i = 0;  //�м�ѭ��
		while (!found && (i <= strlen(info->text) - find_len))  //���ڲ���ѭ��
		{
			strcpy(substring, &info->text[i], find_len);
			substring[find_len] = '\0';
			if (strcmp(substring, to_find) == 0)
			{
				found = 1;
				lnum = info->num;
			}
			else
				++i;
		}
		info = info->next;
	}
	if (found)  //���ҳɹ�
		position = i;
	else   //���Ҳ��ɹ�
		position = NOT_FOUND;
	return(position);
}
//���к����Ĺ����ǲ���ָ���У�������ҳɹ����ؽ�����ڵ���ָ�롣
struct line * find(int linenum)
{
	struct line * info;
	info = start;
	while (info)
	{
		if (linenum != info->num)
			info = info->next;
		else
			break;
	}
	return (info);
}

//���к����Ĺ�������ʾָ����
void printline(int linenum)
{
	struct line *info;
	info = find(linenum);
	if (info)
		printf("%d:%s\n", info->num, info->text);
	else
		printf("���в�����");
}
//���к����Ĺ�������ʾ���Ա��е������ı�
void list()
{
	struct line * info;
	info = start;
	while (info)
	{
		printf("%d:%s\n", info->num, info->text);
		info = info->next;
	}
	printf("\n\n");
}
//���к����Ĺ����ǰ����Ա��е��������ֱ��浽�ļ���
void save()
{
	struct line	* info;
	char * p;
	FILE * fp;
	if ((fp = fopen("D:\\text.txt", "w")) == NULL) {
		printf("\t�ļ��򲻿���n");
		exit(0);
	}
	printf("\t���ڴ����ļ���\n");
	info = start;
	while (info)
	{
		p = info->text;
		while (*p)
			putc(*p++, fp);
		putc('\n', fp);
		info = info->next;
	}
	fclose(fp);
}
//���к����Ĺ����ǰ��ı��ļ��е����ݶ��뵽���Ա��С�
void load()
{
	struct line *info, *temp;  //infoָ��ǰ�У�tempָ��info��ǰ����
	char c;
	FILE *fp;  //�ļ�ָ��
	int inct, i;  //�м�����
	temp = NULL;
	if ((fp = fopen("D:\\text.txt", "r")) == NULL)
	{
		printf("\t�ļ��򲻿���\n");
		exit(0);
	}
	printf("\n\t��װ���ļ���\n");
	start = (struct line*)malloc(sizeof(struct line)); //��̬����һ�еĽ��ռ�
	info = start;
	inct = 1;
	while ((c = fgetc(fp)) != EOF)
	{
		i = 0;
		info->text[i] = c;
		i++;
		while ((c = fgetc(fp)) != '\n')  //���ļ��ж�ȡһ���ַ������Ա��У��ļ���ÿһ����\nΪ������
		{
			info->text[i] = c;
			i++;
		}
		info->text[i] = '\0';  //���Ա���ÿ��ĩβ�Ľ�����־
		info->num = inct++;  //�кźͼ���������1
		info->next = (struct line*)malloc(sizeof(struct line));
		if (!info->next)
		{
			printf("\n\t�ڴ��Ѿ����꣡");
			exit(0);
		}
		info->prior = temp;
		temp = info;
		info = info->next;
	}
	temp->next = NULL;
	last = temp;
	free(info);
	start->prior = NULL;
	fclose(fp);
}
