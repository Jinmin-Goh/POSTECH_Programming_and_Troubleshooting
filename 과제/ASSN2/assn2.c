#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

// ����� ���� �Լ�
void drawLine(void);
int showMenu(void);
int levelSetting(void);
int startGame(int level);
void display(int level, int life, int score, int elapsedTime, int limitTime, char order, char input, int initialFlag);
void showState(int level, int score, int life);
void showTime(int elapsedTime, int limitTime, int initialFlag);
char getInstruction(void);
void showInstruction(char order, int initialFlag);
void showFlag(char input, int initialFlag);
char getUserKey(void);
int judge(char order, char input, int leftTime, int initialFlag);
void situationCheck(int situation);
void gameOver(int score);

// main �Լ�
int main()
{
	// ���� ���� ����
	int menuNum, level, score = 0, life = 5, elapsedTime, limitTime, maxScore = 0;
	char endGame, order, input;

	menuNum = showMenu();	// �޴� ���� �Է�
	
	// �޴� ��� ����
	while (1)
	{
		switch (menuNum)
		{
			case 1:			// ���� �Լ� �Է�
				level = levelSetting();
				// ���� �Է� �˻�
				while (1)	
				{
					switch (level)
					{
					case 1:
					case 2:
					case 3:
						score = startGame(level);
						gameOver(score);
						if (score > maxScore)	// �ְ����� ����
							maxScore = score;
						menuNum = showMenu();	// ���� ���� �� ó��ȭ������ �̵�
						break;
					default:		// �߸��� �Է�
						level = levelSetting();
						continue;
					}
					break;
				}
				continue;
			case 2:			// ���� Ȯ�� �Է�
				printf("\n  �ְ������� %d�� �Դϴ�!\n\n", maxScore);
				menuNum = showMenu();
				continue;
			case 3:			// ���� �Ǵ�
				printf("\n  ������ �����Ͻðڽ��ϱ�? (y/n) : ");
				scanf(" %c", &endGame);
				if (endGame == 'n' || endGame == 'N')
				{
					printf("\n");
					menuNum = showMenu();
					continue;
				}
				else
					return 0;
			default :		// �߸��� �Է�
				printf("\n  �߸��� ���� �Է��ϼ̽��ϴ�. �ٽ� �Է��� �ּ���.\n\n");
				menuNum = showMenu();
				continue;
		}
		break;
	}
}

// 64���� ��=���� ����Ѵ�
void drawLine(void)
{
	int i;
	for (i=1; i<=64; i++)
	printf("=");
	printf("\n");
	return;
}

// �ʱ� �޴� ȭ���� ����ϰ�, ����ڷκ��� �޴� ��ȣ�� �Է� �޾� ��ȯ�Ѵ�
int showMenu(void)
{
	drawLine();
	printf("  û�� ��� ����\n");
	drawLine();
	printf("  1. ���� ����\n  2. �ְ� ���� Ȯ��\n  3. ���� ����\n");
	drawLine();
	printf("  ��ȣ �Է� : ");
	int menuNum;
	scanf("%d", &menuNum);	// ��ȣ �Է�
	return menuNum;			// ��ȣ ��ȯ
}

// ����ڷκ��� ���� ���� ���̵��� �Է� �ް�, �Է� ���� ���̵��� ��ȯ�Ѵ�
int levelSetting(void)
{
	int level;
	printf("  ���̵� ����(1~3) : ");
	scanf("%d",&level);
	return level;
}

// Level, Life, Score, ����ð�, ���ѽð�, ���û���, ���� �Է� Ű �����Ű������� ���޹޾� ����Ѵ�.
void display(int level, int life, int score, int elapsedTime, int limitTime, char order, char input, int initialFlag)
{
	int leftTime, situation;
	leftTime = limitTime - elapsedTime;
	system("cls");	// ȭ�� �����
	drawLine();							
	showState(level, score, life);					// ù°�� : ���� ���� ��Ȳ ǥ��
	drawLine();							
	showTime(elapsedTime, limitTime, initialFlag);	// ��°�� : �ð� ǥ��
	drawLine();
	showInstruction(order, initialFlag);			// ��°�� : ���� ���� ǥ��
	drawLine();
	showFlag(input, initialFlag);					// ��°�� : ��� ǥ��
	drawLine();
	situation = judge(order, input, leftTime, initialFlag);
	situationCheck(situation);						// �ټ�°�� : �ൿ ��� ǥ��
}

// Level, Score, Life�� �Ű������� ���� �޾� ȭ�鿡 �̸� ����Ѵ�
void showState(int level, int score, int life)
{
	int usedLife;
	usedLife = 5 - life;	// �Ҹ��� life
	printf("  LEVEL : %d     SCORE : %d       LIFE : ", level, score);		// ���� ���
	for (life; life >= 1; life--)					// life�� ���� �� �� ��Ʈ ���
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("��");
	}
	for (usedLife; usedLife >= 1; usedLife--)		// ����ִ� ��Ʈ ���
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("��");
	}
	printf("\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	// �� �ʱ�ȭ
}

