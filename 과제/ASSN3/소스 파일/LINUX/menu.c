// �� �ҽ� �ڵ�� ������ �������� ��ȯ�� �ڵ��Դϴ�.


#include <stdio.h>
#include <stdlib.h>
#include "keyboard.h"	// ���������� ���Խ�ų��
#include "menu.h"


void textMenu(char string[], int stringSize)	// ���ڿ��� ���ڿ��� ũ�⸦ �Է¹ް� �˻��ϴ� �Լ�
{
	// ���� ���� ����
	int inputLength, check, check2 = 1;

	while (check2)
	{
		__fpurge(stdin);
		system("clear");			// ȭ�� ���� - ���������� �ٲܰ�
		printf("***** Enter String *****\n(less than 20 letters with 0-9 and a-z)\n: ");
		fgets(string, 27, stdin);	// Ű����κ��� �ִ� 25�� �Է¹���	

		inputLength = inputStringLength(string);	// string �� ���� �� ����
		string[inputLength] = '\0';					// ���� ���� ����
	
		check = inputStringChecker(string, inputLength);	// ���ڿ� �˻�
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
			check2 = 0;		// ���� ��Ż
			break;
		}
	}
	return;
}

int patternMenu()	// LED������ �̵����� ���� ȭ����� �� �޴� ���� ����
{
	// ���� ���� ����
	int check = 1;
	char menuNum[50], inputLength;

	while (check)
	{
		system("clear");			// ȭ�� ���� - ���������� �ٲܰ�
		printf("***** Pattern Selection *****\n");
		printf("1. move leftward\n");
		printf("2. move rightward\n");
		printf("3. move upward\n");
		printf("4. move downward\n");
		printf("(number) : ");
		// �޴� ��ȣ �Է¹���

		fgets(menuNum, 50, stdin);
		inputLength = inputStringLength(menuNum);

		// �߸��� �Է�
		if (inputLength != 1 || !(menuNum[0] >= 49 && menuNum[0] <= 52))
		{
			printf("\n\nplease, put a number between 1 and 4 (enter key to continue)");
			while (1)
			{
				if (kbhit())
					break;
			}
			__fpurge(stdin);		// ���� ���� - ���������� ������
		}
		else
			check = 0;		// ���� ��Ż

	}
	// �޴� ��ȣ ��ȯ
	return menuNum[0];
}

int speedMenu()	// LED������ �̵��ӵ� ���� ȭ����� �� �޴� ���� ����
{
	// ���� ���� ����
	int check = 1;
	char menuNum[50], inputLength;

	while (check)
	{
		system("clear");			// ȭ�� ���� - ���������� �ٲܰ�

		printf("***** Move Speed *****\n");
		printf("1. every 1 second\n");
		printf("2. every 0.5 second\n");
		printf("3. every 0.33 second\n");
		printf("(number) : ");

		// �޴� ��ȣ �Է¹���
		fgets(menuNum, 50, stdin);
		inputLength = inputStringLength(menuNum);
		
		// �߸��� �Է�
		if (inputLength != 1 || !(menuNum[0] >= 49 && menuNum[0] <= 51))
		{
			printf("\n\nplease, put a number between 1 and 3 (enter key to continue)");
			while (1)
			{
				if (kbhit())
					break;
			}
			__fpurge(stdin);		// ���� ���� - ���������� ������
		}
		else
			check = 0;		// ���� ��Ż
	}
	// �޴� ��ȣ ��ȯ
	return menuNum[0];
}

int colorMenu()	// LED������ ȭ����� �� ���� �� �޴� ���� ����
{
	// ���� ���� ����
	int check = 1;
	char menuNum[50], inputLength;

	while (check)
	{
		system("clear");			// ȭ�� ���� - ���������� �ٲܰ�

		printf("***** LED Color *****\n");
		printf("1. red\n");
		printf("2. yellow\n");
		printf("3. green\n");
		printf("4. blue\n");
		printf("(number) : ");

		// ��ȣ �Է¹���
		fgets(menuNum, 50, stdin);
		inputLength = inputStringLength(menuNum);
		
		// �߸��� �Է�
		if (inputLength != 1 || !(menuNum[0] >= 49 && menuNum[0] <= 52))
		{
			printf("\n\nplease, put a number between 1 and 4 (enter key to continue)");
			while (1)
			{
				if (kbhit())
					break;
			}
			__fpurge(stdin);		// ���� ���� - ���������� ������
		}
		else
			check = 0;		// ���� ��Ż
	}
	// �޴� ��ȣ ��ȯ
	return menuNum[0];
}
