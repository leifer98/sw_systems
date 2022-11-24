#include <stdio.h>
#include "my_mat.h"

int main()
{
	int mat[10][10] = {	{0,3,1,0,0,2,0,0,0,0},
						{3,0,1,0,0,0,0,0,0,0},
						{1,1,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,5,0,0},
						{0,0,0,0,0,0,0,4,1,1},
						{2,0,0,0,0,0,0,2,0,0},
						{0,0,0,0,0,2,0,0,0,0},
						{0,0,0,5,4,0,0,0,0,0},
						{0,0,0,0,1,0,0,0,0,0},						
						{0,0,0,0,1,0,0,0,0,0}};

	//  	0 1 2 3 4 5 6 7 8 9

	//0 	0 3 1 0 0 2 0 0 0 0
	//1 	3 0 1 0 0 0 0 0 0 0 
	//2 	1 1 0 0 0 0 0 0 0 0 
	//3		0 0 0 0 0 0 0 5 0 0 
	//4 	0 0 0 0 0 0 0 4 1 1 
	//5  	2 0 0 0 0 0 2 0 0 0 
	//6 	0 0 0 0 0 2 0 0 0 0 
	//7  	0 0 0 5 4 0 0 0 0 0 
	//8  	0 0 0 0 1 0 0 0 0 0 
	//9  	0 0 0 0 1 0 0 0 0 0
	
	
	// b_function(mat,1,9);

	b_function(mat,6,2); //TRUE

	// int result = c_function(mat,4,6); //2
	// printf("The result is: %d\n", result);
	b_function(mat,6,4); //FALSE

	b_function(mat,2,3); //FALSE

	int result = c_function(mat,0,1); //2
	printf("The result is: %d\n", result);

	result = c_function(mat,1,5); //4
	printf("The result is: %d\n", result);

	result = c_function(mat,7,8); //4
	printf("The result is: %d\n", result);

	result = c_function(mat,1,1); //-1
	printf("The result is: %d\n", result);

	b_function(mat,1,1); //FALSE
	result = c_function(mat,5,9); //-1
	printf("The result is: %d\n", result);

	b_function(mat,5,9); //FALSE

	return 0;
}
