#include <stdio.h>
#include <stdlib.h>

// POSITION �ڷ��� ����
typedef struct {
	int row; // x ��ǥ
	int col; // y ��ǥ
	char dir; // �̵� ���� ����
}POSITION;

// ����� ���� �Լ�
void print_map(FILE* outfile, char** map, int map_row, int map_col);	// map ��¿� �Լ�
char getCommand();	// �̵� ����� �Է¹޾� ��ȯ
void checkMap(char** map, int map_row, int map_col, char cmd, POSITION** wolves, POSITION** flowers, POSITION* sheep, 
	int* wolfNum, int* flowerNum, int wolfNum_S, int flowerNum_S);	// ����� �޾� ������ �������� ��Ȳ�� üũ
void makeMap(char** map, int map_row, int map_col, POSITION* wolves, POSITION* flowers, POSITION sheep, int wolfNum, int flowerNum);	// map�� ����� �Լ�

// main �Լ�
int main()
{
	// ���� ���� ����
	FILE *outfile, *mapfile;
	char outfileName[11], mapfileName[11], **map, info[8], cmd;
	int flag = 0, map_row, map_col, wolfNum, flowerNum, wolfNum_S, flowerNum_S, i, life = 5;
	POSITION *wolves, *flowers, sheep;
	

	printf("Input the out file name: ");
	scanf("%s", outfileName);
	printf("Input the map file name: ");
	scanf("%s", mapfileName);
	
	if ((mapfile = fopen(mapfileName, "r")) == NULL)		// �߸��� �Է�
	{
		printf("Could not open %s file\n", mapfileName);
		exit (100);
	}
	outfile = fopen(outfileName, "w");
	
	// map ���� ���� �Է¹ޱ�
	while (1)
	{
		flag = fscanf(mapfile, "%s", info);
		if (flag == EOF)			// ������ ��
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
	// �� �ʱ� ��ġ �ۼ�
	sheep.col = 0;
	sheep.row = 0;
	sheep.dir = 'S';

	wolfNum_S = wolfNum;
	flowerNum_S = flowerNum;

	// map ������ �����Ҵ�
	map = (char**)calloc(map_row, sizeof(char*));
	for (i = 0; i < map_row; i++)
		*(map + i) = (char*)calloc(map_col, sizeof(char));

	// ���� ���� ����
	while (1)
	{
		system("cls");	// ȭ�� ����
		makeMap(map, map_row, map_col, wolves, flowers, sheep, wolfNum_S, flowerNum_S);	// map ����
		printf("LIFE: %d\nFLOWER: %d\n", life, flowerNum);	// ���� ���
		print_map(outfile, map, map_row, map_col);	// map ���

		// life Ȯ�� �� ���� ���� - ���
		if (!life)
		{
			printf("You are dead.\n");
			break;
		}

		// ���ӿ��� - ����
		if (flowerNum == 0 && sheep.col == (map_col - 1) && sheep.row == (map_row - 1))
		{
			printf("Congratulations! You made it!\n");
			break;
		}

		// Ŀ�ǵ� �Է�
		printf("input the command: ");
		cmd = getCommand();
		checkMap(map, map_row, map_col, cmd, &wolves, &flowers, &sheep, &wolfNum, &flowerNum, wolfNum_S, flowerNum_S);

		// ����� ������ ��� �Ǵ�
		for (i = 0; i < wolfNum_S; i++)
		{
			if (((wolves[i].dir == 'L') || (wolves[i].dir == 'R')) && (wolves[i].col == sheep.col) && (wolves[i].row == sheep.row))
			{
				life--;
				wolves[i].dir = 'X';	// ���� ������ �ٲ㼭 map���� ��µ��� �ʵ��� ����
			}
		}
	}

	// �Ҵ�� �޸� ����
	free(wolves);
	free(flowers);
	free(map);
	return 0;
}

void print_map(FILE* outfile, char** map, int map_row, int map_col)		// map ��¿� �Լ�
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

char getCommand()	// �̵� ����� �Է¹޾� ��ȯ
{
	char cmd;
	scanf(" %c", &cmd);
	return cmd;
}

void checkMap(char** map, int map_row, int map_col, char cmd, POSITION** wolves, POSITION** flowers, POSITION* sheep, 
	int* wolfNum, int* flowerNum, int wolfNum_S, int flowerNum_S)	// ����� �޾� ������ �������� ��Ȳ�� üũ
{
	int i = 0, j = 0, flowerFlag = 0;

	// ���� ���� �����δ�
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
					(*flowers)[i].dir = 'G';	// G�� ���� ������ makeMap ���Ͽ��� ���õȴ�.
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
					(*flowers)[i].dir = 'G';	// G�� ���� ������ makeMap ���Ͽ��� ���õȴ�.
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
					(*flowers)[i].dir = 'G';	// G�� ���� ������ makeMap ���Ͽ��� ���õȴ�.
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
					(*flowers)[i].dir = 'G';	// G�� ���� ������ makeMap ���Ͽ��� ���õȴ�.
				}
			}
		}
		break;
	default:		// �߸��� Ŀ�ǵ�

		break;
	}

	// ���� ���밡 �����δ�
	for (i = 0; i < wolfNum_S; i++)
	{
		for (j = flowerFlag; j <= flowerNum_S; j++)
		{
			if ((*wolves)[i].row == (*flowers)[j].row)
				flowerFlag++;	// �� �� ������ ��ģ �� �������� �����ϱ� ����
			if ((*wolves)[i].dir == 'L')	// ���밡 �������� �����̴� ���
			{
				if ((*wolves)[i].col == 0)	// ���밡 ���� ���϶�
				{
					if (((*flowers)[j].dir == 'F') && ((map_col - 1) == (*flowers)[j].col) && ((*wolves)[i].row == (*flowers)[j].row))	// ���� ������ ���� ������
					{
						(*wolves)[i].dir = 'R';	// ���ڸ����� ������ �ٲ۴�.
						break;
					}
					else									// ���� ������
					{
						(*wolves)[i].col = map_col - 1;		// �ǳ������� �̵�
						break;
					}
				}
				else						// ���밡 ���� ���� �ƴ� ���
				{
					if (((*flowers)[j].dir == 'F') && (((*wolves)[i].col - 1) == (*flowers)[j].col) && ((*wolves)[i].row == (*flowers)[j].row))	// ������ ���ʿ� ���� ������
					{
						(*wolves)[i].dir = 'R';	// ���ڸ����� ������ �ٲ۴�.
						break;
					}
					else						// ���� ������
					{
						(*wolves)[i].col--;		// �������� �̵�
						break;
					}
				}
			}
			else if ((*wolves)[i].dir == 'R')	// ���밡 ���������� �����̴� ���
			{
				if ((*wolves)[i].col == (map_col - 1))	// ���밡 ������ ���� ���
				{
					if (((*flowers)[j].dir == 'F') && (0 == (*flowers)[j].col) && ((*wolves)[i].row == (*flowers)[j].row))	// ���� ���� ���� ������
					{
						(*wolves)[i].dir = 'L';													// ������ �ٲ۴�.
						break;
					}
					else						// ���� ������
					{
						(*wolves)[i].col = 0;	// �ǳ������� �̵�
						break;
					}
				}
				else						// ���밡 ������ ���� �ƴ� ���
				{
					if (((*flowers)[j].dir == 'F') && (((*wolves)[i].col + 1) == (*flowers)[j].col) && ((*wolves)[i].row == (*flowers)[j].row))	// ���� ������ �����ʿ� ������
					{
						(*wolves)[i].dir = 'L';																		// ������ �ٲ۴�.
						break;
					}
					else						// ���� ������
					{
						(*wolves)[i].col++;		// ���������� �̵�
						break;
					}
				}
			}
		}
	}

	return;
}

void makeMap(char** map, int map_row, int map_col, POSITION* wolves, POSITION* flowers, POSITION sheep, int wolfNum, int flowerNum)	// map�� ����� �Լ�
{
	int i, j;
	
	// map �ʱ�ȭ
	for (i = 0; i < map_row; i++)
		for (j = 0; j < map_col; j++)
			map[i][j] = '.';

	for (i = 0; i < wolfNum; i++)	// wolf ���
	{
		if (wolves[i].dir == 'R')
			map[wolves[i].row][wolves[i].col] = '>';
		else if (wolves[i].dir == 'L')
			map[wolves[i].row][wolves[i].col] = '<';
	}
	
	for (i = 0; i < flowerNum; i++)	// flower ���
	{
		if (flowers[i].dir == 'F')	// ���� ���� ��
			map[flowers[i].row][flowers[i].col] = '*';
	}

	// �� ��ġ ���
	map[sheep.row][sheep.col] = '@';
	return;
}