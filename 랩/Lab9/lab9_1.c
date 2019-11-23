#include <stdio.h>
#include <stdlib.h>

void find_minmax(int *arr, int size, int *max, int *min);

int main()
{
	int size, max, min, i, addsize;
	int* arr;
	printf("How many integers would you like to enter? ");
	scanf("%d", &size);
	arr = (int *)malloc(size * sizeof(int));

	printf("Enter %d integers: ", size);
	for (i = 0; i < size; i++)
		scanf("%d", &arr[i]);
	printf("The elements in the array include\n");
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");

	find_minmax(arr, size, &max, &min);
	printf("Maximum is %d\n", max);
	printf("Minimum is %d\n", min);

	printf("How many more integers would you like to add? ");
	scanf("%d", &addsize);

	arr = (int*)realloc(arr, (size + addsize) * sizeof(int));

	printf("Enter %d integers: ", addsize);
	for (i = 0; i < addsize; i++)
		scanf("%d", &arr[size + i]);
	printf("The elements in the array include\n");
	for (i = 0; i < size + addsize; i++)
		printf("%d ", arr[i]);
	printf("\n");

	find_minmax(arr, size + addsize, &max, &min);
	printf("Maximum is %d\n", max);
	printf("Minimum is %d\n", min);

	free(arr);

	return 0;
}

void find_minmax(int *arr, int size, int *max, int *min)
{
	int i;
	*max = arr[0];
	*min = arr[0];
	for (i = 0; i < size - 1; i++)
	{
		if (*max < arr[i + 1])
			*max = arr[i + 1];
		if (*min > arr[i + 1])
			*min = arr[i + 1];
	}
	return;
}