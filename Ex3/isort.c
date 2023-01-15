#include <stdio.h>
#include "header.h"

#define INPUT_SIZE 50

int main()
{
	int arr[INPUT_SIZE];
	for (int i = 0; i < INPUT_SIZE; i++)
	{
		scanf("%d", (arr+i));
	}
	insertion_sort(arr, INPUT_SIZE);
	print_array(arr, INPUT_SIZE);	return 0;
}