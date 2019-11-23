#include <stdio.h>
#include <stdlib.h>
// #include "keyboard.h"	// ���������� ���Խ�ų��
#include "menu.h"

#define FLUSH fflush(stdin)		// ���������� ����


void textMenu(char string[], int stringSize)
{
	int inputLength;
	system("cls");
	// system("clear");			// ���������� �ٲܰ�
	printf("***** Enter String *****\n(less than 20 letters with 0-9 and a-z)\n: ");
	fgets(string, 25, stdin); // Ű����κ��� �ִ� 25�� �Է¹���
	
	// __fpurge(stdin); // �Է¹ް� ���ۿ� ���� ���� ���� -  ������

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

int patternMenu()	// LED������ �̵����� ���� ȭ����� �� �޴� ���� ����
{
	char menuNum[50], inputLength;

	system("cls");
	// system("clear");			// ���������� �ٲܰ�

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
		FLUSH;					// ���������� �����
		// __fpurge(stdin);		// ���������� ������
		patternMenu();
	}

	return menuNum[0];
}

int speedMenu()	// LED������ �̵����� ���� ȭ����� �� �޴� ���� ����
{
	char menuNum[50], inputLength;

	system("cls");
	// system("clear");			// ���������� �ٲܰ�

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
		FLUSH;					// ���������� �����
		// __fpurge(stdin);		// ���������� ������
		speedMenu();
	}

	return menuNum[0];
}

int colorMenu()	// LED������ �̵����� ���� ȭ����� �� �޴� ���� ����
{
	char menuNum[50], inputLength;

	system("cls");
	// system("clear");			// ���������� �ٲܰ�

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
		FLUSH;					// ���������� �����
		// __fpurge(stdin);		// ���������� ������
		colorMenu();
	}

	return menuNum[0];
}