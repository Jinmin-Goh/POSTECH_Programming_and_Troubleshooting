#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char title[30];
	char artist[20];
	int time_min, time_sec;
	int qual;
} SONG;

typedef struct node {
	SONG data;
	struct node *next;
}NODE;


typedef struct{
	int count;
	NODE *head;
	NODE *tail;
}LIST;


void add_song(SONG *list);
void print_songs(LIST *plist);
void init_list(LIST *plist);
void insert_node(LIST *plist);
void select_songs(LIST *plist, int num);

int main()
{
	LIST list;
	NODE *head = NULL;
	char cmd[10];
	int num;

	init_list(&list);

	while (1)
	{
		printf(">> ");
		scanf("%s", cmd);
		getchar();

		if (strcmp(cmd, "add") == 0)
			insert_node(&list);
		if (strcmp(cmd, "print") == 0)
			print_songs(&list);
		if (strcmp(cmd, "quit") == 0)
			break;
		if (strcmp(cmd, "select") == 0)
		{
			printf("Input track number: ");
			scanf("%d", &num);
			select_songs(&list, num);
		}

	}

	return 0;
}

void add_song(SONG* list)
{
	printf("\nTITLE   : ");
	fgets(list->title, 30, stdin);
	//getchar();

	printf("ARTIST  : ");
	fgets(list->artist, 30, stdin);
	//getchar();

	printf("TIME    : ");
	scanf("%d%d", &list->time_min, &list->time_sec);

	printf("QUALITY : ");
	scanf("%d", &list->qual);
	printf("\n");
}

void print_songs(LIST *plist)
{
	int i = 0;
	NODE *t;
	for (t = plist->head; t != NULL; t = t->next, i++)
	{
		printf("\nNo. %d\n", i + 1);
		printf("Title   : %s", t->data.title);
		printf("ARTIST  : %s", t->data.artist);
		printf("TIME    : %dmin %dsec\n", t->data.time_min, t->data.time_sec);
		printf("QUALITY : %dkbps\n\n", t->data.qual);
	}
}

void init_list(LIST *plist)
{
	plist->count = 0;
	plist->head = NULL;
	plist->tail = NULL;
}

void insert_node(LIST *plist)
{
	NODE *t;
	t = (NODE*)malloc(sizeof(NODE));
	t->next = NULL;
	add_song(&t->data);
	
	if (plist->count == 0 || plist->head == NULL)
	{
		plist->head = t;
	}
	else
	{
		plist->tail->next = t;
	}
	plist->tail = t;
	plist->count++;
}

void select_songs(LIST *plist, int num)
{
	NODE *t;
	int i = 1;
	for (t = plist->head; t != NULL; t = t->next, i++)
	{
		if (i == num)
			break;
	}
	printf("\nNo. %d\n", i);
	printf("Title   : %s", t->data.title);
	printf("ARTIST  : %s", t->data.artist);
	printf("TIME    : %dmin %dsec\n", t->data.time_min, t->data.time_sec);
	printf("QUALITY : %dkbps\n\n", t->data.qual);
}