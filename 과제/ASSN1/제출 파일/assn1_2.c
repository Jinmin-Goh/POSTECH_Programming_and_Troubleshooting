/*
* Programming Assignment #1_2
* �ۼ��� : 20160074 ȭ�а��а� ������
* �ۼ��� : 160929
*/

#include <stdio.h>
#include <math.h>

int main()
{
	//���� ����
	int x1, x2, x3, y1, y2, y3;
	double S, s, l12, l13, l23;
	//��ǥ �Է�
	printf("Enter P1 (x1, y1) : ");
	scanf("%d%d", &x1, &y1);
	printf("Enter P2 (x2, y2) : ");
	scanf("%d%d", &x2, &y2);
	printf("Enter P3 (x3, y3) : ");
	scanf("%d%d", &x3, &y3);
	//�ﰢ���� �� ���� ���̿� s, S�� ����
	l12 = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	l13 = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
	l23 = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
	s = (l12 + l13 + l23) / 2;
	S = sqrt(s*(s - l12)*(s - l13)*(s - l23));
	//���
	printf("The perimeter of triangle is : %.3lf\n", 2 * s);
	printf("The area of triangle is : %.3lf\n",S);

	return 0;
}