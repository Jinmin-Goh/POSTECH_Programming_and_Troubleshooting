#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "subjectList.h"
#include "studentList.h"

void addStudentList(STDLIST *studentList, int id, char name[], char dept[], int level)		// studentList�� ����� �Լ�
{
	STUDENT *temp, walker;
	// �����Ҵ� �� ������ �Է�
	temp = (STUDENT*)malloc(sizeof(STUDENT));
	temp->id = id;
	strcpy(temp->name, name);
	strcpy(temp->dept, dept);
	temp->level = level;
	temp->next = NULL;

	if (studentList->top == NULL)	// �� list�� ���
	{
		studentList->top = temp;
		studentList->end = temp;
	}
	else		// ������� ���� ��� end�� �̵���Ų��
	{
		studentList->end->next = temp;
		studentList->end = temp;
	}
	studentList->count++;
	return;
}

void printStudentGrade(LIST subjectList, STDLIST studentList)	// �л��� ������ ����ϴ� �Լ�
{
	SUBJECT *walker;
	STUDENT *stdwalker;
	int i, j, k, flag, creditsum;
	double avg, sum;

	walker = subjectList.top;
	stdwalker = studentList.top;

	// �ֻ�� ���
	printf("\n�й�\t\t| �̸�\t\t| �а�(�г�)\t");
	for (i = 0; i < subjectList.count; i++)
	{
		printf("| %s\t", walker->sub_code);
		walker = walker->next;
	}
	printf("| �������\n");

	// �л� �������� �� ���� ���
	for (i = 0; i < studentList.count; i++)
	{
		// �ʱ�ȭ
		sum = 0.0;
		creditsum = 0;
		walker = subjectList.top;

		printf("%d\t| %s\t| %s(%d)\t", stdwalker->id, stdwalker->name, stdwalker->dept, stdwalker->level);

		for (j = 0; j < subjectList.count; j++)
		{
			flag = 0;
			for (k = 0; k < stdwalker->sub_num; k++)
			{
				if (!strcmp(stdwalker->subjects[k].sub_code, walker->sub_code))	// ������ �����Ѵٸ�
				{
					if (!strcmp(stdwalker->subjects[k].grade, "A+"))
					{
						sum += (4.3 * (walker->credit));
						creditsum += walker->credit;
					}
					else if (!strcmp(stdwalker->subjects[k].grade, "A0"))
					{
						sum += (4.0 * (walker->credit));
						creditsum += walker->credit;
					}
					else if (!strcmp(stdwalker->subjects[k].grade, "A-"))
					{
						sum += (3.7 * (walker->credit));
						creditsum += walker->credit;
					}
					else if (!strcmp(stdwalker->subjects[k].grade, "B+"))
					{
						sum += (3.3 * (walker->credit));
						creditsum += walker->credit;
					}
					else if (!strcmp(stdwalker->subjects[k].grade, "B0"))
					{
						sum += (3.0 * (walker->credit));
						creditsum += walker->credit;
					}
					else if (!strcmp(stdwalker->subjects[k].grade, "B-"))
					{
						sum += (2.7 * (walker->credit));
						creditsum += walker->credit;
					}
					else if (!strcmp(stdwalker->subjects[k].grade, "C+"))
					{
						sum += (2.3 * (walker->credit));
						creditsum += walker->credit;
					}
					else if (!strcmp(stdwalker->subjects[k].grade, "C0"))
					{
						sum += (2.0 * (walker->credit));
						creditsum += walker->credit;
					}
					else if (!strcmp(stdwalker->subjects[k].grade, "C-"))
					{
						sum += (1.7 * (walker->credit));
						creditsum += walker->credit;
					}
					else if (!strcmp(stdwalker->subjects[k].grade, "D+"))
					{
						sum += (1.3 * (walker->credit));
						creditsum += walker->credit;
					}
					else if (!strcmp(stdwalker->subjects[k].grade, "D0"))
					{
						sum += (1.0 * (walker->credit));
						creditsum += walker->credit;
					}
					else if (!strcmp(stdwalker->subjects[k].grade, "D-"))
					{
						sum += (0.7 * (walker->credit));
						creditsum += walker->credit;
					}
					else if (!strcmp(stdwalker->subjects[k].grade, "F"))
						creditsum += walker->credit;
					flag++;
				}
				if (flag)	// �����ϴ� ������ ã������ ���� �Է� �� ���� Ż��
					break;
			}
			if (!flag)	// �ش� ������ �������� �ʴ� ���
			{
				printf("| -\t\t");
				walker = walker->next;	// ���� ������ üũ
			}
			else		// �ش� ������ �����ϴ� ���
			{
				printf("| %s\t\t", stdwalker->subjects[k].grade);
				walker = walker->next;	// ���� ������ üũ
			}
		}
		avg = sum / creditsum;
		printf("| %.2lf", avg);			// GPA ���
		stdwalker = stdwalker->next;	// ���� �л����� �̵�
		printf("\n");
	}
	printf("\n");
	return;
}

