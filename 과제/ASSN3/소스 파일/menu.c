#include <stdio.h>
#include <stdlib.h>
// #include "keyboard.h"	// 리눅스에서 포함시킬것
#include "menu.h"

#define FLUSH fflush(stdin)		// 리눅스에서 제거


void textMenu(char string[], int stringSize)
{
	int inputLength;
	system("cls");
	// system("clear");			// 리눅스에서 바꿀것
	printf("***** Enter String *****\n(less than 20 letters with 0-9 and a-z)\n: ");
	fgets(string, 25, stdin); // 키보드로부터 최대 25자 입력받음
	
	// __fpurge(stdin); // 입력받고 버퍼에 남은 내용 지움 -  리눅스

	inputLength = inputStringLength(string);
	string[inputLength] = NULL;

	// printf("%d\n", inputLength);
	
	int check;
	check = inputStringChecker(string, inputLength);
	switch (check)
	{
	case 1:
		printf("\nplease, put a string with 0-9 and a-z (enter key to continue)");
		while (1)
		{
			if (kbhit())
				break;
		}
		textMenu(string, 26);
		break;
	case 2:
		printf("\nplease, put less than 20 letters (enter key to continue)");
		while (1)
		{
			if (kbhit())
				break;
		}
		textMenu(string, 26);
		break;
	default:
		break;
	}
	return;
}

int patternMenu()	// LED전광판 이동패턴 선택 화면출력 및 메뉴 선택 받음
{
	char menuNum[50], inputLength;

	system("cls");
	// system("clear");			// 리눅스에서 바꿀것

	printf("***** Pattern Selection *****\n");
	printf("1. move leftward\n");
	printf("2. move rightward\n");
	printf("3. move upward\n");
	printf("4. move downward\n");
	printf("(number) : ");
	
	fgets(menuNum, 50, stdin);
	inputLength = inputStringLength(menuNum);

	if (inputLength != 1 || !(menuNum[0] >= 49 && menuNum[0] <= 52))
	{
		printf("\n\nplease, put a number between 1 and 4 (enter key to continue)");
		while (1)
		{
			if (kbhit())
				break;
		}
		FLUSH;					// 리눅스에서 지울것
		// __fpurge(stdin);		// 리눅스에서 넣을것
		patternMenu();
	}

	return menuNum[0];
}

int speedMenu()	// LED전광판 이동패턴 선택 화면출력 및 메뉴 선택 받음
{
	char menuNum[50], inputLength;

	system("cls");
	// system("clear");			// 리눅스에서 바꿀것

	printf("***** Move Speed *****\n");
	printf("1. every 1 second\n");
	printf("2. every 0.5 second\n");
	printf("3. every 0.33 second\n");
	printf("(number) : ");

	fgets(menuNum, 50, stdin);
	inputLength = inputStringLength(menuNum);

	if (inputLength != 1 || !(menuNum[0] >= 49 && menuNum[0] <= 51))
	{
		printf("\n\nplease, put a number between 1 and 3 (enter key to continue)");
		while (1)
		{
			if (kbhit())
				break;
		}
		FLUSH;					// 리눅스에서 지울것
		// __fpurge(stdin);		// 리눅스에서 넣을것
		speedMenu();
	}

	return menuNum[0];
}

int colorMenu()	// LED전광판 이동패턴 선택 화면출력 및 메뉴 선택 받음
{
	char menuNum[50], inputLength;

	system("cls");
	// system("clear");			// 리눅스에서 바꿀것

	printf("***** LED Color *****\n");
	printf("1. red\n");
	printf("2. yellow\n");
	printf("3. green\n");
	printf("4. blue\n");
	printf("(number) : ");

	fgets(menuNum, 50, stdin);
	inputLength = inputStringLength(menuNum);

	if (inputLength != 1 || !(menuNum[0] >= 49 && menuNum[0] <= 52))
	{
		printf("\n\nplease, put a number between 1 and 4 (enter key to continue)");
		while (1)
		{
			if (kbhit())
				break;
		}
		FLUSH;					// 리눅스에서 지울것
		// __fpurge(stdin);		// 리눅스에서 넣을것
		colorMenu();
	}

	return menuNum[0];
}