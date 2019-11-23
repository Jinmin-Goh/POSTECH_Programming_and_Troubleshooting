#include <stdio.h>

void partial_print(int *arr_start, int size);
int partial_sum(int *arr_start, int *arr_end);

int main()
{
	int arr[10], i, st, en, sum;

	printf("Enter 10 elements of array: ");
	for (i = 0; i < 10; i++)
		scanf("%d", &arr[i]);
	printf("Numbers that you enter are:");
	partial_print(arr, 10);
	printf("Enter the starting and ending index: ");
	scanf("%d%d", &st, &en);
	sum = partial_sum(arr + st, arr + en);
	printf("Sum from array[%d] to array[%d] is %d\n", st, en, sum);
	printf("Partial array output:");
	partial_print(arr + st, en - st + 1);
	return 0;
}

void partial_print(int *arr_start, int size)
{
	int *i;
	for(i = arr_start; i < arr_start + size; i++)
	{
		printf(" %d", *i);
	}
	printf("\n");
	return;
}

int partial_sum(int *arr_start, int *arr_end)
{
	int sum = 0;
	int *i;
	while(arr_start <= arr_end)
	{
		sum = sum + *arr_start;
		arr_start++;
	}
	printf("\n");
	return sum;
}
