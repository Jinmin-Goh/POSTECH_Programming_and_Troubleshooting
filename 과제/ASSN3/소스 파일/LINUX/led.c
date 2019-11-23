// �� �ҽ� �ڵ�� ������ �������� ��ȯ�� �ڵ��Դϴ�.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>		// ���������� �߰�
#include "led.h"
#include "keyboard.h"	// ���������� ���Խ�ų��

void moveLEDLeft(char led[][220], int inputLength, double speed) //LED������ ������ ��� �̵�
{
	int i, j, k = 0, sum = 0;

	system("clear");			// ȭ�� ���� - ���������� �ٲܰ�
	
	// ���ѷ���
	while (1)
	{
		system("clear");			// ȭ�� ���� - ���������� �ٲܰ�

		if (inputLength >= 7)		// ���ڿ� ���̰� 7 �̻�
		{
			for (i = 0; i < 20; i++)
			{
				for (j = 0; j < 75; j++)
				{
					sum = j - k;
					printf("%c", led[i][sum % (inputLength * 11)]);
				}

				printf("\n");
			}
			k--;			// ��� ������ ���������� �� ĭ �̵�
			usleep(speed);	// ������ �ð���ŭ �Ͻ�����

			// Ű���� �Է��� �ִ� ���
			if (kbhit())
			{
				if (getchar() == 'q')	// 'q'�� �Է����� ��
					break;	// ���α׷� ���Ḧ ���� �ݺ��� Ż��
			}
		}
		else				// ���ڿ� ���̰� 7 �̸��� ���
		{
			for (i = 0; i < 20; i++)
			{
				for (j = 0; j < 75; j++)
				{
					sum = j - k;
					printf("%c", led[i][sum % 75]);
				}

				printf("\n");
			}
			k--;			// ��� ������ �������� �� ĭ �̵�
			usleep(speed);	// ������ �ð���ŭ �Ͻ�����

			// Ű���� �Է��� �ִ� ���
			if (kbhit())
			{
				if (getchar() == 'q') // 'q'�� �Է����� ��
					break; // ���α׷� ���Ḧ ���� �ݺ��� Ż��
			}
		}
	}

	return;
}

void moveLEDRight(char led[][220], int inputLength, double speed) //LED������ ������ �·� �̵�
{
	int i, j, k = 0, sum = 0;

	system("clear");			// ȭ�� ���� - ���������� �ٲܰ�
	while (1)
	{
		system("clear");			// ȭ�� ���� - ���������� �ٲܰ�

		if (inputLength >= 7)		// ���ڿ� ���̰� 7 �̻��� ���
		{
			for (i = 0; i < 20; i++)
			{
				for (j = 0; j < 75; j++)
				{
					sum = j - k;
					while (sum < 0)	// ������ ��� ����� �ɶ����� ��ü ���ڿ��� �����ϴ� ���̸�ŭ �����ش�
						sum = sum + (inputLength * 11);
					printf("%c", led[i][sum % (inputLength * 11)]);
				}

				printf("\n");
			}
			k++;			// ��¹��� ���������� �� ĭ �̵�
			usleep(speed);	// �Է¹��� �ð���ŭ �Ͻ�����

			// �Է��� ������
			if (kbhit())
			{
				if (getchar() == 'q') // 'q'�� �Է����� ��
				{
					break; // ���α׷� ���Ḧ ���� �ݺ��� Ż��
				}
			}
		}
		else		// ���ڿ� ���̰� 7 �̸��� ���
		{
			for (i = 0; i < 20; i++)
			{
				for (j = 0; j < 75; j++)
				{
					sum = j - k;
					while (sum < 0)	// ������ ��� ����� �ɶ����� ��ü ���ڿ��� �����ϴ� ���̸�ŭ �����ش�
						sum = sum + 75;
					printf("%c", led[i][sum % 75]);
				}

				printf("\n");
			}
			k++;			// ��¹��� ���������� �� ĭ �̵�
			usleep(speed);	// �Է¹��� �ð���ŭ �Ͻ�����

			// �Է��� ������
			if (kbhit())
			{
				if (getchar() == 'q') // 'q'�� �Է����� ��
				{
					break; // ���α׷� ���Ḧ ���� �ݺ��� Ż��
				}
			}
		}
	}

	return;
}

