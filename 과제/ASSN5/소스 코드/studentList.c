#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "subjectList.h"
#include "studentList.h"

void addStudentList(STDLIST *studentList, int id, char name[], char dept[], int level)		// studentList를 만드는 함수
{
	STUDENT *temp, walker;
	// 동적할당 및 데이터 입력
	temp = (STUDENT*)malloc(sizeof(STUDENT));
	temp->id = id;
	strcpy(temp->name, name);
	strcpy(temp->dept, dept);
	temp->level = level;
	temp->next = NULL;

	if (studentList->top == NULL)	// 빈 list인 경우
	{
		studentList->top = temp;
		studentList->end = temp;
	}
	else		// 비어있지 않은 경우 end를 이동시킨다
	{
		studentList->end->next = temp;
		studentList->end = temp;
	}
	studentList->count++;
	return;
}

void printStudentGrade(LIST subjectList, STDLIST studentList)	// 학생별 성적을 출력하는 함수
{
	SUBJECT *walker;
	STUDENT *stdwalker;
	int i, j, k, flag, creditsum;
	double avg, sum;

	walker = subjectList.top;
	stdwalker = studentList.top;

	// 최상단 출력
	printf("\n학번\t\t| 이름\t\t| 학과(학년)\t");
	for (i = 0; i < subjectList.count; i++)
	{
		printf("| %s\t", walker->sub_code);
		walker = walker->next;
	}
	printf("| 평점평균\n");

	// 학생 인적사항 및 성적 출력
	for (i = 0; i < studentList.count; i++)
	{
		// 초기화
		sum = 0.0;
		creditsum = 0;
		walker = subjectList.top;

		printf("%d\t| %s\t| %s(%d)\t", stdwalker->id, stdwalker->name, stdwalker->dept, stdwalker->level);

		for (j = 0; j < subjectList.count; j++)
		{
			flag = 0;
			for (k = 0; k < stdwalker->sub_num; k++)
			{
				if (!strcmp(stdwalker->subjects[k].sub_code, walker->sub_code))	// 과목을 수강한다면
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
				if (flag)	// 수강하는 과목을 찾았으면 정보 입력 후 루프 탈출
					break;
			}
			if (!flag)	// 해당 과목을 수강하지 않는 경우
			{
				printf("| -\t\t");
				walker = walker->next;	// 다음 과목을 체크
			}
			else		// 해당 과목을 수강하는 경우
			{
				printf("| %s\t\t", stdwalker->subjects[k].grade);
				walker = walker->next;	// 다음 과목을 체크
			}
		}
		avg = sum / creditsum;
		printf("| %.2lf", avg);			// GPA 출력
		stdwalker = stdwalker->next;	// 다음 학생으로 이동
		printf("\n");
	}
	printf("\n");
	return;
}

void printSubjectGrade(LIST subjectList, STDLIST studentList)	// 과목별 성적을 출력하는 함수
{
	// 변수 선언
	SUBJECT *walker;
	STUDENT *stdwalker;
	int i, j, k, flag, studentsum, cmd;
	double avg = 0.0, sum, gradepoint;

	// 2번 하위 메뉴 루프
	while (1)
	{
		// 초기화
		walker = subjectList.top;
		stdwalker = studentList.top;
		studentsum = 0;
		sum = 0.0;

		showList(subjectList);	// 과목 목록 출력
		// 입력 확인 루프
		while(1)
		{
			printf("나가기(0) >> ");
			scanf("%d", &cmd);
			if (cmd < 0 || cmd > subjectList.count)
				printf("올바른 입력이 아닙니다.\n\n");
			else
				break;
		}
		// 0 입력
		if (!cmd)
		{
			printf("\n");
			break;
		}

		// 번호에 해당하는 과목 정보 출력
		for (cmd -= 1; cmd > 0; cmd--)
		{
			walker = walker->next;
		}
		printf("\n과목명: %s(%s), 학점: %d학점\n\n", walker->sub_name, walker->sub_code, walker->credit);
		printf("학번\t\t| 이름\t\t| 학과(학년)\t| 학점\n");
		
		// 학생 성적 출력
		for (j = 0; j < studentList.count; j++)
		{
			flag = 0;
			for (k = 0; k < stdwalker->sub_num; k++)
			{
				if (!strcmp(stdwalker->subjects[k].sub_code, walker->sub_code))	// 과목을 수강한다면
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
				if (flag)	// 수강하는 과목을 찾았으면 정보 입력 후 루프 탈출
					break;
			}
			if (!flag)	// 해당 과목을 수강하지 않는 경우
			{
				stdwalker = stdwalker->next;	// 다음 사람을 체크
				continue;
			}
			else		// 해당 과목을 수강하는 경우
			{
				printf("%d\t| %s\t| %s(%d)\t| %s(%.2lf)\n", stdwalker->id, stdwalker->name, stdwalker->dept, stdwalker->level, stdwalker->subjects[k].grade, gradepoint);
				stdwalker = stdwalker->next;	// 다음 사람을 체크
			}
		}
		avg = sum / studentsum;	// 과목 평균
		printf("\n** 과목평균: %.2lf\n\n", avg);
	}
	return;
}

void delStdList(STDLIST *studentList)	// 학생 list의 메모리를 해제하는 함수
{
	int i;
	STUDENT *stdwalker;

	stdwalker = studentList->top;	// 초기화

	// 한 칸씩 이동하며 메모리 해제
	for (i = 0; i < studentList->count; i++)
	{
		studentList->top = stdwalker->next;
		free(stdwalker);	// 메모리 해제
		stdwalker = studentList->top;
	}
	return;
}