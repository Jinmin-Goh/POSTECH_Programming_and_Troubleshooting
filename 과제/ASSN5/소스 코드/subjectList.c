#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "subjectList.h"


void addList(LIST *list, char sub_code[], char sub_name[], int credit)	// linked list의 올바른 위치에 SUBJECT를 삽입하는 함수
{
	SUBJECT *temp, *checker1, *checker2;

	// 동적할당, 초기화 및 정보 저장
	temp = (SUBJECT*)malloc(sizeof(SUBJECT));
	temp->next = NULL;
	strcpy(temp->sub_code, sub_code);
	strcpy(temp->sub_name, sub_name);
	temp->credit = credit;
	checker1 = list->top;
	checker2 = list->top;

	// 알파벳순에 맞는 위치를 찾는
	if (list->top == NULL || list->count == 0)	// list가 비어있는 경우
	{
		list->top = temp;
	}
	else	// list가 비어있지 않은 경우
	{
		while (1)	// 올바른 위치를 찾을때까지 checker들이 이동
		{
			if (checker1->next == checker2->next)
			{
				if (checker1->next == NULL && strcmp(checker1->sub_code, temp->sub_code) < 0)	// 처음이자 마지막에 들어가야 하는 경우
				{
					temp->next = NULL;
					checker1->next = temp;
					break;
				}
				else if (strcmp(checker1->sub_code, temp->sub_code) > 0)	// 맨 처음에 삽입되어야 하는 경우
				{
					temp->next = checker1;
					list->top = temp;
					break;
				}
				else
					checker1 = checker1->next;	// checker들의 위치가 둘 다 처음에 있는 경우 하나만 이동
			}
			else if(checker1->next == NULL && strcmp(checker1->sub_code, temp->sub_code) < 0)		// 맨 마지막에 들어가야 하는 경우
			{
				temp->next = NULL;
				checker1->next = temp;
				break;
			}
			else if (strcmp(checker1->sub_code, temp->sub_code) != strcmp(checker2->sub_code, temp->sub_code))		// 중간에 들어가야 하는 경우
			{
				temp->next = checker1;
				checker2->next = temp;
				break;
			}
			else		// 올바른 위치가 아닌 경우
			{
				checker1 = checker1->next;
				checker2 = checker2->next;
			}
		}
	}
	list->count++;
	return;
}

void showList(LIST list)	// list의 과목들을 모두 출력하는 함수
{
	int count = 1, i;
	SUBJECT *walker;

	walker = list.top;	// 초기화

	// 출력부
	printf("과목 목록\n");
	for (i = 0; i < list.count; i++)
	{
		printf("%3d %s %s (%d학점)\n", count, walker->sub_code, walker->sub_name, walker->credit);
		walker = walker->next;
		count++;
	}
	return;
}

int codeCheck(LIST list, char sub_code[])	// 과목 코드를 입력받아 list 안에 있는지 확인하고 있으면 0 없으면 1을 반환
{
	int count = 1, i;
	SUBJECT *walker;

	walker = list.top;	// 초기화

	for (i = 0; i < list.count; i++)
	{
		if (!strcmp(sub_code, walker->sub_code))		// 과목 코드가 같은 게 있으면 0 반환
			return 0;
		walker = walker->next;
		count++;
	}
	return 1;		// 과목 코드가 같은 게 없으면 1 반환
}

void delSubject(LIST *list, char sub_code[])		// 입력받은 과목코드에 해당하는 과목을 list에서 삭제하는 함수
{
	// 변수 선언
	int count = 1, i;
	SUBJECT *walker, *prewalker;

	//초기화
	walker = list->top;
	prewalker = list->top;

	for (i = 0; i < list->count; i++)
	{
		if (!strcmp(sub_code, walker->sub_code))	// 과목을 찾으면
		{
			if (walker == list->top)		// 처음에 있는 경우
			{
				list->top = walker->next;
				free(walker);	// 메모리 해제
				break;
			}
			else		// 중간이나 끝에 있는 경우
			{
				prewalker->next = walker->next;
				free(walker);	// 메모리 해제
				break;
			}
		}
		else if (walker == list->top)	// 과목을 찾지 못한 경우 & 처음인 경우
			walker = walker->next;
		else		// 과목을 찾지 못한 경우 & 중앙인 경우
		{
			walker = walker->next;
			prewalker = prewalker->next;
		}
	}
	return;
}

void delList(LIST *list)	// list의 메모리를 해제하는 함수
{
	int i;
	SUBJECT *walker;

	walker = list->top;	// 초기화

	// 한 칸씩 이동하며 메모리 해제
	for (i = 0; i < list->count; i++)
	{
		list->top = walker->next;
		free(walker);	// 메모리 해제
		walker = list->top;
	}
	return;
}

void printList(FILE *outfile, LIST list)	// list의 내용을 파일에 출력하는 함수
{
	int i;
	SUBJECT *walker;

	walker = list.top;	// 초기화

	// 출력부
	for (i = 0; i < list.count; i++)
	{
		fprintf(outfile, "%s %s %d\n", walker->sub_code, walker->sub_name, walker->credit);
		walker = walker->next;
	}
	return;
}
