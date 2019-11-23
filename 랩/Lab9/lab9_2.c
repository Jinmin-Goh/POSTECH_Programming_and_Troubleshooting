#include <stdio.h>

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
	int opt, songNum = 0;
	int flag = 1;

	while (flag)
	{
		printf("1. Add song\n");
		printf("2. Print songs\n");
		printf("3. Quit\n");
		printf(">> ");
		scanf("%d", &opt);
		getchar();

		switch (opt)
		{
		case 1:	//add
			add_song(list, &songNum);
			break;
		case 2:	//print
			print_songs(list, songNum);
			break;
		case 3:	//quit
			flag--;
			break;
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