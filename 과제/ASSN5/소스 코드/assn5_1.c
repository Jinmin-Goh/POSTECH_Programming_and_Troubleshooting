#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "subjectList.h"



int main(int argc, char *argv[])
{
	// ���� ����
	char infileName[21] = "subject.txt", outfileName[21], sub_code[8], sub_name[41], cmd[7];
	int check, credit, i;
	LIST list;
	FILE *infile, *outfile;

	// �ܼ�â���� �Է��ϴ� �κ�
	if (argc == 2)	// ���ϸ��� �Է��ϴ� ���
		strcpy(infileName, argv[1]);

	if ((infile = fopen(infileName, "r")) == NULL)		// ������ ���� ���
	{
		printf("������ �о�� �� �����ϴ�.\n");
		exit(100);
	}

	// LIST �ʱ�ȭ
	list.top = NULL;
	list.count = 0;

	// ���� ���� �о����
	while (fscanf(infile, "%s %s %d", sub_code, sub_name, &credit) != EOF)
	{
		addList(&list, sub_code, sub_name, credit);
	}
	showList(list);

	// �޴� ����
	while (1)
	{
		printf("\n>> ");
		scanf("%s",cmd);
		if (!strcmp(cmd, "show"))	// show
			showList(list);
		else if (!strcmp(cmd, "delete"))	// delete
		{
			printf("�����ڵ�: ");
			scanf("%s", sub_code);
			check = codeCheck(list, sub_code);	// �����ڵ� �˻�
			if (check)	// �����ڵ尡 ������
			{
				printf("Not found\n");
				continue;
			}
			delSubject(&list, sub_code);	// ���� ����
			list.count--;
		}
		else if (!strcmp(cmd, "add"))	// add
		{
			printf("�����ڵ�: ");
			scanf("%s", sub_code);
			check = codeCheck(list, sub_code);	// �����ڵ� �˻�
			if (!check)		// �����ڵ尡 �ִ� ���
				continue;
			printf("�����: ");
			scanf("%s", sub_name);
			printf("����: ");
			scanf("%d", &credit);
			addList(&list, sub_code, sub_name, credit);	// ���� �߰�
		}
		else if (!strcmp(cmd, "quit"))
			break;
	}
	
	// ���Ͽ� ����ϴ� �κ�
	printf("���ϸ�: ");
	scanf("%s", outfileName);
	outfile = fopen(outfileName, "w");
	printList(outfile, list);
	delList(&list);	// list ����

	// fclose
	fclose(infile);
	fclose(outfile);
	return 0;
}