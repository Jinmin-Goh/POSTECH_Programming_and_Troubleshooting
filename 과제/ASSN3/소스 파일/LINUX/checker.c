// �� �ҽ� �ڵ�� ������ �������� ��ȯ�� �ڵ��Դϴ�.

#include <stdio.h>
#include <stdlib.h>
#include "checker.h"

int inputStringLength(char string[])	// ���ڿ��� ���̸� ���ϴ� �Լ�
{
	// ���� ���� ����
	int i = 0, cnt = 0;

	// NULL ���� �Է½ñ��� cnt�� 1�� ������Ų��
	while (string[i] != NULL)
	{
		i++;
		cnt++;
	}
	// ���ڿ� ���� ��ȯ
	return cnt - 1;
}

int inputStringChecker(char string[], int stringSize)	// LED �����ǿ� ����� ���ڿ��� �ùٸ��� Ȯ���ϴ� �Լ�
{
	int i;
	for (i = 0; i < 26; i++)
	{
		// NULL ������ ���
		if (string[i] == NULL)
		{
			break;	// ��Ż
		}
		// ���ĺ� �ҹ��ڳ� ���ڰ� �ƴ� ���
		if (!((string[i] >= 48 && string[i] <= 57) || (string[i] >= 97 && string[i] <= 122) || string[i] == ' '))
			return 1;
	}
	if (stringSize == 0)	// ���͸� ģ ���
		return 1;
	if (stringSize > 20)	// 20�� �̻��� ���
		return 2;
	else
		return 0;	// ���� �Է�
}