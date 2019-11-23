#include<stdio.h>

int main()
{
	int stdNum, mid, fin, std = 0;
	char grade;
	float avg, sum = 0.0;
	FILE *infile, *outfile;

	infile = fopen("score.txt", "r");
	if (infile == NULL)
	{
		printf("Cannot open file.\n");
		return 100;
	}

	outfile = fopen("report.txt", "w");
	if (outfile == NULL)
	{
		printf("Cannot open file.\n");
		return 200;
	}

	fprintf(outfile, "----------------------\n");
	fprintf(outfile, "  ÇÐ¹ø      ÃÑÁ¡(ÇÐÁ¡)\n");
	fprintf(outfile, "----------------------\n");
	while (fscanf(infile, "%d%d%d", &stdNum, &mid, &fin) != EOF)
	{
		avg = 0.4 * mid + 0.6 * fin;
		if (avg >= 90)
			grade = 'A';
		else if (avg >= 80)
			grade = 'B';
		else if (avg >= 70)
			grade = 'C';
		else if (avg >= 60)
			grade = 'D';
		else
			grade = 'F';
		sum = sum + avg;
		fprintf(outfile, "%d      %.2f (%c)\n", stdNum, avg, grade);
		std++;
	}
	fprintf(outfile, "----------------------\n");
	fprintf(outfile, "  Æò±Õ      %.2f\n", (sum / std));
	fprintf(outfile, "----------------------\n");

	fclose(infile);
	fclose(outfile);

	return 0;
}
