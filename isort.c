#include <stdio.h>
#include "header.h"

#define INPUT_SIZE 50

int main()
{
	// int arr[8] = {8, 7, 6, 5, 4, 3, 2, 1};
	// int arr[INPUT_SIZE] = {75, 43, 28, 29, 70, 76, 23, 96, 26, 2, 40, 21, 55, 13, 32, 56, 5, 64, 14, 77, 40, 70, 67, 38, 48, 59, 42, 42, 28, 6, 79, 46, 81, 26, 64, 66, 78, 58, 9, 1, 14, 44, 8, 31,
	// 			  46, 25, 8, 32, 49, 93};
	int arr[INPUT_SIZE];
	for (int i = 0; i < INPUT_SIZE; i++)
	{
		scanf("%d", &arr[i]);
	}

	// print_array(arr, 8);
	// print_array(arr, INPUT_SIZE);

	// insertion_sort(arr, 8);
	insertion_sort(arr, INPUT_SIZE);
	print_array(arr, INPUT_SIZE);


	return 0;
}