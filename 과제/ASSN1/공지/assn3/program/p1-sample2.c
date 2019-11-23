#include <stdio.h>         

int N;		//사이즈
char ch;	//명령의 종류

int point(int x, int y)		//초기 위치에 따른 숫자를 나타내는 함수
{
	return (N*x + y + 1);	//i행 j열에는 N*(i-1)+j값을 반환
}

void rotation()				//숫자 정사각형을 회전시켜서 출력하는 함수
{
	int i, j;
	if(ch=='l' || ch=='L')		//왼쪽으로 회전시키는 경우
	{
		for(i=N-1;i>=0;i--)		//윗부분 삼각형 모양 출력
		{
			for(j=0;j<i;j++)
			{
				printf(" ");	
			}
			j=0;
			while(1)
			{
				printf("%d ", point(j, j+i));
				if(j+i==N-1)
					break;
				j++;
			}
			printf("\n");
		}
		for(i=1;i<N;i++)		//아랫부분 삼각형 모양 출력
		{
			for(j=0;j<i;j++)
				printf(" ");
			while(1)
			{
				printf("%d ", point(j, j-i));
				if(j==N-1)
					break;
				j++;
			}
			printf("\n");
		}
	}

	else						//오른쪽으로 회전시키는 경우
	{
		for(i=0;i<N;i++)		//윗부분 삼각형 모양 출력
		{
			for(j=N-1;j>i;j--)
			{
				printf(" ");
			}
			j=i;
			while(1)
			{
				printf("%d ", point(j, i-j));
				if(j==0)
					break;
				j--;
			}
			printf("\n");
		}
		for(i=1;i<N;i++)		//아랫부분 삼각형 모양 출력
		{
			for(j=0;j<i;j++)
				printf(" ");
			j=N-1;
			while(1)
			{
				printf("%d ", point(j, N-1+i-j));
				if(j==i)
					break;
				j--;
			}
			printf("\n");
		}
	}
}

int main(void)
{
	int i, j;

	while(1)
	{

		printf("Enter size : ");
		scanf("%d", &N);

		for(i=0;i<N;i++)		//맨 처음 정사각형 모양 출력
		{
			for(j=0;j<N;j++)
			{
				printf("%d ", point(i, j));
			}
			printf("\n");
		}

		while(1)		//계속하여 알파벳을 받도록 while문 설정
		{
			scanf("%c", &ch);
			if( ch=='r' || ch=='R' || ch=='l' || ch=='L' )		//회전시키는 경우
				rotation();
			else if( ch=='c' || ch=='C' )		//c를 받으면 맨 처음의 while문으로 돌아가서 다시 size를 입력받는다
				break;
			else if( ch=='q' || ch=='Q' )		//q를 받으면 프로그램을 종료한다
				return 0;
			else if( ch != '\n')				//이상한 문자를 받으면 에러 처리
				printf("Input error.\n");
		}
	}
}