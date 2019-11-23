/* Student ID: xxxxxxxx */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STRING 20

// 큐 노드 구조체 NODE 선언
typedef struct node
{
	char data;
	struct node *next;
} NODE;

// 큐 헤드 구조체 QUEUE 선언
typedef struct
{
	int count;
	NODE *front;
	NODE *rear;
} QUEUE;

void printQueue(QUEUE *q);
int enqueue(QUEUE *q, char data);
int dequeue(QUEUE *q, char *data);
int isEmpty(QUEUE *q);

int main()
{
	int len, i, ioRes;
	char str[MAX_STRING];
	QUEUE queue; // 큐

	// 큐 초기화
	//---------- 지우고 채우기 ----------//



	while(1)
	{
		printf(">> ");
		ioRes = scanf("%s", str);

		if(ioRes == EOF)
			break;

		len = strlen(str);
		for(i = 0; i < len; i++)
			//---------- 지우고 채우기 ----------// enqueue 함수 호출

		printQueue(&queue);

	} // while

	printf("bye!\n");

	return 0;
} // main

void printQueue(QUEUE *q)
{
	char data;

	printf("   ");
	while(//---------- 지우고 채우기 ----------//) // 큐가 빌 때까지 dequeue 함수 호출
		printf("%c", data);
	printf("\n\n");
} // printQueue

// enqueue 성공시 1, 실패시 0
int enqueue(QUEUE *q, char data)
{
	NODE *tmp;

	// 큐 노드 생성
	tmp = //---------- 지우고 채우기 ----------//;
	if(!tmp) // 동적 할당 실패시
		return 0;

	// 생성한 노드에 값 설정
	//---------- 지우고 채우기 ----------//



	if(//---------- 지우고 채우기 ----------//) // 큐가 비어 있는 경우(isEmpty 함수 호출)
	{
		//---------- 지우고 채우기 ----------//

	}
	else
	{
		//---------- 지우고 채우기 ----------//

	}

	q->count++;

	return 1;
} // enqueue

// dequeue 성공시 1, 실패시 0
int dequeue(QUEUE *q, char *data)
{
	NODE *tmp;

	if(isEmpty(q)) // 큐가 비어 있는 경우
		return 0;

	*data = //---------- 지우고 채우기 ----------//;
	//---------- 지우고 채우기 ----------//




	return 1;
} // dequeue

// 큐가 비어 있으면 1, 그렇지 않으면 0을 반환
int isEmpty(QUEUE *q)
{
	//---------- 지우고 채우기 ----------//
}
