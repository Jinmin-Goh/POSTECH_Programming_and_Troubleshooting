// 이 소스 코드는 리눅스 버전으로 변환한 코드입니다.

#include <stdio.h>
#include <stdlib.h>
#include "checker.h"

int inputStringLength(char string[])	// 문자열의 길이를 구하는 함수
{
	// 변수 선언 영역
	int i = 0, cnt = 0;

	// NULL 문자 입력시까지 cnt를 1씩 증가시킨다
	while (string[i] != NULL)
	{
		i++;
		cnt++;
	}
	// 문자열 길이 반환
	return cnt - 1;
}

int inputStringChecker(char string[], int stringSize)	// LED 전광판에 출력할 문자열이 올바른지 확인하는 함수
{
	int i;
	for (i = 0; i < 26; i++)
	{
		// NULL 문자인 경우
		if (string[i] == NULL)
		{
			break;	// 이탈
		}
		// 알파벳 소문자나 숫자가 아닌 경우
		if (!((string[i] >= 48 && string[i] <= 57) || (string[i] >= 97 && string[i] <= 122) || string[i] == ' '))
			return 1;
	}
	if (stringSize == 0)	// 엔터만 친 경우
		return 1;
	if (stringSize > 20)	// 20자 이상인 경우
		return 2;
	else
		return 0;	// 정상 입력
}