#include <stdio.h>

void print_matrix(int arr[20][20], int size);

int main()
{
	int size, arr[20][20] = {0}, i, j;
	printf("Enter the size of square: ");
	scanf("%d", &size);
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (i + j < size - 1)
				arr[i][j] = 1;
			else if (i + j > size - 1)
				arr[i][j] = -1;
		}
	}
	print_matrix(arr, size);
	return 0;
}

void print_matrix(int arr[20][20], int size)
{
	int i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	return;
}