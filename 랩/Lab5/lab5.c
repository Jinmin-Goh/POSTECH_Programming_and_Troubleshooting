#include <stdio.h>

int seqSearch(int arr[], int search);

int main()
{
	int arr[10], i, result, search;
	printf("Input 10 integer values: ");
	for(i = 0; i < 10; i++)
		scanf("%d", &arr[i]);
	printf("Entered number is        ");
	for(i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");
	printf("Input an integer that you ant to find: ");
	scanf("%d", &search);
	result = seqSearch(arr, search);
	if(result == -1)
		printf("Not Found\n");
	else
		printf("The index of %d is %d\n", search, result);

	return 0;
}

int seqSearch(int arr[], int search)
{
	int i = 0;
	
	while(i < 10)
	{
		if(arr[i] == search)
			return i;
		else
			i++;
	}
	return -1;
}