void moveLEDUp(char led[][220], int inputLength, double speed) //LED������ ������ ���� �̵�
{
	int i, j, k = 0;
	char check;

	system("clear");			// ȭ�� ���� - ���������� �ٲܰ�
	while (1)
	{
		system("clear");			// ȭ�� ���� - ���������� �ٲܰ�
		for (i = 0; i < 20; i++)
		{
			for (j = 0; j < 75; j++)
			{
				printf("%c", led[(i - k) % 20][j]);
			}
			printf("\n");
		}
		k--;			// ��� ���� �Ʒ��� �� ĭ �̵�
		usleep(speed);	// �Է¹��� �ð���ŭ �Ͻ�����

		// Ű���� �Է��� ������
		if (kbhit())
		{
			if (getchar() == 'q') // 'q'�� �Է����� ��
			{
				break; // ���α׷� ���Ḧ ���� �ݺ��� Ż��
			}
		}
	}

	return;
}

void moveLEDDown(char led[][220], int inputLength, double speed) //LED������ ������ �Ʒ��� �̵�
{
	int i, j, k = 0, sum = 0;

	system("clear");			// ȭ�� ���� - ���������� �ٲܰ�
	while (1)
	{
		system("clear");			// ȭ�� ���� - ���������� �ٲܰ�
		for (i = 0; i < 20; i++)
		{
			for (j = 0; j < 75; j++)
			{
				sum = i - k;
				while (sum < 0)		// ������ ��� ����� �ɶ����� ���� ���̸� ���Ѵ�
					sum = sum + 20;
				printf("%c", led[(sum) % 20][j]);
			}

			printf("\n");
		}
		k++;			// ��� ���� ���� �� ĭ �̵�
		usleep(speed);	// �Է¹��� �ð���ŭ �Ͻ�����

		// Ű���� �Է��� ������
		if (kbhit())
		{
			if (getchar() == 'q') // 'q'�� �Է����� ��
			{
				break; // ���α׷� ���Ḧ ���� �ݺ��� Ż��
			}
		}
	}

	return;
}

