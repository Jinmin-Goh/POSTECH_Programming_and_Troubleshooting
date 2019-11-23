#include<stdio.h>

float calc_average(int a, int b);
char calc_grade(float avg);

int main()
{
	int a, b;
	float avg;
	char grd;

	printf("Enter your midterm score: ");
	scanf("%d", &a);
	printf("Enter your final score: ");
	scanf("%d", &b);
	avg = calc_average(a, b);
	grd = calc_grade(avg);
	printf("Average: %.1f\n", avg);
	printf("Grade: %c\n", grd);
	return 0;
}

float calc_average(int a, int b)
{
	float avg;
	avg = ((float)a + b) / 2;
	return avg;
}

char calc_grade(float avg)
{
	if(avg >= 90)
		return 'A';
	else if(avg >= 80)
		return 'B';
	else if(avg >= 70)
		return 'C';
	else if(avg >= 60)
		return 'D';
	else
		return 'F';
}