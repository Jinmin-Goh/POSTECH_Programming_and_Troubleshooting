#include <stdio.h>

void main()
{
	FILE *infile1, *infile2, *infile3, *outfile;
	int a, b, c, n, i;
	int num, xp, yp;
	int swit = 1;										// 아래에서 in, outside를 판단할 swit을 설정해둔다. 초기값은 1이다.
	int x1, x2, y1, y2;
	int sa = 0;

	infile3 = fopen("indata.dat", "r");
	outfile = fopen("20080821.dat", "w");					// 비교할 점들이 들어있는 indata.dat과 결과물을 출력할 학번.dat을 읽는다. 

	while (fscanf(infile3, "%d %d %d", &num, &xp, &yp) != EOF)		// indata.dat을 읽어 끝이 아니면 while문을 돈다.
	{
	infile1 = fopen("polygon.dat", "r");
	infile2 = fopen("polygon.dat", "r");					// polygon.dat를 두번 읽어 들이며 한번은 3개의 숫자를 읽고 넘겨 
															// 두번째 좌표부터 읽고 하나는 첫번째 좌표부터 읽어들인다.
	fscanf(infile2, "%d %d %d", &a, &b, &c);					
	fscanf(infile1, "%d", &n);

		for (i = 1; i <= n; i++)					// 다각형을 이루는 점들의 개수만큼(n) for문을 돌려 비교한다.
		{
			fscanf(infile1, "%d %d", &x1, &y1);
			fscanf(infile2, "%d %d", &x2, &y2);				// 하나는 2, 3, 4,... 번째 좌표를 읽고 하나는 1,2,3,... 좌표를 읽는다.

			
			sa = (x2 - x1) * (yp - y1) - (xp - x1) * (y2 - y1);		//각각의 sa를 계산한다.
		

			if (sa >= 0)							// 한번이라도 sa가 0 이상일 시에는 swit을 0으로 바꾸고 for문을 빠져나가 다음 좌표를 비교한다.
			{swit = 0; 
				break;}
		
			
		}
		if (swit == 0) {fprintf(outfile, "%d outside\n", num);}
		else if (swit == 1) {fprintf(outfile, "%d inside\n", num);}		// swit이 0이면 poind ID와 outside를 출력하고, 1이면 inside를 출력한다.
		swit = 1;									// swit을 1로 초기화.
	}	
	return;
}
