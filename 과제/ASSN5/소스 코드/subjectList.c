#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "subjectList.h"


void addList(LIST *list, char sub_code[], char sub_name[], int credit)	// linked list�� �ùٸ� ��ġ�� SUBJECT�� �����ϴ� �Լ�
{
	SUBJECT *temp, *checker1, *checker2;

	// �����Ҵ�, �ʱ�ȭ �� ���� ����
	temp = (SUBJECT*)malloc(sizeof(SUBJECT));
	temp->next = NULL;
	strcpy(temp->sub_code, sub_code);
	strcpy(temp->sub_name, sub_name);
	temp->credit = credit;
	checker1 = list->top;
	checker2 = list->top;

	// ���ĺ����� �´� ��ġ�� ã��
	if (list->top == NULL || list->count == 0)	// list�� ����ִ� ���
	{
		list->top = temp;
	}
	else	// list�� ������� ���� ���
	{
		while (1)	// �ùٸ� ��ġ�� ã�������� checker���� �̵�
		{
			if (checker1->next == checker2->next)
			{
				if (checker1->next == NULL && strcmp(checker1->sub_code, temp->sub_code) < 0)	// ó������ �������� ���� �ϴ� ���
				{
					temp->next = NULL;
					checker1->next = temp;
					break;
				}
				else if (strcmp(checker1->sub_code, temp->sub_code) > 0)	// �� ó���� ���ԵǾ�� �ϴ� ���
				{
					temp->next = checker1;
					list->top = temp;
					break;
				}
				else
					checker1 = checker1->next;	// checker���� ��ġ�� �� �� ó���� �ִ� ��� �ϳ��� �̵�
			}
			else if(checker1->next == NULL && strcmp(checker1->sub_code, temp->sub_code) < 0)		// �� �������� ���� �ϴ� ���
			{
				temp->next = NULL;
				checker1->next = temp;
				break;
			}
			else if (strcmp(checker1->sub_code, temp->sub_code) != strcmp(checker2->sub_code, temp->sub_code))		// �߰��� ���� �ϴ� ���
			{
				temp->next = checker1;
				checker2->next = temp;
				break;
			}
			else		// �ùٸ� ��ġ�� �ƴ� ���
			{
				checker1 = checker1->next;
				checker2 = checker2->next;
			}
		}
	}
	list->count++;
	return;
}

void showList(LIST list)	// list�� ������� ��� ����ϴ� �Լ�
{
	int count = 1, i;
	SUBJECT *walker;

	walker = list.top;	// �ʱ�ȭ

	// ��º�
	printf("���� ���\n");
	for (i = 0; i < list.count; i++)
	{
		printf("%3d %s %s (%d����)\n", count, walker->sub_code, walker->sub_name, walker->credit);
		walker = walker->next;
		count++;
	}
	return;
}

int codeCheck(LIST list, char sub_code[])	// ���� �ڵ带 �Է¹޾� list �ȿ� �ִ��� Ȯ���ϰ� ������ 0 ������ 1�� ��ȯ
{
	int count = 1, i;
	SUBJECT *walker;

	walker = list.top;	// �ʱ�ȭ

	for (i = 0; i < list.count; i++)
	{
		if (!strcmp(sub_code, walker->sub_code))		// ���� �ڵ尡 ���� �� ������ 0 ��ȯ
			return 0;
		walker = walker->next;
		count++;
	}
	return 1;		// ���� �ڵ尡 ���� �� ������ 1 ��ȯ
}

void delSubject(LIST *list, char sub_code[])		// �Է¹��� �����ڵ忡 �ش��ϴ� ������ list���� �����ϴ� �Լ�
{
	// ���� ����
	int count = 1, i;
	SUBJECT *walker, *prewalker;

	//�ʱ�ȭ
	walker = list->top;
	prewalker = list->top;

	for (i = 0; i < list->count; i++)
	{
		if (!strcmp(sub_code, walker->sub_code))	// ������ ã����
		{
			if (walker == list->top)		// ó���� �ִ� ���
			{
				list->top = walker->next;
				free(walker);	// �޸� ����
				break;
			}
			else		// �߰��̳� ���� �ִ� ���
			{
				prewalker->next = walker->next;
				free(walker);	// �޸� ����
				break;
			}
		}
		else if (walker == list->top)	// ������ ã�� ���� ��� & ó���� ���
			walker = walker->next;
		else		// ������ ã�� ���� ��� & �߾��� ���
		{
			walker = walker->next;
			prewalker = prewalker->next;
		}
	}
	return;
}

void delList(LIST *list)	// list�� �޸𸮸� �����ϴ� �Լ�
{
	int i;
	SUBJECT *walker;

	walker = list->top;	// �ʱ�ȭ

	// �� ĭ�� �̵��ϸ� �޸� ����
	for (i = 0; i < list->count; i++)
	{
		list->top = walker->next;
		free(walker);	// �޸� ����
		walker = list->top;
	}
	return;
}

void printList(FILE *outfile, LIST list)	// list�� ������ ���Ͽ� ����ϴ� �Լ�
{
	int i;
	SUBJECT *walker;

	walker = list.top;	// �ʱ�ȭ

	// ��º�
	for (i = 0; i < list.count; i++)
	{
		fprintf(outfile, "%s %s %d\n", walker->sub_code, walker->sub_name, walker->credit);
		walker = walker->next;
	}
	return;
}
