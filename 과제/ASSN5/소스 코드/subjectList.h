#ifndef __SUBJECTLIST_H
#define __SUBJECTLIST_H

typedef struct subject
{
	char sub_code[8];
	char sub_name[41];
	int credit;
	struct subject *next;
} SUBJECT;

typedef struct
{
	int count;
	SUBJECT *top;
}LIST;


void addList(LIST *list, char sub_code[], char sub_name[], int credit);
void showList(LIST list);
int codeCheck(LIST list, char sub_code[]);
void delSubject(LIST *list, char sub_code[]);
void delList(LIST *list);
void printList(FILE *outfile, LIST list);

#endif