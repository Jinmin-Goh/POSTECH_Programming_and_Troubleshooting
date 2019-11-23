#include<stdio.h>
#define MAX 6

void bubble_sort(int a[], int size);
void swap(int *x, int *y);
void print_array(int a[], int size);
void input_array(int a[], int size);

int main()
{
	int ary[MAX];

	printf("Input integer numbers to be sorted: ");
	input_array(ary, MAX);

	printf(" Unsorted:");
	print_array(ary, MAX);

	printf("----------------------------------\n");
	bubble_sort(ary, MAX);
	printf("----------------------------------\n");

	printf("   Sorted:");
	print_array(ary, MAX);

	return 0;
}

void bubble_sort(int a[], int size)
{
	int i, j, count = 0;
	for (i = 0; i < MAX -1; i++)
	{
		for (j = MAX - 1; j > i; j--)
		{
			if (a[j - 1] > a[j])
				swap(&a[j], &a[j - 1]);
		}
		count++;
		printf("[step%3d]:", count);
		print_array(a, size);
	}
}

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void print_array(int a[], int size)
{
	int i;
	for (i = 0; i < MAX; i++)
		printf("%4d", a[i]);
	printf("\n");
}

void input_array(int a[], int size)
{
	int i;
	for (i = 0; i < MAX; i++)
		scanf("%d", &a[i]);
}