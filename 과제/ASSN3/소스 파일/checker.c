#include <stdio.h>
#include <stdlib.h>
#include "checker.h"

int inputStringLength(char string[])	// 문자열의 길이를 구하는 함수
{
	int i = 0, cnt = 0;
	while (string[i] != NULL)
	{
		i++;
		cnt++;
	}
	return cnt - 1;
}

int inputStringChecker(char string[], int stringSize)	// LED 전광판에 출력할 문자열이 올바른지 확인하는 함수
{
	int i;
	for (i = 0; i < 26; i++)
	{
		if (string[i] == NULL)
		{
			break;
		}
		if (!((string[i] >= 48 && string[i] <= 57) || (string[i] >= 97 && string[i] <= 122) || string[i] == ' '))
			return 1;
	}
	if (stringSize == 0)
		return 1;
	if (stringSize > 20)
		return 2;
	else
		return 0;
}