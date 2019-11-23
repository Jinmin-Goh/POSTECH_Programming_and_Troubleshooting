#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "subjectList.h"
#include "studentList.h"



int main(int argc, char *argv[])
{
	// 변수 선언
	char subjectfileName[21], studentfileName[21], sub_code[8], sub_name[41], test[9], name[11], dept[7], grade[3];
	int check, credit, i, id, level, sub_num, cmd;
	LIST subjectList;
	STDLIST studentList;
	FILE *subjectfile, *studentfile;

	// 콘솔창에서 입력하는 부분
	strcpy(subjectfileName, argv[1]);
	strcpy(studentfileName, argv[2]);

	if (((subjectfile = fopen(subjectfileName, "r")) == NULL) || ((studentfile = fopen(studentfileName, "r")) == NULL))		// 파일이 없는 경우
	{
		printf("파일을 읽어올 수 없습니다.\n");
		exit(100);
	}

	// LIST 초기화
	subjectList.top = NULL;
	subjectList.count = 0;
	studentList.top = NULL;
	studentList.end = NULL;
	studentList.count = 0;

	// subject 파일 정보 읽기 및 LIST 생성
	while (fscanf(subjectfile, "%s %s %d", sub_code, sub_name, &credit) != EOF)
	{
		addList(&subjectList, sub_code, sub_name, credit);
	}

	// students 파일 정보 읽기 밀 STDLIST 생성
	while (fscanf(studentfile, "%s", test) != EOF)
	{
		if (test[0] >= '0' && test[0] <= '9')	// 학번인 경우
		{
			id = atoi(test);
			fscanf(studentfile, "%s %s %d", name, dept, &level);	// 나머지 학생 인적사항을 받은 뒤
			addStudentList(&studentList, id, name, dept, level);	// studentList를  함수로 생성한다
			studentList.end->sub_num = 0;
			i = 0;
		}
		else		// 과목코드인 경우 학번이 나올때까지 studentList에 과목과 점수를 넣는다
		{
			strcpy(sub_code, test);
			fscanf(studentfile, "%s", grade);
			strcpy(studentList.end->subjects[i].sub_code, sub_code);
			strcpy(studentList.end->subjects[i].grade, grade);
			studentList.end->sub_num++;
			i++;
		}
	}
	
	// 메뉴 루프
	while (1)
	{
		printf("### 성적 관리 프로그램 ###\n");
		printf("1. 학생별 성적\n");
		printf("2. 과목별 성적\n");
		printf("0. 종료\n");
	
		// 입력 확인 루프
		while (1)
		{
			printf(">> ");
			scanf("%d", &cmd);
			if (cmd < 0 || cmd > 2)
				printf("올바른 입력이 아닙니다.\n\n");
			else
				break;
		}

		switch (cmd)
		{
		case 1:
			printStudentGrade(subjectList, studentList);	// 학생별 성적을 출력
			continue;
		case 2:
			printSubjectGrade(subjectList, studentList);	// 과목별 성적을 출력
			continue;
		case 0:
			break;	// 메뉴 종료
		}
		break;
	}

	// 메모리 해제
	delList(&subjectList);
	delStdList(&studentList);
	fclose(subjectfile);
	fclose(studentfile);
	return 0;
}