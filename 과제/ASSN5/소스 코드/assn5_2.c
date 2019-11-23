#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "subjectList.h"
#include "studentList.h"



int main(int argc, char *argv[])
{
	// ���� ����
	char subjectfileName[21], studentfileName[21], sub_code[8], sub_name[41], test[9], name[11], dept[7], grade[3];
	int check, credit, i, id, level, sub_num, cmd;
	LIST subjectList;
	STDLIST studentList;
	FILE *subjectfile, *studentfile;

	// �ܼ�â���� �Է��ϴ� �κ�
	strcpy(subjectfileName, argv[1]);
	strcpy(studentfileName, argv[2]);

	if (((subjectfile = fopen(subjectfileName, "r")) == NULL) || ((studentfile = fopen(studentfileName, "r")) == NULL))		// ������ ���� ���
	{
		printf("������ �о�� �� �����ϴ�.\n");
		exit(100);
	}

	// LIST �ʱ�ȭ
	subjectList.top = NULL;
	subjectList.count = 0;
	studentList.top = NULL;
	studentList.end = NULL;
	studentList.count = 0;

	// subject ���� ���� �б� �� LIST ����
	while (fscanf(subjectfile, "%s %s %d", sub_code, sub_name, &credit) != EOF)
	{
		addList(&subjectList, sub_code, sub_name, credit);
	}

	// students ���� ���� �б� �� STDLIST ����
	while (fscanf(studentfile, "%s", test) != EOF)
	{
		if (test[0] >= '0' && test[0] <= '9')	// �й��� ���
		{
			id = atoi(test);
			fscanf(studentfile, "%s %s %d", name, dept, &level);	// ������ �л� ���������� ���� ��
			addStudentList(&studentList, id, name, dept, level);	// studentList��  �Լ��� �����Ѵ�
			studentList.end->sub_num = 0;
			i = 0;
		}
		else		// �����ڵ��� ��� �й��� ���ö����� studentList�� ����� ������ �ִ´�
		{
			strcpy(sub_code, test);
			fscanf(studentfile, "%s", grade);
			strcpy(studentList.end->subjects[i].sub_code, sub_code);
			strcpy(studentList.end->subjects[i].grade, grade);
			studentList.end->sub_num++;
			i++;
		}
	}
	
	// �޴� ����
	while (1)
	{
		printf("### ���� ���� ���α׷� ###\n");
		printf("1. �л��� ����\n");
		printf("2. ���� ����\n");
		printf("0. ����\n");
	
		// �Է� Ȯ�� ����
		while (1)
		{
			printf(">> ");
			scanf("%d", &cmd);
			if (cmd < 0 || cmd > 2)
				printf("�ùٸ� �Է��� �ƴմϴ�.\n\n");
			else
				break;
		}

		switch (cmd)
		{
		case 1:
			printStudentGrade(subjectList, studentList);	// �л��� ������ ���
			continue;
		case 2:
			printSubjectGrade(subjectList, studentList);	// ���� ������ ���
			continue;
		case 0:
			break;	// �޴� ����
		}
		break;
	}

	// �޸� ����
	delList(&subjectList);
	delStdList(&studentList);
	fclose(subjectfile);
	fclose(studentfile);
	return 0;
}