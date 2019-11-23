// 이 소스 코드는 리눅스 버전으로 변환한 코드입니다.


#include <stdio.h>
#include <stdlib.h>
#include "keyboard.h"	// 리눅스에서 포함시킬것
#include "menu.h"


void textMenu(char string[], int stringSize)	// 문자열과 문자열의 크기를 입력받고 검사하는 함수
{
	// 변수 선언 영역
	int inputLength, check, check2 = 1;

	while (check2)
	{
		__fpurge(stdin);
		system("clear");			// 화면 지움 - 리눅스에서 바꿀것
		printf("***** Enter String *****\n(less than 20 letters with 0-9 and a-z)\n: ");
		fgets(string, 27, stdin);	// 키보드로부터 최대 25자 입력받음	

		inputLength = inputStringLength(string);	// string 의 문자 수 저장
		string[inputLength] = '\0';					// 엔터 버퍼 삭제
	
		check = inputStringChecker(string, inputLength);	// 문자열 검사
		switch (check)
		{
		case 1:
			printf("\nplease, put a string with 0-9 and a-z (enter key to continue)");
			while (1)
			{
				if (kbhit())
					break;
			}
			break;
		case 2:
			printf("\nplease, put less than 20 letters (enter key to continue)");
			while (1)
			{
				if (kbhit())
					break;
			}
			break;
		default:
			check2 = 0;		// 루프 이탈
			break;
		}
	}
	return;
}

int patternMenu()	// LED전광판 이동패턴 선택 화면출력 및 메뉴 선택 받음
{
	// 변수 선언 영역
	int check = 1;
	char menuNum[50], inputLength;

	while (check)
	{
		system("clear");			// 화면 지움 - 리눅스에서 바꿀것
		printf("***** Pattern Selection *****\n");
		printf("1. move leftward\n");
		printf("2. move rightward\n");
		printf("3. move upward\n");
		printf("4. move downward\n");
		printf("(number) : ");
		// 메뉴 번호 입력받음

		fgets(menuNum, 50, stdin);
		inputLength = inputStringLength(menuNum);

		// 잘못된 입력
		if (inputLength != 1 || !(menuNum[0] >= 49 && menuNum[0] <= 52))
		{
			printf("\n\nplease, put a number between 1 and 4 (enter key to continue)");
			while (1)
			{
				if (kbhit())
					break;
			}
			__fpurge(stdin);		// 버퍼 삭제 - 리눅스에서 넣을것
		}
		else
			check = 0;		// 루프 이탈

	}
	// 메뉴 번호 반환
	return menuNum[0];
}

int speedMenu()	// LED전광판 이동속도 선택 화면출력 및 메뉴 선택 받음
{
	// 변수 선언 영역
	int check = 1;
	char menuNum[50], inputLength;

	while (check)
	{
		system("clear");			// 화면 지움 - 리눅스에서 바꿀것

		printf("***** Move Speed *****\n");
		printf("1. every 1 second\n");
		printf("2. every 0.5 second\n");
		printf("3. every 0.33 second\n");
		printf("(number) : ");

		// 메뉴 번호 입력받음
		fgets(menuNum, 50, stdin);
		inputLength = inputStringLength(menuNum);
		
		// 잘못된 입력
		if (inputLength != 1 || !(menuNum[0] >= 49 && menuNum[0] <= 51))
		{
			printf("\n\nplease, put a number between 1 and 3 (enter key to continue)");
			while (1)
			{
				if (kbhit())
					break;
			}
			__fpurge(stdin);		// 버퍼 삭제 - 리눅스에서 넣을것
		}
		else
			check = 0;		// 루프 이탈
	}
	// 메뉴 번호 반환
	return menuNum[0];
}

int colorMenu()	// LED전광판 화면출력 색 선택 및 메뉴 선택 받음
{
	// 변수 선언 영역
	int check = 1;
	char menuNum[50], inputLength;

	while (check)
	{
		system("clear");			// 화면 지움 - 리눅스에서 바꿀것

		printf("***** LED Color *****\n");
		printf("1. red\n");
		printf("2. yellow\n");
		printf("3. green\n");
		printf("4. blue\n");
		printf("(number) : ");

		// 번호 입력받음
		fgets(menuNum, 50, stdin);
		inputLength = inputStringLength(menuNum);
		
		// 잘못된 입력
		if (inputLength != 1 || !(menuNum[0] >= 49 && menuNum[0] <= 52))
		{
			printf("\n\nplease, put a number between 1 and 4 (enter key to continue)");
			while (1)
			{
				if (kbhit())
					break;
			}
			__fpurge(stdin);		// 버퍼 삭제 - 리눅스에서 넣을것
		}
		else
			check = 0;		// 루프 이탈
	}
	// 메뉴 번호 반환
	return menuNum[0];
}
