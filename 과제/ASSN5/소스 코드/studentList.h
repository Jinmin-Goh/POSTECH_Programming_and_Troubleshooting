#ifndef __STUDENTLIST_H
#define __STUDENTLIST_H

typedef struct
{
	char sub_code[8];
	char grade[3];
}TAKING_SUBJECTS;

typedef struct student
{
	int id;
	char name[11];
	char dept[7];
	int level;
	int sub_num;
	TAKING_SUBJECTS subjects[8];
	struct student *next;
}STUDENT;

typedef struct
{
	int count;
	STUDENT *top;
	STUDENT *end;
}STDLIST;

void addStudentList(STDLIST *studentList, int id, char name[], char dept[], int level);
void printStudentGrade(LIST subjectList, STDLIST studentList);
void printSubjectGrade(LIST subjectList, STDLIST studentList);
void delStdList(STDLIST *studentList);
#endif