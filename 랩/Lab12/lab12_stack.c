/* Student ID: xxxxxxxx */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STRING 20

// 스택 노드 구조체 NODE 선언
//---------- 지우고 채우기 ----------//

// 스택 헤드 구조체 STACK 선언
//---------- 지우고 채우기 ----------//

void printStack(STACK *s);
int push(STACK *s, char data);
int pop(STACK *s, char *data);
int isEmpty(STACK *s);

int main()
{
    int len, i, ioRes;
    char str[MAX_STRING];
    STACK *stack;

    // 스택 헤드 생성(동적할당) 및 초기화
    //---------- 지우고 채우기 ----------//  동적 할당
    if(!stack)
    {
        printf("동적 할당 에러\n");
        return 100;
    }

    //---------- 지우고 채우기 ----------// 초기화



    while(1)
    {
        printf(">> ");
        ioRes = scanf("%s", str);

        if(ioRes == EOF)
            break;

        len = strlen(str);
        for(i = 0; i < len; i++)
        {
            //---------- 지우고 채우기 ----------// push 함수 호출
        }
		printStack(stack);

    } // while

    free(stack);
    printf("bye!\n");

    return 0;
} // main

void printStack(STACK *s)
{
    char data;

    printf("   ");
    while(//---------- 지우고 채우기 ----------//) // 스택이 빌 때까지 pop 함수 호출
        printf("%c", data);
    printf("\n\n");

} // printStack

// push 성공시 1, 실패시 0을 반환
int push(STACK *s, char data)
{
    NODE *tmp;
    int success = 1;

    // 스택 노드 생성
    tmp = //---------- 지우고 채우기 ----------//;
    if(!tmp) // 동적 할당 실패시
        success = 0;
    else
    {
        //---------- 지우고 채우기 ----------//





    }

    return success;
} // push

// pop 성공시 1, 실패시 0을 반환
int pop(STACK *s, char *data)
{
    NODE *tmp;
    int success = 1;

    if(//---------- 지우고 채우기 ----------//) // 스택이 비어 있지 않으면(isEmpty 함수 호출)
    {
        *data = //---------- 지우고 채우기 ----------//;

        //---------- 지우고 채우기 ----------//




        free(//---------- 지우고 채우기 ----------//); // 노드 삭제
    }
    else
        success = 0;

    return success;
} // pop

// 스택이 비어 있으면 1, 그렇지 않으면 0을 반환
int isEmpty(STACK *s)
{
    //---------- 지우고 채우기 ----------//
} // isEmpty

