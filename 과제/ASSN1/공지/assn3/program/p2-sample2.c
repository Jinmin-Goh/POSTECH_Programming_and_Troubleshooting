#include <stdio.h>

void main()
{
	FILE *infile1, *infile2, *infile3, *outfile;
	int a, b, c, n, i;
	int num, xp, yp;
	int swit = 1;										// �Ʒ����� in, outside�� �Ǵ��� swit�� �����صд�. �ʱⰪ�� 1�̴�.
	int x1, x2, y1, y2;
	int sa = 0;

	infile3 = fopen("indata.dat", "r");
	outfile = fopen("20080821.dat", "w");					// ���� ������ ����ִ� indata.dat�� ������� ����� �й�.dat�� �д´�. 

	while (fscanf(infile3, "%d %d %d", &num, &xp, &yp) != EOF)		// indata.dat�� �о� ���� �ƴϸ� while���� ����.
	{
	infile1 = fopen("polygon.dat", "r");
	infile2 = fopen("polygon.dat", "r");					// polygon.dat�� �ι� �о� ���̸� �ѹ��� 3���� ���ڸ� �а� �Ѱ� 
															// �ι�° ��ǥ���� �а� �ϳ��� ù��° ��ǥ���� �о���δ�.
	fscanf(infile2, "%d %d %d", &a, &b, &c);					
	fscanf(infile1, "%d", &n);

		for (i = 1; i <= n; i++)					// �ٰ����� �̷�� ������ ������ŭ(n) for���� ���� ���Ѵ�.
		{
			fscanf(infile1, "%d %d", &x1, &y1);
			fscanf(infile2, "%d %d", &x2, &y2);				// �ϳ��� 2, 3, 4,... ��° ��ǥ�� �а� �ϳ��� 1,2,3,... ��ǥ�� �д´�.

			
			sa = (x2 - x1) * (yp - y1) - (xp - x1) * (y2 - y1);		//������ sa�� ����Ѵ�.
		

			if (sa >= 0)							// �ѹ��̶� sa�� 0 �̻��� �ÿ��� swit�� 0���� �ٲٰ� for���� �������� ���� ��ǥ�� ���Ѵ�.
			{swit = 0; 
				break;}
		
			
		}
		if (swit == 0) {fprintf(outfile, "%d outside\n", num);}
		else if (swit == 1) {fprintf(outfile, "%d inside\n", num);}		// swit�� 0�̸� poind ID�� outside�� ����ϰ�, 1�̸� inside�� ����Ѵ�.
		swit = 1;									// swit�� 1�� �ʱ�ȭ.
	}	
	return;
}
