#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

// 사용자 정의 함수
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

// main 함수
int main()
{
	// 변수 정의 영역
	int menuNum, level, score = 0, life = 5, elapsedTime, limitTime, maxScore = 0;
	char endGame, order, input;

	menuNum = showMenu();	// 메뉴 숫자 입력
	
	// 메뉴 기능 수행
	while (1)
	{
		switch (menuNum)
		{
			case 1:			// 게임 함수 입력
				level = levelSetting();
				// 레벨 입력 검사
				while (1)	
				{
					switch (level)
					{
					case 1:
					case 2:
					case 3:
						score = startGame(level);
						gameOver(score);
						if (score > maxScore)	// 최고점수 저장
							maxScore = score;
						menuNum = showMenu();	// 게임 종료 후 처음화면으로 이동
						break;
					default:		// 잘못된 입력
						level = levelSetting();
						continue;
					}
					break;
				}
				continue;
			case 2:			// 점수 확인 입력
				printf("\n  최고점수는 %d점 입니다!\n\n", maxScore);
				menuNum = showMenu();
				continue;
			case 3:			// 종료 판단
				printf("\n  게임을 종료하시겠습니까? (y/n) : ");
				scanf(" %c", &endGame);
				if (endGame == 'n' || endGame == 'N')
				{
					printf("\n");
					menuNum = showMenu();
					continue;
				}
				else
					return 0;
			default :		// 잘못된 입력
				printf("\n  잘못된 값을 입력하셨습니다. 다시 입력해 주세요.\n\n");
				menuNum = showMenu();
				continue;
		}
		break;
	}
}

// 64개의 ‘=’을 출력한다
void drawLine(void)
{
	int i;
	for (i=1; i<=64; i++)
	printf("=");
	printf("\n");
	return;
}

// 초기 메뉴 화면을 출력하고, 사용자로부터 메뉴 번호를 입력 받아 반환한다
int showMenu(void)
{
	drawLine();
	printf("  청기 백기 게임\n");
	drawLine();
	printf("  1. 게임 시작\n  2. 최고 점수 확인\n  3. 게임 종료\n");
	drawLine();
	printf("  번호 입력 : ");
	int menuNum;
	scanf("%d", &menuNum);	// 번호 입력
	return menuNum;			// 번호 반환
}

// 사용자로부터 범위 내의 난이도를 입력 받고, 입력 받은 난이도를 반환한다
int levelSetting(void)
{
	int level;
	printf("  난이도 선택(1~3) : ");
	scanf("%d",&level);
	return level;
}

// Level, Life, Score, 진행시간, 제한시간, 지시상태, 유저 입력 키 등을매개변수로 전달받아 출력한다.
void display(int level, int life, int score, int elapsedTime, int limitTime, char order, char input, int initialFlag)
{
	int leftTime, situation;
	leftTime = limitTime - elapsedTime;
	system("cls");	// 화면 지우기
	drawLine();							
	showState(level, score, life);					// 첫째줄 : 게임 진행 상황 표시
	drawLine();							
	showTime(elapsedTime, limitTime, initialFlag);	// 둘째줄 : 시간 표시
	drawLine();
	showInstruction(order, initialFlag);			// 셋째줄 : 지시 사항 표시
	drawLine();
	showFlag(input, initialFlag);					// 넷째줄 : 깃발 표시
	drawLine();
	situation = judge(order, input, leftTime, initialFlag);
	situationCheck(situation);						// 다섯째줄 : 행동 결과 표시
}

// Level, Score, Life를 매개변수로 전달 받아 화면에 이를 출력한다
void showState(int level, int score, int life)
{
	int usedLife;
	usedLife = 5 - life;	// 소모한 life
	printf("  LEVEL : %d     SCORE : %d       LIFE : ", level, score);		// 상태 출력
	for (life; life >= 1; life--)					// life에 따른 꽉 찬 하트 출력
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("♥");
	}
	for (usedLife; usedLife >= 1; usedLife--)		// 비어있는 하트 출력
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("♡");
	}
	printf("\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	// 색 초기화
}

// 진행시간, 제한시간을 매개변수로 전달 받아 화면에 알맞은 개수의 ■를 출력한다.
void showTime(int elapsedTime, int limitTime, int initialFlag)
{
	int square;		// 출력될 네모의 수
	
	if (initialFlag)	// 카운트다운 시간 표시
	{
		square = 10 * initialFlag;
		printf("  ");
		for (square; square >= 1; square--)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			printf("■");
		}
		printf("\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	// 색 초기화
		return;
	}
	square = 30 - 30 / limitTime * elapsedTime;		// 출력될 네모의 개수 계산
	printf("  ");
	for (square; square >= 1; square--)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("■");
	}
	printf("\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	// 색 초기화
}

