#include <stdio.h>
#include <stdlib.h>

// POSITION 자료형 정의
typedef struct {
	int row; // x 좌표
	int col; // y 좌표
	char dir; // 이동 방향 정보
}POSITION;

// 사용자 지정 함수
void print_map(FILE* outfile, char** map, int map_row, int map_col);	// map 출력용 함수
char getCommand();	// 이동 명령을 입력받아 반환
void checkMap(char** map, int map_row, int map_col, char cmd, POSITION** wolves, POSITION** flowers, POSITION* sheep, 
	int* wolfNum, int* flowerNum, int wolfNum_S, int flowerNum_S);	// 명령을 받아 다음에 벌어지는 상황을 체크
void makeMap(char** map, int map_row, int map_col, POSITION* wolves, POSITION* flowers, POSITION sheep, int wolfNum, int flowerNum);	// map을 만드는 함수

// main 함수
int main()
{
	// 변수 선언 영역
	FILE *outfile, *mapfile;
	char outfileName[11], mapfileName[11], **map, info[8], cmd;
	int flag = 0, map_row, map_col, wolfNum, flowerNum, wolfNum_S, flowerNum_S, i, life = 5;
	POSITION *wolves, *flowers, sheep;
	

	printf("Input the out file name: ");
	scanf("%s", outfileName);
	printf("Input the map file name: ");
	scanf("%s", mapfileName);
	
	if ((mapfile = fopen(mapfileName, "r")) == NULL)		// 잘못된 입력
	{
		printf("Could not open %s file\n", mapfileName);
		exit (100);
	}
	outfile = fopen(outfileName, "w");
	
	// map 파일 정보 입력받기
	while (1)
	{
		flag = fscanf(mapfile, "%s", info);
		if (flag == EOF)			// 파일의 끝
			break;
		if (info[1] == 'M')			// #MAP
			fscanf(mapfile, "%d %d", &map_row, &map_col);
		else if (info[1] == 'W')	// #WOLF
		{
			fscanf(mapfile, "%d", &wolfNum);
			wolves = (POSITION*)calloc(wolfNum, sizeof(POSITION));
			for (i = 0; i < wolfNum; i++)
				fscanf(mapfile, "%d %d %c", &wolves[i].row, &wolves[i].col, &wolves[i].dir);
		}
		else if (info[1] == 'F')	// #FLOWER
		{
			fscanf(mapfile, "%d", &flowerNum);
			flowers = (POSITION*)calloc(flowerNum, sizeof(POSITION));
			for (i = 0; i < flowerNum; i++)
			{
				fscanf(mapfile, "%d %d", &flowers[i].row, &flowers[i].col);
				flowers[i].dir = 'F';
			}
		}
	}
	// 양 초기 위치 작성
	sheep.col = 0;
	sheep.row = 0;
	sheep.dir = 'S';

	wolfNum_S = wolfNum;
	flowerNum_S = flowerNum;

	// map 사이즈 동적할당
	map = (char**)calloc(map_row, sizeof(char*));
	for (i = 0; i < map_row; i++)
		*(map + i) = (char*)calloc(map_col, sizeof(char));

	// 게임 진행 루프
	while (1)
	{
		system("cls");	// 화면 지움
		makeMap(map, map_row, map_col, wolves, flowers, sheep, wolfNum_S, flowerNum_S);	// map 생성
		printf("LIFE: %d\nFLOWER: %d\n", life, flowerNum);	// 정보 출력
		print_map(outfile, map, map_row, map_col);	// map 출력

		// life 확인 및 게임 오버 - 사망
		if (!life)
		{
			printf("You are dead.\n");
			break;
		}

		// 게임오버 - 성공
		if (flowerNum == 0 && sheep.col == (map_col - 1) && sheep.row == (map_row - 1))
		{
			printf("Congratulations! You made it!\n");
			break;
		}

		// 커맨드 입력
		printf("input the command: ");
		cmd = getCommand();
		checkMap(map, map_row, map_col, cmd, &wolves, &flowers, &sheep, &wolfNum, &flowerNum, wolfNum_S, flowerNum_S);

		// 늑대와 만나는 경우 판단
		for (i = 0; i < wolfNum_S; i++)
		{
			if (((wolves[i].dir == 'L') || (wolves[i].dir == 'R')) && (wolves[i].col == sheep.col) && (wolves[i].row == sheep.row))
			{
				life--;
				wolves[i].dir = 'X';	// 방향 정보를 바꿔서 map에서 출력되지 않도록 조절
			}
		}
	}

	// 할당된 메모리 해제
	free(wolves);
	free(flowers);
	free(map);
	return 0;
}

