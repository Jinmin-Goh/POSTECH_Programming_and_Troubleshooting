#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "subjectList.h"



int main(int argc, char *argv[])
{
	// 변수 선언
	char infileName[21] = "subject.txt", outfileName[21], sub_code[8], sub_name[41], cmd[7];
	int check, credit, i;
	LIST list;
	FILE *infile, *outfile;

	// 콘솔창에서 입력하는 부분
	if (argc == 2)	// 파일명을 입력하는 경우
		strcpy(infileName, argv[1]);

	if ((infile = fopen(infileName, "r")) == NULL)		// 파일이 없는 경우
	{
		printf("파일을 읽어올 수 없습니다.\n");
		exit(100);
	}

	// LIST 초기화
	list.top = NULL;
	list.count = 0;

	// 파일 정보 읽어오기
	while (fscanf(infile, "%s %s %d", sub_code, sub_name, &credit) != EOF)
	{
		addList(&list, sub_code, sub_name, credit);
	}
	showList(list);

	// 메뉴 루프
	while (1)
	{
		printf("\n>> ");
		scanf("%s",cmd);
		if (!strcmp(cmd, "show"))	// show
			showList(list);
		else if (!strcmp(cmd, "delete"))	// delete
		{
			printf("과목코드: ");
			scanf("%s", sub_code);
			check = codeCheck(list, sub_code);	// 과목코드 검사
			if (check)	// 과목코드가 없으면
			{
				printf("Not found\n");
				continue;
			}
			delSubject(&list, sub_code);	// 과목 삭제
			list.count--;
		}
		else if (!strcmp(cmd, "add"))	// add
		{
			printf("과목코드: ");
			scanf("%s", sub_code);
			check = codeCheck(list, sub_code);	// 과목코드 검사
			if (!check)		// 과목코드가 있는 경우
				continue;
			printf("과목명: ");
			scanf("%s", sub_name);
			printf("학점: ");
			scanf("%d", &credit);
			addList(&list, sub_code, sub_name, credit);	// 과목 추가
		}
		else if (!strcmp(cmd, "quit"))
			break;
	}
	
	// 파일에 출력하는 부분
	printf("파일명: ");
	scanf("%s", outfileName);
	outfile = fopen(outfileName, "w");
	printList(outfile, list);
	delList(&list);	// list 삭제

	// fclose
	fclose(infile);
	fclose(outfile);
	return 0;
}