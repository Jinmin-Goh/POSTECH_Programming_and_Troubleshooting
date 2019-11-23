#include <stdio.h>
#include <string.h>

typedef struct
{
	char title[30];
	char artist[20];
	int time_min, time_sec;
	int qual;
} SONG;

void add_song(SONG list[], int* psongNum);
void print_songs(SONG list[], int songNum);

int main()
{
	SONG list[10];
	int opt, songNum = 0, num;
	int flag = 1;
	char cmd[10];

	while (flag)
	{
		printf(">> ");
		scanf("%s", cmd);
		getchar();

		if(strcmp(cmd, "add") == 0)
			add_song(list, &songNum);
		if (strcmp(cmd, "print") == 0)
			print_songs(list, songNum);
		if (strcmp(cmd, "quit") == 0)
			break;
		if (strcmp(cmd, "select") == 0)
		{
			printf("Input track number: ");
			scanf("%d", &num);
			printf("\nNo. %d\n", num);
			printf("Title   : %s", list[num - 1].title);
			printf("ARTIST  : %s", list[num - 1].artist);
			printf("TIME    : %dmin %dsec\n", list[num - 1].time_min, list[num - 1].time_sec);
			printf("QUALITY : %dkbps\n\n", list[num - 1].qual);
		}
		
	}

	return 0;
}

void add_song(SONG list[], int* psongNum)
{
	printf("\nTITLE   : ");
	fgets(list[*psongNum].title, 30, stdin);
	//getchar();

	printf("ARTIST  : ");
	fgets(list[*psongNum].artist, 30, stdin);
	//getchar();

	printf("TIME    : ");
	scanf("%d%d", &list[*psongNum].time_min, &list[*psongNum].time_sec);

	printf("QUALITY : ");
	scanf("%d", &list[*psongNum].qual);
	printf("\n");

	(*psongNum)++;
}

void print_songs(SONG list[], int songNum)
{
	int i;
	for (i = 0; i < songNum; i++)
	{
		printf("\nNo. %d\n", i + 1);
		printf("Title   : %s", list[i].title);
		printf("ARTIST  : %s", list[i].artist);
		printf("TIME    : %dmin %dsec\n", list[i].time_min, list[i].time_sec);
		printf("QUALITY : %dkbps\n\n", list[i].qual);
	}
}