void print_map(FILE* outfile, char** map, int map_row, int map_col)		// map 출력용 함수
{
	int i, j;
	for (i = 0; i < map_row; i++) {
		for (j = 0; j < map_col; j++) {
			printf("%c ", map[i][j]);
			fprintf(outfile, "%c ", map[i][j]);
		}
		printf("\n");
		fprintf(outfile, "\n");
	}
	fprintf(outfile, "\n");
}

char getCommand()	// 이동 명령을 입력받아 반환
{
	char cmd;
	scanf(" %c", &cmd);
	return cmd;
}

void checkMap(char** map, int map_row, int map_col, char cmd, POSITION** wolves, POSITION** flowers, POSITION* sheep, 
	int* wolfNum, int* flowerNum, int wolfNum_S, int flowerNum_S)	// 명령을 받아 다음에 벌어지는 상황을 체크
{
	int i = 0, j = 0, flowerFlag = 0;

	// 양이 먼저 움직인다
	switch (cmd)
	{
	case 'w':
		if ((*sheep).row == 0)
			break;
		else
		{
			((*sheep).row)--;
			for (i = 0; i < flowerNum_S; i++)
			{
				if (((*flowers)[i].dir == 'F') && ((*sheep).row == (*flowers)[i].row) && ((*sheep).col == (*flowers)[i].col))
				{
					(*flowerNum)--;
					(*flowers)[i].dir = 'G';	// G는 먹힌 꽃으로 makeMap 파일에서 무시된다.
				}
			}
		}
		break;
	case 's':
		if ((*sheep).row == (map_row - 1))
			break;
		else
		{
			(*sheep).row++;
			for (i = 0; i < flowerNum_S; i++)
			{
				if (((*flowers)[i].dir == 'F') && ((*sheep).row == (*flowers)[i].row) && ((*sheep).col == (*flowers)[i].col))
				{
					(*flowerNum)--;
					(*flowers)[i].dir = 'G';	// G는 먹힌 꽃으로 makeMap 파일에서 무시된다.
				}
			}
		}
		break;
	case 'a':
		if ((*sheep).col == 0)
			break;
		else
		{
			((*sheep).col)--;
			for (i = 0; i < flowerNum_S; i++)
			{
				if (((*flowers)[i].dir == 'F') && ((*sheep).row == (*flowers)[i].row) && ((*sheep).col == (*flowers)[i].col))
				{
					(*flowerNum)--;
					(*flowers)[i].dir = 'G';	// G는 먹힌 꽃으로 makeMap 파일에서 무시된다.
				}
			}
		}
		break;
	case 'd':
		if ((*sheep).col == (map_col - 1))
			break;
		else
		{
			((*sheep).col)++;
			for (i = 0; i < flowerNum_S; i++)
			{
				if (((*flowers)[i].dir == 'F') && ((*sheep).row == (*flowers)[i].row) && ((*sheep).col == (*flowers)[i].col))
				{
					(*flowerNum)--;
					(*flowers)[i].dir = 'G';	// G는 먹힌 꽃으로 makeMap 파일에서 무시된다.
				}
			}
		}
		break;
	default:		// 잘못된 커맨드

		break;
	}

	// 이후 늑대가 움직인다
	for (i = 0; i < wolfNum_S; i++)
	{
		for (j = flowerFlag; j <= flowerNum_S; j++)
		{
			if ((*wolves)[i].row == (*flowers)[j].row)
				flowerFlag++;	// 한 번 영향을 미친 꽃 다음부터 시작하기 위함
			if ((*wolves)[i].dir == 'L')	// 늑대가 왼쪽으로 움직이는 경우
			{
				if ((*wolves)[i].col == 0)	// 늑대가 왼쪽 끝일때
				{
					if (((*flowers)[j].dir == 'F') && ((map_col - 1) == (*flowers)[j].col) && ((*wolves)[i].row == (*flowers)[j].row))	// 꽃이 오른쪽 끝에 있으면
					{
						(*wolves)[i].dir = 'R';	// 제자리에서 방향을 바꾼다.
						break;
					}
					else									// 꽃이 없으면
					{
						(*wolves)[i].col = map_col - 1;		// 건너편으로 이동
						break;
					}
				}
				else						// 늑대가 왼쪽 끝이 아닌 경우
				{
					if (((*flowers)[j].dir == 'F') && (((*wolves)[i].col - 1) == (*flowers)[j].col) && ((*wolves)[i].row == (*flowers)[j].row))	// 늑대의 왼쪽에 꽃이 있으면
					{
						(*wolves)[i].dir = 'R';	// 제자리에서 방향을 바꾼다.
						break;
					}
					else						// 꽃이 없으면
					{
						(*wolves)[i].col--;		// 왼쪽으로 이동
						break;
					}
				}
			}
			else if ((*wolves)[i].dir == 'R')	// 늑대가 오른쪽으로 움직이는 경우
			{
				if ((*wolves)[i].col == (map_col - 1))	// 늑대가 오른쪽 끝인 경우
				{
					if (((*flowers)[j].dir == 'F') && (0 == (*flowers)[j].col) && ((*wolves)[i].row == (*flowers)[j].row))	// 꽃이 왼쪽 끝에 있으면
					{
						(*wolves)[i].dir = 'L';													// 방향을 바꾼다.
						break;
					}
					else						// 꽃이 없으면
					{
						(*wolves)[i].col = 0;	// 건너편으로 이동
						break;
					}
				}
				else						// 늑대가 오른쪽 끝이 아닌 경우
				{
					if (((*flowers)[j].dir == 'F') && (((*wolves)[i].col + 1) == (*flowers)[j].col) && ((*wolves)[i].row == (*flowers)[j].row))	// 꽃이 늑대의 오른쪽에 있으면
					{
						(*wolves)[i].dir = 'L';																		// 방향을 바꾼다.
						break;
					}
					else						// 꽃이 없으면
					{
						(*wolves)[i].col++;		// 오른쪽으로 이동
						break;
					}
				}
			}
		}
	}

	return;
}

void makeMap(char** map, int map_row, int map_col, POSITION* wolves, POSITION* flowers, POSITION sheep, int wolfNum, int flowerNum)	// map을 만드는 함수
{
	int i, j;
	
	// map 초기화
	for (i = 0; i < map_row; i++)
		for (j = 0; j < map_col; j++)
			map[i][j] = '.';

	for (i = 0; i < wolfNum; i++)	// wolf 배당
	{
		if (wolves[i].dir == 'R')
			map[wolves[i].row][wolves[i].col] = '>';
		else if (wolves[i].dir == 'L')
			map[wolves[i].row][wolves[i].col] = '<';
	}
	
	for (i = 0; i < flowerNum; i++)	// flower 배당
	{
		if (flowers[i].dir == 'F')	// 먹지 않은 꽃
			map[flowers[i].row][flowers[i].col] = '*';
	}

	// 양 위치 배당
	map[sheep.row][sheep.col] = '@';
	return;
}