// �� �ҽ� �ڵ�� ������ �������� ��ȯ�� �ڵ��Դϴ�.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>		// ���������� �߰�
#include "checker.h"
#include "keyboard.h"	// ���������� ���Խ�ų��
#include "led.h"
#include "menu.h"


int main()
{
	// ���� ����
	int stringSize = 26, menuNum, i, j, inputLength, speedNum, colorNum;
	double speed;
	char string[26], led[20][220];

	// �޴� �ҷ����� ����
	textMenu(string, stringSize);
	menuNum = patternMenu() - 48;
	speedNum = speedMenu() - 48;
	colorNum = colorMenu() - 48;
	inputLength = inputStringLength(string) + 1;	// �Է¹��� ���ڿ� ���� ����

	// led �ʱ�ȭ ����
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 220; j++)
			led[i][j] = ' ';
	}
	
	// �Է¹��� ���ڿ��� led �� ������Ŵ
	makeArray(led, inputLength, string);
	
	// �ӵ� ����
	switch (speedNum)
	{
	case 1:
		speed = 1000.0;
		break;
	case 2:
		speed = 500.0;
		break;
	case 3:
		speed = 330.0;
		break;
	}
	speed = speed * 1000.0;		// ���������� �ּ� �����Ұ� - �ӵ� �и��� ������ ��ȯ (usleep ���)

	// �� ����
	switch (colorNum)
	{
	case 1:
		printf("\033[31m");		// ����
		break;
	case 2:
		printf("\033[33m");		// ���
		break;
	case 3:
		printf("\033[32m");		// �ʷ�
		break;
	case 4:
		printf("\033[34m");		// �Ķ�
		break;
	}
	
	// �̵� ���� ����
	switch (menuNum)
	{
	case 1:
		moveLEDLeft(led, inputLength, speed);
		break;
	case 2:
		moveLEDRight(led, inputLength, speed);
		break;
	case 3:
		moveLEDUp(led, inputLength, speed);
		break;
	case 4:
		moveLEDDown(led, inputLength, speed);
		break;
	}

	// �� �ʱ�ȭ
	printf("\033[0m");

	return 0;
}