void printSubjectGrade(LIST subjectList, STDLIST studentList)	// ���� ������ ����ϴ� �Լ�
{
	// ���� ����
	SUBJECT *walker;
	STUDENT *stdwalker;
	int i, j, k, flag, studentsum, cmd;
	double avg = 0.0, sum, gradepoint;

	// 2�� ���� �޴� ����
	while (1)
	{
		// �ʱ�ȭ
		walker = subjectList.top;
		stdwalker = studentList.top;
		studentsum = 0;
		sum = 0.0;

		showList(subjectList);	// ���� ��� ���
		// �Է� Ȯ�� ����
		while(1)
		{
			printf("������(0) >> ");
			scanf("%d", &cmd);
			if (cmd < 0 || cmd > subjectList.count)
				printf("�ùٸ� �Է��� �ƴմϴ�.\n\n");
			else
				break;
		}
		// 0 �Է�
		if (!cmd)
		{
			printf("\n");
			break;
		}

		// ��ȣ�� �ش��ϴ� ���� ���� ���
		for (cmd -= 1; cmd > 0; cmd--)
		{
			walker = walker->next;
		}
		printf("\n�����: %s(%s), ����: %d����\n\n", walker->sub_name, walker->sub_code, walker->credit);
		printf("�й�\t\t| �̸�\t\t| �а�(�г�)\t| ����\n");
		
		// �л� ���� ���
		for (j = 0; j < studentList.count; j++)
		{
			flag = 0;
			for (k = 0; k < stdwalker->sub_num; k++)
			{
				if (!strcmp(stdwalker->subjects[k].sub_code, walker->sub_code))	// ������ �����Ѵٸ�
				{
					if (!strcmp(stdwalker->subjects[k].grade, "A+"))
					{
						sum += 4.3;
						gradepoint = 4.3;
					}
					else if (!strcmp(stdwalker->subjects[k].grade, "A0"))
					{
						sum += 4.0;
						gradepoint = 4.0;
					}
					else if (!strcmp(stdwalker->subjects[k].grade, "A-"))
					{
						sum += 3.7;
						gradepoint = 3.7;
					}
					else if (!strcmp(stdwalker->subjects[k].grade, "B+"))
					{
						sum += 3.3;
						gradepoint = 3.3;
					}
					else if (!strcmp(stdwalker->subjects[k].grade, "B0"))
					{
						sum += 3.0;
						gradepoint = 3.0;
					}
					else if (!strcmp(stdwalker->subjects[k].grade, "B-"))
					{
						sum += 2.7;
						gradepoint = 2.7;
					}
					else if (!strcmp(stdwalker->subjects[k].grade, "C+"))
					{
						sum += 2.3;
						gradepoint = 2.3;
					}
					else if (!strcmp(stdwalker->subjects[k].grade, "C0"))
					{
						sum += 2.0;
						gradepoint = 2.0;
					}
					else if (!strcmp(stdwalker->subjects[k].grade, "C-"))
					{
						sum += 1.7;
						gradepoint = 1.7;
					}
					else if (!strcmp(stdwalker->subjects[k].grade, "D+"))
					{
						sum += 1.3;
						gradepoint = 1.3;
					}
					else if (!strcmp(stdwalker->subjects[k].grade, "D0"))
					{
						sum += 1.0;
						gradepoint = 1.0;
					}
					else if (!strcmp(stdwalker->subjects[k].grade, "D-"))
					{
						sum += 0.7;
						gradepoint = 0.7;
					}
					else if (!strcmp(stdwalker->subjects[k].grade, "F"))
						gradepoint = 0.0;
					studentsum++;
					flag++;
				}
				if (flag)	// �����ϴ� ������ ã������ ���� �Է� �� ���� Ż��
					break;
			}
			if (!flag)	// �ش� ������ �������� �ʴ� ���
			{
				stdwalker = stdwalker->next;	// ���� ����� üũ
				continue;
			}
			else		// �ش� ������ �����ϴ� ���
			{
				printf("%d\t| %s\t| %s(%d)\t| %s(%.2lf)\n", stdwalker->id, stdwalker->name, stdwalker->dept, stdwalker->level, stdwalker->subjects[k].grade, gradepoint);
				stdwalker = stdwalker->next;	// ���� ����� üũ
			}
		}
		avg = sum / studentsum;	// ���� ���
		printf("\n** �������: %.2lf\n\n", avg);
	}
	return;
}

void delStdList(STDLIST *studentList)	// �л� list�� �޸𸮸� �����ϴ� �Լ�
{
	int i;
	STUDENT *stdwalker;

	stdwalker = studentList->top;	// �ʱ�ȭ

	// �� ĭ�� �̵��ϸ� �޸� ����
	for (i = 0; i < studentList->count; i++)
	{
		studentList->top = stdwalker->next;
		free(stdwalker);	// �޸� ����
		stdwalker = studentList->top;
	}
	return;
}