#include <stdio.h>

int sigma(int a, int b);
int sigma_rec(int a, int b);

int main()
{
	int a, b, sum;
	printf("2개의 정수입력: ");
	scanf("%d%d", &a, &b);
	printf("%d\n", sigma(a, b));
	printf("%d\n", sigma_rec(a, b));
}

int sigma(int a, int b)
{
	int i, sum = 0;
	for (i = a; i <= b; i++)
		sum = sum + i;
	return sum;
}

int sigma_rec(int a, int b)
{
	if (b == a)
		return a;
	else
		return a + sigma_rec(a + 1, b);
}