/*
* Programming Assignment #1_2
* 작성자 : 20160074 화학공학과 고진민
* 작성일 : 160929
*/

#include <stdio.h>
#include <math.h>

int main()
{
	//변수 선언
	int x1, x2, x3, y1, y2, y3;
	double S, s, l12, l13, l23;
	//좌표 입력
	printf("Enter P1 (x1, y1) : ");
	scanf("%d%d", &x1, &y1);
	printf("Enter P2 (x2, y2) : ");
	scanf("%d%d", &x2, &y2);
	printf("Enter P3 (x3, y3) : ");
	scanf("%d%d", &x3, &y3);
	//삼각형의 세 변의 길이와 s, S의 정의
	l12 = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	l13 = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
	l23 = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
	s = (l12 + l13 + l23) / 2;
	S = sqrt(s*(s - l12)*(s - l13)*(s - l23));
	//출력
	printf("The perimeter of triangle is : %.3lf\n", 2 * s);
	printf("The area of triangle is : %.3lf\n",S);

	return 0;
}