// ����ð�, ���ѽð��� �Ű������� ���� �޾� ȭ�鿡 �˸��� ������ �Ḧ ����Ѵ�.
void showTime(int elapsedTime, int limitTime, int initialFlag)
{
	int square;		// ��µ� �׸��� ��
	
	if (initialFlag)	// ī��Ʈ�ٿ� �ð� ǥ��
	{
		square = 10 * initialFlag;
		printf("  ");
		for (square; square >= 1; square--)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			printf("��");
		}
		printf("\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	// �� �ʱ�ȭ
		return;
	}
	square = 30 - 30 / limitTime * elapsedTime;		// ��µ� �׸��� ���� ���
	printf("  ");
	for (square; square >= 1; square--)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("��");
	}
	printf("\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	// �� �ʱ�ȭ
}

// Random �Լ��� �̿��� 'e', 'd', 'i', 'k', ' ' �� �ϳ��� ��ȯ�Ѵ�
char getInstruction(void)
{
	srand((int)time(NULL));
	int inst = rand() % 5;	// 0~4�� ������ ������ ����
	switch (inst)
	{
	case 0:
		return 'e';		// û�� �÷�
	case 1:
		return 'd';		// û�� ����
	case 2:
		return 'i';		// ��� �÷�
	case 3 :
		return 'k';		// ��� ����
	default:
		return ' ';		// û�� �ø�����
	}
}

// ���� ���¸� �Ű������� ���� �޾� ȭ�鿡 �˸��� ���ø� ����Ѵ�
void showInstruction(char order, int initialFlag)
{
	if (initialFlag)	// ī��Ʈ�ٿ� ����
	{
		printf("  %d�� �� �����մϴ�\n", initialFlag);
		return;
	}
	switch (order)		// ���� ���
	{
	case 'e':
		printf("  û�� �÷�\n");
		break;
	case 'd':
		printf("  û�� ����\n");
		break;
	case 'i':
		printf("  ��� �÷�\n");
		break;
	case 'k' :
		printf("  ��� ����\n");
		break;
	default :
		printf("  û�� �ø�����\n");
	}
}

