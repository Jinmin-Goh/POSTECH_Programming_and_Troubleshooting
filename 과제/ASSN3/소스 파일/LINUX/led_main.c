// 이 소스 코드는 리눅스 버전으로 변환한 코드입니다.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>		// 리눅스에서 추가
#include "checker.h"
#include "keyboard.h"	// 리눅스에서 포함시킬것
#include "led.h"
#include "menu.h"


int main()
{
	// 변수 선언
	int stringSize = 26, menuNum, i, j, inputLength, speedNum, colorNum;
	double speed;
	char string[26], led[20][220];

	// 메뉴 불러오기 영역
	textMenu(string, stringSize);
	menuNum = patternMenu() - 48;
	speedNum = speedMenu() - 48;
	colorNum = colorMenu() - 48;
	inputLength = inputStringLength(string) + 1;	// 입력받은 문자열 길이 저장

	// led 초기화 과정
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 220; j++)
			led[i][j] = ' ';
	}
	
	// 입력받은 문자열을 led 에 대응시킴
	makeArray(led, inputLength, string);
	
	// 속도 설정
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
	speed = speed * 1000.0;		// 리눅스에서 주석 해제할것 - 속도 밀리초 단위로 변환 (usleep 사용)

	// 색 설정
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
	
	// 이동 방향 설정
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

	// 색 초기화
	printf("\033[0m");

	return 0;
}
