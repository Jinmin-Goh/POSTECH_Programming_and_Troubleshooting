/*
* Programming Assignment #1_1
* 작성자 : 20160074 화학공학과 고진민
* 작성일 : 160929


#include <stdio.h>

int main()
{
	//변수선언
	int bi,de,bi_1,bi_2,bi_3,bi_4;
	printf("Input a 4-bit binary number: ");
	//이진수 입력
	scanf("%d",&bi);
	//이진수 자리수 분리
	bi_1 = bi % 10;								//이진수 첫째자리
	bi_2 = (bi / 10) % 10;						//이진수 둘째자리
	bi_3 = (bi / 100) % 10;						//이진수 셋째자리
	bi_4 = bi/1000;								//이진수 넷째자리
	//십진수로 변환
	de = bi_1 + bi_2 * 2 + bi_3 * 4 + bi_4 * 8;
	//출력
	printf("The binary number %d is a decimal number %d\n",bi,de);
	printf("Written by %c%c%c %c%c%c%c%c%c\n", 71, 111, 104, 74, 105, 110, 109, 105, 110);
}*/