/*
* Programming Assignment #1_1
* �ۼ��� : 20160074 ȭ�а��а� ������
* �ۼ��� : 160929


#include <stdio.h>

int main()
{
	//��������
	int bi,de,bi_1,bi_2,bi_3,bi_4;
	printf("Input a 4-bit binary number: ");
	//������ �Է�
	scanf("%d",&bi);
	//������ �ڸ��� �и�
	bi_1 = bi % 10;								//������ ù°�ڸ�
	bi_2 = (bi / 10) % 10;						//������ ��°�ڸ�
	bi_3 = (bi / 100) % 10;						//������ ��°�ڸ�
	bi_4 = bi/1000;								//������ ��°�ڸ�
	//�������� ��ȯ
	de = bi_1 + bi_2 * 2 + bi_3 * 4 + bi_4 * 8;
	//���
	printf("The binary number %d is a decimal number %d\n",bi,de);
	printf("Written by %c%c%c %c%c%c%c%c%c\n", 71, 111, 104, 74, 105, 110, 109, 105, 110);
}*/