// ������� �Է��� �Ű������� ���� �޾� ȭ�鿡 �˸��� ��� ���¸� ����Ѵ�
void showFlag(char input, int initialFlag)
{
	if (initialFlag)	// ī��Ʈ�ٿ�� ��븸 ���
	{
		printf("\n\n\n\n\n");	// ����
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("����������������    ����������������\n");
		printf("\n\n\n\n\n");	// ����
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	// �� �ʱ�ȭ
		return;
	}
	
	int i, j, k;
	switch (input)
	{
	case 'e':	// û�� �÷�
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		for (i = 1; i <= 5; i++)	// ��� ���
		{
			for (j = 1; j <= 8; j++)
			{
				printf("��");
			}
			printf("\n");
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("����������������    ����������������\n");	// ���
		printf("\n\n\n\n\n");	// ����
		break;
	case 'd':	// û�� ����
		printf("\n\n\n\n\n");	// ����
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("����������������    ����������������\n");	// ���
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		for (i = 1; i <= 5; i++)	// ��� ���
		{
			for (j = 1; j <= 8; j++)
			{
				printf("��");
			}
			printf("\n");
		}
		break;
	case 'i':	// ��� �÷�
		for (i = 1; i <= 5; i++)	// ��� ���
		{
			for (k = 1; k <= 48; k++)	//�� ��� �պκ� ���� ���
				printf(" ");
			for (j = 1; j <= 8; j++)
			{
				printf("��");
			}
			printf("\n");
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("����������������    ����������������\n");	// ���
		printf("\n\n\n\n\n");	// ����
		break;
	case 'k':	// ��� ����
		printf("\n\n\n\n\n");	// ����
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("����������������    ����������������\n");	// ���
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		for (i = 1; i <= 5; i++)	// ��� ���
		{
			for (k = 1; k <= 48; k++)	//�� ��� �պκ� ���� ���
				printf(" ");
			for (j = 1; j <= 8; j++)
			{
				printf("��");
			}
			printf("\n");
		}
		break;
	default :	// ��븸 ���
		printf("\n\n\n\n\n");	// ����
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("����������������    ����������������\n");	// ���
		printf("\n\n\n\n\n");	// ����
		break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	// �� �ʱ�ȭ
}

// ����ڰ� 1�� �̳��� 'e', 'd', 'i', 'k' Ű�� �Է��ϸ� �Է��� Ű�� ��ȯ�ϰ�, �׷��� ������ ' '�� ��ȯ�Ѵ�
char getUserKey(void)
{
	char input;
	clock_t time;
	time = clock();					// ���� �ð� �Է�
	while (clock() - time <= 1000)	// �ð��� 1�ʺ��� �� �����ٸ�
	{
		if (_kbhit())				// Ű���� �Է��� �ִٸ�
		{
			input = _getch();		
			return input;			// �Է��� Ű ��ȯ
		}
	}
	return ' ';						// 1�ʰ� ������ ���� ��ȯ
}

// ���û���, ���� �Է� Ű, ���� �ð��� �Ű������� ���� �޾� ���� ��Ȳ�� ��ȯ�Ѵ�
int judge(char order, char input, int leftTime, int initialFlag)
{
	if (initialFlag)		// ī��Ʈ�ٿ�� ��� ����
		return 0;

	switch (order)			// order�� �������� �Ǵ�
	{
	case ' ':				// û�� �ø������� ���
		if (leftTime)		// ���� �ð��� ������
		{
			switch (input)
			{
			case ' ':	
				return 0;	// �Է��� ���� ������ ���
			default : 
				return 1;	// �Է��� ������ ����
			}
		}
		else				// ���� �ð��� ������
		{
			return 2;		// �Է��� �����Ƿ� ����
		}
	default :				// �ٸ� ��ߵ��� ���
		if (leftTime)		// ���� �ð��� ������
		{
			if (input == ' ')
				return 0;	// �Է��� ������ ���
			else if (input == order)
				return 2;	// �Է°� ���û��°� ������ ����
			else
				return 1;	// �Է°� ���û��°� �ٸ��� ����
		}
		else				// ���� �ð��� ������
		{
			return 3;		// �Է��� �����Ƿ� �ð��ʰ�
		}
	}
}

// judge �Լ����� ���ڷ� ��ȯ�� ���� ��Ȳ�� �Ű������� ���� �޾� �˸��� ������ ȭ�鿡 ����Ѵ�
void situationCheck(int situation)
{
	switch (situation)
	{
	case 1:
		printf("  Ʋ�Ƚ��ϴ�!!\n");
		break;
	case 2:
		printf("  �����Դϴ�!!\n");
		break;
	case 3:
		printf("  �ð� �ʰ�!!\n");
		break;
	default :
		break;		// ��� �����ϴ� ����̹Ƿ� ��� ���� ��Ż
	}
}

// ���̵��� �Ű������� ���� �޾� ���� ���� �� ������ ��ȯ�Ѵ�
int startGame(int level)
{
	// ���� ����
	int score = 0, life = 5, elapsedTime = 0, limitTime, initialFlag = 3, judgeFlag, leftTime;	// ���� �� �ʱⰪ ����
	char order = ' ', input = ' ';		// �ʱⰪ ����
	clock_t currentTime;

	limitTime = 4 - level;

	// ī��Ʈ�ٿ� ���
	for (initialFlag; initialFlag >= 1; initialFlag--)
	{
		display(level, life, score, elapsedTime, limitTime, order, input, initialFlag);
		Sleep(1000);
	}


	// �� ���� ����
	while (life)	// ������ ���� �����ñ��� ���� ����
	{
		elapsedTime = 0;				// ����� �ð� �ʱ�ȭ
		order = getInstruction();		// ���ο� ���� ����
		display(level, life, score, elapsedTime, limitTime, order, input = ' ', initialFlag);	// �ʱ� ���� ���
		elapsedTime = 1;	// 1�� �߰�
		// display ��� ����
		while (elapsedTime <= limitTime)	// ���ѽð����� �ð��� �� �����ٸ�
		{
			input = getUserKey();
			
			switch (input)		// input�� �������� score�� life ����
			{
			case ' ':		// �Է��� ������
				leftTime = limitTime - elapsedTime;		// ���� �ð� ����
				judgeFlag = judge(order, input, leftTime, initialFlag);	// judgeFlag�� ��Ȳ ����
				switch (judgeFlag)
				{
				case 2:		// ���� 
					score++;
					break;
				case 3:		// �ð��ʰ�
					life--;
					break;
				}
				display(level, life, score, elapsedTime, limitTime, order, input, initialFlag);	// ȭ�� ���
				elapsedTime++;	//����ð� ����
				continue;		// switch(input) �����
			default :		// �Է��� ������ 
				elapsedTime--;	
				leftTime = limitTime - elapsedTime;
				judgeFlag = judge(order, input, leftTime, initialFlag);	// judgeFlag�� ��Ȳ ����
				switch (judgeFlag)
				{
				case 2:
					score++;	// ����
					break;
				case 1:
					life--;		// ����
					break;
				}
				display(level, life, score, elapsedTime, limitTime, order, input, initialFlag);	// ȭ�� ���
				break;	// �Է��� �־����Ƿ� ��Ż
			}
			break;	// �Է��� �־ ��Ż�� ��� ��� ��� �� ��Ż
		}
		Sleep(2000);		// 2�ʰ� ����
	}
	return score;	// life ���� ���� �� ���� ��ȯ
}

// ������ �Ű������� ���� �޾� ���� ���� ������ ����Ѵ�
void gameOver(int score)
{
	Sleep(1000);
	system("cls");
	printf("\n  GAME OVER\n");
	printf("  %d ������ �������ϴ�.\n\n", score);
}