void makeArray(char led[][220], int inputLength, char string[])
{
	// ���� ���� ����
	int i, j, k;

	// ���ĺ��� ��� ����
	char alphabet_A[14][11] = {
		"           ",
		"           ",
		"     *     ",
		"    * *    ",
		"    * *    ",
		"    * *    ",
		"   *   *   ",
		"   *****   ",
		"   *   *   ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"           ",
		"           " };
	char alphabet_B[14][11] = {
		"           ",
		"           ",
		"  *****    ",
		"  *    *   ",
		"  *    *   ",
		"  *    *   ",
		"  *****    ",
		"  *    *   ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  ******   ",
		"           ",
		"           " };
	char alphabet_C[14][11] = {
		"           ",
		"           ",
		"   *****   ",
		"  *     *  ",
		"  *        ",
		"  *        ",
		"  *        ",
		"  *        ",
		"  *        ",
		"  *        ",
		"  *     *  ",
		"   *****   ",
		"           ",
		"           " };
	char alphabet_D[14][11] = {
		"           ",
		"           ",
		"  *****    ",
		"  *    *   ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *    *   ",
		"  *****    ",
		"           ",
		"           " };
	char alphabet_E[14][11] = {
		"           ",
		"           ",
		"  *******  ",
		"  *        ",
		"  *        ",
		"  *        ",
		"  *        ",
		"  ******   ",
		"  *        ",
		"  *        ",
		"  *        ",
		"  *******  ",
		"           ",
		"           " };
	char alphabet_F[14][11] = {
		"           ",
		"           ",
		"  *******  ",
		"  *        ",
		"  *        ",
		"  *        ",
		"  *        ",
		"  ******   ",
		"  *        ",
		"  *        ",
		"  *        ",
		"  *        ",
		"           ",
		"           " };
	char alphabet_G[14][11] = {
		"           ",
		"           ",
		"   *****   ",
		"  *     *  ",
		"  *        ",
		"  *        ",
		"  * *****  ",
		"  * *   *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"   *****   ",
		"           ",
		"           " };
	char alphabet_H[14][11] = {
		"           ",
		"           ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *******  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"           ",
		"           " };
	char alphabet_I[14][11] = {
		"           ",
		"           ",
		"  *******  ",
		"     *     ",
		"     *     ",
		"     *     ",
		"     *     ",
		"     *     ",
		"     *     ",
		"     *     ",
		"     *     ",
		"  *******  ",
		"           ",
		"           " };
	char alphabet_J[14][11] = {
		"           ",
		"           ",
		"        *  ",
		"        *  ",
		"        *  ",
		"        *  ",
		"        *  ",
		"        *  ",
		"        *  ",
		"  *     *  ",
		"  *     *  ",
		"   *****   ",
		"           ",
		"           " };
	char alphabet_K[14][11] = {
		"           ",
		"           ",
		"  *     *  ",
		"  *    *   ",
		"  *   *    ",
		"  *  *     ",
		"  * *      ",
		"  ***      ",
		"  *  *     ",
		"  *   *    ",
		"  *    *   ",
		"  *     *  ",
		"           ",
		"           " };
	char alphabet_L[14][11] = {
		"           ",
		"           ",
		"  *        ",
		"  *        ",
		"  *        ",
		"  *        ",
		"  *        ",
		"  *        ",
		"  *        ",
		"  *        ",
		"  *        ",
		"  *******  ",
		"           ",
		"           " };
	char alphabet_M[14][11] = {
		"           ",
		"           ",
		"  *     *  ",
		"  **   **  ",
		"  * * * *  ",
		"  *  *  *  ",
		"  *  *  *  ",
		"  *  *  *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"           ",
		"           " };
	char alphabet_N[14][11] = {
		"           ",
		"           ",
		"  *     *  ",
		"  **    *  ",
		"  * *   *  ",
		"  * *   *  ",
		"  *  *  *  ",
		"  *  *  *  ",
		"  *   * *  ",
		"  *   * *  ",
		"  *    **  ",
		"  *     *  ",
		"           ",
		"           " };
	char alphabet_O[14][11] = {
		"           ",
		"           ",
		"   *****   ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"   *****   ",
		"           ",
		"           " };
	char alphabet_P[14][11] = {
		"           ",
		"           ",
		"  ******   ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  ******   ",
		"  *        ",
		"  *        ",
		"  *        ",
		"  *        ",
		"           ",
		"           " };
	char alphabet_Q[14][11] = {
		"           ",
		"           ",
		"   *****   ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *  *  *  ",
		"  *   * *  ",
		"  *    *   ",
		"   **** *  ",
		"           ",
		"           " };
	char alphabet_R[14][11] = {
		"           ",
		"           ",
		"  ******   ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  ******   ",
		"  *  *     ",
		"  *   *    ",
		"  *    *   ",
		"  *     *  ",
		"           ",
		"           " };
	char alphabet_S[14][11] = {
		"           ",
		"           ",
		"   *****   ",
		"  *     *  ",
		"  *        ",
		"  *        ",
		"   *****   ",
		"        *  ",
		"        *  ",
		"        *  ",
		"  *     *  ",
		"   *****   ",
		"           ",
		"           " };
	char alphabet_T[14][11] = {
		"           ",
		"           ",
		"  *******  ",
		"     *     ",
		"     *     ",
		"     *     ",
		"     *     ",
		"     *     ",
		"     *     ",
		"     *     ",
		"     *     ",
		"     *     ",
		"           ",
		"           " };
	char alphabet_U[14][11] = {
		"           ",
		"           ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"   *****   ",
		"           ",
		"           " };
	char alphabet_V[14][11] = {
		"           ",
		"           ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"   *   *   ",
		"    * *    ",
		"     *     ",
		"           ",
		"           " };
	char alphabet_W[14][11] = {
		"           ",
		"           ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *  *  *  ",
		"  *  *  *  ",
		"  *  *  *  ",
		"  *  *  *  ",
		"  *  *  *  ",
		"  *  *  *  ",
		"   ** **   ",
		"           ",
		"           " };
	char alphabet_X[14][11] = {
		"           ",
		"           ",
		"  *     *  ",
		"   *   *   ",
		"   *   *   ",
		"    * *    ",
		"    * *    ",
		"     *     ",
		"    * *    ",
		"   *   *   ",
		"   *   *   ",
		"  *     *  ",
		"           ",
		"           " };
	char alphabet_Y[14][11] = {
		"           ",
		"           ",
		"  *     *  ",
		"   *   *   ",
		"    * *    ",
		"     *     ",
		"     *     ",
		"     *     ",
		"     *     ",
		"     *     ",
		"     *     ",
		"     *     ",
		"           ",
		"           " };
	char alphabet_Z[14][11] = {
		"           ",
		"           ",
		"  *******  ",
		"        *  ",
		"       *   ",
		"      *    ",
		"     *     ",
		"     *     ",
		"    *      ",
		"   *       ",
		"  *        ",
		"  *******  ",
		"           ",
		"           " };
	char alphabet_0[14][11] = {
		"           ",
		"           ",
		"   *****   ",
		"  **    *  ",
		"  * *   *  ",
		"  * *   *  ",
		"  *  *  *  ",
		"  *  *  *  ",
		"  *   * *  ",
		"  *   * *  ",
		"  *    **  ",
		"   *****   ",
		"           ",
		"           " };
	char alphabet_1[14][11] = {
		"           ",
		"           ",
		"     *     ",
		"    **     ",
		"   * *     ",
		"  *  *     ",
		"     *     ",
		"     *     ",
		"     *     ",
		"     *     ",
		"     *     ",
		"  *******  ",
		"           ",
		"           " };
	char alphabet_2[14][11] = {
		"           ",
		"           ",
		"   *****   ",
		"  *     *  ",
		"        *  ",
		"        *  ",
		"       *   ",
		"      *    ",
		"     *     ",
		"    *      ",
		"   *       ",
		"  *******  ",
		"           ",
		"           " };
	char alphabet_3[14][11] = {
		"           ",
		"           ",
		"   *****   ",
		"  *     *  ",
		"        *  ",
		"        *  ",
		"   *****   ",
		"        *  ",
		"        *  ",
		"        *  ",
		"  *     *  ",
		"   *****   ",
		"           ",
		"           " };
	char alphabet_4[14][11] = {
		"           ",
		"           ",
		"     *     ",
		"    **     ",
		"   * *     ",
		"  *  *     ",
		"  *  *     ",
		"  *******  ",
		"     *     ",
		"     *     ",
		"     *     ",
		"     *     ",
		"           ",
		"           " };
	char alphabet_5[14][11] = {
		"           ",
		"           ",
		"  *******  ",
		"  *        ",
		"  *        ",
		"  *        ",
		"  ******   ",
		"        *  ",
		"        *  ",
		"        *  ",
		"  *     *  ",
		"   *****   ",
		"           ",
		"           " };
	char alphabet_6[14][11] = {
		"           ",
		"           ",
		"   *****   ",
		"  *     *  ",
		"  *        ",
		"  *        ",
		"  ******   ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"   *****   ",
		"           ",
		"           " };
	char alphabet_7[14][11] = {
		"           ",
		"           ",
		"  *******  ",
		"        *  ",
		"       *   ",
		"      *    ",
		"     *     ",
		"    *      ",
		"    *      ",
		"    *      ",
		"    *      ",
		"    *      ",
		"           ",
		"           " };
	char alphabet_8[14][11] = {
		"           ",
		"           ",
		"   *****   ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"   *****   ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"   *****   ",
		"           ",
		"           " };
	char alphabet_9[14][11] = {
		"           ",
		"           ",
		"   *****   ",
		"  *     *  ",
		"  *     *  ",
		"  *     *  ",
		"   ******  ",
		"        *  ",
		"        *  ",
		"        *  ",
		"  *     *  ",
		"   *****   ",
		"           ",
		"           " };
	char alphabet__[14][11] = {
		"           ",
		"           ",
		"           ",
		"           ",
		"           ",
		"           ",
		"           ",
		"           ",
		"           ",
		"           ",
		"           ",
		"           ",
		"           ",
		"           " };

	// �Է¹��� ���ڿ���� led �迭�� ������ ������ 2���� �迭�� ������� ����
	for (i = 0; i < inputLength; i++)
	{
		for (j = 0; j < 14; j++)
		{
			for (k = 0; k < 11; k++)
			{
				switch (string[i])
				{
				case 'a':
					led[j + 3][k + 11 * i] = alphabet_A[j][k];
					break;
				case 'b':
					led[j + 3][k + 11 * i] = alphabet_B[j][k];
					break;
				case 'c':
					led[j + 3][k + 11 * i] = alphabet_C[j][k];
					break;
				case 'd':
					led[j + 3][k + 11 * i] = alphabet_D[j][k];
					break;
				case 'e':
					led[j + 3][k + 11 * i] = alphabet_E[j][k];
					break;
				case 'f':
					led[j + 3][k + 11 * i] = alphabet_F[j][k];
					break;
				case 'g':
					led[j + 3][k + 11 * i] = alphabet_G[j][k];
					break;
				case 'h':
					led[j + 3][k + 11 * i] = alphabet_H[j][k];
					break;
				case 'i':
					led[j + 3][k + 11 * i] = alphabet_I[j][k];
					break;
				case 'j':
					led[j + 3][k + 11 * i] = alphabet_J[j][k];
					break;
				case 'k':
					led[j + 3][k + 11 * i] = alphabet_K[j][k];
					break;
				case 'l':
					led[j + 3][k + 11 * i] = alphabet_L[j][k];
					break;
				case 'm':
					led[j + 3][k + 11 * i] = alphabet_M[j][k];
					break;
				case 'n':
					led[j + 3][k + 11 * i] = alphabet_N[j][k];
					break;
				case 'o':
					led[j + 3][k + 11 * i] = alphabet_O[j][k];
					break;
				case 'p':
					led[j + 3][k + 11 * i] = alphabet_P[j][k];
					break;
				case 'q':
					led[j + 3][k + 11 * i] = alphabet_Q[j][k];
					break;
				case 'r':
					led[j + 3][k + 11 * i] = alphabet_R[j][k];
					break;
				case 's':
					led[j + 3][k + 11 * i] = alphabet_S[j][k];
					break;
				case 't':
					led[j + 3][k + 11 * i] = alphabet_T[j][k];
					break;
				case 'u':
					led[j + 3][k + 11 * i] = alphabet_U[j][k];
					break;
				case 'v':
					led[j + 3][k + 11 * i] = alphabet_V[j][k];
					break;
				case 'w':
					led[j + 3][k + 11 * i] = alphabet_W[j][k];
					break;
				case 'x':
					led[j + 3][k + 11 * i] = alphabet_X[j][k];
					break;
				case 'y':
					led[j + 3][k + 11 * i] = alphabet_Y[j][k];
					break;
				case 'z':
					led[j + 3][k + 11 * i] = alphabet_Z[j][k];
					break;
				case '0':
					led[j + 3][k + 11 * i] = alphabet_0[j][k];
					break;
				case '1':
					led[j + 3][k + 11 * i] = alphabet_1[j][k];
					break;
				case '2':
					led[j + 3][k + 11 * i] = alphabet_2[j][k];
					break;
				case '3':
					led[j + 3][k + 11 * i] = alphabet_3[j][k];
					break;
				case '4':
					led[j + 3][k + 11 * i] = alphabet_4[j][k];
					break;
				case '5':
					led[j + 3][k + 11 * i] = alphabet_5[j][k];
					break;
				case '6':
					led[j + 3][k + 11 * i] = alphabet_6[j][k];
					break;
				case '7':
					led[j + 3][k + 11 * i] = alphabet_7[j][k];
					break;
				case '8':
					led[j + 3][k + 11 * i] = alphabet_8[j][k];
					break;
				case '9':
					led[j + 3][k + 11 * i] = alphabet_9[j][k];
					break;
				case ' ':
					led[j + 3][k + 11 * i] = alphabet__[j][k];
					break;

				}
			}
		}
	}
	return;
}