// Random 함수를 이용해 'e', 'd', 'i', 'k', ' ' 중 하나를 반환한다
char getInstruction(void)
{
	srand((int)time(NULL));
	int inst = rand() % 5;	// 0~4의 정수만 나오게 설정
	switch (inst)
	{
	case 0:
		return 'e';		// 청기 올려
	case 1:
		return 'd';		// 청기 내려
	case 2:
		return 'i';		// 백기 올려
	case 3 :
		return 'k';		// 백기 내려
	default:
		return ' ';		// 청기 올리지마
	}
}

// 지시 상태를 매개변수로 전달 받아 화면에 알맞은 지시를 출력한다
void showInstruction(char order, int initialFlag)
{
	if (initialFlag)	// 카운트다운 영역
	{
		printf("  %d초 후 시작합니다\n", initialFlag);
		return;
	}
	switch (order)		// 지시 출력
	{
	case 'e':
		printf("  청기 올려\n");
		break;
	case 'd':
		printf("  청기 내려\n");
		break;
	case 'i':
		printf("  백기 올려\n");
		break;
	case 'k' :
		printf("  백기 내려\n");
		break;
	default :
		printf("  청기 올리지마\n");
	}
}

// 사용자의 입력을 매개변수로 전달 받아 화면에 알맞은 깃발 상태를 출력한다
void showFlag(char input, int initialFlag)
{
	if (initialFlag)	// 카운트다운시 깃대만 출력
	{
		printf("\n\n\n\n\n");	// 공백
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("■■■■■■■■■■■■■■■    ■■■■■■■■■■■■■■■\n");
		printf("\n\n\n\n\n");	// 공백
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	// 색 초기화
		return;
	}
	
	int i, j, k;
	switch (input)
	{
	case 'e':	// 청기 올려
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		for (i = 1; i <= 5; i++)	// 깃발 출력
		{
			for (j = 1; j <= 8; j++)
			{
				printf("■");
			}
			printf("\n");
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("■■■■■■■■■■■■■■■    ■■■■■■■■■■■■■■■\n");	// 깃대
		printf("\n\n\n\n\n");	// 공백
		break;
	case 'd':	// 청기 내려
		printf("\n\n\n\n\n");	// 공백
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("■■■■■■■■■■■■■■■    ■■■■■■■■■■■■■■■\n");	// 깃대
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		for (i = 1; i <= 5; i++)	// 깃발 출력
		{
			for (j = 1; j <= 8; j++)
			{
				printf("■");
			}
			printf("\n");
		}
		break;
	case 'i':	// 백기 올려
		for (i = 1; i <= 5; i++)	// 깃발 출력
		{
			for (k = 1; k <= 48; k++)	//흰 깃발 앞부분 공백 출력
				printf(" ");
			for (j = 1; j <= 8; j++)
			{
				printf("■");
			}
			printf("\n");
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("■■■■■■■■■■■■■■■    ■■■■■■■■■■■■■■■\n");	// 깃대
		printf("\n\n\n\n\n");	// 공백
		break;
	case 'k':	// 백기 내려
		printf("\n\n\n\n\n");	// 공백
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("■■■■■■■■■■■■■■■    ■■■■■■■■■■■■■■■\n");	// 깃대
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		for (i = 1; i <= 5; i++)	// 깃발 출력
		{
			for (k = 1; k <= 48; k++)	//흰 깃발 앞부분 공백 출력
				printf(" ");
			for (j = 1; j <= 8; j++)
			{
				printf("■");
			}
			printf("\n");
		}
		break;
	default :	// 깃대만 출력
		printf("\n\n\n\n\n");	// 공백
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("■■■■■■■■■■■■■■■    ■■■■■■■■■■■■■■■\n");	// 깃대
		printf("\n\n\n\n\n");	// 공백
		break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	// 색 초기화
}

// 사용자가 1초 이내에 'e', 'd', 'i', 'k' 키를 입력하면 입력한 키를 반환하고, 그렇지 않으면 ' '를 반환한다
char getUserKey(void)
{
	char input;
	clock_t time;
	time = clock();					// 기준 시간 입력
	while (clock() - time <= 1000)	// 시간이 1초보다 덜 지났다면
	{
		if (_kbhit())				// 키보드 입력이 있다면
		{
			input = _getch();		
			return input;			// 입력한 키 반환
		}
	}
	return ' ';						// 1초가 지나면 공백 반환
}

// 지시상태, 유저 입력 키, 남은 시간을 매개변수로 전달 받아 게임 상황을 반환한다
int judge(char order, char input, int leftTime, int initialFlag)
{
	if (initialFlag)		// 카운트다운시 계속 진행
		return 0;

	switch (order)			// order를 기준으로 판단
	{
	case ' ':				// 청기 올리지마의 경우
		if (leftTime)		// 남은 시간이 있으면
		{
			switch (input)
			{
			case ' ':	
				return 0;	// 입력을 하지 않으면 계속
			default : 
				return 1;	// 입력이 있으면 오답
			}
		}
		else				// 남은 시간이 없으면
		{
			return 2;		// 입력이 없으므로 정답
		}
	default :				// 다른 깃발들의 경우
		if (leftTime)		// 남은 시간이 있으면
		{
			if (input == ' ')
				return 0;	// 입력이 없으면 계속
			else if (input == order)
				return 2;	// 입력과 지시상태가 같으면 정답
			else
				return 1;	// 입력과 지시상태가 다르면 오답
		}
		else				// 남은 시간이 없으면
		{
			return 3;		// 입력이 없으므로 시간초과
		}
	}
}

// judge 함수에서 숫자로 반환된 게임 상황을 매개변수로 전달 받아 알맞은 문구를 화면에 출력한다
void situationCheck(int situation)
{
	switch (situation)
	{
	case 1:
		printf("  틀렸습니다!!\n");
		break;
	case 2:
		printf("  정답입니다!!\n");
		break;
	case 3:
		printf("  시간 초과!!\n");
		break;
	default :
		break;		// 계속 진행하는 경우이므로 출력 없이 이탈
	}
}

// 난이도를 매개변수로 전달 받아 게임 진행 후 점수를 반환한다
int startGame(int level)
{
	// 변수 정의
	int score = 0, life = 5, elapsedTime = 0, limitTime, initialFlag = 3, judgeFlag, leftTime;	// 변수 및 초기값 지정
	char order = ' ', input = ' ';		// 초기값 지정
	clock_t currentTime;

	limitTime = 4 - level;

	// 카운트다운 출력
	for (initialFlag; initialFlag >= 1; initialFlag--)
	{
		display(level, life, score, elapsedTime, limitTime, order, input, initialFlag);
		Sleep(1000);
	}


	// 본 게임 시작
	while (life)	// 라이프 전부 소진시까지 게임 진행
	{
		elapsedTime = 0;				// 경과된 시간 초기화
		order = getInstruction();		// 새로운 지시 지정
		display(level, life, score, elapsedTime, limitTime, order, input = ' ', initialFlag);	// 초기 지시 출력
		elapsedTime = 1;	// 1초 추가
		// display 출력 루프
		while (elapsedTime <= limitTime)	// 제한시간보다 시간이 덜 지났다면
		{
			input = getUserKey();
			
			switch (input)		// input을 기준으로 score와 life 변경
			{
			case ' ':		// 입력이 없으면
				leftTime = limitTime - elapsedTime;		// 남은 시간 설정
				judgeFlag = judge(order, input, leftTime, initialFlag);	// judgeFlag에 상황 저장
				switch (judgeFlag)
				{
				case 2:		// 정답 
					score++;
					break;
				case 3:		// 시간초과
					life--;
					break;
				}
				display(level, life, score, elapsedTime, limitTime, order, input, initialFlag);	// 화면 출력
				elapsedTime++;	//경과시간 증가
				continue;		// switch(input) 재시작
			default :		// 입력이 있으면 
				elapsedTime--;	
				leftTime = limitTime - elapsedTime;
				judgeFlag = judge(order, input, leftTime, initialFlag);	// judgeFlag에 상황 저장
				switch (judgeFlag)
				{
				case 2:
					score++;	// 정답
					break;
				case 1:
					life--;		// 오답
					break;
				}
				display(level, life, score, elapsedTime, limitTime, order, input, initialFlag);	// 화면 출력
				break;	// 입력이 있었으므로 이탈
			}
			break;	// 입력이 있어서 이탈한 경우 결과 출력 후 이탈
		}
		Sleep(2000);		// 2초간 정지
	}
	return score;	// life 전부 소진 후 점수 반환
}

// 점수를 매개변수로 전달 받아 게임 오버 문구를 출력한다
void gameOver(int score)
{
	Sleep(1000);
	system("cls");
	printf("\n  GAME OVER\n");
	printf("  %d 점으로 끝났습니다.\n\n", score);
}