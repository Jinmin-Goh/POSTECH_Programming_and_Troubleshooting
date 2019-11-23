#include <stdio.h>
#include <stdlib.h>
// #include <Windows.h>	// 리눅스에서 제거
// #include <unistd.h>	// 리눅스에서 추가
// #include "keyboard.h"	// 리눅스에서 포함시킬것
// #include "getch.h"		// 리눅스에서 포함시킬것
#include "checker.h"
#include "keyboard.h"
#include "led.h"
#include "menu.h"

int main()
{
	int stringSize = 26, menuNum, i, j, inputLength, speedNum, colorNum;
	double speed;
	char string[26], led[20][220];

	textMenu(string, stringSize);
	menuNum = patternMenu() - 48;
	speedNum = speedMenu() - 48;
	colorNum = colorMenu() - 48;
	inputLength = inputStringLength(string) + 1;
	
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 220; j++)
			led[i][j] = ' ';
	}
	makeArray(led, inputLength, string);
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
	// speed = speed / 1000;		// 리눅스에서 주석 해제할것 

	switch (colorNum)
	{
	case 1:
		printf("\033[31m");		// 빨강
		break;
	case 2:
		printf("\033[33m");		// 노랑
		break;
	case 3:
		printf("\033[32m");		// 초록
		break;
	case 4:
		printf("\033[34m");		// 파랑
		break;
	}
	// printf("%d %d %d text\n", menuNum, speedNum, colorNum);

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
	printf("\033[0m");


	return 0;
}